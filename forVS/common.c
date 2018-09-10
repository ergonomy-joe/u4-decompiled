#include <windows.h>

#include "common.h"

#include "u4_scan.h"

int CMN_kbhit = 0;

static HWND CMN_hwnd = 0;
/*static */HDC currentHDC = 0;
static unsigned char *pShapesWIN = 0;
static unsigned char *pCharsetWIN = 0;
//----------------------------------------
COLORREF U4_PALETTE[4] = {
	RGB(0x1f,0x1f,0x1f),//black
	RGB(0x1f,0xe0,0xe0),//cyan
	RGB(0xe0,0x1f,0xe0),//magenta
	RGB(0xe0,0xe0,0xe0)//white
};
unsigned int U4_PAL_STRETCH[4];
HBRUSH U4_BRUSH[4];
HPEN U4_PEN[4];

//SetPixelV[must verify with GetDeviceCaps RC_BITBLT] or SetPixel
//try SetDIBitsToDevice?

void CMN_putpixel(int x, int y, int col) {
#if (RATIO == 1)
	SetPixelV(currentHDC, x, y, U4_PALETTE[col]);
#elif (RATIO == 2)
	SetPixelV(currentHDC, x * RATIO + 0, y * RATIO + 0, U4_PALETTE[col]);
	SetPixelV(currentHDC, x * RATIO + 0, y * RATIO + 1, U4_PALETTE[col]);
	SetPixelV(currentHDC, x * RATIO + 1, y * RATIO + 0, U4_PALETTE[col]);
	SetPixelV(currentHDC, x * RATIO + 1, y * RATIO + 1, U4_PALETTE[col]);
#else
	#error unknown ratio
#endif
}

void CMN_xorpixel(int x, int y, int col) {
	COLORREF pix = GetPixel(currentHDC, x * RATIO, y * RATIO) ^ U4_PALETTE[col];
#if (RATIO == 1)
	SetPixelV(currentHDC, x, y, pix);
#elif (RATIO == 2)
	SetPixelV(currentHDC, x * RATIO + 0, y * RATIO + 0, pix);
	SetPixelV(currentHDC, x * RATIO + 0, y * RATIO + 1, pix);
	SetPixelV(currentHDC, x * RATIO + 1, y * RATIO + 0, pix);
	SetPixelV(currentHDC, x * RATIO + 1, y * RATIO + 1, pix);
#else
	#error unknown ratio
#endif
}

unsigned char *CMN_getCharsetData(int c) {
	return pCharsetWIN + c * 2 * 8;
}

unsigned char *CMN_getShapeData(int c) {
	return pShapesWIN + c * 4 * 16;
}

void CMN_puttile(unsigned char c, int x, int y) {
/*	static char HEX[] = "0123456789ABCDEF";
	char txt[2];

	txt[0] = HEX[(c >> 4) & 0xf];
	txt[1] = HEX[c & 0xf];
	TextOut(currentHDC, x * RATIO, y * RATIO, txt, 2);*/
	int i,j;
	unsigned char *p = CMN_getShapeData(c);
	static unsigned int lpvBits[16*16];
	BITMAPINFO bi;
	for(i = 0; i < 16; i ++) {
		for(j = 0; j < 16; j += 4) {
			unsigned char byt;
			int ii;

			byt = *p++;
			ii = (i & 7) * 2 + (i >> 3);
			lpvBits[j + 0 + ((16 - 1) - ii) * 16] = U4_PAL_STRETCH[(byt & 0xc0) >> 6];
			lpvBits[j + 1 + ((16 - 1) - ii) * 16] = U4_PAL_STRETCH[(byt & 0x30) >> 4];
			lpvBits[j + 2 + ((16 - 1) - ii) * 16] = U4_PAL_STRETCH[(byt & 0x0c) >> 2];
			lpvBits[j + 3 + ((16 - 1) - ii) * 16] = U4_PAL_STRETCH[(byt & 0x03) >> 0];
		}
	}

	bi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	bi.bmiHeader.biWidth = 16;
	bi.bmiHeader.biHeight = 16;
	bi.bmiHeader.biPlanes = 1;
	bi.bmiHeader.biBitCount = 32;
	bi.bmiHeader.biCompression = BI_RGB;
	bi.bmiHeader.biSizeImage = 0;
	bi.bmiHeader.biXPelsPerMeter = 0;
	bi.bmiHeader.biYPelsPerMeter = 0;
	bi.bmiHeader.biClrUsed = 0;
	bi.bmiHeader.biClrImportant = 0;

	/*int */StretchDIBits(
		currentHDC,
		x * RATIO, y * RATIO, 16 * RATIO, 16 * RATIO,//dst
		0, 0, 16, 16,//src
		lpvBits,
		&bi,
		DIB_RGB_COLORS,
		SRCCOPY
	);
}

void CMN_putchar(char c, int x, int y) {
/*	RECT rect;

	rect.top = txt_Y * 16;
	rect.left = txt_X * 16;
	rect.bottom = rect.top + 16;
	rect.right = rect.left + 16;
	FillRect(currentHDC, &rect, U4_BRUSH[0]);
	SetBkColor(currentHDC, 0xff0000);
	SetTextColor(currentHDC, 0xffffff);
	TextOut(currentHDC, txt_X * 16, txt_Y * 16, &c, 1);*/
	int i,j;
	unsigned char *p = CMN_getCharsetData(c);
	static unsigned int lpvBits[8*8];
	BITMAPINFO bi;
	for(i = 0; i < 8; i ++) {
		for(j = 0; j < 8; j += 4) {
			unsigned char byt;
			int ii;
			
			byt = *p++;
			ii = (i & 3) * 2 + (i >> 2);
			lpvBits[j + 0 + ((8 - 1) - ii) * 8] = U4_PAL_STRETCH[(byt & 0xc0) >> 6];
			lpvBits[j + 1 + ((8 - 1) - ii) * 8] = U4_PAL_STRETCH[(byt & 0x30) >> 4];
			lpvBits[j + 2 + ((8 - 1) - ii) * 8] = U4_PAL_STRETCH[(byt & 0x0c) >> 2];
			lpvBits[j + 3 + ((8 - 1) - ii) * 8] = U4_PAL_STRETCH[(byt & 0x03) >> 0];
		}
	}

	bi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	bi.bmiHeader.biWidth = 8;
	bi.bmiHeader.biHeight = 8;
	bi.bmiHeader.biPlanes = 1;
	bi.bmiHeader.biBitCount = 32;
	bi.bmiHeader.biCompression = BI_RGB;
	bi.bmiHeader.biSizeImage = 0;
	bi.bmiHeader.biXPelsPerMeter = 0;
	bi.bmiHeader.biYPelsPerMeter = 0;
	bi.bmiHeader.biClrUsed = 0;
	bi.bmiHeader.biClrImportant = 0;

	/*int */StretchDIBits(
		currentHDC,
		x * RATIO, y * RATIO, 8 * RATIO, 8 * RATIO,//dst
		0, 0, 8, 8,//src
		lpvBits,
		&bi,
		DIB_RGB_COLORS,
		SRCCOPY
	);
}
void CMN_clear(int x, int y, int w, int h, int col) {
	RECT rect;

	CONSOLE("Gra_clrscr\n");
	if(CMN_beginScene()) {
		rect.left = x * 8 * RATIO;
		rect.top = y * 8 * RATIO;
		rect.right = rect.left + w * 8 * RATIO;
		rect.bottom = rect.top + h * 8 * RATIO;

		FillRect(currentHDC, &rect, U4_BRUSH[col]);
		CMN_endScene();
	}
}
//----------------------------------------
LRESULT CALLBACK WndProc(HWND hWnd, UINT dwMsg, WPARAM wParam, LPARAM lParam) {
	switch(dwMsg) {
		case WM_PAINT:
		break;
		case WM_KEYDOWN:
			switch(wParam) {
				case VK_LEFT: CMN_kbhit = KBD_LEFT; break;
				case VK_RIGHT: CMN_kbhit = KBD_RIGHT; break;
				case VK_UP: CMN_kbhit = KBD_UP; break;
				case VK_DOWN: CMN_kbhit = KBD_DOWN; break;

				case VK_RETURN: CMN_kbhit = KBD_ENTER; break;
				case VK_ESCAPE: CMN_kbhit = KBD_ESC; break;
				case VK_SPACE: CMN_kbhit = KBD_SPACE; break;
				case VK_BACK: CMN_kbhit = KBD_BS; break;

				case 'A': CMN_kbhit = KBD_A; break;
				case 'B': CMN_kbhit = KBD_B; break;
				case 'C': CMN_kbhit = KBD_C; break;
				case 'D': CMN_kbhit = KBD_D; break;
				case 'E': CMN_kbhit = KBD_E; break;
				case 'F': CMN_kbhit = KBD_F; break;
				case 'G': CMN_kbhit = KBD_G; break;
				case 'H': CMN_kbhit = KBD_H; break;
				case 'I': CMN_kbhit = KBD_I; break;
				case 'J': CMN_kbhit = KBD_J; break;
				case 'K': CMN_kbhit = KBD_K; break;
				case 'L': CMN_kbhit = KBD_L; break;
				case 'M': CMN_kbhit = KBD_M; break;
				case 'N': CMN_kbhit = KBD_N; break;
				case 'O': CMN_kbhit = KBD_O; break;
				case 'P': CMN_kbhit = KBD_P; break;
				case 'Q': CMN_kbhit = KBD_Q; break;
				case 'R': CMN_kbhit = KBD_R; break;
				case 'S': CMN_kbhit = KBD_S; break;
				case 'T': CMN_kbhit = KBD_T; break;
				case 'U': CMN_kbhit = KBD_U; break;
				case 'V': CMN_kbhit = KBD_V; break;
				case 'W': CMN_kbhit = KBD_W; break;
				case 'X': CMN_kbhit = KBD_X; break;
				case 'Y': CMN_kbhit = KBD_Y; break;
				case 'Z': CMN_kbhit = KBD_Z; break;

				case '0': CMN_kbhit = KBD_0; break;
				case '1': CMN_kbhit = KBD_1; break;
				case '2': CMN_kbhit = KBD_2; break;
				case '3': CMN_kbhit = KBD_3; break;
				case '4': CMN_kbhit = KBD_4; break;
				case '5': CMN_kbhit = KBD_5; break;
				case '6': CMN_kbhit = KBD_6; break;
				case '7': CMN_kbhit = KBD_7; break;
				case '8': CMN_kbhit = KBD_8; break;
				//case '9': CMN_kbhit = KBD_9; break;
			}
		break;
		case WM_KEYUP:
		break;
	}

	return DefWindowProc(hWnd, dwMsg, wParam, lParam);
}
void CMN_createWindow(int dwWidth, int dwHeight, void *pShp, void *pChr) {
	WNDCLASS wndclass;

	pShapesWIN = (unsigned char *)pShp;
	pCharsetWIN = (unsigned char *)pChr;

	memset(&wndclass, 0, sizeof(WNDCLASS));
    wndclass.style = 0;//CS_HREDRAW|CS_VREDRAW;
    wndclass.lpfnWndProc = WndProc;
    wndclass.cbClsExtra = 0;
    wndclass.cbWndExtra = 0;
    wndclass.hInstance = GetModuleHandle(0);
    wndclass.hIcon = LoadIcon(0, IDI_APPLICATION);
    wndclass.hCursor = LoadCursor(0, IDC_ARROW);
    wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    wndclass.lpszMenuName = 0;
	wndclass.lpszClassName = TEXT("U4_CLASS");
	if(RegisterClass(&wndclass)) {
		RECT rect;
		int dwStyle;

		dwStyle = WS_OVERLAPPEDWINDOW;

		rect.left = 0;
		rect.top = 0;
		rect.right = dwWidth;
		rect.bottom = dwHeight;
		AdjustWindowRect(&rect, dwStyle, 0);

		CMN_hwnd = CreateWindow(
			TEXT("U4_CLASS"),//lpClassName,
			TEXT("U4"),//lpWindowName,
			dwStyle,
			CW_USEDEFAULT,CW_USEDEFAULT,//x,y,
			rect.right - rect.left, rect.bottom - rect.top,//nWidth,nHeight,
			0,//hWndParent,
			0,//hMenu,
			GetModuleHandle(0),//hInstance,
			0//lpParam
		);
		if(CMN_hwnd) {
			UpdateWindow(CMN_hwnd);
			ShowWindow(CMN_hwnd, SW_SHOWDEFAULT);
		}
	}

	//-- convert palette for StretchDIBits --
	U4_PAL_STRETCH[0] = (GetRValue(U4_PALETTE[0]) << 16) | (GetGValue(U4_PALETTE[0]) << 8) | GetBValue(U4_PALETTE[0]);
	U4_PAL_STRETCH[1] = (GetRValue(U4_PALETTE[1]) << 16) | (GetGValue(U4_PALETTE[1]) << 8) | GetBValue(U4_PALETTE[1]);
	U4_PAL_STRETCH[2] = (GetRValue(U4_PALETTE[2]) << 16) | (GetGValue(U4_PALETTE[2]) << 8) | GetBValue(U4_PALETTE[2]);
	U4_PAL_STRETCH[3] = (GetRValue(U4_PALETTE[3]) << 16) | (GetGValue(U4_PALETTE[3]) << 8) | GetBValue(U4_PALETTE[3]);
	//-- --
	U4_BRUSH[0] = CreateSolidBrush(U4_PALETTE[0]);
	U4_BRUSH[1] = CreateSolidBrush(U4_PALETTE[1]);
	U4_BRUSH[2] = CreateSolidBrush(U4_PALETTE[2]);
	U4_BRUSH[3] = CreateSolidBrush(U4_PALETTE[3]);

	U4_PEN[0] = CreatePen(PS_SOLID, 0, U4_PALETTE[0]);
	U4_PEN[1] = CreatePen(PS_SOLID, 0, U4_PALETTE[1]);
	U4_PEN[2] = CreatePen(PS_SOLID, 0, U4_PALETTE[2]);
	U4_PEN[3] = CreatePen(PS_SOLID, 0, U4_PALETTE[3]);
}
void CMN_pumpmessages() {
	MSG msg;

	while(PeekMessage(&msg, CMN_hwnd, 0, 0, PM_REMOVE)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}
int CMN_beginScene() {
	if(currentHDC)
		return 0;
	currentHDC = GetDC(CMN_hwnd);

	return currentHDC != 0;
}
int CMN_endScene() {
	if(currentHDC == 0)
		return 0;
	ReleaseDC(CMN_hwnd, currentHDC);
	currentHDC = 0;

	return 1;
}
//----------------------------------------
