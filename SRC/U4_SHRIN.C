/*
 * Ultima IV - Quest Of The Avatar
 * (c) Copyright 1987 Lord British
 * reverse-coded by Ergonomy Joe in 2012
 */

#include "u4.h"

#include <string.h>
#include <stdlib.h>

/*---- mantras*/
char *D_8322[] = {
	/*D_7B62*/"ahm",
	/*D_7B66*/"mu",
	/*D_7B69*/"ra",
	/*D_7B6C*/"beh",
	/*D_7B70*/"cah",
	/*D_7B74*/"summ",
	/*D_7B79*/"om",
	/*D_7B7C*/"lum"
};
/*---- visions*/
char *D_8332[][3] = {
	{
		/*D_7B80*/"Take not the gold of others found in towns and castles for yours it is not!\n",
		/*D_7BCD*/"Cheat not the merchants and peddlers for tis an evil thing to do!\n",
		/*D_7C10*/"Second, read the Book of Truth at the entrance to the Great Stygian Abyss!\n",
	}, {
		/*D_7C5C*/"Kill not the non-evil beasts of the land, and do not attack the fair people!\n",
		/*D_7CAA*/"Give of thy purse to those who beg and thy deed shall not be forgotten!\n",
		/*D_7CF3*/"Third, light the Candle of Love at the entrance to the Great Stygian Abyss!\n",
	}, {
		/*D_7D40*/"Victories scored over evil creatures help to build a valorous soul!\n",
		/*D_7D85*/"To flee from battle with less than grievous wounds often shows a coward!\n",
		/*D_7DCF*/"First, ring the Bell of Courage at the entrance to the Great Stygian Abyss!\n",
	}, {
		/*D_7E1C*/"To take the gold of others is injustice not soon forgotten. Take only thy due!\n",
		/*D_7E6C*/"Attack not a peaceful citizen for that action deserves strict punishment!\n",
		/*D_7EB7*/"Kill not a non-evil beast for they deserve not death, even if in hunger they attack thee!",
	}, {
		/*D_7F11*/"To give thy last gold piece unto the needy shows good measure of self-sacrifice!\n",
		/*D_7F63*/"For thee to flee and leave thy companions is a self-serving action to be avoided!\n",
		/*D_7FB6*/"To give of thy life's blood so that others may live is a virtue of great praise!\n",
	}, {
		/*D_8008*/"Take not the gold of others for this shall bring dishonor upon thee!\n",
		/*D_804E*/"To strike first a non-evil being is by no means an honorable deed!\n",
		/*D_8092*/"Seek ye to solve the many Quests before thee, and honor shall be a reward!\n",
	}, {
		/*D_80DE*/"Seek ye to know thyself.  Visit the seer often for he can see into thy inner being!\n",
		/*D_8133*/"Meditation leads to enlightenment Seek ye all Wisdom and Knowledge!\n",
		/*D_8178*/"If thou dost seek the White Stone, search ye not under the ground, but in Serpent's Spine!\n",
	}, {
		/*D_81D4*/"Claim not to be that which thou art not.  Humble actions speak well of thee!\n",
		/*D_8222*/"Strive not to wield the Great Force of Evil for its power will overcome thee!\n",
		/*D_8271*/"If thou dost seek the Black Stone, search ye at the Time and Place of the Gate on the darkest of all nights!\n"
	}
};
/*---- visions 2*/
char *D_8362[] = {
	/*D_82DF*/"rune_1",/*I*/
	/*D_82E6*/"rune_2",/*N*/
	/*D_82ED*/"rune_0",/*F*/
	/*D_82F4*/"rune_1",/*I*/
	/*D_82FB*/"rune_2",/*N*/
	/*D_8302*/"rune_1",/*I*/
	/*D_8309*/"rune_3",/*T*/
	/*D_8310*/"rune_4" /*Y*/
};

/*display avatarhood vision I.N.F.I.N.I.T.Y*/
C_E6DF(bp04)
int bp04;
{
	char bp_14[20];

	CurMode = MOD_VISION;
	strcpy(bp_14, D_8362[bp04]);
	strcat(bp_14, (D_943A == 1)?/*D_8317*/".pic":/*D_831C*/".ega");
	Gra_10();
	Gra_16(bp_14, 0, 0);
}

/*enter a shrine*/
C_E72C()
{
	int loc_A, loc_B, loc_C;
	char loc_D[16];
	int loc_E;

	loc_A = Party._loc - 0x19;/*shrine "number"*/
	if(!TST_MSK(Party.mRunes, loc_A)) {
		u4_puts(/*D_8372*/"\nThou dost not bear the rune of entry!  A strange force keeps you out!\n");
C_E755:
		CurMode = MOD_OUTDOORS;
		Party._loc = 0;
		return;
	}
	if(Load(/*D_83BA*/"SHRINE.CON", 11 * 11, Combat._map) == -1)
		exit(3);
	CurMode = MOD_SHRINE;
	u4_puts(/*D_83C5*/"\nYou enter the ancient shrine and sit before the altar...\nUpon what virtue dost thou meditate?\n");
	u4_gets(loc_D, 15);
	Gra_CR();
	u4_puts(/*D_8425*/"\nFor how many\n");
	loc_E = AskLetter(/*D_8434*/"Cycles (0-3)?\x12\x12\b", '0', '3');
	if(loc_E < 0) {
		goto C_E755;
	}
	loc_E -= '0';
	if(loc_E == 0 || strnicmp(loc_D, D_1E98[151 + loc_A], 16)) {
		u4_puts(/*D_8445*/"\nThou art unable to focus thy thoughts on this subject!\n");
		goto C_E755;
	}
	if(Party._moves / 100 == Party.f_1ea) {
		u4_puts(/*D_847E*/"\nThy mind is still weary from thy last Meditation!\n");
		goto C_E755;
	}
	Party.f_1ea = Party._moves / 100;
	u4_puts(/*D_84B2*/"Begin Meditation\n");
	for(loc_B = 0; loc_B < loc_E; loc_B ++) {
		for(loc_C = 0; loc_C < 0x10; loc_C ++) {
			u_delay(1, 0);
			u4_putc('.');
		}
		u_kbflush();
		u4_puts(/*D_84C4*/"\nMantra: ");
		u4_gets(loc_D, 15);
		Gra_CR();
		if(strnicmp(loc_D, D_8322[loc_A], 0x10)) {
			u4_puts(/*D_84CE*/"\nThou art not able to focus thy thoughts with that Mantra!\n");
			karma_dec(&(Party._spiri), 3);
			goto C_E755;
		}
	}
	if(loc_E != 3 || *(pKarmas[loc_A]) != 99) {
		u4_puts(/*D_850A*/"\nThy thoughts are pure. Thou art granted a vision!\n");
		karma_inc(&(Party._spiri), loc_E * 3);
		u_kbflush();
		u_kbread();
		Gra_CR();
		u4_puts(D_8332[loc_A][loc_E - 1]);
	} else {
		u4_puts(/*D_853E*/"\nThou hast achieved partial Avatarhood in the Virtue of\n");
		u4_puts(D_1E98[151 + loc_A]);
		Gra_09(); sound(9, 0xff); Gra_09();
		Gra_CR();
		*(pKarmas[loc_A]) = 0;
		dspl_Stats();
		u_kbflush();
		u_kbread();
		u4_puts(/*D_8577*/"\n\nThou art granted a vision!\n");
		C_E6DF(loc_A);
		u_kbflush();
	}
	u_kbread();
	Gra_CR();
	goto C_E755;
}
