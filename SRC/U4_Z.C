/*
 * Ultima IV - Quest Of The Avatar
 * (c) Copyright 1987 Lord British
 * reverse-coded by Ergonomy Joe in 2012
 */

#include "u4.h"

#include <string.h>

C_45B5()
{
	for( ;txt_Y <= 8; txt_Y ++) {
		txt_X = 24;
		u4_puts(/*D_18C6*/"               ");
	}
}

/*display centered string*/
C_45D6(si/*bp06*/, bp04)
register char *si;
unsigned bp04;
{
	register int di;

	di = strlen(si);
	if(di > 12)
		di = 12;
	di -= (di & 1);

	txt_X = (di>=8) + ((12 - di)  / 2) + bp04 + 25;
	if(txt_Y == 0) {
		txt_X --;
		u4_putc(0x10);
	}
	u4_puts(si);
	if(txt_Y == 0)
		u4_putc(0x11);
}

C_4649()
{
	unsigned bp_02, bp_04;

	bp_02 = txt_Y;
	bp_04 = txt_X;
	txt_Y = 0;
	txt_X = 24;
	do
		Gra_putchar('\r');
	while(++txt_X < 39);
	txt_Y = bp_02;
	txt_X = bp_04;
}

C_4689(bp04)
int bp04;
{
	register struct tChara *si;

	si = &(Party.chara[bp04]);
	txt_Y = 0; C_45D6(si->_name, 0);
	txt_X = 24;
	txt_Y = 1; u4_putc(si->p_24);
	txt_Y = 1; C_45D6(D_1E98[77 + si->_class], 0);
	txt_X = 38; u4_putc(si->_stat);
	txt_X = 25;
	txt_Y = 3; u4_puts(/*D_18D6*/"MP:"); u4_putl(si->_MP, 2, '0');
	txt_X = 32; u4_puts(/*D_18DA*/"LV:"); u4_putc((si->_HP[1]/100)+'0');
	txt_X = 24;
	txt_Y = 4; u4_puts(/*D_18DE*/"STR:"); u4_putl(si->_str, 2, '0');
	txt_X = 32; u4_puts(/*D_18E3*/"HP:"); u4_putl(si->_HP[0], 4, '0');
	txt_X = 24;
	txt_Y = 5; u4_puts(/*D_18E7*/"DEX:"); u4_putl(si->_dex, 2, '0');
	txt_X = 32; u4_puts(/*D_18EC*/"HM:"); u4_putl(si->_HP[1], 4, '0');
	txt_X = 24;
	txt_Y = 6; u4_puts(/*D_18F0*/"INT:"); u4_putl(si->_int, 2, '0');
	txt_X = 32; u4_puts(/*D_18F5*/"EX:"); u4_putl(si->_XP, 4, '0');
	txt_Y = 7;
	txt_X = 24; u4_puts(/*D_18F9*/"W:"); u4_puts(D_1E98[37 + si->_weapon]);
	txt_Y = 8;
	txt_X = 24; u4_puts(/*D_18FC*/"A:"); u4_puts(D_1E98[53 + si->_armor]);
}

C_4832()
{
	register int si;

	txt_Y = 0;
	C_45D6(/*D_18FF*/"Weapons", 0);
	txt_Y = 1;
	txt_X = 24;
	u4_puts(/*D_1907*/"A-Hands");
	txt_Y = 2;
	txt_X = 24;
	si = 1;
	do {
		if(Party._weapons[si]) {
			u4_putc(si+'A');
			u4_putl(Party._weapons[si], 2, '-');
			u4_putc('-');
			u4_puts(D_1E98[61 + si]);
			txt_X = (txt_X - 1) & ~7;
			if(++txt_Y == 9) {
				txt_Y = 1;
				txt_X += 8;
			}
		}
	} while(++si < 0x10);
	while(txt_X < 40) {
		u4_puts(/*D_190F*/"       ");
		txt_X = (txt_X - 1) & ~7;
		if(++txt_Y == 9) {
			txt_Y = 1;
			txt_X += 8;
		}
	}
}

C_48F8()
{
	register int si;

	txt_Y = 0;
	C_45D6(/*D_1917*/"Armour", 0);
	txt_Y = 1;
	txt_X = 24;
	u4_puts(/*D_191E*/"A  -No Armour");
	txt_Y = 2;
	for(si = 1; si < 8; si ++) {
		if(Party._armors[si]) {
			txt_X = 24;
			u4_putc(si + 'A');
			u4_putl(Party._armors[si], 2, '-');
			u4_putc('-');
			u4_puts(D_1E98[53 + si]);
			while(txt_X != 39)
				u4_putc(' ');
			txt_Y ++;
		}
	}
	C_45B5();
}

C_4987()
{
	txt_Y = 0;
	C_45D6(/*D_192C*/"Equipment", -1);

	txt_X = 24; txt_Y = 1;
	u4_putl(Party._torches, 2, ' '); u4_puts(/*D_1936*/" Torches");

	txt_X = 24; txt_Y ++;
	u4_putl(Party._gems, 2, ' '); u4_puts(/*D_193F*/" Gems");

	txt_X = 24; txt_Y ++;
	u4_putl(Party._keys, 2, ' '); u4_puts(/*D_1945*/" Keys");

	if(Party._sextants) {
		txt_X = 24; txt_Y = 4;
		u4_putl(Party._sextants, 2, ' '); u4_puts(/*D_194B*/" Sextants");
	}
	txt_Y ++;
	C_45B5();
}

char D_199A[] = "BYRGOPWB";
char D_19A4[] = "HCVJSHSH";

C_4A3D()
{
	register int si;

	txt_Y = 0;
	C_45D6(/*D_1955*/"Items", 0);
	txt_Y = 1;
	if(Party.mStones) {
		txt_X = 24;
		u4_puts(/*D_195B*/"Stones:");
		si = 0;
		do {
			if(TST_MSK(Party.mStones, si))
				u4_putc(D_199A[si]);
		} while(++si < 8);
		txt_Y ++;
	}
	if(Party.mRunes) {
		txt_X = 24;
		u4_puts(/*D_1963*/"Runes:");
		si = 0;
		do {
			if(TST_MSK(Party.mRunes, si))
				u4_putc(D_19A4[si]);
		} while(++si < 8);
		txt_Y ++;
	}
	if(TST_MSK(Party.mItems, ST_BELL) || TST_MSK(Party.mItems, ST_BOOK) || TST_MSK(Party.mItems, ST_CANDLE)) {
		txt_X = 24;
		if(TST_MSK(Party.mItems, ST_BELL))
			u4_puts(/*D_196A*/"Bell ");
		if(TST_MSK(Party.mItems, ST_BOOK))
			u4_puts(/*D_1970*/"Book ");
		if(TST_MSK(Party.mItems, ST_CANDLE)) {
			u4_puts(/*D_1976*/"Candl");
			if(!TST_MSK(Party.mItems, ST_BOOK) || !TST_MSK(Party.mItems, ST_BELL))
				u4_putc('e');
		}
		txt_Y ++;
	}
	if(TST_MSK(Party.mItems, ST_KEY_C) || TST_MSK(Party.mItems, ST_KEY_L) || TST_MSK(Party.mItems, ST_KEY_T)) {
		txt_X = 24;
		u4_puts(/*D_197C*/"3 Part Key:");
		if(TST_MSK(Party.mItems, ST_KEY_T))
			u4_putc('T');
		if(TST_MSK(Party.mItems, ST_KEY_L))
			u4_putc('L');
		if(TST_MSK(Party.mItems, ST_KEY_C))
			u4_putc('C');
		txt_Y ++;
	}
	if(TST_MSK(Party.mItems, ST_HORN)) {
		txt_X = 24;
		u4_puts(/*D_1988*/"Horn");
		txt_Y ++;
	}
	if(TST_MSK(Party.mItems, ST_WHEEL)) {
		txt_X = 24;
		u4_puts(/*D_198D*/"Wheel");
		txt_Y ++;
	}
	if(TST_MSK(Party.mItems, ST_SKULL)) {
		txt_X = 24;
		u4_puts(/*D_1993*/"Skull");
	}
}

C_4BC7()
{
	register int si;

	txt_Y = 0;
	C_45D6(/*D_19AD*/"Reagents", 0);
	txt_Y = 1;
	si = 0;
	do {
		if(Party._reagents[si]) {
			txt_X = 24;
			u4_putc(si+'A');
			u4_putl(Party._reagents[si], 2, '-');
			u4_putc('-');
			u4_puts(D_1E98[93 + si]);
			while(txt_X != 39)
				u4_putc(' ');
			txt_Y ++;
		}
	} while(++si < 8);
	C_45B5();
}

C_4C42()
{
	register int si;

	txt_Y = 0;
	C_45D6(/*D_19B6*/"Mixtures", 0);
	txt_Y = 1;
	txt_X = 24;
	si = 0;
	do {
		if(Party._mixtures[si]) {
			u4_putc(si+'A');
			u4_putc('-');
			u4_putl(Party._mixtures[si], 2, '0');
			txt_X -= 4;
			txt_Y ++;
			if(txt_Y == 9) {
				txt_Y = 1;
				txt_X += 5;
				if(txt_X >= 39)
					return;
			}
		}
	} while(++si < 26);
}

typedef z_handler(int);
typedef z_handler *pZ_handler;

pZ_handler D_19C0[] = {
	C_4689,C_4689,C_4689,C_4689,
	C_4689,C_4689,C_4689,C_4689,
	C_4832,
	C_48F8,
	C_4987,
	C_4A3D,
	C_4BC7,
	C_4C42
};

C_4CC1(bp04)
int bp04;
{
	unsigned bp_02, bp_04;

	bp_02 = txt_Y;
	bp_04 = txt_X;
	do {
		register int si;

		Gra_13();
		C_4649();
		(*D_19C0[bp04])(bp04);
		while(!u_kbhit());
		switch(si = u_kbread()) {
			case KBD_1:
			case KBD_2:
			case KBD_3:
			case KBD_4:
			case KBD_5:
			case KBD_6:
			case KBD_7:
			case KBD_8:
				if((si&0xf) <= Party.f_1d8)
					bp04 = (si&0xf) - 1;
				else
					sound(1);
			break;
			case KBD_RIGHT: case KBD_DOWN:
				bp04 = (bp04 + 1) % 14;
				if(bp04 == Party.f_1d8)
					bp04 = 8;
			break;
			case KBD_UP: case KBD_LEFT:
				if(bp04 == 8)
					bp04 = Party.f_1d8 - 1;
				else
					bp04 = (bp04 + 13) % 14;
			break;
			case KBD_PGUP:
				if(bp04 >= 1 && bp04 <= 8)
					bp04 = 0;
				else if(bp04 > 8 && bp04 <= 13)
					bp04 = 8;
				else bp04 = 13;
			break;
			case KBD_HOME:
				bp04 = 0;
			break;
			case KBD_0:
				bp04 = 8;
			break;
			case KBD_PGDN:
				if(bp04 >= 0 && bp04 <= 7)
					bp04 = 8;
				else if(bp04 >= 8 && bp04 <= 12)
					bp04 = 13;
				else
					bp04 = 0;
			break;
			case KBD_END:
				bp04 = 13;
			break;
			default:
				bp04 = -1;
		}
	} while(bp04 != -1);
	C_4649();
	Gra_13();
	dspl_Stats();
	txt_Y = bp_02;
	txt_X = bp_04;
}

/*C_4E45*/CMD_Ztats()
{
	if(CurMode >= MOD_COMBAT) {
		u4_puts(/*D_19DC*/"Ztats\n");
		Gra_11(activeChara);
		C_4CC1(activeChara);
		Gra_11(activeChara);
	} else {
		int bp_02;

		bp_02 = AskChara(/*D_19E3*/"Ztats for:\x12\x12\b");
		if(bp_02 != -1)
			C_4CC1((bp_02 == -2)?8:bp_02);
	}
}
