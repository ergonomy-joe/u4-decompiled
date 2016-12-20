/*
 * Ultima IV - Quest Of The Avatar
 * (c) Copyright 1987 Lord British
 * reverse-coded by Ergonomy Joe in 2012
 */

#include "u4.h"

unsigned D_1630 = 0;

/*animate force fields, water, ...*/
C_34EA()
{
	if(D_1630 -- == 0) {
		D_1630 = speed_info - 1;
		Gra_animFlow(TIL_00);
		Gra_animFlow(TIL_01);
		Gra_animFlow(TIL_02);
		Gra_animFlow(TIL_4C);
		Gra_animFlow(TIL_44);
		Gra_animFlow(TIL_46);
		Gra_animFlow(TIL_47);
		Gra_animFlow(TIL_45);
	}
	Gra_animSpit();
}

/*display direction*/
C_353D(bp06, bp04)
unsigned bp06;
char *bp04;
{
	unsigned bp_02, bp_04;

	bp_02 = txt_X;
	bp_04 = txt_Y;
	txt_Y = 23;
	txt_X = 7;
	u4_puts(bp04);
	switch(bp06) {
		case DIR_N: u4_puts(" North"); break;
		case DIR_S: u4_puts(" South"); break;
		case DIR_E: u4_puts("  East"); break;
		case DIR_W: u4_puts("  West"); break;
	}
	if(CurMode == MOD_DUNGEON) {
		txt_Y = 0;
		txt_X = 11;
		u4_putc('L');
		u4_putc(Party._z + '1');
	}
	txt_X = bp_02;
	txt_Y = bp_04;
}

unsigned D_1654 = 0;

/*update/display wind*/
C_35C7()
{
	if(D_1654-- == 0) {
		D_1654 = speed_info - 1;
		if(!U4_RND1(0xfc))
			WindDir = (U4_RND1(2) + WindDir - 1) & 3;
	}
	C_353D(WindDir, "Wind");
}

unsigned D_1656[] = {192, 96, 60, 36, 20, 12, 8};

/*animate sprites*/
C_3605()
{
	register int si, di;

	for(si = 0; si < 32; si++) {
		di = D_8742._npc._tile[si];
		if(
			(di >= TIL_84 && di <= TIL_8E) ||
			(di >= TIL_20 && di <= TIL_2E) ||
			(di >= TIL_50 && di <= TIL_5E)
		) {
			if(U4_RND2(1) != 0)
			if(((speed_info < 8)?D_1656[speed_info - 1]:0xff) > U4_RND2(0xff))
			D_8742._npc._gtile[si] = ((D_8742._npc._gtile[si] & 1) | di) ^ 1;
		} else if(di >= TIL_90) {
			if(((speed_info < 8)?D_1656[speed_info - 1]:0xff) > U4_RND2(0xff))
			D_8742._npc._gtile[si] = ((D_8742._npc._gtile[si] + 1) & 3) | di;
		} else if(di != TIL_80) {
			D_8742._npc._gtile[si] = di;
		}
	}
	C_34EA();
	Gra_animFlag();
}

C_36C7()
{
	register unsigned si;

	si = D_96F9[hit_y*11 + hit_x];
	if(hit_tile)
		D_96F9[hit_y*11 + hit_x] = hit_tile;
	Gra_05(11, 11, D_96F9, 4  * 80 + 2);
	if(activeCharaX != -1) {
		register int di;

		di = D_95C8;
		D_95C8 -= u4_sign(D_95C8);
		if(D_95C8 == 0) {
			if(di < 0)
				D_95C8 = 4;
			else
				D_95C8 = -9;
		}
		if(D_95C8 > 0)
			Gra_00(activeCharaY, activeCharaX);
	}
	D_96F9[hit_y*11 + hit_x] = si;
}

/*cast one ray*/
C_376F(bp0a, bp08, bp06, bp04)
int bp0a;/*diff_x*/
int bp08;/*diff_y*/
unsigned char bp06;/*pos_x*/
unsigned char bp04;/*pos_y*/
{
	register unsigned si;/*tmp_x*/
	unsigned bp_04;/*tmp_y*/

	si = &(D_96F9[bp04*11 + bp06]) - D_96F9;
	if(bp06 > 10 || bp04 > 10)
		return;
	if(D_96F9[si] != TIL_7E)
		return;
	bp_04 = Combat._map[si];
	D_96F9[si] = bp_04;
	/*opaque tiles*/
	if(
		bp_04 == TIL_06 ||
		bp_04 == TIL_08 ||
		bp_04 == TIL_7E ||
		bp_04 == TIL_49 ||
		bp_04 == TIL_7F
	) return;

	bp06 += bp0a;
	bp04 += bp08;
	C_376F(bp0a, bp08, bp06, bp04);
	if(bp0a & bp08) {
		C_376F(bp0a, bp08, bp06,        bp04 - bp08);
		C_376F(bp0a, bp08, bp06 - bp0a, bp04);
	} else {
		C_376F((!bp0a) * bp08 + bp0a, bp08 - (!bp08) * bp0a, bp08 + bp06, bp04 - bp0a);
		C_376F(bp0a - (!bp0a) * bp08, (!bp08) * bp0a + bp08, bp06 - bp08, bp0a + bp04);
	}
}

/*process visible area (raycast)*/
C_38BB()
{
	register int si;

	/*-- set all visible squares to TIL_7E --*/
	for(si = 10 * 11 + 10; si >= 0; si --)
		D_96F9[si] = TIL_7E;
	/*-- --*/
	D_96F9[5*11 + 5] = Combat_MAP(5, 5);/*display character's icon*/
/*                 -1   0  +1
    0   1   2   3   4   5   6   7   8   9   a
  +---+---+---+---+---+---+---+---+---+---+---+
0 | . |   |   |   |   | . |   |   |   |   | . |
  +---+---+---+---+---+---+---+---+---+---+---+
1 |   | . |   |   |   | . |   |   |   | . |   |
  +---+---+---+---+---+---+---+---+---+---+---+
2 |   |   | . |   |   | . |   |   | . |   |   |
  +---+---+---+---+---+---+---+---+---+---+---+
3 |   |   |   | . |   | . |   | . |   |   |   |
  +---+---+---+---+---+---+---+---+---+---+---+
4 |   |   |   |   |4 4|5 4|6 4|   |   |   |   | -1
  +---+---+---+---+---+---+---+---+---+---+---+
5 | . | . | . | . |4 5|   |6 5| . | . | . | . |  0
  +---+---+---+---+---+---+---+---+---+---+---+
6 |   |   |   |   |4 5|5 6|6 6|   |   |   |   | +1
  +---+---+---+---+---+---+---+---+---+---+---+
7 |   |   |   | . |   | . |   | . |   |   |   |
  +---+---+---+---+---+---+---+---+---+---+---+
8 |   |   | . |   |   | . |   |   | . |   |   |
  +---+---+---+---+---+---+---+---+---+---+---+
9 |   | . |   |   |   | . |   |   |   | . |   |
  +---+---+---+---+---+---+---+---+---+---+---+
a | . |   |   |   |   | . |   |   |   |   | . |
  +---+---+---+---+---+---+---+---+---+---+---+*/
	C_376F( 0, -1, 5, 4);/*UP*/
	C_376F( 0,  1, 5, 6);/*DOWN*/
	C_376F(-1,  0, 4, 5);/*LEFT*/
	C_376F( 1,  0, 6, 5);/*RIGHT*/
	C_376F( 1,  1, 6, 6);/*DOWN RIGHT*/
	C_376F( 1, -1, 6, 4);/*UP RIGHT*/
	C_376F(-1,  1, 4, 6);/*DOWN LEFT*/
	C_376F(-1, -1, 4, 4);/*UP LEFT*/
}

C_3960()
{
	register int loc_B;
	unsigned char loc_A, loc_C;

	for(loc_B = 31; loc_B >= 0; loc_B --) {

		loc_A = D_8742._npc._x[loc_B] - Party._x + 5;
		loc_C = D_8742._npc._y[loc_B] - Party._y + 5;
		if(D_8742._npc._gtile[loc_B] && loc_A < 11 && loc_C < 11)
			Combat_MAP(loc_C, loc_A) = D_8742._npc._gtile[loc_B];
	}
}

C_39BA()
{
	register int loc_A;

	C_3960();
	if(D_9141) {
		unsigned char loc_B, loc_C;

		loc_B = D_9445 - Party._x + 5;
		loc_C = D_9448 - Party._y + 5;
		if(loc_B < 11 && loc_C < 11)
			Combat_MAP(loc_C, loc_B) = D_9141;
	}
	tile_cur   = Combat_MAP(5, 5);
	tile_north = Combat_MAP(4, 5);
	tile_south = Combat_MAP(6, 5);
	tile_east  = Combat_MAP(5, 6);
	tile_west  = Combat_MAP(5, 4);
	Combat_MAP(5, 5) = Party._tile;
	if(D_9440)
		C_38BB();
	else {
		for(loc_A = 10 * 11 + 10; loc_A >= 0; loc_A --)
			D_96F9[loc_A] = Combat._map[loc_A];
	}
	C_36C7();
}

unsigned char D_1664 = 0;
unsigned char D_1665 = 0;/*trammel counter*/
unsigned char D_1666 = 0;/*felucca counter*/

C_3A4F()
{
	D_9445 = D_0814[(D_1665 & 0xe0) >> 5];
	D_9448 = D_081C[(D_1665 & 0xe0) >> 5];
	return ((D_1664 & 0xc0) >> 6);
}

unsigned D_1668 = 0;

/*display tramel and feluca ?*/
C_3A80()
{
	unsigned char bp_02, bp_04;

	if(D_1668-- == 0) {
		D_1668 = speed_info / 2;
		D_1664 += 0x40;
		if(D_1664 == 0) {
			D_1665 += 2;
			D_1666 += 6;
		}
		Party._trammel = D_1665 >> 5;
		Party._felucca = D_1666 >> 5;
		if((D_1665 & 0x1f) == 0) {
			D_9141 = C_3A4F() + 0x40;
		} else if((D_1665 & 0x1f) == 0x1e){
			D_9141 = (C_3A4F() ^ 3) + 0x40;
		}
	}
	bp_02 = txt_X;
	bp_04 = txt_Y;
	txt_Y = 0;
	txt_X = 11;
	Gra_putchar((((D_1665 >> 5) - 1) & 7) + 0x14);
	txt_X ++;
	Gra_putchar((((D_1666 >> 5) - 1) & 7) + 0x14);
	txt_X = bp_02;
	txt_Y = bp_04;
}

C_3B35()
{
	register unsigned loc_B;
	int loc_C, loc_A;

	C_3605();/*animate sprites*/
	C_3A80();/*display tramel and feluca*/
	loc_B = 10 * 11 + 10;
	for(loc_C = 10; loc_C >= 0; loc_C --) {
		for(loc_A = 10; loc_A >= 0; loc_A --) {
			Combat._map[loc_B] = D_8742._map.x32x32[loc_C+D_959C.y-5][loc_A+D_959C.x-5];
			loc_B --;
		}
	}
	C_39BA();/*display 11x11 icons zone*/
}

/*display inside towne/castle ...*/
C_3B83()
{
	register int si, di;

	C_3605();
	for(di = -5; di <= 5; di ++) {
		for(si = -5; si <= 5; si ++) {
			if(
				((int)Party._x + si < 0) || ((int)Party._x + si > 0x1f) ||
				((int)Party._y + di < 0) || ((int)Party._y + di > 0x1f)
			) {
				Combat_MAP(di+5, si+5) = TIL_04;
			} else {
				Combat_MAP(di+5, si+5) = D_8742._map.x32x32[Party._y + di][Party._x + si];
			}
		}
	}
	C_39BA();/*display 11x11 icons zone*/
	C_35C7();/*update/display wind*/
}

unsigned D_166A = 0;

/*move balloon*/
C_3C08()
{
	if(D_166A -- == 0) {
		D_166A = speed_info;
		Party._moves ++;
		switch(WindDir) {
			case DIR_N: C_2891(); break;
			case DIR_S: C_2839(); break;
			case DIR_E: C_28E9(); break;
			case DIR_W: C_2941(); break;
		}
	}
}

unsigned D_166C[] = {1,3,3,7,7,7,7,15};

C_3C54()
{
	register int loc_A;
	unsigned loc_B;
	unsigned char *loc_C;
	unsigned char *loc_D;
	unsigned char *loc_E;

	loc_B = (speed_info < 8)?D_166C[speed_info - 1]:15;
	C_34EA();
	for(loc_A = 10 * 11 + 10; loc_A >= 0; loc_A--)
		D_96F9[loc_A] = Combat._map[loc_A];
	if(CurMode != MOD_SHRINE) {
		for(loc_A = 15; loc_A >= 0; loc_A--) {
			loc_E = &(Fighters._tile[loc_A]);
			if(*loc_E == 0)
				continue;
			loc_D = &(D_96F9[Combat._npcY[loc_A]*11 + Combat._npcX[loc_A]]);
			loc_C = &(Fighters._gtile[loc_A]);
			if(Fighters._sleeping[loc_A])
				*loc_D = *loc_C;
			else if(*loc_E >= TIL_90) {
				if(*loc_E == TIL_AC && *loc_C == TIL_3C || U4_RND1(loc_B) == 0) {
					*loc_D = *loc_C;
				} else if(U4_RND1(loc_B) == 0) {
					*loc_C = ((*loc_C + 1) & 3) | *loc_E;
					*loc_D = *loc_C;
				} else {
					*loc_D = *loc_C;
				}
			} else if(*loc_E == TIL_38) {
				*loc_D = *loc_C = TIL_38;
			} else {
/*C_3D35*/
#if 0
				*loc_D = *loc_C ^= (u_rand_b() & u_rand_a() & 1)/*TODO*/;
#else
				*loc_D = *loc_C ^= U4_RND1(U4_RND2(1));
#endif
			}
		}
		for(loc_A = Party.f_1d8 - 1; loc_A >= 0; loc_A --) {
			unsigned char *bp_0c;
			unsigned char *bp_0e;
			unsigned char bp_10;

			bp_0e = &(Fighters._chtile[loc_A]);
			bp_10 = *bp_0e;
			if(bp_10 == 0)
				continue;
			bp_0c = &(D_96F9[Combat._charaY[loc_A]*11 + Combat._charaX[loc_A]]);
			if(bp_10 == TIL_38) {
				*bp_0c = D_944A[loc_A] = bp_10;
				continue;
			}
			*bp_0c = (D_944A[loc_A] ^= !U4_RND1(loc_B));
		}
	}
	C_36C7();
}

/*display game zone*/
/*C_3DC8*/t_callback()
{
	if(CurMode == MOD_VISION) {
		cursor_rate = 233;
		return;
	}
	cursor_rate = 0;
	if(CurMode == MOD_OUTDOORS) {
		if(Party._tile == TIL_18 && Party.f_1dc)
			C_3C08();
		C_35C7();/*update/display wind*/
		C_3B35();
	} else if(CurMode == MOD_BUILDING) {
		C_3B83();
	} else if(CurMode == MOD_DUNGEON) {
		C_353D(Party._dir, "DIR:");
		C_34EA();
		C_B677();
		C_ADEF();
	} else {/*Combat*/
		C_3C54();
	}
}
