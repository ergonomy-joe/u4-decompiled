/*
 * Ultima IV - Quest Of The Avatar
 * (c) Copyright 1987 Lord British
 * reverse-coded by Ergonomy Joe in 2012
 */

#include "u4.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void cdecl /*C_191E*/main()
{
	register unsigned si;
	int bp_04;

	low_init();
	C_C51C();
	if(Party._loc >= 0x11 && Party._loc <= 0x18) {
		CurMode = MOD_DUNGEON;
		if(Load("DNGMAP.SAV", sizeof(tMap8x8x8), &(D_8742._map)) == -1)
			exit(3);
		File_DNG = dopen(D_0894[Party._loc - 0x11], 0);
		if(setjmp(D_9458) == 0)
			DNG_main();
	} else {
		Party._loc = 0;
	}
	u_kbflush();
	bp_04 = 0;
	for(;;) {
		setjmp(D_9458);
		t_callback();
		C_9209();
		if(C_10FD()) {
			u4_putc(0x10);
			u_delay(25, 1);
			si = u_kbhit()?u_kbread():KBD_SPACE;
			if(u4_isupper((unsigned char)si))
				si = (si & 0xff00) | u4_lower((unsigned char)si);
			switch(si) {
				case KBD_SPACE: w_Pass(); break;
				case 0x487e:
				case KBD_UP: CMDDIR_Up(); break;
				case 0x4b7c:
				case KBD_LEFT: CMDDIR_Left(); break;
				case 0x5060:
				case KBD_DOWN: CMDDIR_Down(); break;
				case 0xf400:
				case KBD_RIGHT: CMDDIR_Right(); break;
				case KBD_A: CMD_Attack(); break;
				case KBD_B: CMD_Board(); break;
				case KBD_C: CMD_Cast(); break;
				case KBD_D: CMD_Descend(); break;
				case KBD_E: CMD_Enter(); break;
				case KBD_F: CMD_Fire(); break;
				case KBD_G: CMD_Get(); break;
				case KBD_H: CMD_HoleUp(); break;
				case KBD_I: CMD_Ignite(); break;
				case KBD_J: CMD_Jimmy(); break;
				case KBD_K: CMD_Klimb(); break;
				case KBD_L: CMD_Locate(); break;
				case KBD_M: CMD_Mix(); break;
				case KBD_N: CMD_NewOrder(); break;
				case KBD_O: CMD_Open(); break;
				case KBD_P: CMD_Peer(); break;
				case KBD_Q: CMD_Quit(); break;
				case KBD_R: CMD_Ready(); break;
				case KBD_S: CMD_Search(); break;
				case KBD_T: CMD_Talk(); break;
				case KBD_U: CMD_Use(); break;
				case KBD_V: CMD_Volume(); break;
				case KBD_W: CMD_Wear(); break;
				case KBD_X: CMD_X_it(); break;
				case KBD_Y: CMD_Yell(); break;
				case KBD_Z: CMD_Ztats(); break;
				case KBD_CTRL_S:
					if(bp_04 == KBD_ALT_Z) {
						C_1C21();
						break;
					}
				default:
					u4_puts("Bad command!\n");
					sound(2);
					D_07F8 = 0;
				break;
			}
		} else {
			u4_puts("Zzzzz\n");
		}
		if(D_07F8 != 0) {
			C_1C53();
		} else {
			t_callback();
			D_07F8 = 1;
		}
		bp_04 = si;
	}
}

/*cheat code --> reveal the different levels of karmas*/
C_1C21()
{
	register int si;

	Gra_CR();
	for(si = 0; si < 8; si++)
		u4_putl(*(pKarmas[si]), 2, '0');
	Gra_CR();
}

C_1C53()
{
	register int si;
	register struct tChara *di;

	C_10FD();
	/*restore some hull*/
	if(Party._ship < 50 && U4_RND1(3) == 0)
		Party._ship ++;
	/*S=>G(randomly), P=>takes 2 hit*/
	for(di = Party.chara, si = 0; si < Party.f_1d8; di++, si++) {
		if(di->_stat == 'S' && U4_RND1(7) == 0) {
			di->_stat = 'G';
		} else if(di->_stat == 'P') {
			hitChara(si, 2);
			Gra_11(si); sound(6); Gra_11(si);
		}
	}
	/*FOOD management*/
	if(food_dec(Party.f_1d8)) {
		u4_puts("\nStarving!!!\n");
		for(si = 0; si < Party.f_1d8; si ++) {
			if(isCharaAlive(si))
				hitChara(si, 2);
		}
		si = Party.f_1d8;
		while(--si >= 0)
			Gra_11(si);
		sound(6);
		si = Party.f_1d8;
		while(--si >= 0)
			Gra_11(si);
	}
	/* */
	MP_recover();
	if(Party.f_1dc == 0) {
		C_7918();
		C_5834();
		C_5851();
		C_7918();
	}
	Party._moves ++;
	if(spell_cnt) {
		if(--spell_cnt == 0)
			spell_sta = 7;
	}
	dspl_Stats();
	/*automatic door closing*/
	C_431D();
}
