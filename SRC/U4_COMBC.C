/*
 * Ultima IV - Quest Of The Avatar
 * (c) Copyright 1987 Lord British
 * reverse-coded by Ergonomy Joe in 2012
 */

#include "u4.h"

#include <string.h>
#include <stdlib.h>

/*----------------------------------------

----------------------------------------*/

/*base for enemy HP/XP/attack*/
unsigned char D_23D2[] = {
	/*80~8f*/
	0xFF,/*pirate*/
	0xFF,/*pirate*/
	0x40,/*nixie*/
	0x60,/*squid*/
	0x80,/*serpent*/
	0x60,/*seahorse*/
	0xFF,/*whirlpool*/
	0xFF,/*twister*/
	/*90~AF*/
	0x30,/*rat*/
	0x30,/*bat*/
	0x40,/*spider*/
	0x50,/*ghost*/
	0x30,/*slime*/
	0x60,/*troll*/
	0x30,/*gremlin*/
	0xC0,/*mimic*/
	0xFF,/*reaper*/
	0x30,/*insects*/
	0xF0,/*gazer*/
	0x80,/*phantom*/
	0x50,/*orc*/
	0x30,/*skeleton*/
	0x50,/*rogue*/
	0x30,/*python*/
	0x70,/*ettin*/
	0x40,/*headless*/
	0x80,/*cyclops*/
	0x40,/*wisp*/
	0xB0,/*mage*/
	0xC0,/*lyche*/
	0x60,/*lava lizard*/
	0xF0,/*zorn*/
	0x70,/*daemon*/
	0xD0,/*hydra*/
	0xE0,/*dragon*/
	0xFF,/*balron*/
	/*20~2f[buggy]*/
	0x70,/*mage*/
	0x30,/*bard*/
	0x60,/*fighter*/
	0x40,/*druid*/
	0x60,/*tinker*/
	0x80,/*paladin*/
	0x90,/*ranger*/
	0x30,/*shepherd*/
	/*50~5f[buggy]*/
	0x80,/*guard*/
	0x30,/*merchant*/
	0x30,/*bard*/
	0x30,/*jester*/
	0x20,/*beggar/sleep*/
	0x20,/*child*/
	0x80,/*bull*/
	0xFF /*lord british*/
};

/*enemy tile "partners"*/
unsigned char D_2406[] = {
	/*80~8f*/
	TIL_C8,/*pirate->rogue*/
	TIL_C8,/*pirate->rogue*/
	TIL_8A,/*nixie->seahorse*/
	TIL_88,/*squid->serpent*/
	TIL_86,/*serpent->squid*/
	TIL_84,/*seahorse->nixie*/
	TIL_8C,/*whirlpool->whirlpool*/
	TIL_8E,/*twister->twister*/
	/*90~AF*/
	TIL_C4,/*rat->skeleton*/
	TIL_E9,/*bat->lava lizard*/
	TIL_90,/*spider->rat*/
	TIL_E4,/*ghost->lyche*/
	TIL_A0,/*slime->slime*/
	TIL_D0,/*troll->ettin*/
	TIL_A8,/*gremlin->gremlin*/
	TIL_AC,/*mimic->mimic*/
	TIL_B0,/*reaper->reaper*/
	TIL_90,/*insects->rat*/
	TIL_BC,/*gazer->phantom*/
	TIL_9C,/*phantom->ghost*/
	TIL_A4,/*orc->troll*/
	TIL_E0,/*skeleton->mage*/
	TIL_C8,/*rogue->rogue*/
	TIL_90,/*python->rat*/
	TIL_F0,/*ettin->daemon*/
	TIL_B8,/*headless->gazer*/
	TIL_EC,/*cyclops->zorn*/
	TIL_BC,/*wisp->phantom*/
	TIL_F0,/*mage->daemon*/
	TIL_F0,/*lyche->daemon*/
	TIL_F4,/*lava lizard->hydra*/
	TIL_B8,/*zorn->gazer*/
	TIL_FC,/*daemon->balron*/
	TIL_F8,/*hydra->dragon*/
	TIL_FC,/*dragon->balron*/
	TIL_FC /*balron->balron*/
};

/*enemy number*/
unsigned char D_242A[] = {
	/*80~8F*/
	 1,/*pirate*/
	 1,/*pirate*/
	12,/*nixie*/
	 4,/*squid*/
	 4,/*serpent*/
	 8,/*seahorse*/
	 1,/*whirlpool*/
	 1,/*twister*/
	/*90~AF*/
	12,/*rat*/
	12,/*bat*/
	 6,/*spider*/
	 4,/*ghost*/
	15,/*slime*/
	 6,/*troll*/
	15,/*gremlin*/
	 1,/*mimic*/
	 1,/*reaper*/
	15,/*insects*/
	 4,/*gazer*/
	 8,/*phantom*/
	10,/*orc*/
	12,/*skeleton*/
	10,/*rogue*/
	12,/*python*/
	 6,/*ettin*/
	 8,/*headless*/
	 6,/*cyclops*/
	12,/*wisp*/
	 6,/*mage*/
	 4,/*lyche*/
	 8,/*lava lizard*/
	 4,/*zorn*/
	 6,/*daemon*/
	 4,/*hydra*/
	 4,/*dragon*/
	 1,/*balron*/
	/* */
/*__244e*/0, 0/*padding?*/
};

/*weapons damage*/
unsigned char D_2450[] = {0x08,0x10,0x18,0x20,0x28,0x30,0x40,0x28,0x38,0x40,0x60,0x60,0x80,0x50,0xA0,0xFF};

unsigned char D_2460[] = {0x60,0x80,0x90,0xA0,0xB0,0xC0,0xD0,0xF8};
/*range weapons flag*/
unsigned char D_2468[] = {0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0xFF,0xFF,0xFF,0x00,0xFF,0x00,0xFF,0xFF,0x00};

C_7C25(bp04)
unsigned char bp04;
{
	if(bp04 >= TIL_80) {
		bp04 &= 0x7f;
		if((bp04 >> 1) < 8)
			return bp04 >> 1;
		return (bp04 >> 2) + 4;
	}
	/* not monster */
#ifdef WIN32
	return ((bp04&0x1f) >> 1) + 0x24;
#else
	/*this looks like an original bug:
	the values from D_23D2 are not
	correctly indexed.
	Without the patch the index will go
	out-of-bound and access unrelated values
	from D_2406. Hence, except for the mage
	ans the fighter, all the non-monster
	livings will get faulty values.
	On the original environement:
	  mage         0x70 should be 0x70
	  bard         0x60 should be 0x30
	  fighter      0x60 should be 0x60
	  druid        0x90 should be 0x40
	  tinker       0x80 should be 0x60
	  paladin      0x30 should be 0x80
	  ranger       0x20 should be 0x90
	  shepherd     0x80 should be 0x30
	  guard        0xC8 should be 0x80
	  merchant     0x8A should be 0x30
	  bard         0x86 should be 0x30
	  jester       0x8C should be 0x30
	  beggar/sleep 0xC4 should be 0x20
	  child        0x90 should be 0x20
	  bull         0xA0 should be 0x80
	  lord british 0xA8 should be 0xFF

	  because of different padding/alignement
	  policies, we may get different values
	  with another compiler.
	 (issue raised by @plaidpants,
	 with cooperation from @Fenyx4)
	*/
	return (bp04&0x1f) + 0x24;
#endif
}

char *D_2512[] = {
	/*D_2478*//* 0*/"GRASS.CON",
	/*D_2482*//* 1*/"BRIDGE.CON",
	/*D_248D*//* 2*/"BRICK.CON",
	/*D_2497*//* 3*/"DUNGEON.CON",
	/*D_24A3*//* 4*/"HILL.CON",
	/*D_24AC*//* 5*/"FOREST.CON",
	/*D_24B7*//* 6*/"BRUSH.CON",
	/*D_24C1*//* 7*/"MARSH.CON",
	/*D_24CB*//* 8*/"SHIPSEA.CON",
	/*D_24D7*//* 9*/"SHIPSHOR.CON",
	/*D_24E4*//*10*/"SHORE.CON",
	/*D_24EE*//*11*/"SHIPSHIP.CON",
	/*D_24FB*//*12*/"SHORSHIP.CON",
	/*D_2508*//*13*/"CAMP.CON"
};

/*load CON file*/
C_7C65()
{
	register int si;

	if(Party._tile <= TIL_13 || (tile_cur & ~3) == TIL_10) {
		if(D_96F8 == TIL_80) {
			D_9452 = TIL_C8;
			si = 11;
		} else if(D_946C < TIL_03) {
			si = 8;
		} else {
			si = 9;
		}
	} else {
		if(D_96F8 == TIL_80) {
			D_9452 = TIL_C8;
			si = 12;
		} else if(D_946C < TIL_03) {
			si = 10;
		} else {
			switch(tile_cur) {
				case TIL_03: si = 7; break;
				case TIL_05: si = 6; break;
				case TIL_06: si = 5; break;
				case TIL_07: si = 4; break;
				case TIL_09: si = 3; break;
				case TIL_3E: si = 2; break;
				case TIL_17:
				case TIL_19:
				case TIL_1A:
				case TIL_3F: si = 1; break;
				default: si = 0;
			}
		}
	}
#ifdef WIN32
	if(Load(D_2512[si], sizeof(struct tCombat), &Combat) == -1)
#else
	if(Load(D_2512[si], (char *)&Fighters - (char *)&Combat, &Combat) == -1)
#endif
		exit(3);
}

int D_256E[] = {0,1,2,3,4,0,0,0,0,0,0,0,5,0,6,0};

char *D_258E[] = {
	/*D_252E*/"DNG0.CON",
	/*D_2537*/"DNG1.CON",
	/*D_2540*/"DNG2.CON",
	/*D_2549*/"DNG3.CON",
	/*D_2552*/"DNG4.CON",
	/*D_255B*/"DNG5.CON",
	/*D_2564*/"DNG6.CON"
};

/*load dungeon CON file*/
C_7D50()
{
#ifdef WIN32
	if(Load(D_258E[D_256E[tile_cur>>4]], sizeof(struct tCombat), &Combat) == -1)
#else
	if(Load(D_258E[D_256E[tile_cur>>4]], (char *)&Fighters - (char *)&Combat, &Combat) == -1)
#endif
		exit(3);
	C_7FD7();
	D_9446 = 1;	/*force 3d render*/
}

/*load inn CON file*/
C_7D92()
{
#ifdef WIN32
	if(Load(/*D_259C*/"INN.CON", sizeof(struct tCombat), &Combat) == -1)
#else
	if(Load(/*D_259C*/"INN.CON", (char *)&Fighters - (char *)&Combat, &Combat) == -1)
#endif
		exit(3);
	C_7FD7();
}

/*start a combat bis ?*/
C_7DBC()
{
	register int si;

	u4_puts(/*D_25A4*/"\n\n**** Combat ****\n\n");
	D_9452 = D_96F8;
	for(si = 15; si >= 0; si --) {
		Fighters._tile[si] = 
		Fighters._x[si] = 
		Fighters._y[si] = 
		Fighters._sleeping[si] = 0;
	}
	for(si = 7; si >= 0; si --)
		Fighters._chtile[si] = 0;
	C_7C65();
	C_7FD7();
}

/*start a combat ?*/
C_7DFE(si/*bp04*/)
register unsigned si;
{
	D_96F8 = D_8742._npc._tile[si];
	D_9772 = D_8742._npc._x[si];
	D_9140 = D_8742._npc._y[si];
	if(Party._loc == 0x00) {
		D_946C = D_8742._map.x32x32[(D_9140 - (D_95A5.y<<4))][(D_9772 - (D_95A5.x<<4))];
	} else {
		D_946C = D_8742._map.x32x32[D_9140][D_9772];
	}
	D_8742._npc._var[si] =
	D_8742._npc._gtile[si] =
	D_8742._npc._tile[si] = 0;
	C_7DBC();
}

/*init fighters info?*/
C_7E7E()
{
	register int loc_A, loc_D;
	int loc_B, loc_C;
	unsigned loc_E;

	for(loc_D = 15; loc_D >= 0; loc_D --)
		Fighters._tile[loc_D] = 0;
	if(D_95CC == MOD_BUILDING && CurMode != MOD_COM_CAMP) {
		if(D_96F8 == TIL_50)
			loc_A = Party.f_1d8 * 2 - 1;
		else
			loc_A = 0;
	} else if((loc_A = D_9452, D_9452 < TIL_80) || (loc_A = U4_RND1(7)) == 0) {
		loc_A = (U4_RND4(D_242A[C_7C25(loc_A)]) + D_242A[C_7C25(loc_A)]) / 2;
	}
	while(loc_D = loc_A, (loc_A >> 1) >= Party.f_1d8)
		loc_A = U4_RND4(Party.f_1d8 * 2);
	for(loc_B = loc_D; loc_B >= 0; loc_B--) {
		do {
			loc_D = U4_RND1(15);
		} while(Fighters._tile[loc_D]);
		loc_E = D_9452;
		/* add some "partners" */
		if(D_9452 > TIL_80 && loc_B) {
			if(U4_RND1(31) == 0) {
				loc_E = D_2406[C_7C25(D_2406[C_7C25(D_9452)])];
			} else if(U4_RND1(7) == 0) {
				loc_E = D_2406[C_7C25(D_9452)];
			}
		}
		/* */
		Fighters._tile[loc_D] = Fighters._gtile[loc_D] = loc_E;
		loc_C = D_23D2[C_7C25(loc_E)];
		Fighters._HP[loc_D] = (loc_C >> 1) | U4_RND4(loc_C);
	}
	for(loc_D = Party.f_1d8 - 1; loc_D >= 0; loc_D --) {
		if(!isCharaAlive(loc_D))
			Fighters._chtile[loc_D] = 0;
		else
			D_944A[loc_D] = Fighters._chtile[loc_D] = C_0ACF(loc_D);
	}
}

C_7FD7()
{
	if(CurMode != MOD_COM_CAMP) {
		D_95CC = CurMode;
		CurMode = MOD_COMBAT;
	}
	C_7E7E();
	COM_main();
	CurMode = D_95CC;
}

/*enter dungeon room?*/
C_7FFD()
{
	struct /*dungeon room info*/ {
		/*secret tiles info*/
		unsigned char _000[16];
		/*enemies*/
		unsigned char _010[16];/*tile*/
		unsigned char _020[16],_030[16];/*pos*/
		/*charas positions*/
		unsigned char _040[8],_048[8];/*pos.dir 0*/
		unsigned char _050[8],_058[8];/*pos.dir 1*/
		unsigned char _060[8],_068[8];/*pos.dir 2*/
		unsigned char _070[8],_078[8];/*pos.dir 3*/
		/*room map*/
		unsigned char _080[0x80];
	} loc_A;
	register int loc_B, loc_C;

	dlseek(File_DNG, sizeof(tMap8x8x8) + (Party._loc == 0x18?
		((Party._z >> 1) * 0x1000) + ((tile_cur & 0xf) * 0x100):
		((tile_cur & 0xf) * 0x100)
	));
	dread(File_DNG, &loc_A, 0x100);
	D_95CC = MOD_DUNGEON;
	CurMode = MOD_COM_ROOM;
	memcpy(D_95B2, loc_A._000, 16);
	D_943E = -1;
	if((tile_cur & 0xf) == 0xf && Party._loc < 0x18) {
		u4_puts(/*D_25B9*/"\nThe Altar Room of ");
		if(Party._x == 3) {
			u4_puts(/*D_25CD*/"Love\n");
			D_943E = 1;
		} else if(Party._x <= 2) {
			u4_puts(/*D_25D3*/"Truth\n");
			D_943E = 0;
		} else {
			u4_puts(/*D_25DA*/"Courage\n");
			D_943E = 2;
		}
	}
	switch(((Party._dir - 1) ^ 2) & 3) {
		case 2:
			for(loc_B = 7; loc_B >= 0; loc_B --) {
				Combat._charaX[loc_B] = loc_A._060[loc_B];
				Combat._charaY[loc_B] = loc_A._068[loc_B];
			}
		break;
		case 0:
			for(loc_B = 7; loc_B >= 0; loc_B --) {
				Combat._charaX[loc_B] = loc_A._040[loc_B];
				Combat._charaY[loc_B] = loc_A._048[loc_B];
			}
		break;
		case 3:
			for(loc_B = 7; loc_B >= 0; loc_B --) {
				Combat._charaX[loc_B] = loc_A._070[loc_B];
				Combat._charaY[loc_B] = loc_A._078[loc_B];
			}
		break;
		case 1:
			for(loc_B = 7; loc_B >= 0; loc_B --) {
				Combat._charaX[loc_B] = loc_A._050[loc_B];
				Combat._charaY[loc_B] = loc_A._058[loc_B];
			}
		break;
	}
	for(loc_B = Party.f_1d8; --loc_B >= 0; ) {
		if(isCharaAlive(loc_B)) {
			D_944A[loc_B] = Fighters._chtile[loc_B] = C_0ACF(loc_B);
		} else {
			Fighters._chtile[loc_B] = 0;
		}
	}
	for(loc_B = 15; loc_B >= 0; loc_B--) {
/*C_817D*/
		if(loc_A._010/*bug?*/) {
		/*shouldn't be "if(loc_A._010[loc_B]) {" ?*/
			Combat._npcX[loc_B] = loc_A._020[loc_B];
			Combat._npcY[loc_B] = loc_A._030[loc_B];
			Fighters._tile[loc_B] = Fighters._gtile[loc_B] = loc_A._010[loc_B];
			loc_C = D_23D2[C_7C25(loc_A._010[loc_B])];
			Fighters._HP[loc_B] = (loc_C >> 1) | U4_RND4(loc_C);
			if(Fighters._tile[loc_B] == (char)TIL_AC)
				Fighters._gtile[loc_B] = TIL_3C;
		}
	}
	for(loc_B = 10; loc_B >= 0; loc_B--)
		for(loc_C = 10; loc_C >= 0; loc_C --)
			Combat._map[loc_B*11+loc_C] = loc_A._080[loc_B*11+loc_C];
	COM_main();
	CurMode = D_95CC;
}

C_8214()
{
	if(D_95CC == MOD_DUNGEON)
		C_AE41();
	u_kbflush();
}

C_8228()
{
	register int si;

	for(si = 31; /*bug?*/si >= (D_95CC == MOD_OUTDOORS)?8:0; si--) {
		if(!D_8742._npc._tile[si])
			break;
	}
	if(si == -1 || (si == 7 && D_95CC == MOD_OUTDOORS))
		si = U4_RND3(24) + 8;

	return si;
}

C_8283()
{
	register int si;

	si = D_96F8;
	if(si == TIL_80) {
		/*pirate ship becomes player ship*/
		si = C_8228();
		D_8742._npc._x[si] = D_9772;
		D_8742._npc._y[si] = D_9140;
		D_8742._npc._tile[si] = D_8742._npc._gtile[si] = TIL_10;
	} else
	if(D_95CC == MOD_DUNGEON) {
		/*monster leaves chest?*/
		if(si != TIL_94 && si != TIL_B4 && si != TIL_A0) {
			if(D_8742._map.x8x8x8[Party._z][Party._y][Party._x] == 0)
				D_8742._map.x8x8x8[Party._z][Party._y][Party._x] = 0x40;
		}
	} else
	if(D_95CC != MOD_COM_CAMP || tile_cur < TIL_10 || tile_cur > TIL_13) {
		/*monster leaves chest?*/
		if(
			si >= TIL_90 ||
			(si >= TIL_20 && si <= TIL_2E) ||
			(si >= TIL_50 && si <= TIL_5E)
		) {
			if(si != TIL_94 && si != TIL_A0 && si != TIL_B8 && si != TIL_B4 && si != TIL_DC) {
				if(C_2999(D_946C)) {
					si = C_8228();
					D_8742._npc._x[si] = D_9772;
					D_8742._npc._y[si] = D_9140;
					D_8742._npc._tile[si] = D_8742._npc._gtile[si] = TIL_3C;
				}
			}
		}
	}
	C_8214();
}

/*altar rooms/dungeons connection
	0x11 - deceit   - truth
	0x12 - despise  - love
	0x13 - destard  - courage
	0x14 - wrong    - truth love
	0x15 - covetous - love courage
	0x16 - shame    - truth courage
	0x17 - hythloth - truth love courage*/
unsigned char D_261A[][4] = {
	{0x11,0x16,0x17,0x14},/*truth*/
	{0x12,0x14,0x17,0x15},/*love*/
	{0x13,0x15,0x17,0x16} /*courage*/
};

C_837A()
{
	register int si;

	for(si = 7; ; si --)
		if(si < 0 || Fighters._chtile[si] != 0)
			break;

	if(si == -1 || CurMode == MOD_COM_ROOM) {
		if(CurMode != MOD_COM_ROOM) {
			if(C_0AFE(D_96F8)) {
				karma_inc(&(Party._compa), 2);
				karma_inc(&(Party._justi), 2);
			} else {
/*C_83CE:*/
				u4_puts(/*D_25E3*/"Battle is lost!\n");
				karma_dec(&(Party._valor), 2);
			}
			C_8214();
			return;
		}
/*C_83E6:*/
		u4_puts(/*D_25F4*/"Leave Room!\n");
		if(D_96EE == 0) {
			if(D_96F4 < 0)
				Party._dir = DIR_N;
			else
				Party._dir = DIR_S;
		} else {
			if(D_96EE < 0)
				Party._dir = DIR_W;
			else
				Party._dir = DIR_E;
		}
		if(D_943E != -1) {
			Party._loc = D_261A[D_943E][(Party._dir - 1) & 3];
			Party.out_x = D_0844[Party._loc - 1];
			Party.out_y = D_0864[Party._loc - 1];
			u4_puts(/*D_2601*/"into Dungeon\n");
			u4_puts(D_1E98[127 + Party._loc - 1]);
			dclose(File_DNG);
			File_DNG = 0;
			C_3E94();
		}
		Gra_CR();
		u_kbflush();
		Party._x = DNG_X_p(Party._x, Party._dir);
		Party._y = DNG_Y_p(Party._y, Party._dir);
		return;
	}
/*C_849E:*/
	u4_puts(/*D_260F*/"\nVictory!\n");
	if(!C_0AFE(D_96F8))
		karma_inc(&(Party._valor), U4_RND1(1));
	if(D_95CC != MOD_COM_CAMP)
		C_8283();
}
