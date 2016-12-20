/*
 * Ultima IV - Quest Of The Avatar
 * (c) Copyright 1987 Lord British
 * reverse-coded by Ergonomy Joe in 2012
 */

#include "u4.h"

/*C_891E();
C_895F();
C_899F();
C_89BD();
C_89DB();
C_8A1F();
C_87E2();*/

/*C_84D2*/DNG_main()
{
	register unsigned si;
	int bp_04;

	D_9446 = 1;
	u_kbflush();
	bp_04 = 0;
	do {
		C_9209();
		u4_putc(0x10);
		t_callback();
		if(C_10FD()) {
			u_delay(25, 1);
			si = u_kbhit()?u_kbread():KBD_SPACE;
			if(u4_isupper((unsigned char)si))
				si = (si & 0xff00) | u4_lower((unsigned char)si);
			switch(si) {
				case KBD_SPACE: w_Pass(); break;
				case KBD_UP:
				case 0x487e: C_891E(); break;
				case KBD_LEFT:
				case 0x4b7c: C_899F(); break;
				case KBD_DOWN:
				case 0x5060: C_895F(); break;
				case KBD_RIGHT:
				case 0xf400: C_89BD(); break;
				case KBD_C: CMD_Cast(); break;
				case KBD_D: C_8A1F(); break;/*(D)escend [dungeon]*/
				case KBD_G: CMD_Get(); break;
				case KBD_H: CMD_HoleUp(); break;
				case KBD_I: CMD_Ignite(); break;
				case KBD_K: C_89DB(); break;/*(K)limb [dungeon]*/
				case KBD_M: CMD_Mix(); break;
				case KBD_N: CMD_NewOrder(); break;
				case KBD_P: CMD_Peer(); break;
				case KBD_Q: CMD_Quit(); break;
				case KBD_R: CMD_Ready(); break;
				case KBD_S: C_B9B2(); break;/*(S)earch [dungeon]*/
				case KBD_U: CMD_Use(); break;
				case KBD_V: CMD_Volume(); break;
				case KBD_W: CMD_Wear(); break;
				case KBD_Z: CMD_Ztats(); break;
				case KBD_A:
				case KBD_B: 
				case KBD_E:
				case KBD_F:
				case KBD_J:
				case KBD_L:
				case KBD_O:
				case KBD_T:
				case KBD_X:
				case KBD_Y: w_NotHere(); sound(2); break;
				case KBD_CTRL_S:
					if(bp_04 == KBD_ALT_Z) {
						C_1C21();
						break;
					}
				default:
					u4_puts(/*D_2626*/"Bad command\n");
					sound(2);
					D_07F8 = 0;
			}
			C_AE41();
		} else {
			u4_puts(/*D_2633*/"Zzzzz\n");
		}
		if(D_07F8 != 0 && Party._z >= 0)
			C_87E2();
		else
			D_07F8 = 1;
		bp_04 = si;
	} while(Party._z >= 0);
	C_2747();
	dclose(File_DNG);
	File_DNG = 0;
}

C_8743()
{
	register int si;

	if(
		(tile_cur & 0x0f) == 0 ||
		(tile_cur & 0xf0) == 0x80 ||
		(tile_cur & 0xf0) == 0x90 ||
		(tile_cur & 0xf0) == 0xA0 ||
		(tile_cur & 0xf0) == 0xD0 ||
		(tile_cur & 0xf0) == 0xF0
	) return 0;
	D_96F8 = D_9452 = TIL_90 + (tile_cur & 0x0f) * 4 - 4;
	D_8742._map.x8x8x8[Party._z][Party._y][Party._x] &= 0xf0;
	for(si = 0x1f; si >= 0; si --) {
		if(
			D_8742._npc._var[si] == Party._z &&
			D_8742._npc._x[si] == Party._x &&
			D_8742._npc._y[si] == Party._y
		) {
			D_8742._npc._var[si] =
			D_8742._npc._tile[si] =
			D_8742._npc._x[si] =
			D_8742._npc._y[si] = 0;
			break;
		}
	}
	C_7D50();

	return 1;
}

C_87E2()
{
	register int si;
	register struct tChara *di;

	C_10FD();
	for(di = &(Party.chara[0]), si = 0; si < Party.f_1d8; di ++, si++) {
		if(di->_stat == 'S' && U4_RND1(7) == 0) {
			di->_stat = 'G';
		} else if(di->_stat == 'P') {
			hitChara(si, 2);
			Gra_11(si);
			sound(6);
			Gra_11(si);
		}
	}
	if(food_dec(Party.f_1d8)) {
		u4_puts(/*D_263A*/"\nStarving!!!\n");
		for(si = 0; si < Party.f_1d8; si++) {
			if(isCharaAlive(si))
				hitChara(si, 2);
		}
		for(si = Party.f_1d8; --si >= 0; )
			Gra_11(si);
		sound(6);
		for(si = Party.f_1d8; --si >= 0; )
			Gra_11(si);
	}
	MP_recover();
	C_9414();
	C_95AA();
	if(Party.f_1dc)
		Party.f_1dc --;
	Party._moves ++;
	if(spell_cnt) {
		if(--spell_cnt == 0)
			spell_sta = 7;
	}
	if(Party.f_1dc == 0)
		u4_puts(/*D_2648*/"It's Dark!\n");
	dspl_Stats();
	if(C_8743() == 0) {
		while((tile_cur & 0xf0) == 0xd0) {
			C_10FD();/*check death*/
			C_7FFD();/*enter dungeon room*/
			C_B677();/*render 3d*/
		}
	}
}

C_88E8(bp06, bp04)
unsigned char bp06;
unsigned bp04;
{
	if(bp04 == 0) {
		if(
			(bp06 & 0xf0) == 0xc0 ||
			(bp06 & 0xf0) == 0xe0 ||
			(bp06 & 0xf0) == 0xd0
		) return 1;
	}
	if(bp06 != 0xa1 && bp06 < 0xc0)
		return 1;
	return 0;
}

/*Advance*/
C_891E()
{
	u4_puts(/*D_2654*/"Advance\n");
	if(!C_88E8(tile_forward, 0)) {
		w_Blocked();
		return;
	}
	Party._x = DNG_X_p(Party._x, Party._dir);
	Party._y = DNG_Y_p(Party._y, Party._dir);
}

/*Retreat*/
C_895F()
{
	u4_puts(/*D_265D*/"Retreat\n");
	if(!C_88E8(tile_back, 1)) {
		w_Blocked();
		return;
	}
	Party._x = DNG_X_m(Party._x, Party._dir);
	Party._y = DNG_Y_m(Party._y, Party._dir);
}

/*Turn Left*/
C_899F()
{
	u4_puts(/*D_2666*/"Turn Left\n");
	Party._dir = (Party._dir - 1) & 3;
	D_07F8 = 0;
}

/*Turn Right*/
C_89BD()
{
	u4_puts(/*D_2671*/"Turn Right\n");
	Party._dir = (Party._dir + 1) & 3;
	D_07F8 = 0;
}

/*(K)limb [dungeon]*/
C_89DB()
{
	u4_puts(/*D_267D*/"Klimb ");
	if(
		(tile_cur & 0xf0) == 0x10 ||
		(tile_cur & 0xf0) == 0x30
	) {
		u4_puts(/*D_2684*/"up!\n");
		if(--Party._z >= 0) {
			u4_puts(/*D_2689*/"To level ");
			u4_putc(Party._z + '1');
			Gra_CR();
		}
	} else {
		w_What();
	}
}

/*(D)escend [dungeon]*/
C_8A1F()
{
	u4_puts(/*D_2693*/"Descend ");
	if(
		(tile_cur & 0xf0) == 0x20 ||
		(tile_cur & 0xf0) == 0x30
	) {
		Party._z ++;
		u4_puts(/*D_269C*/"down to level ");
		u4_putc(Party._z + '1');
		Gra_CR();
	} else {
		w_What();
	}
}
