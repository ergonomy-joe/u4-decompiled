/*
 * Ultima IV - Quest Of The Avatar
 * (c) Copyright 1987 Lord British
 * reverse-coded by Ergonomy Joe in 2012
 */

#include "u4.h"

unsigned char /*D_2D74*/Wall_x0[] = {0x08,0x28,0x48,0x58,0x5F,0x00};
unsigned char /*D_2D7A*/Wall_x1[] = {0xB7,0x97,0x77,0x67,0x60,0x00};
unsigned char /*D_2D80*/Wall_y0[] = {0x08,0x28,0x48,0x58,0x5F,0x00};
unsigned char /*D_2D86*/Wall_y1[] = {0xB7,0x97,0x77,0x67,0x60,0x00};

unsigned char /*D_2D8C*/LDoor_x0[]  = {0x08,0x30,0x4C,0x5A};
unsigned char /*D_2D90*/LDoor_x1[]  = {0x18,0x40,0x54,0x5C};
unsigned char /*D_2D94*/RDoor_x0[]  = {0xB7,0x8F,0x72,0x64};
unsigned char /*D_2D98*/RDoor_x1[]  = {0xA7,0x7F,0x6A,0x62};
unsigned char /*D_2D9C*/Door_y0[]  = {0x34,0x48,0x56,0x5A};
unsigned char /*D_2DA0*/Door_y0p[] = {0x3D,0x51,0x5B,0x5F};
unsigned char /*D_2DA4*/Door_y1[]  = {0xB7,0x8F,0x73,0x65};
unsigned char /*D_2DA8*/Door_y1p[] = {0xA7,0x7F,0x6B,0x62};

unsigned char D_2DAC[] = {0x08,0x30,0x4C,0x5A};
unsigned char D_2DB0[] = {0x18,0x40,0x54,0x5D};
unsigned char D_2DB4[] = {0xB7,0x8F,0x73,0x65};
unsigned char D_2DB8[] = {0xA7,0x7F,0x6B,0x62};
unsigned char D_2DBC[] = {0x35,0x48,0x55,0x5C};
unsigned char D_2DC0[] = {0x3C,0x50,0x5A,0x5D};
unsigned char D_2DC4[] = {0x8B,0x78,0x6A,0x62};
unsigned char D_2DC8[] = {0x83,0x70,0x65,0x61};
unsigned char /*D_2DCC*/Ladder_x0[] = {0x48,0x54,0x5C,0x5F};
unsigned char /*D_2DD0*/Ladder_x1[] = {0x77,0x6B,0x63,0x60};
unsigned char D_2DD4[] = {0x10,0x38,0x50,0x5D};/*up ladder rung 1 y*/
unsigned char D_2DD8[] = {0x30,0x48,0x56,0x5E};/*up ladder rung 2 y*/
unsigned char D_2DDC[] = {0x50,0x58,0x5C,0x5F};/*up ladder rung 3 y*/
unsigned char D_2DE0[] = {0xAF,0x87,0x6F,0x62};/*down ladder rung 1 y*/
unsigned char D_2DE4[] = {0x8F,0x77,0x69,0x61};/*down ladder rung 2 y*/
unsigned char D_2DE8[] = {0x6F,0x67,0x63,0x60};/*down ladder rung 3 y*/

int D_2DEC = 0;
int D_2DEE = 0;

/*TODO*/
/*D_8CE8*/static unsigned char STA_A/*tile_forward_1*/;
/*D_8CE9*/static unsigned char STA_B/*tile_forward_2*/;
/*D_8CEA*/static int STA_C;/*<backup (Party.f_1dc == 0)>*/
/*D_8CEC*/static int STA_D;/*<backup Party._z>*/
/*D_8CEE*/static int STA_E;/*current rendering depth*/
/*D_8CF0*/static unsigned char STA_F;/*<backup Party._x>*/
/*D_8CF2*/static unsigned STA_G;/*<backup Party._dir>*/
/*D_8CF4*/static unsigned char STA_H;/*<backup Party._y>*/
/*D_8CF5*/static unsigned char STA_I;/*<backup tile_cur>*/
/*D_8CF6*/static unsigned char STA_J;/*<backup tile_forward>*/
/*D_8CF7*/static unsigned char STA_K;/*<backup tile_forward_1>*/
/*D_8CF8*/static unsigned char STA_L;/*<backup tile_forward_2>*/

/*render force fields?*/
C_A7F2(bp04)
unsigned char bp04;
{
	Gra_02(
		(Wall_y1[STA_E] - Wall_y0[STA_E] + 1) / 16,
		(Wall_x1[STA_E] - Wall_x0[STA_E] + 1) / 16,
		(bp04 & 3) | 0x44,
		Wall_y0[STA_E],
		Wall_x0[STA_E] >> 2
	);
}

/*drawLine*/
C_A842(bp0a, bp08, bp06, bp04)
int bp0a;
int bp08;
int bp06;
int bp04;
{
	int loc_A, loc_B, loc_C, loc_D, loc_E;

	loc_E = bp0a;
	loc_A = bp08;
	loc_B = u4_sign(bp06 - bp0a);
	loc_C = u4_sign(bp04 - bp08);

	if(u4_abs(bp0a - bp06) < u4_abs(bp08 - bp04)) {
		loc_D = u4_abs(bp04 - bp08) / 2;
		do {
			Gra_dot_OR(loc_A, loc_E, 3);
			loc_A += loc_C;
			loc_D -= u4_abs(bp06 - bp0a);
			if(loc_D <= 0) {
				loc_E += loc_B;
				loc_D += u4_abs(bp04 - bp08);
			}
		} while(loc_A != bp04);
	} else {
		loc_D = u4_abs(bp06 - bp0a) / 2;
		do {
			Gra_dot_OR(loc_A, loc_E, 3);
			loc_E += loc_B;
			loc_D -= u4_abs(bp04 - bp08);
			if(loc_D <= 0) {
				loc_A += loc_C;
				loc_D += u4_abs(bp06 - bp0a);
			}
		} while(loc_E != bp06);
	}
	Gra_dot_OR(loc_A, loc_E, 3);
}

/*up pit*/
C_A94A()
{
	register int si;

	si = STA_E;
	Gra_line(D_2DBC[si],   D_2DAC[si], D_2DC0[si],   D_2DB0[si], 3);
	Gra_line(D_2DBC[si]+1, D_2DAC[si], D_2DC0[si]+1, D_2DB0[si], 3);
	Gra_line(D_2DC0[si]+1, D_2DB0[si], D_2DC8[si],   D_2DB0[si], 3);
	Gra_line(D_2DC8[si],   D_2DB0[si], D_2DC4[si],   D_2DAC[si], 3);
	Gra_line(D_2DC8[si]-1, D_2DB0[si], D_2DC4[si]-1, D_2DAC[si], 3);
	Gra_line(D_2DC4[si]-1, D_2DAC[si], D_2DBC[si]+1, D_2DAC[si], 3);
}

/*low pit*/
C_AA29()
{
	register int si;

	si = STA_E;
	Gra_line(D_2DBC[si],   D_2DB4[si], D_2DC0[si],   D_2DB8[si], 3);
	Gra_line(D_2DBC[si]+1, D_2DB4[si], D_2DC0[si]+1, D_2DB8[si], 3);
	Gra_line(D_2DC0[si]+1, D_2DB8[si], D_2DC8[si],   D_2DB8[si], 3);
	Gra_line(D_2DC8[si],   D_2DB8[si], D_2DC4[si],   D_2DB4[si], 3);
	Gra_line(D_2DC8[si]-1, D_2DB8[si], D_2DC4[si]-1, D_2DB4[si], 3);
	Gra_line(D_2DC4[si]-1, D_2DB4[si], D_2DBC[si]+1, D_2DB4[si], 3);
}

C_AB08(bp04)
unsigned char bp04;
{
	if(D_2DEC-- == 0)
		D_2DEC = speed_info - 1;
	switch(bp04 & 0xf0) {
		default: return ((bp04 & 0xf0) < 0xc0)?0:-1;
		case 0x40: return TIL_3C;
		case 0x70: return TIL_4E;
		case 0x80:
			if(D_2DEC == 1 && U4_RND1(0x3f) == 0 && (bp04 & 0xf)) {
				if((bp04 & 0x0f) >= 8)
					C_AA29();
				else
					C_A94A();
			}
		return 0;
		case 0x90: return TIL_02;
		case 0xa0:
			C_A7F2((bp04 & 3) | TIL_44);
			switch(STA_E) {
				case 0: cursor_rate = 0; break;
				case 1: cursor_rate = 1; break;
				case 2: cursor_rate = 6; break;
				case 3: cursor_rate = 10; break;
			}
		return TIL_48;
		case 0xb0: return TIL_4A;
	}
	return -1;
}

/*isSpriteRenderable?*/
C_ABE5(bp04)
unsigned char bp04;
{
	register int si;

	si = bp04 & 0xf0;
	if(
		si == 0x80 ||
		si == 0x90 ||
		si == 0xa0 ||
		si >= 0xd0
	) return 0;
	if(!(bp04 & 0x0f))
		return 0;
	return 1;
}

/*render sprites?*/
C_AC23(bp04)
unsigned char bp04;
{
	register int loc_B;
	long loc_A;

	cursor_rate = 0;
	switch(STA_E) {
		case 0:
			for(loc_B = 0; loc_B < 48; loc_B++)
				Gra_01(bp04, loc_B / 3, loc_B + 0x70, 0x14, 2);
			loc_A = 1000 * speed_info;
			while(--loc_A);
		break;
		case 1:
			for(loc_B = 0; loc_B < 32; loc_B++)
				Gra_01(bp04, loc_B >> 1, loc_B + 0x68, 0x14, 2);
			loc_A = 1200 * speed_info;
			while(--loc_A);
		break;
		case 2:
			Gra_02(1, 1, bp04, 0x60, 0x16);
			loc_A = 2400 * speed_info;
			while(--loc_A);
		break;
		case 3:
			for(loc_B = 0; loc_B < 8; loc_B ++)
				Gra_01(bp04, loc_B << 1, loc_B + 0x60, 0x16, 1);
			loc_A = 3000 * speed_info;
			while(--loc_A);
		break;
	}
}

C_AD6A(bp06, bp04)
unsigned char bp06;
int bp04;
{
	static int D_8CFA;
	int bp_02;

	STA_E = bp04;
	if(D_2DEE-- == 0) {
		D_2DEE = speed_info - 1;
		D_8CFA = U4_RND1(3);
	}
	if(C_ABE5(bp06)) {
		C_AC23(TIL_90 + ((bp06 & 0xf) << 2) - 4 + D_8CFA);
		return 0;
	}
	if((bp_02 = C_AB08(bp06)) > 0) {
		if(bp_02 != TIL_48)
			C_AC23(bp_02);
		return 0;
	}
	if(bp_02 != 0) {
		if(STA_E != 0 || bp06 >= 0xd0)
			return 0;
	}
	return 1;
}

/*animate 3D sprites?*/
C_ADEF()
{
	if(Party.f_1dc == 0) {
		Gra_10();
		return;
	}
	if(!C_AD6A(tile_cur, 0))
		return;
	if(!C_AD6A(tile_forward, 1))
		return;
	if(!C_AD6A(STA_A, 2))
		return;
	C_AD6A(STA_B, 3);
}

/*compute nearest tiles*/
C_AE41()
{
	unsigned char bp_04, bp_02;

	/*back*/
	bp_04 = DNG_X_m(Party._x, Party._dir);
	bp_02 = DNG_Y_m(Party._y, Party._dir);
	tile_back = D_8742._map.x8x8x8[Party._z][bp_02][bp_04];
	/*current tile*/
	tile_cur = D_8742._map.x8x8x8[Party._z][Party._y][Party._x];
	/*forward*/
	bp_04 = DNG_X_p(Party._x, Party._dir);
	bp_02 = DNG_Y_p(Party._y, Party._dir);
	tile_forward = D_8742._map.x8x8x8[Party._z][bp_02][bp_04];
	/*another 2 steps forward*/
	bp_04 = DNG_X_p(bp_04, Party._dir);
	bp_02 = DNG_Y_p(bp_02, Party._dir);
	STA_A = D_8742._map.x8x8x8[Party._z][bp_02][bp_04];

	bp_04 = DNG_X_p(bp_04, Party._dir);
	bp_02 = DNG_Y_p(bp_02, Party._dir);
	STA_B = D_8742._map.x8x8x8[Party._z][bp_02][bp_04];
}

/*compute the actual x,y of the expected square on the map
 according to current {x, y, orientation}
 STA_E: current depth of rendering
 bp04: current column of rendering:
 .-1 left
 . 0 straight
 .+1 right*/
C_AF36(getX, getY, bp04)
register int *getX;
register int *getY;
int bp04;
{
	*getX = Party._x;
	*getY = Party._y;
	switch(Party._dir) {
		case DIR_N:
			*getY -= STA_E; *getY &= 7;
			*getX += bp04;   *getX &= 7;
		break;
		case DIR_S:
			*getY += STA_E; *getY &= 7;
			*getX -= bp04;   *getX &= 7;
		break;
		case DIR_E:
			*getX += STA_E; *getX &= 7;
			*getY += bp04;   *getY &= 7;
		break;
		case DIR_W:
			*getX -= STA_E; *getX &= 7;
			*getY -= bp04;   *getY &= 7;
		break;
	}
}

#define VERTICAL(x, y0, y1, c) Gra_line((unsigned char)(x), (y0), (unsigned char)(x), (y1), (c));
#define HORIZONTAL(x0, y, x1, c) Gra_line((unsigned char)(x0), (y), (unsigned char)(x1), (y), (c));

/*up ladder*/
C_AFB5()
{
	register int si;

	si = STA_E;
	C_A94A();
	if(Party._dir == DIR_N || Party._dir == DIR_S) {
		VERTICAL(0x5f,   D_2DAC[si], 0x5f, 3);
		VERTICAL(0x5f+1, D_2DAC[si], 0x5f, 3);
	} else {
		/*left stile*/
		VERTICAL(Ladder_x0[si],   D_2DAC[si], 0x5e, 3);
		VERTICAL(Ladder_x0[si]+1, D_2DAC[si], 0x5e, 3);
		/*right stile*/
		VERTICAL(Ladder_x1[si],   D_2DAC[si], 0x5e, 3);
		VERTICAL(Ladder_x1[si]-1, D_2DAC[si], 0x5e, 3);
		/*rungs*/
		HORIZONTAL(Ladder_x0[si], D_2DD4[si], Ladder_x1[si], 3);
		HORIZONTAL(Ladder_x0[si], D_2DD8[si], Ladder_x1[si], 3);
		HORIZONTAL(Ladder_x0[si], D_2DDC[si], Ladder_x1[si], 3);
	}
}

/*down ladder*/
C_B0E9()
{
	register int si;

	si = STA_E;
	C_AA29();
	if(Party._dir == DIR_N || Party._dir == DIR_S) {
		VERTICAL(0x5f,   D_2DB4[si], 0x5f, 3);
		VERTICAL(0x5f+1, D_2DB4[si], 0x5f, 3);
	} else {
		/*left stile*/
		VERTICAL(Ladder_x0[si],   0x5f, D_2DB4[si], 3);
		VERTICAL(Ladder_x0[si]+1, 0x5f, D_2DB4[si], 3);
		/*right stile*/
		VERTICAL(Ladder_x1[si],   0x5f, D_2DB4[si], 3);
		VERTICAL(Ladder_x1[si]-1, 0x5f, D_2DB4[si], 3);
		/*rungs*/
		HORIZONTAL(Ladder_x0[si], D_2DE0[si], Ladder_x1[si], 3);
		HORIZONTAL(Ladder_x0[si], D_2DE4[si], Ladder_x1[si], 3);
		HORIZONTAL(Ladder_x0[si], D_2DE8[si], Ladder_x1[si], 3);
	}
}

#undef VERTICAL
#undef HORIZONTAL

/*Gra_18(
	x0, x1,
	y0, y1,
	y0p, y1p,
	col0, col1
);*/

/*front wall?*/
C_B21D()
{
	Gra_18(
		Wall_x0[STA_E], Wall_x1[STA_E] + 1,
		Wall_y0[STA_E], Wall_y1[STA_E],
		Wall_y0[STA_E], Wall_y1[STA_E],
		(Party._dir & 1) + 1, 0
	);
}

/*left front wall?*/
C_B25E()
{
	Gra_18(
		Wall_x0[STA_E],   Wall_x0[STA_E+1],
		Wall_y0[STA_E+1], Wall_y1[STA_E+1],
		Wall_y0[STA_E+1], Wall_y1[STA_E+1],
		(Party._dir & 1) + 1, 0
	);
}

/*right front wall?*/
C_B29C()
{
	Gra_18(
		Wall_x1[STA_E],   Wall_x1[STA_E+1],
		Wall_y0[STA_E+1], Wall_y1[STA_E+1],
		Wall_y0[STA_E+1], Wall_y1[STA_E+1],
		(Party._dir & 1) + 1, 0
	);
}

/*left lateral wall?*/
C_B2DA()
{
	Gra_18(
		Wall_x0[STA_E],   Wall_x0[STA_E+1],
		Wall_y0[STA_E],   Wall_y1[STA_E],
		Wall_y0[STA_E+1], Wall_y1[STA_E+1],
		!(Party._dir & 1) + 1, 0
	);
}

/*right lateral wall?*/
C_B31B()
{
	Gra_18(
		Wall_x1[STA_E],   Wall_x1[STA_E+1],
		Wall_y0[STA_E],   Wall_y1[STA_E],
		Wall_y0[STA_E+1], Wall_y1[STA_E+1],
		!(Party._dir & 1) + 1, 0
	);
}

/*front door?*/
C_B35C()
{
	Gra_18(
		Wall_x0[STA_E+1], Wall_x1[STA_E+1],
		Wall_y0[STA_E+1], Wall_y1[STA_E],
		Wall_y0[STA_E+1], Wall_y1[STA_E],
		!STA_E?0:3, !STA_E?3:0
	);
}

/*left door?*/
C_B3AE()
{
	Gra_18(
		LDoor_x0[STA_E], LDoor_x1[STA_E],
		Door_y0[STA_E],  Door_y1[STA_E],
		Door_y0p[STA_E], Door_y1p[STA_E],
		3, 0
	);
}

/*right door?*/
C_B3E3()
{
	Gra_18(
		RDoor_x0[STA_E], RDoor_x1[STA_E],
		Door_y0[STA_E],  Door_y1[STA_E],
		Door_y0p[STA_E], Door_y1p[STA_E],
		3, 0
	);
}

/*right walls*/
C_B418()
{
	int bp_02, bp_04;

	C_AF36(&bp_04, &bp_02, 1);
	switch(D_8742._map.x8x8x8[Party._z][bp_02][bp_04] >> 4) {
		case 0x0:
		case 0x1:
		case 0x2:
		case 0x3:
		case 0x4:
		case 0x5:
		case 0x6:
		case 0x7:
		case 0x8:
		case 0x9:
		case 0xa:
		case 0xb: C_B29C(); break;
		case 0xc:
		case 0xd: C_B31B(); C_B3E3(); break;
		case 0xe:
		case 0xf: C_B31B(); break;
	}
}

/*left & right walls*/
C_B47A()
{
	int bp_02, bp_04;

	C_AF36(&bp_04, &bp_02, -1);
	switch(D_8742._map.x8x8x8[Party._z][bp_02][bp_04] >> 4) {
		case 0x0:
		case 0x1:
		case 0x2:
		case 0x3:
		case 0x4:
		case 0x5:
		case 0x6:
		case 0x7:
		case 0x8:
		case 0x9:
		case 0xa:
		case 0xb: C_B25E(); break;
		case 0xc:
		case 0xd: C_B2DA(); C_B3AE(); break;
		case 0xe:
		case 0xf: C_B2DA(); break;
	}
	C_B418();
}

/*render 3d*/
C_B4DF()
{
	int bp_04, bp_02;

	bp_04 = Party._x;
	bp_02 = Party._y;
	for(STA_E = 0; STA_E <= 3; STA_E ++) {
		C_AF36(&bp_04, &bp_02, 0);
		switch(D_8742._map.x8x8x8[Party._z][bp_02][bp_04] & 0xf0) {
			case 0x30: C_B0E9();
			case 0x10: C_AFB5();
			case 0x00:
			case 0x40:
			case 0x70:
			case 0x80:
			case 0x90:
			case 0xb0: C_B47A(); break;
			case 0x20: C_B0E9(); C_B47A(); break;
			case 0x50: C_A94A(); C_B47A(); break;
			case 0x60: C_AA29(); C_B47A(); break;
			case 0xc0: C_B21D(); C_B35C(); if(STA_E) return; break;
			case 0xd0: C_B21D(); C_B35C(); return;
			case 0xa0: C_A7F2(D_8742._map.x8x8x8[Party._z][bp_02][bp_04]); return;
			case 0xe0:
			case 0xf0: C_B21D(); return;
		}
	}
	STA_E = 4;
	C_AF36(&bp_04, &bp_02, 0);
	if(
		(D_8742._map.x8x8x8[Party._z][bp_02][bp_04] & 0xf0) == 0xf0 ||
		(D_8742._map.x8x8x8[Party._z][bp_02][bp_04] & 0xf0) == 0xe0
	) C_B21D();
}

/*backup dungeon infos & render 3D*/
C_B61C()
{
	STA_D = Party._z;
	STA_F = Party._x;
	STA_H = Party._y;
	STA_G = Party._dir;
	STA_C = (Party.f_1dc == 0);
	STA_I = tile_cur;
	STA_J = tile_forward;
	STA_K = STA_A;
	STA_L = STA_B;
	D_9446 = 0;
	Gra_10();
	if(Party.f_1dc)
		C_B4DF();
}

/*render 3d if necessary*/
C_B677()
{
	unsigned char bp_02;

	cursor_rate = (Party.f_1dc != 0)?13:1;
	C_AE41();
	if(
		D_9446 == 0 &&
		STA_D == Party._z &&
		STA_F == Party._x &&
		STA_H == Party._y &&
		STA_G == Party._dir &&
		STA_I == tile_cur &&
		STA_C == (Party.f_1dc == 0)
	) {
		bp_02 = tile_cur & 0xf0;
		if(bp_02 == 0xa0 || bp_02 >= 0xd0)
			return;
		if(tile_forward != STA_J)
			goto C_B729;
		if((bp_02 = tile_forward & 0xf0) == 0xa0 || bp_02 >= 0xc0)
			return;
		if(STA_A != STA_K)
			goto C_B729;
		if((bp_02 = STA_A & 0xf0) == 0xa0 || bp_02 >= 0xc0)
			return;
		if(STA_L == STA_L/*bug?*/)
			return;
	}
C_B729:
	C_B61C();
}
