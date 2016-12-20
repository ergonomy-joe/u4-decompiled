/*
 * Ultima IV - Quest Of The Avatar
 * (c) Copyright 1987 Lord British
 * reverse-coded by Ergonomy Joe in 2012
 */

#include "u4.h"

/*----------------------------------------
MODULE SEARCH[dungeon]
----------------------------------------*/

char *D_2E04[] = {/*D_2DF0*/"\nHmmm--No Effect!\n"};

C_B730(bp06, bp04)
int bp06;
int bp04;
{
	Gra_11(bp06);
	sound(7);
	sound(7);
	sound(7);
	Gra_11(bp06);
	hitChara(bp06, 100 * bp04);
}

/*increment characteristic (max 50)*/
C_B770(bp06, bp04)
int *bp06;
int bp04;
{
	*bp06 += bp04;
	*bp06 = (*bp06 > 50)?50:*bp06;
}

int D_2E6E[] = {2,2,2,4,4,4,6,6};/*magical ball hits points*/
int D_2E7E[][8] = {/*magical ball characteristic*/
	{0,0,5,0,5,5,5,0},
	{0,5,0,5,5,0,5,0},
	{5,0,0,5,0,5,5,0}
};

/*magical ball*/
C_B795()
{
	int bp_02;

	u4_puts(/*D_2E06*/"\nYou find a Magical Ball...\n");
	if((bp_02 = AskChara(/*D_2E23*/"Who touches?\x12\x12\b")) < 0)
		return;
	if(!isCharaConscious(bp_02)) {
		u4_puts(/*D_2E33*/"\nDisabled!\n");
		return;
	}
	D_8742._map.x8x8x8[Party._z][Party._y][Party._x] = 0;
	C_B730(bp_02, D_2E6E[Party._loc - 0x11]);
	/*-- which characteristic(s) ? --*/
	if(D_2E7E[0][Party._loc - 0x11]) {
		C_B770(&(Party.chara[bp_02]._str), 5);
		u4_puts(/*D_2E3F*/"Strength + 5\n");
	}
	if(D_2E7E[1][Party._loc - 0x11]) {
		C_B770(&(Party.chara[bp_02]._dex), 5);
		u4_puts(/*D_2E4D*/"Dexterity + 5\n");
	}
	if(D_2E7E[2][Party._loc - 0x11]) {
		C_B770(&(Party.chara[bp_02]._int), 5);
		u4_puts(/*D_2E5C*/"Intelligence + 5\n");
	}
}

/*fountain*/
C_B863()
{
	int bp_02;

	u4_puts(/*D_2EAE*/"You find a Fountain.\n");
	if((bp_02 = AskChara(/*D_2EC4*/"Who drinks?\x12\x12\b")) < 0)
		return;
	if(!isCharaConscious(bp_02)) {
		u4_puts(/*D_2ED3*/"\nDisabled!\n");
		return;
	}
	switch(tile_cur & 0xf) {
		case 0:	u4_puts(D_2E04[0]); break;
		case 1:
			if(Party.chara[bp_02]._HP[0] == Party.chara[bp_02]._HP[1]) {
				u4_puts(D_2E04[0]);
			} else {
				u4_puts(/*D_2EDF*/"\nAhh-Refreshing!\n");
				Party.chara[bp_02]._HP[0] = Party.chara[bp_02]._HP[1];
			}
		break;
		case 2:
			u4_puts(/*D_2EF1*/"\nBleck--Nasty!\n");
			C_B730(bp_02, 1);
		return;
		case 3:
			if(Party.chara[bp_02]._stat != 'P') {
				u4_puts(D_2E04[0]);
			} else {
				Party.chara[bp_02]._stat = 'G';
				u4_puts(/*D_2F01*/"\nHmm--Delicious!\n");
			}
		break;
		case 4:
			if(Party.chara[bp_02]._stat == 'P') {
				u4_puts(D_2E04[0]);
			} else {
				Party.chara[bp_02]._stat = 'P';
				u4_puts(/*D_2F13*/"\nArgh-Choke-Gasp!\n");
				C_B730(bp_02, 1);
			};
		break;
	}
}

/*found stone*/
C_B93F()
{
	if(
		Party._loc == 0x17 || Party._loc == 0x18 ||
		TST_MSK(Party.mStones, Party._loc - 0x11)
	) {
		u4_puts(/*D_2F26*/"\nYou find Nothing!\n");
		return;
	}
	SET_MSK(Party.mStones, Party._loc - 0x11);
	u4_puts(/*D_2F3A*/"\nYou find the ");
	u4_puts(D_0884[Party._loc - 0x11]);
	u4_puts(/*D_2F49*/" stone!\n");
	karma_inc(&(Party._honor), 5);
	XP_inc(0, 200);
}

/*(S)earch [dungeon]*/
C_B9B2()
{
	u4_puts(/*D_2F52*/"Search...\n");
	switch(tile_cur & 0xf0) {
		case 0x70: C_B795(); break;
		case 0x90: C_B863(); break;
		case 0xB0: C_B93F(); break;
		default: u4_puts(/*D_2F5D*/"\nYou find Nothing!\n");
	}
}
