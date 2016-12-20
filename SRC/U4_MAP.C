/*
 * Ultima IV - Quest Of The Avatar
 * (c) Copyright 1987 Lord British
 * reverse-coded by Ergonomy Joe in 2012
 */

#include "u4.h"

#include <stdlib.h>

int D_08CE = -1;
int D_08D0 = -1;

/*load the portion of the map with coordinates in parameter*/
C_2399(bp06, bp04)
unsigned bp06;
unsigned bp04;
{
	int bp_02;

	if(D_08CE != -1) {
		dfree((void far *)D_933A[D_08D0][D_08CE]);
		D_933A[D_08D0][D_08CE] = 0;
	}
	if(D_933A[bp06][bp04] == 0) {
		if(dlseek(File_MAP, (bp06 * 8 + bp04) * sizeof(tMap32x32)) == -1)
			exit(1);
		D_933A[bp06][bp04] = (tMap32x32 far *)dalloc(sizeof(tMap32x32));
		if(D_933A[bp06][bp04] == 0)
			exit(1);
		bp_02 = dread(File_MAP, D_933A[bp06][bp04], sizeof(tMap32x32));
		if(bp_02 != sizeof(tMap32x32))
			exit(3);
	}
	D_08CE = bp04;
	D_08D0 = bp06;
}

C_249C()
{
	register int si, di;

	C_2399(D_95A5.y / 2, D_95A5.x / 2);
	for(di = 0; di < 16; di ++)
		for(si = 0; si < 16; si ++)
			D_8742._map.x32x32[di][si] = 
				(*(D_933A[D_95A5.y/2][D_95A5.x/2]))[(D_95A5.y&1)*0x10+di][(D_95A5.x&1)*0x10+si];
}

#define TMP0 (((D_95A5.x+1)&15))
#define TMP1 (((D_95A5.y+1)&15))

C_2517()
{
	register int si, di;

	C_2399(D_95A5.y / 2, TMP0 / 2);
	for(di = 0; di < 16; di ++)
		for(si = 0; si < 16; si ++)
			D_8742._map.x32x32[di][si+16] = 
				(*(D_933A[D_95A5.y/2][TMP0/2]))[(D_95A5.y&1)*0x10+di][(TMP0&1)*0x10+si];
}

C_259F()
{
	register int si, di;

	C_2399(TMP1 / 2, D_95A5.x / 2);
	for(di = 0; di < 16; di ++)
		for(si = 0; si < 16; si ++)
			D_8742._map.x32x32[di+16][si] = 
				(*(D_933A[TMP1/2][D_95A5.x/2]))[(TMP1&1)*0x10+di][(D_95A5.x&1)*0x10+si];
}

C_2624()
{
	register int si, di;

	C_2399(TMP1 / 2, TMP0 / 2);
	for(di = 0; di < 16; di ++)
		for(si = 0; si < 16; si ++)
			D_8742._map.x32x32[di+16][si+16] = 
				(*(D_933A[TMP1/2][TMP0/2]))[(TMP1&1)*0x10+di][(TMP0&1)*0x10+si];
}

C_26B6()
{
	D_95A5.x = ((Party._loc < 0x11)?Party._x:Party.out_x) >> 4;
	D_959C.x = ((Party._loc < 0x11)?Party._x:Party.out_x) & 15;
	if(D_959C.x < 8) {
		D_959C.x += 0x10;
		D_95A5.x = (D_95A5.x - 1) & 15;
	}
	D_95A5.y = ((Party._loc < 0x11)?Party._y:Party.out_y) >> 4;
	D_959C.y = ((Party._loc < 0x11)?Party._y:Party.out_y) & 15;
	if(D_959C.y < 8) {
		D_959C.y += 0x10;
		D_95A5.y = (D_95A5.y - 1) & 15;
	}
	C_249C();
	C_2517();
	C_259F();
	C_2624();
}

/*Leaving...*/
C_2747()
{
	u4_puts("Leaving...\n");
	CurMode = MOD_VISION;
	if(Load("OUTMONST.SAV", sizeof(struct tNPC), &(D_8742._npc)) == -1)
		exit(3);
	if(File_TLK) {
		dclose(File_TLK);
		File_TLK = 0;
	}
	Party._x = Party.out_x;
	Party._y = Party.out_y;
	C_26B6();
	CurMode = MOD_OUTDOORS;
	Party._loc = 0;
	Party.f_1dc = 0;
	D_9440 = 1;
	if(Party._x == 0xef && Party._y == 0xf0) {
		D_8742._npc._tile[31] = D_8742._npc._gtile[31] = TIL_18;
		D_8742._npc._x[31] = 0xe9;
		D_8742._npc._y[31] = 0xf2;
	}
	u_kbflush();
}

/*spawn daemons(if horn not used)*/
C_27D9()
{
	if(spell_sta != 1) {
		/*horn not in use*/
		register int si;

		for(si = 7; si >= 0; si--) {
			D_8742._npc._tile[si] = D_8742._npc._gtile[si] = TIL_F0;
			D_8742._npc._x[si] = 0xe7;
			D_8742._npc._y[si] = Party._y + 1;
		}
	}
}

unsigned char D_08EC[] = {  0xE0,  0xE0,  0xE2,  0xE3,  0xE4,  0xE5,  0xE5,  0xE4};
unsigned char D_08F4[] = {  0xDC,  0xE4,  0xDC,  0xE4,  0xE3,  0xE1,  0xDF,  0xDE};
unsigned char D_08FC[] = {TIL_82,TIL_82,TIL_82,TIL_82,TIL_83,TIL_83,TIL_81,TIL_81};

/*spawn pirate ships*/
C_280A()
{
	register int si;

	for(si = 7; si >= 0; si --) {
		D_8742._npc._x[si] = D_08EC[si];
		D_8742._npc._y[si] = D_08F4[si];
		D_8742._npc._tile[si] = TIL_80;
		D_8742._npc._gtile[si] = D_08FC[si];
	}
}

/*GOING NORTH*/
C_2839()
{
	register int si, di;

	Party._y --;
	D_959C.y = (D_959C.y - 1) & 0xff;
	if(D_959C.y < 5) {
		D_959C.y += 16;
		D_95A5.y = (D_95A5.y - 1) & 15;
		for(di = 0; di < 16; di ++)
			for(si = 0; si < 32; si ++)
				D_8742._map.x32x32[di+16][si] = D_8742._map.x32x32[di][si];
		C_249C();
		C_2517();
	}
}

/*GOING SOUTH*/
C_2891()
{
	register int si, di;

	Party._y ++;
	D_959C.y = (D_959C.y + 1) & 0xff;
	if(D_959C.y >= 27) {
		D_959C.y -= 16;
		D_95A5.y = (D_95A5.y + 1) & 15;
		for(di = 0; di < 16; di ++)
			for(si = 0; si < 32; si ++)
				D_8742._map.x32x32[di][si] = D_8742._map.x32x32[di+16][si];
		C_259F();
		C_2624();
	}
}

/*GOING WEST*/
C_28E9()
{
	register int si, di;

	Party._x --;
	D_959C.x = (D_959C.x - 1) & 0xff;
	if(D_959C.x < 5) {
		D_959C.x += 16;
		D_95A5.x = (D_95A5.x - 1) & 15;
		for(di = 0; di < 32; di ++)
			for(si = 0; si < 16; si ++)
				D_8742._map.x32x32[di][si+16] = D_8742._map.x32x32[di][si];
		C_249C();
		C_259F();
	}
}

/*GOING EAST*/
C_2941()
{
	register int si, di;

	Party._x ++;
	D_959C.x = (D_959C.x + 1) & 0xff;
	if(D_959C.x >= 27) {
		D_959C.x -= 16;
		D_95A5.x = (D_95A5.x + 1) & 15;
		for(di = 0; di < 32; di ++)
			for(si = 0; si < 16; si ++)
				D_8742._map.x32x32[di][si] = D_8742._map.x32x32[di][si+16];
		C_2517();
		C_2624();
	}
}

unsigned char D_0904[] = {
	TIL_03,TIL_04,TIL_05,TIL_06,TIL_07,TIL_09,TIL_0A,TIL_0B,TIL_0C,
	TIL_10,TIL_11,TIL_12,TIL_13,TIL_14,TIL_15,TIL_16,TIL_17,TIL_18,
	TIL_19,TIL_1A,TIL_1B,TIL_1C,TIL_1D,TIL_1E,TIL_3C,TIL_3E,TIL_3F,
	TIL_43,TIL_44,TIL_46,TIL_47,TIL_49,TIL_4A,TIL_4C,TIL_8E,TIL_8F,
	0/*End of list*/
};

/*isBrickSolid*/
C_2999(bp04)
unsigned char bp04;
{
	register int si;

	for(si = 0; D_0904[si]; si ++)
		if(bp04 == D_0904[si])
			return 1;
	return 0;
}

/*C_29C3*/w_Blocked()
{
	u4_puts("Blocked!\n");
	sound(1);
	u_kbflush();
}

/*C_29DE*/w_DriftOnly()
{
	u4_puts("Drift Only!\n");
	u_kbflush();
}

/*check slow progress*/
C_29EF(bp04)
unsigned char bp04;
{
	switch(bp04) {
		case TIL_03: if(U4_RND1(7) != 0) return 0; break;
		case TIL_05: case TIL_06: if(U4_RND1(3) != 0) return 0; break;
		case TIL_07: case TIL_46: if(U4_RND1(1) == 0) return 0; break;
		default: return 0;
	}
	return 1;
}

C_2A38(bp04)
unsigned char bp04;
{
	return (bp04 < TIL_02) || ((bp04 >= TIL_8C) && (bp04 < TIL_90));
}

/*check slow progress [boat]*/
C_2A5A(bp04)
unsigned int bp04;
{
	if(WindDir == bp04)
		return !(Party._moves & 3);
	if(WindDir == ((bp04+2)&3))
		return (Party._moves & 3);
	return 1;
}

/*enter moongate ?*/
C_2A91(bp04)
unsigned char bp04;
{
	if(bp04 != TIL_43)
		return 0;
	if(Party._trammel == 4 && Party._felucca == 4) {
		t_callback();
		Gra_09();
		Party._loc = 0x1f;
		sound(9, 0xa0);
		C_E72C();
		return 1;
	}
	t_callback();
	Party._x = D_0814[Party._felucca];
	Party._y = D_081C[Party._felucca];
	Gra_09(); sound(9, 0xa0); Gra_09();
	C_26B6();
	t_callback();
	Gra_09(); sound(9, 0xa0); Gra_09();
	return 1;
}

/*move North*/
C_2B19()
{
	/*LB's castle middle wing*/
	if(tile_cur == TIL_0E) {
		w_Blocked();
		return 0;
	}
	if(tile_north != TIL_0E && !C_2999(tile_north)) {
		w_Blocked();
		return 0;
	}
	if(C_29EF(tile_north)) {
		w_SlowProgress();
		return 1;
	}
	sound(0);
	if(CurMode == MOD_OUTDOORS) {
		C_2839();
		if(C_2A91(tile_north))
			return 0;
		return 1;
	}
	Party._y --;
	D_959C.y = Party._y;
	if(D_959C.y <= 0x1f) {
		return 1;
	}
	C_2747();
	return 0;
}

/*C_2B8C*/CMDDIR_Up()
{
	if(Party._tile == TIL_10 || Party._tile == TIL_12 || Party._tile == TIL_13) {
		Party._tile = TIL_11;
		u4_puts("Turn North!\n");
	} else if(Party._tile == TIL_11) {
		u4_puts("Sail North!\n");
		if(!C_2A38(tile_north)) {
			w_Blocked();
		} else if(!C_2A5A(DIR_N)) {
			w_SlowProgress();
		} else {
			C_2839();
		}
	} else if(Party._tile == TIL_18) {
		w_DriftOnly();
	} else {
		sound(0);
		u4_puts("North\n");
		if(C_2B19() && D_95C6) {
			t_callback();
			sound(0);
			C_2B19();
		}
	}
}

/*move South*/
C_2C25()
{
	if(!C_2999(tile_south)) {
		w_Blocked();
		return 0;
	}
	if(C_29EF(tile_south)) {
		w_SlowProgress();
		return 1;
	}
	sound(0);
	if(CurMode == MOD_OUTDOORS) {
		C_2891();
		if(C_2A91(tile_south))
			return 0;
		return 1;
	}
	Party._y ++;
	D_959C.y = Party._y;
	if(D_959C.y <= 0x1f) {
		return 1;
	}
	C_2747();
	return 0;
}

/*C_2C8A*/CMDDIR_Down()
{
	if(Party._tile == TIL_18) {
		w_DriftOnly();
	} else if(Party._tile == TIL_10 || Party._tile == TIL_12 || Party._tile == TIL_11) {
		Party._tile = TIL_13;
		u4_puts("Turn South!\n");
	} else if(Party._tile == TIL_13) {
		u4_puts("Sail South!\n");
		if(!C_2A38(tile_south)) {
			w_Blocked();
		} else if(!C_2A5A(DIR_S)) {
			w_SlowProgress();
		} else {
			C_2891();
		}
	} else {
		sound(0);
		u4_puts("South\n");
		if(C_2C25() && D_95C6) {
			t_callback();
			sound(0);
			C_2C25();
		}
		/*spawn demons on verity island?*/
		if(
			Party._x >= 0xe5 && Party._x < 0xea &&
			Party._y >= 0xd4 && Party._y < 0xd9
		) C_27D9();
	}
}

/*move West*/
C_2D44()
{
	if(!C_2999(tile_west)) {
		w_Blocked();
		return 0;
	}
	if(C_29EF(tile_west)) {
		w_SlowProgress();
		return 1;
	}
	sound(0);
	if(CurMode == MOD_OUTDOORS) {
		C_28E9();
		if(C_2A91(tile_west))
			return 0;
		return 1;
	}
	Party._x --;
	D_959C.x = Party._x;
	if(D_959C.x <= 0x1f) {
		return 1;
	}
	C_2747();
	return 0;
}

/*C_2DA9*/CMDDIR_Left()
{
	if(Party._tile == TIL_18) {
		w_DriftOnly();
	} else if(Party._tile == TIL_13 || Party._tile == TIL_12 || Party._tile == TIL_11) {
		Party._tile = TIL_10;
		u4_puts("Turn West!\n");
	} else if(Party._tile == TIL_10) {
		u4_puts("Sail West!\n");
		if(!C_2A38(tile_west)) {
			w_Blocked();
		} else if(!C_2A5A(DIR_W)) {
			w_SlowProgress();
		} else {
			C_28E9();
		}
	} else {
		if(Party._tile == TIL_15)
			Party._tile = TIL_14;
		sound(0);
		u4_puts("West\n");
		if(C_2D44() && D_95C6) {
			t_callback();
			sound(0);
			C_2D44();
		}
	}
}

/*move East*/
C_2E4F()
{
	if(!C_2999(tile_east)) {
		w_Blocked();
		return 0;
	}
	if(C_29EF(tile_east)) {
		w_SlowProgress();
		return 1;
	}
	sound(0);
	if(CurMode == MOD_OUTDOORS) {
		C_2941();
		if(Party._y == 0xe0 && Party._x == 0xdd)
			C_280A();
		if(C_2A91(tile_east))
			return 0;
		return 1;
	}
	Party._x ++;
	D_959C.x = Party._x;
	if(D_959C.x <= 0x1f) {
		return 1;
	}
	C_2747();
	return 0;
}


/*C_2EC5*/CMDDIR_Right()
{
	if(Party._tile == TIL_18) {
		w_DriftOnly();
	} else if(Party._tile == TIL_13 || Party._tile == TIL_10 || Party._tile == TIL_11) {
		Party._tile = TIL_12;
		u4_puts("Turn East!\n");
	} else if(Party._tile == TIL_12) {
		u4_puts("Sail East!\n");
		if(!C_2A38(tile_east)) {
			w_Blocked();
		} else if(!C_2A5A(DIR_E)) {
			w_SlowProgress();
		} else {
			C_2941();
			if(Party._y == 0xe0 && Party._x == 0xdd)
				C_280A();
		}
	} else {
		if(Party._tile == TIL_14)
			Party._tile = TIL_15;
		sound(0);
		u4_puts("East\n");
		if(C_2E4F() && D_95C6) {
			t_callback();
			sound(0);
			C_2E4F();
		}
	}
}
