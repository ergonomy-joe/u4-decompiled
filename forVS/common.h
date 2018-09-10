#ifndef __COMMON_H__
#define __COMMON_H__

#include <stdio.h>

//#define U4_ROOT "I:\\OSI\\U4\\ORIGINAL\\"
#define U4_ROOT "G:/WORKSPACE/UN_U4/ultima_4/"
#define RATIO 2

#define CONSOLE printf
#define FAKE_RET return 0

#define DO_SWAP(a,b,temp) { (temp) = (a); (a) = (b); (b) = (temp); }

extern int CMN_kbhit;

extern COLORREF U4_PALETTE[];
extern HBRUSH U4_BRUSH[];
extern HPEN U4_PEN[];

extern void CMN_createWindow(int dwWidth, int dwHeight, void *pShp, void *pChr);
extern void CMN_pumpmessages(void);
extern void CMN_clear(int x, int y, int w, int h, int col);

extern unsigned char *CMN_getCharsetData(int c);
extern unsigned char *CMN_getShapeData(int c);

extern int CMN_beginScene(void);
extern int CMN_endScene(void);
extern void CMN_putpixel(int x, int y, int col);
extern void CMN_xorpixel(int x, int y, int col);
extern void CMN_puttile(unsigned char c, int x, int y);
extern void CMN_putchar(char c, int x, int y);

#endif
