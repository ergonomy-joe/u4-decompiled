/*
 * Ultima IV - Quest Of The Avatar
 * (c) Copyright 1987 Lord British
 * reverse-coded by Ergonomy Joe in 2012
 */

#ifndef __U4_DOS_H__
#define __U4_DOS_H__

/*u4_dos*/
extern void far * cdecl /*C_1FF4*/dalloc(int);
extern cdecl /*C_2023*/dfree(void far *);
extern cdecl /*C_2033*/dopen(char *, int);
extern cdecl /*C_2049*/dlseek(int, unsigned long);
extern cdecl /*C_2067*/dread(int, void far *, int);
extern cdecl /*C_208B*/dwrite(int, void far *, int);
extern cdecl /*C_20AB*/dclose(int);

#endif
