/*
 * Ultima IV - Quest Of The Avatar
 * (c) Copyright 1987 Lord British
 * reverse-coded by Ergonomy Joe in 2012
 */

#include "u4.h"

#include <string.h>

typedef tHandler_tlk();
typedef tHandler_tlk *pHandler_tlk;

TLK_name();
TLK_look();
TLK_job();
TLK_health();
TLK_special1();
TLK_special2();
TLK_join();
TLK_give();

char D_2A7A[] = "Funny, no response!\n";

struct {
	char *_00;
	pHandler_tlk _02;
} D_2A90[] = {
	{/*D_2A3E*/"bye",    0},
	{/*D_2A42*/"name",   TLK_name},
	{/*D_2A47*/"look",   TLK_look},
	{/*D_2A4C*/"job",    TLK_job},
	{/*D_2A50*/"health", TLK_health},
	{0,                  TLK_special1},
	{0,                  TLK_special2},
	{/*D_2A57*/"join",   TLK_join},
	{/*D_2A5C*/"give",   TLK_give},
	{/*D_2A61*/"",       0}
};

/*D_8CCE:
	0.name
	1.pronoun
	2.look
	3.job
	4.health
	5.personnal answer1
	6.personnal answer2
	7.special question
	8.special answer Y
	9.special answer N
	10.personnal question1
	11.personnal question2*/
static char *D_8CCE[12];

/*special question*/
C_A163()
{
	char bp_04[4];

	Gra_CR();
	u_kbread();
	u4_puts(D_8CCE[7]);
	u4_puts(/*D_2A62*/"\n\nYou say: ");
	do {
		u4_gets(bp_04, 4);
		Gra_CR();
		if(bp_04[0] == 0)
			break;
		u4_toupper2(bp_04[0]);
		if(bp_04[0] != 'N' && bp_04[0] != 'Y')
			u4_puts(/*D_2A6E*/"Yes or no!\n");
	} while(bp_04[0] != 'N' && bp_04[0] != 'Y');
	if(bp_04[0] == 0)
		return;
	if(bp_04[0] == 'Y') {
		if(D_95CE[1])
			karma_dec(&(Party._humil), 5);
		u4_puts(D_8CCE[8]);
	} else {
		if(D_95CE[1] && (Party._moves >> 4) != Party.f_1ec)
			karma_inc(&(Party._humil), 10);
		u4_puts(D_8CCE[9]);
	}
	Party.f_1ec = (Party._moves >> 4);
	Gra_CR();
}

#ifdef WIN32
C_A22D(bp06, bp04)
int bp06;
char *bp04;
#else
C_A22D(bp04)
char *bp04;
#endif
{
	if(!bp04)
		return;
	u4_puts(bp04);
	Gra_CR();
}

/*C_A245*/TLK_special1()
{
#ifdef WIN32
	C_A22D(6, D_8CCE[5]);
#else
	C_A22D(D_8CCE[5]);
#endif
}

/*C_A253*/TLK_special2()
{
#ifdef WIN32
	C_A22D(7, D_8CCE[6]);
#else
	C_A22D(D_8CCE[6]);
#endif
}

/*C_A261*/TLK_name()
{
	u4_puts(D_8CCE[1]);
	u4_puts(/*D_2AB8*/" says: I am ");
	u4_puts(D_8CCE[0]);
	Gra_CR();
}

/*C_A280*/TLK_look()
{
	u4_puts(/*D_2AC5*/"You see ");
	C_A22D(3, D_8CCE[2]);
}

/*C_A299*/TLK_job()
{
	C_A22D(4, D_8CCE[3]);
}

/*C_A2AB*/TLK_health()
{
	C_A22D(5, D_8CCE[4]);
}

char *D_2BB2[] = {
	/*D_2ACE*/"honest",
	/*D_2AD5*/"compassionate",
	/*D_2AE3*/"valiant",
	/*D_2AEB*/"just",
	/*D_2AF0*/"sacrificial",
	/*D_2AFC*/"honorable",
	/*D_2B06*/"spiritual",
	/*D_2B10*/"humble"
};

static unsigned D_8CE6;/*type?*/

/*C_A2BD*/TLK_join()
{
	int bp_02;

	if(
		(unsigned)D_8742._npc._tlkidx[D_8CE6] != 1 ||
		(Party._loc - 0x05) >= 8 ||
		(Party._loc - 0x05) == Party.chara[0]._class
	) {
		u4_puts(D_8CCE[1]);
		u4_puts(/*D_2B17*/" says: I cannot join thee.\n");
		return;
	}
	if(*pKarmas[Party._loc - 0x05] < 40 && *pKarmas[Party._loc - 0x05] != 0) {
		u4_puts(/*D_2B33*/"Thou art not ");
		u4_puts(D_2BB2[Party._loc - 0x05]);
		u4_puts(/*D_2B41*/" enough for me to join thee.\n");
		return;
	}
	if(100 * Party.f_1d8 + 100 > Party.chara[0]._HP[1]) {
		u4_puts(/*D_2B5F*/"Thou art not experienced enough for me to join thee.\n");
		return;
	}
	u4_puts(/*D_2B95*/"I am honored to join thee!\n");
	D_8742._npc._tile[31] =
	D_8742._npc._gtile[31] =
	D_8742._npc._var[31] =
	D_8742._npc._tlkidx[31] = 0;
	t_callback();
	for(bp_02 = 7; bp_02 >= 0; bp_02 --) {
		if(Party.chara[bp_02]._class == (Party._loc - 0x05))
			break;
	}
	if(bp_02 != -1)
		C_6FF9(&(Party.chara[Party.f_1d8]), &(Party.chara[bp_02]));
	Party.f_1d8 ++;
	Gra_13();
	dspl_Stats();
}

/*C_A3A2*/TLK_give()
{
	int bp_02;

	if(D_8742._npc._tile[D_8CE6] != TIL_58) {
		u4_puts(D_8CCE[1]);
		u4_puts(/*D_2BC2*/" says: I do not need thy gold.  Keep it!\n");
		return;
	}
	u4_puts(/*D_2BEC*/"How much?\x12\x12\x12\b\b");
	if((bp_02 = AskInt(2)) > 0) {
		if(Party._gold < bp_02) {
			u4_puts(/*D_2BFB*/"Thou hast not that much gold!\n");
		} else {
			Party._gold -= bp_02;
			dspl_Stats();
			u4_puts(D_8CCE[1]);
			u4_puts(/*D_2C1A*/" says: Oh, Thank thee! I shall never forget thy kindness!\n");
			if((Party._moves >> 4) != Party.f_1ec)
				karma_inc(&(Party._compa), 2);
			Party.f_1ec = Party._moves >> 4;
		}
	}
	C_A22D(6, 0);
}

/*parse talk info*/
C_A443(si/*bp04*/)
register char *si;
{
	register char **di;

	for(di = &(D_8CCE[0]); di != &(D_8CCE[12]); ) {
		*(di++) = si;
		while(*(si++));
	}
	u4_tolower(D_8CCE[2][0]);
}

C_A47F(bp04)
char *bp04;
{
	char *bp_02;

	for(bp_02 = strchr(bp04, 0) - 1; bp_02 + 1 != bp04 && *bp_02 == ' '; )
		*(bp_02--) = 0;
}

/*talk to citizen*/
C_A4B4(bp04)
int bp04;
{
	int bp_02, bp_04;

	dlseek(File_TLK, (D_8742._npc._tlkidx[bp04] - 1) * 0x120);
	dread(File_TLK, D_95CE, 0x120);
	bp_04 = Party.f_1d8;
	D_9452 = D_8742._npc._tile[bp04];
	C_A443(D_95CE+3);
	/*personnal question 1 & 2*/
	D_2A90[5]._00 = D_8CCE[10];
	D_2A90[6]._00 = D_8CCE[11];
	C_A47F(D_2A90[5]._00);
	C_A47F(D_2A90[6]._00);
	/* */
	u4_puts(/*D_2C55*/"\nYou meet ");
	C_A22D(3, D_8CCE[2]);
	/*randomly says his name*/
	if(U4_RND1(1)) {
		Gra_CR();
		u4_puts(D_8CCE[1]);
		u4_puts(/*D_2C60*/" says: I am ");
		u4_puts(D_8CCE[0]);
		Gra_CR();
	}
	bp_02 = 0;
	do {
		register int si;
		char bp_12[12];

		u4_puts(/*D_2C6D*/"\nYour Interest:\n");
		u4_gets(bp_12, 11);
		Gra_CR();
		if(bp_12[0] == 0)
			break;
		if((si = u_rand_a()) < D_95CE[2]) {
			if(D_95CE[2] - si >= 0x40) {
				/*he/she gets upset*/
				if(strnicmp(D_8CCE[0], /*D_2C7E*/"a ", 2) && strnicmp(D_8CCE[0], /*D_2C81*/"the ", 4))
					u4_puts(D_8CCE[0]);
				else
					u4_puts(D_8CCE[1]);
				u4_puts(/*D_2C86*/" says: On guard! Fool!\n");
				D_8742._npc._var[bp04] = 0xff;
			} else {
				u4_puts(D_8CCE[1]);
				u4_puts(/*D_2C9E*/" turns away!\n\n");
			}
			return;
		}
		for(si = 0; D_2A90[si]._00[0]; si++) {
			if(strnicmp(D_2A90[si]._00, bp_12, 4) == 0) {
				if(D_2A90[si]._02) {
					Gra_CR();
					D_8CE6 = bp04;
					(*(D_2A90[si]._02))();
					if(Party.f_1d8 != bp_04)
						return;/*looks like he/she has joined*/
				} else {
					bp_02 = 1;
				}
				if(!bp_02) {
					if(D_95CE[0] == si)
						C_A163();
				}
				break;
			}
		}
		if(D_2A90[si]._00[0] == 0)
			u4_puts(/*D_2CAD*/"That I cannot help thee with.\n");
	} while(bp_02 == 0);
	u4_puts(/*D_2CCC*/"\nBye.\n");
}

/*shops'y positions by town*/
unsigned char D_2CD4[][8] = {
	{0x00,0x00,0x00,0x00,0x00,0x1A,0x00,0x00},/*LB*/

	{0x00,0x00,0x00,0x00,0x00,0x0C,0x00,0x00},/*lycaeum*/
	{0x00,0x00,0x00,0x00,0x00,0x0F,0x00,0x00},/*empath*/
	{0x00,0x00,0x00,0x00,0x00,0x0C,0x00,0x00},/*serpent*/

	{0x00,0x00,0x0E,0x00,0x1A,0x1B,0x02,0x00},/*MOONGLOW*/
	{0x03,0x07,0x06,0x02,0x00,0x1D,0x0C,0x00},/*BRITAIN*/
	{0x09,0x05,0x00,0x13,0x00,0x06,0x1A,0x00},/*JHELOM*/
	{0x00,0x00,0x18,0x00,0x00,0x19,0x00,0x00},/*YEW.ULT*/
	{0x1C,0x00,0x00,0x00,0x00,0x00,0x03,0x00},/*MINOC*/
	{0x14,0x18,0x00,0x02,0x00,0x00,0x03,0x00},/*TRINSIC*/
	{0x00,0x00,0x11,0x00,0x04,0x1B,0x0D,0x00},/*SKARA*/
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*MAGINCIA*/

	{0x00,0x04,0x1A,0x05,0x07,0x00,0x00,0x00},/*paws*/
	{0x0B,0x11,0x00,0x19,0x08,0x00,0x00,0x07},/*den*/
	{0x14,0x00,0x00,0x16,0x00,0x00,0x15,0x1A},/*vesper*/
	{0x00,0x00,0x00,0x00,0x00,0x1A,0x00,0x00} /*cove*/
};

extern SHP_weapon();
extern SHP_armor();
extern SHP_food();
extern SHP_pub();
extern SHP_reagent();
extern SHP_healer();
extern SHP_inn();
extern SHP_guild();
extern SHP_horse();
extern SHP_hawkwind();

/*shops functions callbacks*/
pHandler_tlk D_2D54[] = {
	SHP_weapon,
	SHP_armor,
	SHP_food,
	SHP_pub,
	SHP_reagent,
	SHP_healer,
	SHP_inn,
	SHP_guild,

	SHP_horse,
	SHP_hawkwind
};

/*shop at Y*/
C_A686(bp04)
unsigned char bp04;
{
	register int si;

	for(si = 7; si >= 0;si--) {
		if(D_2CD4[Party._loc - 1][si] == bp04)
			break;
	}
	if(si == -1 && bp04 == 0x18 && Party._loc == 0x0d)
		si = 8;/*patch! paws' horses*/
	if(si == -1 && bp04 == 0x19 && Party._loc == 0x01)
		si = 9;/*patch! LB's hawkwind*/
	if(si == -1) {
		u4_puts(D_2A7A);
		return;
	}
	(*(D_2D54[si]))();
}

/*C_A6F3*/CMD_Talk() {
	unsigned char loc_A, loc_E;
	int loc_B, loc_C, loc_D;

	u4_puts(/*D_2D68*/"Talk\n");
	if(Party.f_1dc != 0) {
		w_DriftOnly();
		return;
	}
	AskDir(/*D_2D6E*/"Dir: ", &loc_B, &loc_D);
	if(!(loc_B | loc_D))
		return;
	loc_E = Party._x + loc_B;
	loc_A = Party._y + loc_D;
	loc_C = C_0A8B(loc_E, loc_A);
	if(loc_E > 31 || loc_A > 31 || Party._loc == 0) {
		u4_puts(D_2A7A);
		return;
	}
	if(
		D_8742._map.x32x32[loc_A][loc_E] >= TIL_60 &&
		D_8742._map.x32x32[loc_A][loc_E] <= TIL_7E
	) {/*alphabet*/
		loc_E += loc_B;
		loc_A += loc_D;
		if(loc_E > 31 || loc_A > 31) {
			u4_puts(D_2A7A);
			return;
		}
		if((loc_C = C_0A8B(loc_E, loc_A)) == -1 || D_8742._npc._tile[loc_C] != TIL_52) {
			u4_puts(D_2A7A);
			return;
		}
		C_A686(loc_A - loc_D);
		return;
	}
	if(loc_C == -1 || D_8742._npc._tlkidx[loc_C] == 0) {
		u4_puts(D_2A7A);
		return;
	}
	if(D_8742._npc._tile[loc_C] == TIL_5E) {
		C_E59B();
		return;
	}
	C_A4B4(loc_C);
}
