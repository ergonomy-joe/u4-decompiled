/*
 * Ultima IV - Quest Of The Avatar
 * (c) Copyright 1987 Lord British
 * reverse-coded by Ergonomy Joe in 2012
 */
#ifndef __U4_GRAPH_H__
#define __U4_GRAPH_H__

extern C_20C1(char *);
extern C_213B();
extern cdecl Gra_line(int, int, int, int, int);
extern cdecl /*C_2201*/Gra_00(int, int);
extern cdecl /*C_2206*/Gra_01(/**/);
extern cdecl /*C_220B*/Gra_02(/**/);
extern cdecl /*C_2210*/Gra_03();
extern cdecl /*C_221B*/Gra_04();
extern cdecl /*C_2226*/Gra_05(/*int h, int w, void *src, int dst_ofs*/);
extern cdecl /*C_222B*/Gra_dot(/*int, int, int*/);
extern /*C_2230*/Gra_CR();
extern /*C_2241*/Gra_09();
extern /*C_2246*/Gra_10();
extern /*C_224B*/Gra_11(int);
extern cdecl /*C_2250*/Gra_12(int, int);/*(uncalled)*/
extern /*C_226C*/Gra_13();
extern cdecl /*C_2271*/Gra_dot_OR(/*int, int, int*/);
extern cdecl /*C_2276*/Gra_dot_XOR(/*int, int, int*/);
extern cdecl /*C_227B*/Gra_16(/*char *, int, int*/);
extern cdecl /*C_2280*/Gra_17();
extern cdecl /*C_2297*/Gra_18(/**/);
extern cdecl /*C_229C*/Gra_19();
extern cdecl /*C_22A7*/Gra_animSpit();
extern cdecl /*C_22AC*/Gra_init(/*char *, char *, callback*/);
extern cdecl /*C_22B1*/Gra_clrscr();
extern /*C_22B6*/Gra_animFlow(unsigned);/*bug?*/
extern /*C_22BB*/Gra_animFlag();
extern /*C_22C0*/Gra_putchar(char);
extern /*C_22CF*/sizzleShapes();
extern /*C_2341*/sizzleCharset();

#endif
