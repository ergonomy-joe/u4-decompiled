/*
 * Ultima IV - Quest Of The Avatar
 * (c) Copyright 1987 Lord British
 * reverse-coded by Ergonomy Joe in 2012
 */

#include "u4.h"

#include <stdlib.h>

unsigned char D_26B8[] = {TIL_C0,TIL_C4,TIL_C8,TIL_CC,TIL_B4,TIL_A0,TIL_A4,TIL_DC};

C_8A5A()
{
	register int si;

	u4_puts(/*D_26AC*/"Ambushed!\n");
	D_9772 = Party._x;
	D_9140 = Party._y;
	D_96F8 = D_9452 = D_26B8[U4_RND1(7)];
	for(si = Party.f_1d8; --si >= 0; ) {
		if(Party.chara[si]._stat == 'G')
			Party.chara[si]._stat = 'S';
	}
	dspl_Stats();
	C_7FD7();
}

/*C_8AB0*/CMD_HoleUp() {
	register int si;

	u4_puts(/*D_26C0*/"Hole up & Camp\n");
	if(CurMode != MOD_DUNGEON && Party._loc != 0) {
		w_NotHere();
		return;
	}
	if(Party._tile != TIL_1F) {
		w_OnlyOnFoot();
		return;
	}
#ifdef WIN32
	if(Load(CurMode == MOD_DUNGEON?/*D_26D0*/"CAMP.DNG":/*D_26D9*/"CAMP.CON", sizeof(struct tCombat), &Combat) == -1)
#else
	if(Load(CurMode == MOD_DUNGEON?/*D_26D0*/"CAMP.DNG":/*D_26D9*/"CAMP.CON", (char *)&Fighters - (char *)&Combat, &Combat) == -1)
#endif
		exit(3);
	for(si = 31; si >= 0; si--)
		Fighters._tile[si] = 0;
	for(si = Party.f_1d8; --si >= 0; ) {
		D_944A[si] = Fighters._chtile[si] = isCharaAlive(si)?TIL_38:0;
	}
	dspl_Stats();
	u4_puts(/*D_26E2*/"Resting...\n");
	D_95CC = CurMode;
	CurMode = MOD_COM_CAMP;
	u_delay(10, 0);
	if(U4_RND1(7) == 0) {
		C_8A5A();
	} else if(Party._moves / 100 == Party.f_1e6) {
		u4_puts(/*D_26EE*/"No effect.\n");
	} else {
		Party.f_1e6 = Party._moves / 100;
		for(si = Party.f_1d8; --si >= 0; ) {
			if(isCharaAlive(si)) {
				if(Party.chara[si]._stat == 'S')
					Party.chara[si]._stat = 'G';
				HP_inc(si, U4_RND1(119));
				HP_inc(si, 99);
				Party.chara[si]._MP = 99;
			}
		}
		MP_recover();
		u4_puts(/*D_26FA*/"Players Healed!\n");
	}
	dspl_Stats();
	CurMode = D_95CC;
	if(CurMode == MOD_DUNGEON)
		D_9446 = 1;
}
