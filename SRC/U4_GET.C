/*
 * Ultima IV - Quest Of The Avatar
 * (c) Copyright 1987 Lord British
 * reverse-coded by Ergonomy Joe in 2012
 */

#include "u4.h"

C_70CE(bp04)
int bp04;
{
	C_09D9(bp04);
	hitChara(bp04, U4_RND3(30));
}

C_70F1()
{
	register int si;

	u4_puts(/*D_2240*/"The Chest Holds:\n");
	si = U4_RND3(80) + U4_RND1(7) + 10;
	u4_putl(si, 1, ' ');
	u4_puts(/*D_2252*/" Gold\n");
	Party._gold = (Party._gold + si <= 9999)?Party._gold + si:9999;
}

/*trapped chest ?*/
C_7150(bp04)
int bp04;
{
	register unsigned si;

	if(((si = U4_RND1(3))&1) == 0) {
		/*note:si's bit 0 is always reset when reaching here,
		 therefore, Sleep or Poison trap never occur.*/
		si &= u_rand_a();
		if(si == 0)
			u4_puts(/*D_2259*/"Acid");
		else if(si == 1)
			u4_puts(/*D_225E*/"Sleep");
		else if(si == 2)
			u4_puts(/*D_2264*/"Poison");
		else
			u4_puts(/*D_226B*/"Bomb");
		u4_puts(/*D_2270*/" Trap!\n");
		if(bp04 == -1 || U4_RND3(100) <= Party.chara[bp04]._dex + 25) {
			u4_puts(/*D_2278*/"Evaded!\n");
			sound(8);
		} else if(si == 0) {/*Acid*/
			C_70CE(bp04);
		} else if(si == 1) {/*Sleep*/
			Party.chara[bp04]._stat = 'S';
			if(CurMode >= MOD_COMBAT)
				Fighters._chtile[bp04] = TIL_38;
			C_09D9(bp04);
		} else if(si == 2) {/*Poison*/
			Party.chara[bp04]._stat = 'P';
			dspl_Stats();
			C_09D9(bp04);
		} else {/*Bomb*/
			C_1584();
		}
	}
	C_70F1();
}

C_722F(bp04)
int bp04;
{
	if(CurMode == MOD_DUNGEON) {
		if(tile_cur != 0x40) {
			w_NotHere();
			return;
		}
		D_8742._map.x8x8x8[Party._z][Party._y][Party._x] = 0;
	} else {
		if(tile_cur != TIL_3C) {
			w_NotHere();
			return;
		}
		if(Party._loc != 0 && D_8742._map.x32x32[Party._y][Party._x] == TIL_3C) {
			D_8742._map.x32x32[Party._y][Party._x] = TIL_3E;
			karma_dec(&(Party._hones), 1);
			karma_dec(&(Party._justi), 1);
			karma_dec(&(Party._honor), 1);
		} else {
			register int si;

			for(si = 0x1f; si >= 0; si --)
				if(
					D_8742._npc._tile[si] == TIL_3C &&
					Party._x == D_8742._npc._x[si] &&
					Party._y == D_8742._npc._y[si]
				) break;
			D_8742._npc._tile[si] = D_8742._npc._gtile[si] = 0;
		}
	}
	C_7150(bp04);
}

/*C_72EC*/CMD_Get()
{
	register int si;

	if(Party.f_1dc != 0 && Party._tile == TIL_18) {
		u4_puts(/*D_2281*/"Get chest\n");
		w_DriftOnly();
		return;
	}
	u4_puts(/*D_228C*/"Get Chest!\n");
	if((si = AskChara(/*D_2298*/"Who opens?\x12\x12\b")) < 0)
		return;
	if(!isCharaConscious(si)) {
		w_Disabled();
		return;
	}
	C_722F(si);
}

C_7337()
{
	if(Combat_MAP(Combat._charaY[activeChara], Combat._charaX[activeChara]) != TIL_3C) {
		w_NotHere();
		return;
	}
	Combat_MAP(Combat._charaY[activeChara], Combat._charaX[activeChara]) = TIL_16;
	if(D_8742._map.x8x8x8[Party._z][Party._y][Party._x] == 0x40)
		D_8742._map.x8x8x8[Party._z][Party._y][Party._x] = 0;
	C_7150(activeChara);
}

/*(G)et chest [combat]*/
C_73B8()
{
	u4_puts(/*D_22A6*/"Get Chest!\n");
	C_7337();
}

/*----------------------------------------
FIRE
----------------------------------------*/

char D_22C8[] = "Broadsides Only!\n";

/*C_73C9*/CMD_Fire()
{
	int loc_A, loc_B, loc_C, loc_D, loc_E, loc_F;

	u4_puts(/*D_22B2*/"Fire ");
	if(Party._tile < TIL_10 || Party._tile > TIL_13) {
		w_What();
		return;
	}
	u4_puts(/*D_22B8*/"Cannon!\n");
	AskDir(/*D_22C1*/"Dir: ", &loc_C, &loc_D);
	if(!(loc_C|loc_D))
		return;
	if(loc_C != 0) {
		if(Party._tile != TIL_11 && Party._tile != TIL_13) {
			u4_puts(D_22C8);
			sound(2);
			return;
		}
	} else if(Party._tile != TIL_10 && Party._tile != TIL_12) {
		u4_puts(D_22C8);
		sound(2);
		return;
	}
	/*-- FIRING --*/
	sound(3);
	loc_F = Party._x + loc_C;
	loc_B = Party._y + loc_D;
	hit_x = loc_C + 5;
	hit_y = loc_D + 5;
	hit_tile = TIL_4D;
	for(loc_E = 1; ; loc_E++) {
		if(loc_E > 3 || (
			((loc_A = C_0A58(0x1f, loc_F, loc_B)) != -1) &&
			(D_8742._npc._tile[loc_A] != TIL_8C && D_8742._npc._tile[loc_A] != TIL_18)
		)) {
			hit_tile = 0;
			if(loc_A == -1)
				return;
			/*-- HIT SOMETHING --*/
			hit_tile = TIL_4F; C_36C7(); hit_tile = 0;
			sound(6);
			if(loc_A < 8 && U4_RND1(3))
				return;
			if(D_8742._npc._tile[loc_A] == TIL_5E)
				return;
			break;
		}
		C_36C7();
		hit_x += loc_C; loc_F += loc_C;
		hit_y += loc_D; loc_B += loc_D;
		loc_A = -1;
	}
	D_8742._npc._tile[loc_A] = D_8742._npc._gtile[loc_A] = 0;
}

/*----------------------------------------
IGNITE
----------------------------------------*/

/*C_7525*/CMD_Ignite()
{
	u4_puts(/*D_22DA*/"Ignite Torch!\n");
	if(CurMode != MOD_DUNGEON) {
		w_NotHere();
		return;
	}
	if(Party._torches == 0) {
		w_NoneLeft();
		return;
	}
	Party._torches --;
	Party.f_1dc += 100;
	if(CurMode == MOD_DUNGEON)
		C_AE41();
}
