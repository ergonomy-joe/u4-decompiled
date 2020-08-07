#include "title.h"

#include <windows.h>
#include <stdio.h>
#include <io.h>
#include <fcntl.h>

#include "common.h"

unsigned D_31C0;
struct tParty Party;
void *pShapes;
void *pCharset;
unsigned D_7082;
unsigned equip_flags;
struct tPSP *far_psp;
void *pAnim;
unsigned cursor_rate;
unsigned D_6E80;
unsigned D_6E80;
unsigned speed_info;
struct t_500 D_6976;
unsigned D_7078;
unsigned txt_X;
void *pTitle;
unsigned txt_Y;

//----------------------------------------
int u_kbhit() {
	CONSOLE("u_kbhit\n");
	CMN_pumpmessages();
	t_callback();

	return CMN_kbhit != 0;
}
int u_kbread() {
	int ret;

	while(CMN_kbhit == 0) {
		CMN_pumpmessages();
	}
	ret = CMN_kbhit;
	CMN_kbhit = 0;

	return ret;
}
u_kbflush() {
	CONSOLE("u_kbflush\n");
	CMN_kbhit = 0;

	FAKE_RET;
}

__cdecl u_delay(unsigned a, unsigned b) {
	while(a) {
		a --;
		CMN_pumpmessages();
		t_callback();
		if(b && CMN_kbhit != 0)
			break;
	}

	FAKE_RET;
}
int u_rand_a() {
	CONSOLE("u_rand_a\n");

	return rand();
}
unsigned char u_rand_b() {
	CONSOLE("u_rand_b\n");

	return rand();
}

Gra_putchar(char c) {
#if 0
	CONSOLE("Gra_putchar(%d,%d,", txt_X, txt_Y);
	switch(c) {
		case 7:
			CONSOLE("0x07");
		break;
		default:
			CONSOLE("'%c'", c);
	}
	CONSOLE(")\n");
#endif
	CMN_beginScene();
	CMN_putchar(c, txt_X * 8, txt_Y * 8);
	CMN_endScene();

	FAKE_RET;
}
__cdecl Gra_dot(int y, int x, int col) {
	CMN_beginScene();
	CMN_putpixel(x, y, col);
	CMN_endScene();

	FAKE_RET;
}
Gra_animFlow(unsigned tile) {
	int i;
	unsigned char *p;
	unsigned short AX,DX;
	CONSOLE("Gra_animFlow(%x)\n", tile);

	p = CMN_getShapeData(tile);
	AX = *(unsigned short *)(p + 0x3c);
	DX = *(unsigned short *)(p + 0x3e);
	for(i = 0; i < 8; i ++) {
		unsigned short temp;
		DO_SWAP(AX, *(unsigned short *)(p + 0x00), temp);
		DO_SWAP(AX, *(unsigned short *)(p + 0x20), temp);
		DO_SWAP(DX, *(unsigned short *)(p + 0x02), temp);
		DO_SWAP(DX, *(unsigned short *)(p + 0x22), temp);
		p += 4;
	}

	FAKE_RET;
}
static char random() { return (char)(rand() & 0xff); }
Gra_animFlag() {
	unsigned char *p;
	unsigned short temp;
	CONSOLE("Gra_animFlag\n");

	p = CMN_getShapeData(0);
	if(random() >= 0) {
		DO_SWAP(*(unsigned short *)(p + 0x2A4), *(unsigned short *)(p + 0x288), temp);
	}
	if(random() >= 0) {
		DO_SWAP(*(unsigned short *)(p + 0x2E2), *(unsigned short *)(p + 0x2c6), temp);
	}
	if(random() >= 0) {
		DO_SWAP(*(unsigned short *)(p + 0x404), *(unsigned short *)(p + 0x424), temp);
		DO_SWAP(*(unsigned short *)(p + 0x406), *(unsigned short *)(p + 0x426), temp);
	}
	if(random() >= 0) {
		DO_SWAP(*(unsigned short *)(p + 0x484), *(unsigned short *)(p + 0x4A4), temp);
		DO_SWAP(*(unsigned short *)(p + 0x486), *(unsigned short *)(p + 0x4A6), temp);
	}
	if(random() >= 0) {
		DO_SWAP(*(unsigned short *)(p + 0x3A0), *(unsigned short *)(p + 0x384), temp);
	}

	FAKE_RET;
}

__cdecl Gra_0(
	int height/*bp04*/, int width/*bp06*/, unsigned char *pSrc_0/*bp08*/,
	int dst_y/*bp0a*/,
	unsigned dst_ofs/*bp0c*/, unsigned dst_seg/*bp0e*/,
	int dst_x_in_byte/*bp10*/
) {
	int i, j;
	unsigned char *pSrc;

	CONSOLE("Gra_0\n");
	pSrc = pSrc_0;
	if(dst_ofs | dst_seg) {
		//*** render offscren ***
		CONSOLE("\t<<TODO>>\n");
	} else {
		CMN_beginScene();
		for(i = 0; i < height; i ++) {
			for(j = 0; j < width; j ++) {
				CMN_puttile(*(pSrc ++), dst_x_in_byte * 4 + j * 16, dst_y + i * 16);
			}
		}
		CMN_endScene();
	}

	FAKE_RET;
}
/*clear view zone*/
Gra_2() {
	CONSOLE("Gra_2 \"clear view zone\"\n");
	CMN_clear(1, 13, 38, 10, 0);

	FAKE_RET;
}

__cdecl Gra_3(
	int width_in_char/*bp04*/, int height/*bp06*/,
	int src_x_in_char/*bp08*/, int src_y/*bp0a*/,
	void *p/*bp0e:bp0c*/,
	int dst_y/*bp10*/,
	int random_stuff/*bp12*/,
	int dst_x_in_char/*bp14*/
) {
	int i,j;
	unsigned char *src_0;
	int width;
	int dst_x;

	CONSOLE("Gra_3\n");

	src_0 = (unsigned char *)p + (src_x_in_char * 8) / 4;
	width = width_in_char * 8;
	dst_x = dst_x_in_char * 8;
	CMN_beginScene();
	for(i = 0; i < height; i ++) {
		unsigned char *src;

		src = src_0 + ((src_y + i) & 1) * 0x2000 + ((src_y + i) >> 1) * 80;
		for(j = 0; j < width; j += 2 * 4) {
			unsigned short word;

			word = *(unsigned short *)src;
			src += sizeof(unsigned short);

			if(random_stuff != -1) {
				static unsigned short D_32D0[] = {
					0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
					0x0000,0x0001,0xC004,0x0010,0x0080,0x0104,0x0400,0x0401,
					0x0100,0xC3C0,0x1000,0xC410,0x1004,0x0411,0x0110,0x03C4,
					0x1080,0xC481,0x0110,0xC104,0x1010,0xD101,0x1084,0x13C1,
					0x1010,0x1304,0xC484,0x3CF0,0x0F3C,0x0F3F,0x3C84,0x3C3F,
					0x10F1,0x13FC,0xCFC1,0x3CF1,0xCFCF,0x3CFF,0xD13F,0x3FF1,
					0xD3F1,0xF3FC,0x3C8F,0xCF8F,0x3F3F,0xFFCF,0x13FC,0xCFFF,
					0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF
				};
				if(word == 0)
					continue;
				//TODO noise
				word &= D_32D0[(random_stuff & 0xff) + (rand() % 7)];
			}

			CMN_putpixel(dst_x + j + 0, dst_y + i, (word & 0x00c0) >>  6);
			CMN_putpixel(dst_x + j + 1, dst_y + i, (word & 0x0030) >>  4);
			CMN_putpixel(dst_x + j + 2, dst_y + i, (word & 0x000c) >>  2);
			CMN_putpixel(dst_x + j + 3, dst_y + i, (word & 0x0003) >>  0);
			CMN_putpixel(dst_x + j + 4, dst_y + i, (word & 0xc000) >> 14);
			CMN_putpixel(dst_x + j + 5, dst_y + i, (word & 0x3000) >> 12);
			CMN_putpixel(dst_x + j + 6, dst_y + i, (word & 0x0c00) >> 10);
			CMN_putpixel(dst_x + j + 7, dst_y + i, (word & 0x0300) >>  8);
		}
	}
	CMN_endScene();

	FAKE_RET;
}
/*clear text zone*/
Gra_5() {
	CONSOLE("Gra_5 \"clear text zone\"\n");
	CMN_clear(0, 19, 40, 6, 0);

	FAKE_RET;
}
__cdecl Gra_B(
	int width_in_char/*bp04*/, int height/*bp06*/,
	int src_x_in_char/*bp08*/, int src_y/*bp0a*/,
	void *p/*bp0e:bp0c*/,
	int dst_y/*bp10*/,
	int somecounter/*bp12*/,
	int dst_x_in_char/*bp14*/
) {
	CONSOLE("Gra_B==>");
	Gra_3(width_in_char, height, src_x_in_char, src_y, p, dst_y, somecounter, dst_x_in_char);

	FAKE_RET;
}
__cdecl Gra_C(int height, int width, void *p_0, int dst_y, void *dst, int dst_x_in_byte) {
	unsigned char *pSrc;
	unsigned char *dst_0;
	int i, j;

	CONSOLE("Gra_C\n");
	pSrc = (unsigned char *)p_0;
	dst_0 = (unsigned char *)dst + dst_x_in_byte;
	for(i = 0; i < height; i ++) {
		unsigned char *p;

		p = dst_0 + ((dst_y + i * 16) & 1) * 0x2000 + ((dst_y + i * 16) >> 1) * 80;
		for(j = 0; j < width; j ++) {
			int k;
			unsigned char *src;

			src = CMN_getShapeData(*(pSrc ++));
			for(k = 0; k < 8; k ++) {
				p[         k * 80 + 0] = src[0x00 + k * 4 + 0]; p[         k * 80 + 1] = src[0x00 + k * 4 + 1]; p[         k * 80 + 2] = src[0x00 + k * 4 + 2]; p[         k * 80 + 3] = src[0x00 + k * 4 + 3];
				p[0x2000 + k * 80 + 0] = src[0x20 + k * 4 + 0]; p[0x2000 + k * 80 + 1] = src[0x20 + k * 4 + 1]; p[0x2000 + k * 80 + 2] = src[0x20 + k * 4 + 2]; p[0x2000 + k * 80 + 3] = src[0x20 + k * 4 + 3];
			}
			p += 4;
		}
	}

	FAKE_RET;
}

int skip_bytes = 0;

void output_func(unsigned char root, unsigned char *destination, long* position) {
	if(skip_bytes) {
		skip_bytes --;
		return;
	}
    destination[*position] = root;
    (*position)++;
}

__cdecl Gra_inflate(const char *fname, void *dest) {
	char path[256];
	int fd;

	CONSOLE("Gra_inflate \"%s\"\n", fname);
	strcpy(path, U4_ROOT);
	strcat(path, fname);
	fd = _open(path, _O_RDONLY|_O_BINARY);
	if(fd) {
		int csz;
		int dsz;
		void *src;

		csz = _lseek(fd, 0, SEEK_END);
		_lseek(fd, 0, SEEK_SET);

		src = (unsigned char *)malloc(csz);
		_read(fd, src, csz);
		_close(fd);

		skip_bytes = 7;//skip bitmap header
{//from lzw.c
		typedef void (*WRITE_DECOMP)(unsigned char root, unsigned char *destination, long* position);
		extern long generalizedDecompress(WRITE_DECOMP outFunc, unsigned char* compressedMem, unsigned char* decompressedMem, long compressedSize);

		dsz = generalizedDecompress(output_func, src, dest, csz);
}
		free(src);
	}

	FAKE_RET;
}
Gra_clrscr() {
	CONSOLE("Gra_clrscr\n");
	CMN_clear(0, 0, 40, 25, 0);

	FAKE_RET;
}

void *_fmalloc(int sz) {
	void *ret;

	ret = malloc(sz);//add somme mem for security

	return ret;
}
_ffree(void *p) {
	free(p);

	FAKE_RET;
}
//-- for EGA? --
sizzleShapes() {
	FAKE_RET;
}
C_217E(char *a, void *b) {
	FAKE_RET;
}
//-- --
sound_1() {
	FAKE_RET;
}
low_clean() {
	FAKE_RET;
}
/*set int 24h handler*/
C_331E() {
	FAKE_RET;
}
Gra_init() {
	CMN_createWindow(320 * RATIO, 200 * RATIO, pShapes, pCharset);

	FAKE_RET;
}

int low_gra() {
	return 1;
}

struct tPSP the_psp;

low_init() {
	CONSOLE("low_init\n");
	//TODO
	far_psp = &the_psp;
	the_psp._80[0] =
	the_psp._80[2] =
	the_psp._80[4] = 0;

	FAKE_RET;
}

/*get some floppy #?*/
C_32AB(int a) {
	return 1;
}
int current_drive = 0;
/*current drive*/
int C_3290() {
	return current_drive;
}
/*current drive*/
C_3299(int num) {
	current_drive = num;

	FAKE_RET;
}

int Load(char *fname, unsigned size, void *buff) {
	int fd;
	unsigned ret;
	static char path[256];

	CONSOLE("Load:\"%s\"\n", fname);
	strcpy(path, U4_ROOT);
	strcat(path, fname);
	fd = _open(path, _O_RDONLY|_O_BINARY);
	if(fd <= 0)
		return -1;
	ret = _read(fd, buff, size);
	_close(fd);

	if(size == ret)
		return 1;

	return -1;
}
Save(char *fname, unsigned size, void *buff) {
	int fd;
	unsigned ret;
	static char path[256];

	CONSOLE("Save:\"%s\"\n", fname);
	strcpy(path, U4_ROOT);
	strcat(path, fname);
	fd = _open(path, _O_WRONLY|_O_BINARY);
	if(fd <= 0)
		return -1;
	ret = _write(fd, buff, size);
	_close(fd);

	if(size == ret)
		return 1;

	return -1;
}
Console(char *txt) {
	FAKE_RET;
}
