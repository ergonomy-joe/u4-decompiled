/*
 * Ultima IV - Quest Of The Avatar
 * (c) Copyright 1987 Lord British
 * reverse-coded by Ergonomy Joe in 2012
 */

#include "u4.h"

#include <stdlib.h>

char D_27A6[] = "Nothing Here!\n";

/*"You find..." & karma+=5*/
C_8D4B()
{
	u4_puts(/*D_2798*/"You find...\n");
	karma_inc(&(Party._honor), 5);
	Party.f_1e8 = Party._moves & 0xf0;
}

/*get random amount of reagent (max 99)*/
C_8D6D(bp04)
int bp04;
{
	Party._reagents[bp04] += U4_RND1(7) + 2;
	if(Party._reagents[bp04] > 99) {
		Party._reagents[bp04] = 99;
		u4_puts(/*D_27B5*/"Dropped some!\n");
		sound(1);
	}
}

C_8DAA()
{
	if((Party._trammel | Party._felucca) || (Party._moves & 0xf0) == Party.f_1e8) {
		u4_puts(D_27A6);
		return;
	}
	C_8D4B();
	u4_puts(/*D_27C4*/"Mandrake Root!\n");
	C_8D6D(7);
}

C_8DE0()
{
	if((Party._trammel | Party._felucca) || (Party._moves & 0xf0) == Party.f_1e8) {
		u4_puts(D_27A6);
		return;
	}
	C_8D4B();
	u4_puts(/*D_27D4*/"Nightshade!\n");
	C_8D6D(6);
}

C_8E16()
{
	if(TST_MSK(Party.mItems, 4)) {
		u4_puts(D_27A6);
		return;
	}
	SET_MSK(Party.mItems, 4);
	C_8D4B();
	u4_puts(/*D_27E1*/"The Bell of Courage!\n");
	XP_inc(0, 400);
}

C_8E46()
{
	if(TST_MSK(Party.mItems, 8)) {
		u4_puts(D_27A6);
		return;
	}
	SET_MSK(Party.mItems, 8);
	C_8D4B();
	u4_puts(/*D_27F7*/"A Silver Horn!\n");
	XP_inc(0, 400);
}

C_8E77()
{
	if(TST_MSK(Party.mItems, 9)) {
		u4_puts(D_27A6);
		return;
	}
	SET_MSK(Party.mItems, 9);
	C_8D4B();
	u4_puts(/*D_2807*/"The Wheel from the H.M.S. Cape!\n");
	XP_inc(0, 400);
}

C_8EA8()
{
	if(
		TST_MSK(Party.mItems, 0) ||
		(Party._trammel | Party._felucca) ||
		TST_MSK(Party.mItems, 1)
	) {
		u4_puts(D_27A6);
		return;
	}
	SET_MSK(Party.mItems, 0);
	C_8D4B();
	u4_puts(/*D_2828*/"The Skull of Mondain the Wizard!\n");
	XP_inc(0, 400);
}

C_8EE8()
{
	if(
		TST_MSK(Party.mStones, 7) ||
		(Party._trammel | Party._felucca)
	) {
		u4_puts(D_27A6);
		return;
	}
	SET_MSK(Party.mStones, 7);
	C_8D4B();
	u4_puts(/*D_284A*/"The Black Stone!\n");
	XP_inc(0, 200);
}

C_8F21()
{
	if(TST_MSK(Party.mStones, 6)) {
		u4_puts(D_27A6);
		return;
	}
	SET_MSK(Party.mStones, 6);
	C_8D4B();
	u4_puts(/*D_285C*/"The White Stone!\n");
	XP_inc(0, 200);
}

C_8F51()
{
	if(TST_MSK(Party.mItems, 3)) {
		u4_puts(D_27A6);
		return;
	}
	SET_MSK(Party.mItems, 3);
	C_8D4B();
	u4_puts(/*D_286E*/"The Book of Truth!\n");
	XP_inc(0, 400);
}

C_8F81()
{
	if(TST_MSK(Party.mItems, 2)) {
		u4_puts(D_27A6);
		return;
	}
	SET_MSK(Party.mItems, 2);
	C_8D4B();
	u4_puts(/*D_2882*/"The Candle of Love!\n");
	XP_inc(0, 400);
}

/*use telescope*/
C_8FB1()
{
	int bp_02;

	u4_puts(/*D_2897*/"You see a knob on the Telescope marked A-P\n");
	if((bp_02 = AskLetter(/*D_28C3*/"You Select:\x12\x12\b", 'A', 'P')) < 0)
		return;
	bp_02 -= 'A';
	if(Load(D_0824[bp_02], sizeof(tMap32x32), &(D_8742._map)) == -1)
		exit(3);
	C_B9EF(0);
	if(Load(D_0824[Party._loc - 1], sizeof(tMap32x32), &(D_8742._map)) == -1)
		exit(3);
}

C_9027()
{
	if(
		Party._armors[7] |
		Party._hones | Party._compa |
		Party._valor | Party._justi |
		Party._sacri | Party._honor |
		Party._spiri | Party._humil
	) {
		u4_puts(D_27A6);
		return;
	}
	Party._armors[7] = 8;
	C_8D4B();
	u4_puts(/*D_28D2*/"Mystic Armour!\n");
	XP_inc(0, 400);
}

C_9076()
{
	if(
		Party._weapons[15] |
		Party._hones | Party._compa |
		Party._valor | Party._justi |
		Party._sacri | Party._honor |
		Party._spiri | Party._humil
	) {
		u4_puts(D_27A6);
		return;
	}
	Party._weapons[15] = 8;
	C_8D4B();
	u4_puts(/*D_28E2*/"Mystic Weapons!\n");
	XP_inc(0, 400);
}

unsigned char D_2904[][2] = {
	{0x05,0x01},
	{0x06,0x02},
	{0x07,0x04},
	{0x08,0x08},
	{0x09,0x10},
	{0x0A,0x20},
	{0x01,0x40},
	{0x0D,0x80}
};

C_90C5()
{
	register int si;

	for(si = 7; si >= 0; si --)
		if(D_2904[si][0] == Party._loc)
			break;
	if(D_2904[si][1] & Party.mRunes) {
		u4_puts(D_27A6);
		return;
	}
	Party.mRunes |= D_2904[si][1];
	C_8D4B();
	u4_puts(/*D_28F3*/"The rune of ");
	u4_puts(D_1E98[151 + si]);
	u4_puts(/*D_2900*/"!\n");
	XP_inc(0, 100);
}

typedef s_handler();
typedef s_handler *pS_handler;

struct t_05_local {
	unsigned char _00, _01, _02;
	pS_handler _03;
} D_2920[] = {
	{0x00,0xB6,0x36,C_8DAA},/*Mandrake root*/
	{0x00,0x64,0xA5,C_8DAA},/*Mandrake root*/
	{0x00,0x2E,0x95,C_8DE0},/*Nightshade*/
	{0x00,0xCD,0x2C,C_8DE0},/*Nightshade*/
	{0x00,0xB0,0xD0,C_8E16},/*The Bell of Courage!*/
	{0x00,0x2D,0xAD,C_8E46},/*'A Silver Horn!'*/
	{0x00,0x60,0xD7,C_8E77},/*The Wheel from the H.M.S. Cape!*/
	{0x00,0xC5,0xF5,C_8EA8},/*The Skull of Mondain the Wizard!*/
	{0x00,0xE0,0x85,C_8EE8},/*The Black Stone!*/
	{0x00,0x40,0x50,C_8F21},/*The White Stone!*/
	{0x02,0x06,0x06,C_8F51},/*The Book of Truth!*/
	{0x10,0x16,0x01,C_8F81},/*The Candle of Love!*/
	{0x02,0x16,0x03,C_8FB1},/*use Telescope*/
	{0x03,0x16,0x04,C_9027},/*Mystic Armour!*/
	{0x04,0x08,0x0F,C_9076},/*Mystic Weapons!*/
	{0x05,0x08,0x06,C_90C5},/*rune of ...*/
	{0x06,0x19,0x01,C_90C5},/*rune of ...*/
	{0x07,0x1E,0x1E,C_90C5},/*rune of ...*/
	{0x08,0x0D,0x06,C_90C5},/*rune of ...*/
	{0x09,0x1C,0x1E,C_90C5},/*rune of ...*/
	{0x0A,0x02,0x1D,C_90C5},/*rune of ...*/
	{0x01,0x11,0x08,C_90C5},/*rune of ...*/
	{0x0D,0x1D,0x1D,C_90C5},/*rune of ...*/
	{0x00,0x00,0x00,0}
};

/*C_913A*/CMD_Search()
{
	register struct t_05_local *si;

	u4_puts(/*D_2914*/"Search...\n");
	if(CurMode <= MOD_BUILDING && Party.f_1dc != 0) {
		w_DriftOnly();
		return;
	}
	for(si = D_2920; si->_03; si ++) {
		if(si->_00 == Party._loc && si->_01 == Party._x && si->_02 == Party._y)
			break;
	}
	if(si->_03 == 0) {
		u4_puts(D_27A6);
	} else {
		(*si->_03)();
	}
}
