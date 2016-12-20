/*
 * Ultima IV - Quest Of The Avatar
 * (c) Copyright 1987 Lord British
 * reverse-coded by Ergonomy Joe in 2012
 */

#include "u4.h"

#include <string.h>

char *D_0BDA[] = {
	/*D_09BE*/"What dost thou possess if all may rely upon your every word?",
	/*D_09FB*/"What quality compels one to share in the journeys of others?",
	/*D_0A38*/"What answers when great deeds are called for?",
	/*D_0A66*/"What should be the same for Lord and Serf alike?",
	/*D_0A97*/"What is loath to place the self above aught else?",
	/*D_0AC9*/"What shirks no duty?",
	/*D_0ADE*/"What, in knowing the true self, knows all?",
	/*D_0B09*/"What is that which Serfs are born with but Nobles must strive to obtain?",
	/*D_0B52*/"If all else is imaginary, this is real...",
	/*D_0B7C*/"What plunges to the depths, while soaring on the heights?",
	/*D_0BB6*/"What turns not away from any peril?"
};

C_2F7E()
{
	u_delay(15, 1);
	if(u_kbhit())
		u_kbread();
}

unsigned char D_0BF0[] = {0xE7,0x53,0x23,0x3B,0x9E,0x69,0x17,0xBA,0xD8,0x1D,0x91,0x59,0xE9};
unsigned char D_0BFE[] = {0x88,0x69,0xDD,0x2C,0x15,0xB7,0x81,0xAC,0x6A,0x30,0xF3,0x6A,0xE9};

static unsigned D_8CCA;

/*return to surface*/
C_2F9D(bp04)
unsigned bp04;
{
	u_delay(5, 0);
	Gra_CR();
	Party._x = D_0BF0[bp04];
	Party._y = D_0BFE[bp04];
	Party.f_1d8 = D_8CCA;
	Party._loc = 0;
	CurMode = MOD_OUTDOORS;
	spell_cnt = 0;
	hit_tile = 0;
	spell_sta = 7;
	D_9440 = 1;
	D_95C6 = 0;
	Party.f_1dc = 0;
	C_26B6();
	dspl_Stats();
	u_kbflush();
	longjmp(D_9458, -1);
}

/*passage is not granted*/
C_3010()
{
	u4_puts(/*D_0C0B*/"\nPassage is not granted.\n");
	C_2F9D(12);
}

/*Victory !*/
C_3025()
{
	u_delay(2, 0);
	shakefx();
	shakefx();
	shakefx();
	shakefx();
	u_delay(3, 0);
	dfree(pShapes);
	Gra_17();
	u_delay(3, 0);
	u4_puts(/*D_0C25*/"\n\nThe boundless knowledge of the Codex of Ultimate Wisdom is revealed unto thee.");
	C_2F7E();
	u4_puts(/*D_0C76*/"\n\nThe voice says: Thou hast proven thyself to be truly good in nature.");
	C_2F7E();
	u4_puts(/*D_0CBD*/"\n\nThou must know that thy quest to become an Avatar is the endless quest of a lifetime.");
	C_2F7E();
	u4_puts(/*D_0D15*/"\n\nAvatarhood is a living gift.  It must always and forever be nurtured to flourish.");
	C_2F7E();
	u4_puts(/*D_0D69*/"\n\nFor if thou dost stray from the paths of virtue, thy way may be lost forever.");
	C_2F7E();
	u4_puts(/*D_0DB9*/"\n\nReturn now unto thine own world. Live there as an example to thy people, as our memory of thy gallant deeds serves us.");
	C_2F7E();
	Gra_10();
	u4_puts(/*D_0E32*/"\n\nAs the sound of the voice trails off, darkness seems to rise around you. There is a moment of intense, wrenching vertigo.");
	C_2F7E();
	Gra_16((D_943A == 1)?/*D_0EAE*/"stoncrcl.pic":/*D_0EBB*/"stoncrcl.ega", 0, 0);
	u4_puts(/*D_0EC8*/"\n\nYou open your eyes to a familiar circle of stones.  You wonder of your recent adventures.");
	C_2F7E();
	u4_puts(/*D_0F24*/"\n\nIt seems a time and place very distant.  You wonder if it really happened. Then you realize that in your hand you hold The Ankh.");
	C_2F7E();
	u4_puts(/*D_0FA7*/"\n\nYou walk away from the circle, knowing that you can always return from whence you came, since you now know the secret of the gates.");
	C_2F7E();
	u4_puts(/*D_102D*/"\n\nCONGRATULATIONS!\n   Thou hast\n   completed\n   ULTIMA IV\n  Quest of the\n    AVATAR\n  in ");
	u4_putl(Party._moves, 0, '0');
	u4_puts(/*D_1087*/"\n turns! Report\n thy feat unto\nLord British at\nOrigin Systems!");
	while(1);
}

C_310F(bp06, bp04)
char *bp06;
char *bp04;
{
	char bp_10[16];

	u4_puts(bp06);
	Gra_CR();
	Gra_CR();
	u4_gets(bp_10, 15);
	Gra_CR();
	if(strnicmp(bp_10, bp04, 15) != 0) {
		u_delay(1, 0);
		u4_puts(/*D_10C6*/"\nThy thoughts are not pure.\nI ask again.\n");
		u_delay(2, 0);

		u4_puts(bp06);
		Gra_CR();
		Gra_CR();
		u4_gets(bp_10, 15);
		Gra_CR();
		if(strnicmp(bp_10, bp04, 15) != 0) {
			u_delay(1, 0);
			u4_puts(/*D_10F0*/"\nThy thoughts are not pure.\nI ask again.\n");
			u_delay(2, 0);

			u4_puts(bp06);
			Gra_CR();
			Gra_CR();
			u4_gets(bp_10, 15);
			Gra_CR();
			if(strnicmp(bp_10, bp04, 15) != 0)
				return 0;
		}
	}
	return 1;
}

char *D_161A[] = {
	/*D_111A*/"truth",
	/*D_1120*/"love",
	/*D_1125*/"courage"
};

char *D_1620[] = {
	/*D_112D*/"honesty",
	/*D_1135*/"compassn",
	/*D_113E*/"valor",
	/*D_1144*/"justice",
	/*D_114C*/"sacrific",
	/*D_1155*/"honor",
	/*D_115B*/"spirit",
	/*D_1162*/"humility"
};

/*last phase of game ?*/
C_31F4()
{
	int bp_02;
	char bp_12[16];

	D_8CCA = Party.f_1d8;
	Party.f_1d8 = 1;
	CurMode = MOD_VISION;
	Gra_13();
	dspl_Stats();
	Gra_10();
	u4_puts(/*D_116B*/"\n\n\nThere is a sudden darkness, and you find yourself alone in an empty chamber.\n");
	u_delay(4, 0);
	Gra_16((D_943A == 1)?/*D_11BC*/"key7.pic":/*D_11C5*/"key7.ega", 0, 0);
	if(
		!TST_MSK(Party.mItems, 5) |
		!TST_MSK(Party.mItems, 7) |
		!TST_MSK(Party.mItems, 6)
	) {
		u4_puts(/*D_11CE*/"\nThou dost not have the Key of Three Parts.\n");
		C_2F9D(12);
	}
	u4_puts(/*D_11FB*/"\nYou use your Key of Three Parts.\n");
	u_delay(3, 0);
	u4_puts(/*D_121E*/"\nA voice rings out:\n");
	if(!C_310F(/*D_123D*/"\"What is the Word of Passage?\"", /*D_1233*/"veramocor"))
		C_3010();
	if(D_8CCA != 8) {
		u4_puts(/*D_125C*/"\nThou hast not proved thy leadership in all eight virtues.\n");
		u_delay(8, 0);
		C_3010();
	}
	for(bp_02 = 7; bp_02 >= 0; bp_02 --) {
		if(*(pKarmas[bp_02])) {
			u4_puts(/*D_1298*/"\nThou art not ready.\n");
			C_3010();
		}
	}
	u4_puts(/*D_12AE*/"\nPassage is granted.\n");
	u_delay(5, 0);
	Gra_10();
	for(bp_02 = 0; bp_02 < 11; bp_02 ++) {
		char bp_26[20];

		u_delay(2, 0);
		u4_puts(/*D_12C4*/"\n\nThe voice asks:\n\n");
		u_delay(2, 0);
		if(!C_310F(D_0BDA[bp_02], (bp_02<=7)?D_1E98[151 + bp_02]:D_161A[bp_02-8])) {
			u_delay(1, 0);
			u4_puts(/*D_12D8*/"\nThy quest is not yet complete.\n");
			C_2F9D(bp_02);
		}
		strcpy(bp_26, (bp_02 >= 8)?D_161A[bp_02-8]:D_1620[bp_02]);
		strcat(bp_26, (D_943A == 1)?/*D_12F9*/".pic":/*D_12FE*/".ega");
		Gra_16(bp_26, 0, 0);
		if(bp_02 == 7) {
			u_delay(3, 0);
			u4_puts(/*D_1303*/"\nThou art well versed in the virtues of the Avatar.\n");
			u_delay(5, 0);
		}
	}
	u4_puts(/*D_1338*/"\n\nThe floor rumbles beneath your feet.\n");
	shakefx();
	shakefx();
	u_delay(5, 0);
	u4_puts(/*D_1360*/"\nAbove the din, the voice asks:\n\nIf all eight virtues of the Avatar combine into and are derived from the Three Principles of Truth, Love and Courage...");
	C_2F7E();
	u4_puts(/*D_13F9*/"\n\nThen what is the one thing which encompasses and is the whole of all undeniable Truth, unending Love, and unyielding Courage?\n\n");
	u4_gets(bp_12, 15);
	Gra_CR();
	if(strnicmp(bp_12, /*D_147B*/"infinity", 16) != 0) {
		u4_puts(/*D_1484*/"\nThy thoughts are not pure.\nI ask again.\n");
		u_delay(3, 0);
		u4_puts(/*D_14AE*/"\n\nWhat is the one thing which encompasses and is the whole of all undeniable Truth, unending Love, and unyielding Courage?\n\n");
		u4_gets(bp_12, 15);
		Gra_CR();
		if(strnicmp(bp_12, /*D_152B*/"infinity", 16) != 0) {
			u4_puts(/*D_1534*/"\nThy thoughts are not pure.\nI ask again.\n");
			u_delay(3, 0);
			u4_puts(/*D_155E*/"\n\nWhat is the one thing which encompasses and is the whole of all undeniable Truth, unending Love, and unyielding Courage?\n\n");
			u4_gets(bp_12, 15);
			Gra_CR();
			if(strnicmp(bp_12, /*D_15DB*/"infinity", 16) != 0) {
				u_delay(1, 0);
				u4_puts(/*D_15E4*/"\nThou dost not know the true nature of the Universe.\n");
				C_2F9D(11);
			}
		}
	}
	C_3025();
}
