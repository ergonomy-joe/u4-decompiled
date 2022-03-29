/*
 * Ultima IV - Quest Of The Avatar
 * (c) Copyright 1987 Lord British
 * reverse-coded by Ergonomy Joe in 2012
 */

#include "u4.h"

#include <string.h>
#include <stdlib.h>

/*shake screen + noise*/
/*C_095E*/shakefx()
{
	Gra_04(); Gra_03();
	Gra_04(); Gra_03();
	Gra_04(); Gra_03();
	Gra_04(); Gra_03();
}

/*increase exp (max 9999)*/
/*C_097D*/XP_inc(bp06, bp04)
int bp06;
int bp04;
{
	Party.chara[bp06]._XP += bp04;
	if(Party.chara[bp06]._XP > 9999)
		Party.chara[bp06]._XP = 9999;
}

/*C_09A3*/w_Pass()
{
	u4_puts("Pass\n");
}

/*increments hit points*/
/*C_09B1*/HP_inc(bp06, bp04)
int bp06;
int bp04;
{
	register U16 *si = Party.chara[bp06]._HP;
	if((si[0] += bp04) > si[1])
		si[0] = si[1];
}

C_09D9(bp04)
int bp04;
{
	Gra_11(bp04);
	sound(7);
	Gra_11(bp04);
}

/*increment karma (max 99)*/
/*C_09F8*/karma_inc(bp06, bp04)
U16 *bp06;
unsigned bp04;
{
	if(*bp06) {
		*bp06 += bp04;
		if(*bp06 > 99)
			*bp06 = 99;
	}
}

/*decrement karma*/
/*C_0A17*/karma_dec(bp06, bp04)
U16 *bp06;
unsigned bp04;
{
	if(*bp06 == 0) {
		*bp06 = 99;
		Gra_19();
		txt_X = 31;
		txt_Y = 10;
		u4_putc(spell_sta);
		u4_puts("\n Thou hast lost\n  an Eighth!\n");
	}
	*bp06 -= bp04;
	if(*bp06 <= 0)
		*bp06 = 1;
}

/*findEnemyAt*/
C_0A58(bp08, bp06, bp04)
int bp08;
unsigned char bp06;
unsigned char bp04;
{
	register int i;
	for(i = bp08; i >= 0; i--) {
		if(
			D_8742._npc._tile[i] != 0 &&
			D_8742._npc._x[i] == bp06 &&
			D_8742._npc._y[i] == bp04
		) break;
	}
	return i;
}

C_0A8B(bp06, bp04)
unsigned char bp06;
unsigned char bp04;
{
	return C_0A58((Party._loc == 0)?7:31, bp06, bp04);
}

/*C_0AB1*/SafeModulo(bp06, bp04)
int bp06;
int bp04;
{
	if(bp04 == 0)
		return 0;
	return bp06 % bp04;
}

/*get character sprite id ?*/
C_0ACF(bp04)
{
	if(Party.chara[bp04]._stat == 'S')
		return TIL_38;
	return (Party.chara[bp04]._class << 1) + TIL_20;
}

/*isNotEvil
 returns 1 if param in {TIL_00~TIL_7F,TIL_8A,TIL_90,TIL_94,TIL_98,TIL_B4,TIL_CC}
 i.e.      if the creatures's defeat leads to karma increase
 else returns 0
*/
C_0AFE(bp04)
unsigned char bp04;
{
	if(bp04 < TIL_80 ||
		bp04 == TIL_8A || bp04 == TIL_90 ||
		bp04 == TIL_94 || bp04 == TIL_98 ||
		bp04 == TIL_B4 || bp04 == TIL_CC
	) return 1;
	return 0;
}

/*C_0B38*/u4_puts(txt/*si/bp04*/)
register char *txt;
{
	register int /*di*/i;
	int /*bp_02*/loc_A;
	int /*bp_04*/loc_B;
	
	loc_A = loc_B = 0;
	i = 0;
	while(txt[i]) {
		if(loc_B-- == 0) {
			char /*bp_08*/loc_C;
			for(loc_B = 0; loc_C = txt[i + loc_B]; loc_B ++) {
				if(loc_C == '\n' || loc_C == ' ')
					break;
			}
			if(loc_B + txt_X > 40 && txt_X != 24) {
				if(loc_A++ == 12) {
					u_kbflush();
					if(txt_X == 39)
						while(!u_kbhit());
					u_kbread();
					loc_A = 0;
				}
				Gra_CR();
			}
		}
		if(txt[i] == '\n' && loc_A++ == 12) {
			u_kbflush();
			if(txt_X == 39)
				while(!u_kbhit());
			u_kbread();
			loc_A = 0;
		}
		u4_putc(txt[i]);
		i++;
	}
	return i;
}

/*C_0C03*/u4_putl(bp0a, bp06, bp04)
long bp0a;
int bp06;
char bp04;
{
	if(bp0a < 0) {
		u4_putc('-');
		u4_putl(-bp0a, bp06 - 1, bp04);
	}
	if(bp0a < 10) {
		if(bp06 > 1) {
			u4_putc(bp04);
			u4_putl(bp0a, bp06 - 1, bp04);
		} else {
			u4_putc(bp0a + '0');
		}
	} else {
		u4_putl(bp0a / 10, bp06 - 1, bp04);
		u4_putc((bp0a % 10) + '0');
	}
}

/*C_0C9F*/u4_putc(bp04)
unsigned char bp04;
{
	switch(bp04) {
		case '\b':
			if(txt_X > 1) {
				txt_X --;
				Gra_putchar(' ');
			}
		break;
		case '\n':
			Gra_CR();
		break;
		case ' ':
			if(txt_X <= 39) {
				Gra_putchar(bp04);
				txt_X ++;
			}
		break;
		default:
			if(txt_X > 39)
				Gra_CR();
			Gra_putchar(bp04);
			txt_X ++;
	}
}

/*display party info*/
/*C_0CF7*/dspl_Stats()
{
	register int loc_C/*si*/;
	register struct tChara *loc_D/*di*/;
	int loc_B/*bp_04*/;
	int loc_A/*bp_02*/, loc_E/*bp_0a*/;

	Gra_19();
	loc_E = txt_Y;
	loc_A = txt_X;
	for(
		loc_B = 0, loc_D = &(Party.chara[0]);
		loc_B < Party.f_1d8;
		loc_D++, loc_B++
	) {
		txt_Y = loc_B + 1;
		txt_X = 24;
		u4_putc(loc_B + '1'); u4_putc('-');
		for(loc_C = 0; loc_D->_name[loc_C] && loc_C < 8; loc_C++)
			u4_putc(loc_D->_name[loc_C]);
		txt_X = 35;
		u4_putl(loc_D->_HP[0], 3, ' ');
		u4_putc(loc_D->_stat);
	}
	txt_X = 24;
	txt_Y = 10;
	u4_putc('F'); u4_putc(':');
	u4_putl(Party._food / 100, 4, '0');
	u4_putc(' ');
	u4_putc(spell_sta);
	if(Party._tile < TIL_14) {
		u4_puts(" SHP:");
		u4_putl(Party._ship, 2, '0');
	} else {
		u4_puts(" G:");
		u4_putl(Party._gold, 4, '0');
	}
	txt_Y = loc_E;
	txt_X = loc_A;
}

/*display gold*/
/*C_0E0E*/dspl_Gold() {
	int bp_02, bp_04;

	bp_02 = txt_X;
	bp_04 = txt_Y;
	txt_X = 35;
	txt_Y = 10;
	u4_putl(Party._gold, 4, '0');
	txt_Y = bp_04;
	txt_X = bp_02;
}

/*i.e. state 'G' or 'P' or 'S'*/
/*C_0E4E*/isCharaAlive(bp04)
int bp04;
{
	if(bp04 >= Party.f_1d8)
		return 0;
	switch(Party.chara[bp04]._stat) {
		case 'G': case 'P': case 'S': return 1;
		default: return 0;
	}
}

/*i.e. state 'G' or 'P'*/
/*C_0E82*/isCharaConscious(bp04)
int bp04;
{
	if(bp04 >= Party.f_1d8)
		return 0;
	switch(Party.chara[bp04]._stat) {
		case 'G': case 'P': return 1;
		default: return 0;
	}
}

/*death/revive*/
C_0EB1()
{
	int bp_02;

	for(bp_02 = Party.f_1d8 - 1; bp_02 >= 0; bp_02 --) {
		Party.chara[bp_02]._stat = 'D';
		Party.chara[bp_02]._HP[0] = 0;
	}
	Gra_13();
	dspl_Stats();
	u_delay(5, 0);
	Gra_10();
	CurMode = MOD_VISION;
	u4_puts("\n\n\nAll is Dark...\n");
	u_delay(5, 0);
	u4_puts("\nBut wait...\n");
	u_delay(5, 0);
	u4_puts("Where am I?...\n");
	u_delay(5, 0);
	u4_puts("Am I dead?...\n");
	u_delay(5, 0);
	u4_puts("Afterlife?...\n");
	u_delay(5, 0);
	u4_puts("You hear:\n");
	txt_X = (12 - (unsigned)strlen(Party.chara[0]._name)) / 2 + 25;
	u4_puts(Party.chara[0]._name);
	Gra_CR();
	u_delay(5, 0);
	u4_puts("I feel motion...\n");
	u_delay(5, 0);
	Party._tile = TIL_1F;
	Party._x = 0x13; Party._y = 0x08;
	Party.out_x = 0x56;
	Party.out_y = 0x6c;

	if(File_TLK) {
		dclose(File_TLK);
		File_TLK = 0;
	}
	if(File_DNG) {
		dclose(File_DNG);
		File_TLK = 0;/*bug??*/
	}
	if(Party._loc == 0) {
		if(Save("OUTMONST.SAV", sizeof(struct tNPC), &(D_8742._npc)) == -1)
			exit(3);
	}
	if(Load("LCB_2.ULT", sizeof(struct t_500), &D_8742) == -1)
		exit(3);
	File_TLK = dopen("LCB.TLK", 0);
	CurMode = MOD_BUILDING;
	Party._loc = 0x01;
	Party.f_1dc = 0;
	D_95CC = MOD_OUTDOORS;
	spell_cnt = 0;
	hit_tile = 0;
	spell_sta = 7;
	D_9440 = 1;
	D_95C6 = 0;
	t_callback();
	C_3A80();
	u4_puts("\n\nLord British says: I have pulled thy spirit and some possessions from the void.  Be more careful in the future!\n");
	for(bp_02 = Party.f_1d8 - 1; bp_02 >= 0; bp_02 --) {
		Party.chara[bp_02]._stat = 'G';
		Party.chara[bp_02]._HP[0] = Party.chara[bp_02]._HP[1];
	}
	for(bp_02 = 15; bp_02 >= 0; bp_02 --)
		Party._weapons[bp_02] = 0;
	for(bp_02 = 7; bp_02 >= 0; bp_02 --)
		Party._armors[bp_02] = 0;
	Party._food = 20099L;
	Party._gold = 200;
	dspl_Stats();
	u_kbflush();
	longjmp(D_9458, -1);
}

/*
returns 1: at least one chara conscious
returns 0: all charas disabled and at least one alive*/
C_10FD()
{
	register int si;

	for(si = Party.f_1d8 - 1; si >= 0; si --) {
		if(isCharaAlive(si)) {
			for(; si >= 0; si--) {
				if(isCharaConscious(si))
					return 1;
			}
			return 0;
		}
	}
	C_0EB1();
}

/*character bp06 takes bp04 hits
 -> 0 : alive
 -> 1 : died*/
/*C_1135*/hitChara(bp06, bp04)
unsigned bp04;
int bp06;
{
	register struct tChara *si = &(Party.chara[bp06]);
	if(si->_HP[0] >= bp04) {
		si->_HP[0] -= bp04;
		dspl_Stats();
		return 0;
	}
	/*character dies*/
	si->_HP[0] = 0;
	si->_stat = 'D';
	if(CurMode >= MOD_COMBAT)
		D_944A[bp06] = Fighters._chtile[bp06] = TIL_38;
	dspl_Stats();
	return 1;
}

/*C_1188*/w_What()
{
	u4_puts("What?\n");
	u_kbflush();
}

/*C_1199*/w_Cant_t()
{
	u4_puts("Can't!\n");
	u_kbflush();
}

/*C_11AA*/w_NotHere()
{
	u4_puts("Not Here!\n");
	u_kbflush();
}

/*C_11BB*/w_Disabled()
{
	u4_puts("Disabled!\n");
	u_kbflush();
}

/*C_11CC*/w_OnlyOnFoot()
{
	u4_puts("Only on foot!\n");
	u_kbflush();
}

/*C_11DD*/w_SlowProgress()
{
	u4_puts("Slow progress!\n");
}

/*C_11EB*/w_NoneLeft()
{
	u4_puts("None left!\n");
}

/*C_11F9*/AskLetter(bp08, bp06, bp04)
char *bp08;
char bp06;
char bp04;
{
	register int si;

	si = -1;
	do {
		if(si != -1)
			sound(1);
		u4_puts(bp08);
		si = u_kbread();
		if(si == KBD_ENTER || si == KBD_ESC || si == KBD_SPACE) {
			if(si == KBD_ENTER || si == KBD_SPACE)
				si = -1;
			else
				si = -2;
			Gra_CR();
			break;
		}
		si &= 0xff;
		u4_toupper2(si);
		if(si > ' ' && si < 0x7f)
			u4_putc(si);
		Gra_CR();
		if(bp06 <= si && si <= bp04)
			break;
	} while(si >= 0);

	return si;
}

/*C_1287*/AskChara(bp04)
char *bp04;
{
	register int si;

	if(Party.f_1d8 == 1) {
		u4_puts(bp04);
		u4_puts("1\n");
		return 0;
	}
	si = AskLetter(bp04, '0', '0' + Party.f_1d8);
	if(si == '0')
		return -2;
	if(si < 0)
		return -1;

	return si - '1';
}

/*C_12D6*/AskDir(bp08, si/*bp06*/, di/*bp04*/)
char *bp08;
register int *si;
register int *di;
{
	unsigned bp_02, bp_04;

	*si = *di = 0;
	do {
		bp_02 = 1;
		u4_puts(bp08);
		bp_04 = u_kbread();
		switch(bp_04) {
			case KBD_SPACE: case KBD_ESC: case KBD_BS: case KBD_ENTER:
			break;
			case KBD_UP:
				*di = -1;
				u4_puts("North");
			break;
			case KBD_DOWN:
				*di = 1;
				u4_puts("South");
			break;
			case KBD_RIGHT:
				*si = 1;
				u4_puts("East");
			break;
			case KBD_LEFT:
				*si = -1;
				u4_puts("West");
			break;
			default:
				bp_04 &= 0xff;
				if(bp_04 >= ' ' && bp_04 < 0x7f)
					u4_putc(bp_04);
				Gra_CR();
				sound(1);
				bp_02 = 0;
		}
	} while(!bp_02);
	Gra_CR();
}

/*C_138B*/food_dec(bp04)
int bp04;
{
	Party._food -= bp04;
	if(Party._food >= 0)
		return 0;
	Party._food = 0;

	return 1;
}

/*C_13B6*/MP_recover()
{
	register struct tChara *si;
	int bp_04;

	for(bp_04 = Party.f_1d8 - 1; bp_04 >= 0; bp_04 --) {
		if(isCharaAlive(bp_04)) {
			register int di;
			si = &(Party.chara[bp_04]);
			switch(si->_class) {
				case 0: di = si->_int * 2; break;
				case 1:
				case 5:
				case 6: di = si->_int; break;
				case 3: di = (si->_int / 2) + si->_int; break;
				case 4: di = si->_int / 2; break;
				default: di = 0;
			}
			if(di > 99)
				di = 99;
			si->_MP ++;
			if(si->_MP > di)
				si->_MP = di;
		}
	}
}

/*C_1445*/u4_gets(si/*bp06*/, bp04)
register char *si;
unsigned bp04;
{
	register int loc_A;
	unsigned loc_B;

	loc_A = 0;
	do {
		loc_B = u_kbread();
		switch(loc_B) {
			case KBD_BS:
			case KBD_0e7f:
			case KBD_LEFT:
				if(loc_A == 0) {
					sound(1);
				} else {
					u4_putc(8);
					loc_A --;
					si[loc_A] = ' ';
				}
			break;
			default:
				loc_B &= 0xff;
				if(bp04 - 1 == loc_A || loc_B < ' ' || loc_B >= 0x80) {
					sound(1);
				} else {
					si[loc_A] = loc_B;
					u4_putc(loc_B);
					loc_A ++;
				}
			break;
			case KBD_ENTER:
				si[loc_A] = 0;
			break;
		}
	} while(loc_B != KBD_ENTER);

	loc_B = 0;
	while(si[loc_B++] == ' ');
	loc_B --;
	if(si[loc_B]) {
		loc_A = 0;
		while(si[loc_B])
			si[loc_A++] = si[loc_B++];
	} else {
		loc_A = loc_B;
	}
	do {
		si[loc_A] = 0;
	} while(si[--loc_A] == ' ');
}

/*get creature name*/
char *C_1513(bp04)
unsigned char bp04;
{
	if(bp04 >= TIL_80) {
		if(bp04 >= TIL_90)
			return D_1E98[9 + (bp04 - TIL_80)/4 - (TIL_90 - TIL_80)/4];
		else
			return D_1E98[1 + (bp04 - TIL_80)/2];
	}
	if(bp04 == TIL_38)
		return D_1E98[159];
	if(bp04 < TIL_20 || bp04 >= TIL_60 || (bp04 >= TIL_30 && bp04 < TIL_50))
		return D_1E98[20];/*"Phantom"*/
	return D_1E98[77 + (bp04 & 0x1f)/2];
}

/*all party damage*/
C_1584()
{
	register int loc_B;
	int loc_A;

	for(loc_B = Party.f_1d8 - 1; loc_B >= 0; loc_B --)
		Gra_11(loc_B);
	sound(6);
	shakefx();
	for(loc_B = Party.f_1d8 - 1; loc_B >= 0; loc_B --)
		Gra_11(loc_B);
	if(CurMode >= MOD_COMBAT || Party._tile > TIL_13) {
		/*normal case*/
		for(loc_B = Party.f_1d8 - 1; loc_B >= 0; loc_B --) {
			if(U4_RND1(1) && isCharaAlive(loc_B)) {
				loc_A = U4_RND3(15) + 10;
				if(CurMode < MOD_COMBAT || Fighters._chtile[loc_B])
					hitChara(loc_B, loc_A);
			}
		}
	} else {
		/*on ship*/
		if((Party._ship -= 10) < 0) {
			Party._ship = 0;
			for(loc_B = Party.f_1d8; --loc_B >= 0; )
				Gra_11(loc_B);
			dspl_Stats();
			u4_puts("Thy Ship Sinks!\n");
			C_0EB1();
		}
	}
	dspl_Stats();
}

/*C_162F*/AskY_N()
{
	int bp_02;

	bp_02 = -1;
	do {
		if(bp_02 != -1)
			sound(1);
		bp_02 = u_kbread() & 0x7f;
		u4_toupper(bp_02);
	} while(
		bp_02 != 'N' && bp_02 != 'Y' &&
		bp_02 != ' ' && bp_02 != 0x1b && bp_02 != '\r'
	);
	if(bp_02 == 'Y' || bp_02 == 'N')
		u4_putc(bp_02);
	Gra_CR();
	return (char)bp_02;
}

long /*C_169C*/AskInt(bp04)
int bp04;
{
	char bp_14[20];

	u4_gets(bp_14, bp04 + 1);
	Gra_CR();
	return bp_14[0]?atol(bp_14):-1L;
}
