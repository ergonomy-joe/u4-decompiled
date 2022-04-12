/*
 * Ultima IV - Quest Of The Avatar
 * (c) Copyright 1987 Lord British
 * reverse-coded by Ergonomy Joe in 2012
 */

#include "u4.h"

/*----------------------------------------
Whirlpool and Twister management?
----------------------------------------*/

/*remove monster?*/
C_7821(si/*bp06*/, bp04)
register int si;
int bp04;
{
	register int di;

	for(di = 31; di >= 0; di --) {
		if(
			di != si &&
			D_8742._npc._tile[di] &&
			D_8742._npc._x[di] == D_8742._npc._x[si] &&
			D_8742._npc._y[di] == D_8742._npc._y[si]
		) {
			D_8742._npc._tile[di] = D_8742._npc._gtile[di] = 0;
			t_callback();
			sound(bp04);
		}
	}
}

/*whirlpool contact?*/
C_786F(si/*bp04*/)
register int si;
{
	if(Party._x == D_8742._npc._x[si] && Party._y == D_8742._npc._y[si]) {
		t_callback();
		hit_y = hit_x = 5;
		hit_tile = TIL_8C;
		C_36C7();
		Party._x = 0x7f;
		Party._y = 0x4e;
		sound(11);
		C_1584();
		Party._tile = TIL_10;
		hit_tile = 0;
		C_26B6();
	}
	C_7821(si, 11);
}

/*twister contact?*/
C_78D1(si/*bp04*/)
register int si;
{
	if(Party._x == D_8742._npc._x[si] && Party._y == D_8742._npc._y[si]) {
		t_callback();
		sound(12);
		C_1584();
		C_1584();
		C_1584();
		C_1584();
		hit_tile = 0;
	}
	C_7821(si, 12);
}

C_7918()
{
	register int si;

	if(CurMode != MOD_OUTDOORS)
		return;

	for(si = 3; si >= 0; si--) {
		if(D_8742._npc._tile[si] == TIL_8C)
			C_786F(si);
		else if(D_8742._npc._tile[si] == TIL_8E)
			C_78D1(si);
	}
}

/*----------------------------------------

----------------------------------------*/

/*C_794D*/w_SameExit()
{
	u4_puts(/*D_239E*/"All must use same exit!\n");
	sound(1);
}

/*exit combat zone*/
C_7962()
{
	Combat._charaX[activeChara] = Combat._charaY[activeChara] = 0x80;
	Fighters._chtile[activeChara] = 0;
	sound(8);
	if(CurMode == MOD_COMBAT && !C_0AFE(D_96F8) && Party.chara[activeChara]._HP[0] == Party.chara[activeChara]._HP[1]) {
		karma_dec(&(Party._valor), 2);
		karma_dec(&(Party._sacri), 2);
	}
}

/*exiting fight*/
C_79C9(bp06, bp04)
unsigned char bp06;
unsigned char bp04;
{
	if(CurMode == MOD_COM_ROOM) {
		/*-- dungeon room --*/
		/*someone already exited W/E*/
		if(D_96EE != 0) {
			if(bp06 != (unsigned char)D_96EE) {
				w_SameExit();
				return;
			}
			C_7962();
			return;
		}
		/*someone already exited N/S*/
		if(D_96F4 != 0) {
			if(bp04 != (unsigned char)D_96F4) {
				w_SameExit();
				return;
			}
			C_7962();
			return;
		}
		/*-- --*/
		if(bp06 > 10)
			D_96EE = bp06;
		else
			D_96F4 = bp04;
	}
	C_7962();
}

/*room special tiles*/
C_7A15(bp06, bp04)
unsigned char bp06;
unsigned char bp04;
{
	register int /*si*/loc_A;
	int loc_B, loc_C/*bp_04, bp_06*/;

	for(loc_A = 3; loc_A >= 0; loc_A --) {
		if(D_95B2[(loc_A << 2)]) {
			if(
				(bp06 << 12) == (*(U16 *)(D_95B2+(loc_A << 2)) & 0xf000) &&
				(bp04 <<  8) == (*(U16 *)(D_95B2+(loc_A << 2)) & 0x0f00)
			) {
				loc_B = *(U16 *)(D_95B2+(loc_A << 2)+2) & 0xf;
				if(
					loc_B |
					(loc_C = (*(U16 *)(D_95B2+(loc_A << 2)+2) >> 4) & 0xf)
				) Combat_MAP(loc_B, loc_C) = D_95B2[(loc_A << 2)];
				loc_B = (*(U16 *)(D_95B2+(loc_A << 2)+2) >> 8) & 0xf;
				if(
					loc_B |
					(loc_C = (*(U16 *)(D_95B2+(loc_A << 2)+2) >> 12) & 0xf)
				) Combat_MAP(loc_B, loc_C) = D_95B2[(loc_A << 2)] & 0xff;
			}
		}
	}
}

/*move [fight]*/
C_7AE3(si/*bp08*/, bp06, bp04)
register int si;
unsigned char bp06;
unsigned char bp04;
{
	register unsigned char *di;

	sound(0);
	/*-- out of bounds=>exiting*/
	if((unsigned)bp06 > 10 || (unsigned)bp04 > 10) {
		C_79C9(bp06, bp04);
		return;
	}
	di = &(D_96F9[bp04*11 + bp06]);
	if(!C_2999(*di)) {
		w_Blocked();
		return;
	}
	if(C_29EF(*di)) {
		w_SlowProgress();
		return;
	}
	Combat._charaX[si] = bp06;
	Combat._charaY[si] = bp04;
	sound(0);
	if(CurMode == MOD_COM_ROOM)
		C_7A15(bp06, bp04);
}

/*North [combat]*/
C_7B89()
{
	u4_puts(/*D_23B7*/"North\n");
	C_7AE3(activeChara, Combat._charaX[activeChara], Combat._charaY[activeChara] - 1);
}

/*South [combat]*/
C_7BAF()
{
	u4_puts(/*D_23BE*/"South\n");
	C_7AE3(activeChara, Combat._charaX[activeChara], Combat._charaY[activeChara] + 1);
}

/*East [combat]*/
C_7BD5()
{
	u4_puts(/*D_23C5*/"East\n");
	C_7AE3(activeChara, Combat._charaX[activeChara] + 1, Combat._charaY[activeChara]);
}

/*West [combat]*/
C_7BFD()
{
	u4_puts(/*D_23CB*/"West\n");
	C_7AE3(activeChara, Combat._charaX[activeChara] - 1, Combat._charaY[activeChara]);
}
