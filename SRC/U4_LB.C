/*
 * Ultima IV - Quest Of The Avatar
 * (c) Copyright 1987 Lord British
 * reverse-coded by Ergonomy Joe in 2012
 */

#include "u4.h"

#include <string.h>

char *D_6FF0[28] = {
	/*D_639A*/"bye",
	/*D_639E*/"help",
	/*D_63A3*/"health",
	/*D_63AA*/"name",
	/*D_63AF*/"look",
	/*D_63B4*/"job",
	/*D_63B8*/"truth",
	/*D_63BE*/"love",
	/*D_63C3*/"courage",
	/*D_63CB*/"honesty",
	/*D_63D3*/"compassion",
	/*D_63DE*/"valor",
	/*D_63E4*/"justice",
	/*D_63EC*/"sacrifice",
	/*D_63F6*/"honor",
	/*D_63FC*/"spirituality",
	/*D_6409*/"humility",
	/*D_6412*/"pride",
	/*D_6418*/"avatar",
	/*D_641F*/"quest",
	/*D_6425*/"britannia",
	/*D_642F*/"ankh",
	/*D_6434*/"abyss",
	/*D_643A*/"mondain",
	/*D_6442*/"minax",
	/*D_6448*/"exodus",
	/*D_644F*/"virtue",
	/*D_6456*/""
};

char *D_7028[24] = {
	/*D_6457*/"\n\n\nHe says:\nMy name is\nLord British,\nSovereign of\nall Britannia!\n",
	/*D_6499*/"\n\n\n\n\nThou see the\nKing with the\nRoyal Sceptre.\n",
	/*D_64C9*/"\n\n\nHe says:\nI rule all\nBritannia, and\nshall do my best\nto help thee!\n",
	/*D_650F*/"He says:\nMany truths can\nbe learned at\nthe Lycaeum.  It\nlies on the\nnorthwestern\nshore of Verity\nIsle!\n",
	/*D_6577*/"He says:\nLook for the\nmeaning of Love\nat Empath Abbey.\nThe Abbey sits\non the western\nedge of the Deep\nForest!\n",
	/*D_65E6*/"\n\nHe says:\nSerpent's Castle\non the Isle of\nDeeds is where\nCourage should\nbe sought!\n",
	/*D_663B*/"\nHe says:\nThe fair towne\nof Moonglow on\nVerity Isle is\nwhere the virtue\nof Honesty\nthrives!\n",
	/*D_6698*/"\n\nHe says:\nThe bards in the\ntowne of Britain\nare well versed\nin the virtue of\nCompassion!\n",
	/*D_66F3*/"\n\nHe says:\nMany valiant\nfighters come\nfrom Jhelom\nin the Valarian\nIsles!\n",
	/*D_673D*/"\n\n\nHe says:\nIn the city of\nYew, in the Deep\nForest, Justice\nis served!\n",
	/*D_6785*/"\nHe says:\nMinoc, towne of\nself-sacrifice,\nlies on the\neastern shores\nof Lost Hope\nBay!\n",
	/*D_67DD*/"\nHe says:\nThe Paladins who\nstrive for Honor\nare oft seen in\nTrinsic, north\nof the Cape of\nHeroes!\n",
	/*D_6840*/"\nHe says:\nIn Skara Brae\nthe Spiritual\npath is taught.\nFind it on an\nisle near\nSpiritwood!\n",
	/*D_689B*/"\n\n\nHe says:\nHumility is the\nfoundation of\nVirtue!  The\nruins of proud\nMagincia are a\ntestimony unto\nthe Virtue of\nHumility!\n\nFind the Ruins\nof Magincia far\noff the shores\nof Britannia,\non a small isle\nin the vast\nOcean!\n",
	/*D_6978*/"\n\n\nHe says:\nOf the eight\ncombinations of\nTruth, Love and\nCourage, that\nwhich contains\nneither Truth,\nLove nor Courage\nis Pride.\n\nPride being not\na Virtue must be\nshunned in favor\nof Humility, the\nVirtue which is\nthe antithesis\nof Pride!\n",
	/*D_6A66*/"\n\n\n\n\n\nLord British\nsays:\nTo be an Avatar\nis to be the\nembodiment of\nthe Eight\nVirtues.\n\n\nIt is to live a\nlife constantly\nand forever in\nthe Quest to\nbetter thyself\nand the world in\nwhich we live.\n",
	/*D_6B2B*/"\n\n\nLord British\nsays:\nThe Quest of\nthe Avatar is\nto know and\nbecome the\nembodiment of\nthe Eight\nVirtues of\nGoodness!\nIt is known that\nall who take on\nthis Quest must\nprove themselves\nby conquering\nthe Abyss and\nViewing the\nCodex of\nUltimate Wisdom!\n",
	/*D_6C25*/"\n\n\n\n\n\n\nHe says:\nEven though the\nGreat Evil Lords\nhave been routed\nevil yet remains\nin Britannia.\n\n\n\n\n\nIf but one soul\ncould complete\nthe Quest of the\nAvatar, our\npeople would\nhave a new hope,\na new goal for\nlife.\n\nThere would be a\nshining example\nthat there is\nmore to life\nthan the endless\nstruggle for\npossessions\nand gold!\n",
	/*D_6D6C*/"He says:\nThe Ankh is the\nsymbol of one\nwho strives for\nVirtue.  Keep it\nwith thee at all\ntimes for by\nthis mark thou\nshalt be known!\n",
	/*D_6DF2*/"\n\n\n\n\n\nHe says:\nThe Great\nStygian Abyss\nis the darkest\npocket of evil\nremaining in\nBritannia!\n\n\n\n\n\n\n\nIt is said that\nin the deepest\nrecesses of the\nAbyss is the\nChamber of the\nCodex!\n\n\nIt is also said\nthat only one of\nhighest Virtue\nmay enter this\nChamber, one\nsuch as an\nAvatar!!!\n",
	/*D_6F0C*/"\n\n\n\n\n\nHe says:\nMondain is dead!\n",
	/*D_6F2D*/"\n\n\n\n\n\nHe says:\nMinax is dead!\n",
	/*D_6F4C*/"\n\n\n\n\n\nHe says:\nExodus is dead!\n",
	/*D_6F6C*/"\nHe says:\nThe Eight\nVirtues of the\nAvatar are:\nHonesty,\nCompassion,\nValor,\nJustice,\nSacrifice,\nHonor,\nSpirituality,\nand Humility!\n"
};

/*10 seconds delay*/
C_E1FC() {
	u_kbflush();
	u_delay(10, 1);
	if(u_kbhit())
		u_kbread();
}

/*when asked 'help'*/
C_E21E() {
	u4_puts(/*D_7058*/"He says: ");
	if(Party._moves < 1000) {
		u4_puts(/*D_7062*/"To survive in this hostile land thou must first know thyself! Seek ye to master thy weapons and thy magical ability!\n"); C_E1FC();
		u4_puts(/*D_70D8*/"\nTake great care in these thy first travels in Britannia.\n"); C_E1FC();
		u4_puts(/*D_7113*/"\nUntil thou dost well know thyself, travel not far from the safety of the townes!\n");
	} else
	if(Party.f_1d8 == 1) {
		u4_puts(/*D_7166*/"Travel not the open lands alone. There are many worthy people in the diverse townes whom it would be wise to ask to Join thee!\n"); C_E1FC();
		u4_puts(/*D_71E6*/"\nBuild thy party unto eight travellers, for only a true leader can win the Quest!\n");
	} else
	if(Party.mRunes == 0) {
		u4_puts(/*D_7239*/"Learn ye the paths of virtue. Seek to gain entry unto the eight shrines!\n"); C_E1FC();
		u4_puts(/*D_7283*/"\nFind ye the Runes, needed for entry into each shrine, and learn each chant or \"Mantra\" used to focus thy meditations.\n"); C_E1FC();
		u4_puts(/*D_72FB*/"\nWithin the Shrines thou shalt learn of the deeds which show thy inner virtue or vice!\n"); C_E1FC();
		u4_puts(/*D_7353*/"\nChoose thy path wisely for all thy deeds of good and evil are remembered and can return to hinder thee!\n");
	} else
	if(
		Party._hones & Party._compa &
		Party._valor & Party._justi &
		Party._sacri & Party._honor &
		Party._spiri & Party._humil
	) {
		u4_puts(/*D_73BD*/"Visit the Seer Hawkwind often and use his wisdom to help thee prove thy virtue.\n"); C_E1FC();
		u4_puts(/*D_740E*/"\nWhen thou art ready, Hawkwind will advise thee to seek the Elevation unto partial Avatarhood in a virtue.\n"); C_E1FC();
		u4_puts(/*D_747A*/"\nSeek ye to become a partial Avatar in all eight virtues, for only then shalt thou be ready to seek the codex!\n");
	} else
	if(Party.mStones == 0) {
		u4_puts(/*D_74EA*/"Go ye now into the depths of the dungeons. Therein recover the 8 colored stones from the altar pedestals in the halls of the dungeons.\n"); C_E1FC();
		u4_puts(/*D_7572*/"\nFind the uses of these stones for they can help thee in the Abyss!\n");
	} else
	if(
		Party._hones | Party._compa |
		Party._valor | Party._justi |
		Party._sacri | Party._honor |
		Party._spiri | Party._humil
	) {
		u4_puts(/*D_75B7*/"Thou art doing very well indeed on the path to Avatarhood! Strive ye to achieve the Elevation in all eight virtues!\n");
	} else
	if(!((Party.mItems >> ST_BELL) & (Party.mItems >> ST_BOOK) & (Party.mItems >> ST_CANDLE) & 1)) {
		u4_puts(/*D_762C*/"Find ye the Bell, Book and Candle!  With these three things, one may enter the Great Stygian Abyss!\n");
	} else
	if(!((Party.mItems >> ST_KEY_C) & (Party.mItems >> ST_KEY_L) & (Party.mItems >> ST_KEY_T) & 1)) {
		u4_puts(/*D_7691*/"Before thou dost enter the Abyss thou shalt need the Key of Three Parts, and the Word of Passage.\n"); C_E1FC();
		u4_puts(/*D_76F4*/"\nThen might thou enter the Chamber of the Codex of Ultimate Wisdom!\n");
	} else {
		u4_puts(/*D_7739*/"Thou dost now seem ready to make the final journey into the dark Abyss! Go only with a party of eight!\n"); C_E1FC();
		u4_puts(/*D_77A1*/"\nGood Luck, and may the powers of good watch over thee on this thy most perilous endeavor!\n"); C_E1FC();
		u4_puts(/*D_77FD*/"\nThe hearts and souls of all Britannia go with thee now. Take care, my friend.\n");
	}
}

/*looks for the parameter in Lord British's keywords
 (4 char is enough)
 not found => -1
 else => index of the keywords*/
C_E37E(bp04)
char *bp04;
{
	int bp_02;

	for(bp_02 = 0; D_6FF0[bp_02][0]; bp_02++) {
		if(strnicmp(bp04, D_6FF0[bp_02], 4) == 0)
			break;
	}
	if(D_6FF0[bp_02][0] == 0)
		return -1;
	return bp_02;
}

C_E3D2(bp04)
register char *bp04;
{
	register int di;

	di = 0;
	while(*bp04) {
		if(*bp04 == '\n') {
			if(di++ == 12) {
				C_E1FC();
				di = 0;
			}
		}
		u4_putc(*bp04);
		bp04++;
	}
}

C_E408() {
	int bp_02;

	for(bp_02 = Party.f_1d8 - 1; bp_02 >= 0; bp_02 --) {
		if(Party.chara[bp_02]._stat != 'D') {
			Party.chara[bp_02]._stat = 'G';
			Party.chara[bp_02]._HP[0] = Party.chara[bp_02]._HP[1];
		}
	}
}

/*when asekd 'health'*/
C_E442() {
	char bp_02;

	u4_puts(/*D_784D*/"\n\n\n\n\n\nHe says: I am well, thank ye.\n\nHe asks: Art thou well?\x12\x12\b");
	bp_02 = AskY_N();
	if(bp_02 == 'Y') {
		u4_puts(/*D_788D*/"\nHe says: That is good.\n");
	} else if(bp_02 =='N') {
		u4_puts(/*D_78A6*/"\nHe says: Let me heal thy wounds!\n");
		/*heal party*/
		sound(10, 10);
		Gra_09(); sound(9, 0xc0); Gra_09();
		C_E408();
		dspl_Stats();
	}
}

C_E498(bp04)
int *bp04;
{
	*bp04 += U4_RND1(7)+1;
	*bp04 = u4_min(*bp04, 50);
}

C_E4C3() {
	int loc_A, loc_B, loc_C;

	for(loc_B = 0; loc_B < Party.f_1d8; loc_B++) {
		for(loc_C = loc_A = 100; loc_A <= Party.chara[loc_B]._XP; loc_C += 100, loc_A <<= 1);
		if(Party.chara[loc_B]._HP[1] < loc_C) {
			Party.chara[loc_B]._HP[1] = loc_C;
			Party.chara[loc_B]._HP[0] = loc_C;
			Party.chara[loc_B]._stat = 'G';
			C_E498(&(Party.chara[loc_B]._str));
			C_E498(&(Party.chara[loc_B]._dex));
			C_E498(&(Party.chara[loc_B]._int));
			Gra_CR();
			u4_puts(Party.chara[loc_B]._name);
			u4_puts(/*D_78C9*/"\nThou art now Level ");
			u4_putl(loc_C / 100, 1, '0');
			Gra_CR();
			Gra_09(); sound(9, 0xc0); Gra_09();
			dspl_Stats();
		}
	}
	u4_puts(/*D_78DE*/"What would thou ask of me?\n");
}

/*conversation with Lord british*/
C_E59B()
{
	int bp_02;
	char bp_12[15];

	if(Party.f_1e4 == 0) {
		/*-- first time --*/
		Party.f_1e4 = 1;
		u4_puts(/*D_78FA*/"\n\n\nLord British rises and says: At long last!\n");
		u4_puts(Party.chara[0]._name);
		u4_putc(',');
		u4_puts(/*D_7929*/" thou hast come!  We have waited such a long, long time...\n\n");
		C_E1FC();
		u4_puts(/*D_7966*/"\n\nLord British sits and says: A new age is upon Britannia. The great evil Lords are gone but our people lack direction and purpose in their lives...\n\n\n\
A champion of virtue is called for. Thou may be this champion, but only time shall tell.  I will aid thee any way that I can!\n");
		u4_puts(/*D_7A7C*/"How may I help thee?\n");
	} else {
		/*-- second time and after --*/
		if(Party.chara[0]._stat == 'D') {
			/*resurection*/
			Party.chara[0]._stat = 'G';
			u4_puts(Party.chara[0]._name);
			u4_puts(/*D_7A92*/", Thou shalt live again!\n");
			/*heal party*/
			sound(10, 20);
			Gra_09(); sound(9, 0xc0); Gra_09();
			C_E408();
			dspl_Stats();
		}
		u4_puts(/*D_7AAC*/"\n\n\nLord British says:  Welcome ");
		u4_puts(Party.chara[0]._name);
		if(Party.f_1d8 >= 3) {
			u4_puts(/*D_7ACC*/" and thy worthy Adventurers!\n");
		} else if(Party.f_1d8 == 2) {
			u4_puts(/*D_7AEA*/" and thee also ");
			u4_puts(Party.chara[1]._name);
			u4_puts(/*D_7AFA*/"!\n");
		} else {
			Gra_CR();
		}
		C_E4C3();
	}

	for(;;) {
		u4_gets(bp_12, 15);
		Gra_CR();
		if(bp_12[0] == 0)
			bp_02 = 0;
		else
			bp_02 = C_E37E(bp_12);
		if(bp_02 == 0)/*"bye"*/
			break;
		switch(bp_02) {
			case 2: C_E442(); break;
			case 1: C_E21E(); break;
			case -1: u4_puts(/*D_7AFD*/"\nHe says: I cannot help thee with that.\n"); break;
			default: C_E3D2(D_7028[bp_02-3]);
		}
		u4_puts(/*D_7B26*/"\nWhat else?\n");
	}

	u4_puts(/*D_7B33*/"Lord British says: Fare thee well my friend");
	if(Party.f_1d8 > 1)
		u4_putc('s');
	u4_puts(/*D_7B5F*/"!\n");
}
