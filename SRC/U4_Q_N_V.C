/*
 * Ultima IV - Quest Of The Avatar
 * (c) Copyright 1987 Lord British
 * reverse-coded by Ergonomy Joe in 2012
 */

#include "u4.h"

#include <string.h>
#include <stdlib.h>

/*C_6F29*/CMD_Quit()
{
	u4_puts(/*D_21A2*/"Quit & Save...\n");
	u4_putl(Party._moves, 1, '0');
	u4_puts(/*D_21B2*/" moves\n");
	if(Party._loc) {
		if(Party._loc < 0x11 || Party._loc > 0x18) {
			u4_puts(/*D_21BA*/"Not Here!\n");
			return;
		}
	}
	if(Save(/*D_21C5*/"PARTY.SAV", sizeof(struct tParty), &Party) == -1)
		exit(3);
	if(Party._loc == 0) {
		if(Save(/*D_21CF*/"MONSTERS.SAV", sizeof(struct tNPC), &(D_8742._npc)) == -1)
			exit(3);
	}
	if(Party._loc < 0x11 || Party._loc > 0x18)
		return;
	if(Save(/*D_21DC*/"MONSTERS.SAV", sizeof(struct tNPC), &(D_8742._npc)) == -1)
		exit(3);
	if(Save(/*D_21E9*/"DNGMAP.SAV", sizeof(tMap8x8x8), &(D_8742._map)) == -1)
		exit(3);
}

char D_21F4[] = ", You must lead!\n";

/*exchange two party members ?*/
C_6FF9(bp06, bp04)
struct tChara *bp06;
struct tChara *bp04;
{
	struct tChara bp_28;
	memcpy(&bp_28, bp06, sizeof(struct tChara));
	memcpy(bp06, bp04, sizeof(struct tChara));
	memcpy(bp04, &bp_28, sizeof(struct tChara));
}

/*C_7034*/CMD_NewOrder()
{
	register struct tChara *loc_A, *loc_B;
	struct tChara loc_E;/*not used*/
	int loc_C, loc_D;

	u4_puts(/*D_2206*/"New Order!\n");
	if((loc_C = AskChara(/*D_2212*/"Exchange #\x12\x12\b")) < 0)
		return;
	loc_A = &(Party.chara[loc_C]);
	if(loc_A == &(Party.chara[0])) {
		u4_puts(Party.chara[0]._name);
		u4_puts(D_21F4);
		return;
	}
	if((loc_D = AskChara(/*D_2220*/"    with #\x12\x12\b")) < 0)
		return;
	loc_B = &(Party.chara[loc_D]);
	if(loc_B == &(Party.chara[0])) {
		u4_puts(Party.chara[0]._name);
		u4_puts(D_21F4);
		return;
	}
	if(loc_A == loc_B) {
		w_What();
		return;
	}
	C_6FF9(loc_A, loc_B);
	Gra_13();
	dspl_Stats();
}

/*C_70AD*/CMD_Volume()
{
	u4_puts(/*D_222E*/"Volume O");
	u4_puts((SoundFlag ^= 1)?/*D_2237*/"n!\n":/*D_223B*/"ff!\n");
}
