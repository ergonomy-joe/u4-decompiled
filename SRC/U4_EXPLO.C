/*
 * Ultima IV - Quest Of The Avatar
 * (c) Copyright 1987 Lord British
 * reverse-coded by Ergonomy Joe in 2012
 */

#include "u4.h"

#include <stdlib.h>

char *D_1738[] ={
	/*Castles*/
	/*D_1682*/"LCB.TLK",
	/*D_168A*/"LYCAEUM.TLK",
	/*D_1696*/"EMPATH.TLK",
	/*D_16A1*/"SERPENT.TLK",
	/*Townes*/
	/*D_16AD*/"MOONGLOW.TLK",
	/*D_16BA*/"BRITAIN.TLK",
	/*D_16C6*/"JHELOM.TLK",
	/*D_16D1*/"YEW.TLK",
	/*D_16D9*/"MINOC.TLK",
	/*D_16E3*/"TRINSIC.TLK",
	/*D_16EF*/"SKARA.TLK",
	/*D_16F9*/"MAGINCIA.TLK",
	/*Villages*/
	/*D_1706*/"PAWS.TLK",
	/*D_170F*/"DEN.TLK",
	/*D_1717*/"VESPER.TLK",
	/*D_1722*/"COVE.TLK"
};

/*load casle/towne/village files*/
C_3E30(bp04)
unsigned bp04;
{
	if(Save(/*D_172B*/"OUTMONST.SAV", sizeof(struct tNPC), &(D_8742._npc)) == -1)
		exit(3);
	if(Load(D_0824[bp04 - 0x01], sizeof(struct t_500), &D_8742) == -1)
		exit(3);
	File_TLK = dopen(D_1738[Party._loc - 1], 0);
	CurMode = MOD_BUILDING;
}

/*load dungeon files*/
C_3E94()
{
	register int si;

	if(Load(D_0894[Party._loc - 0x11], sizeof(tMap8x8x8), &(D_8742._map)) == -1)
		exit(3);
	File_DNG = dopen(D_0894[Party._loc - 0x11], 0);
	for(si = 0x1f; si >= 0; si --)
		D_8742._npc._tile[si] = 0;
}

C_3EE4()
{
	C_3E94();
	CurMode = MOD_DUNGEON;
	Party._dir = DIR_E;
	Party._z = 0;
	DNG_main();
}

/*enter dungeon*/
C_3F03()
{
	Gra_CR();
	Gra_CR();
	if(Party._tile != TIL_1F) {
		Party._loc = 0;
		w_OnlyOnFoot();
		return;
	}
	Party._x = Party._y = 1;
	if(Save(/*D_1758*/"OUTMONST.SAV", sizeof(struct tNPC), &(D_8742._npc)) == -1)
		exit(3);
	C_3EE4();
}

/*enter towne*/
C_3F4A()
{
	register int si;

	u4_puts(D_1E98[127 + Party._loc - 1]);
	Gra_CR();
	Gra_CR();
	Party._y = D_959C.y = 15;
	Party._x = D_959C.x = 1;
	C_3E30(Party._loc);

	if((Party._loc - 0x05) < 8) {
		for(si = Party.f_1d8; --si >= 1; ) {
			if(Party.chara[si]._class == (Party._loc - 0x05)) {
				D_8742._npc._tile[31] = D_8742._npc._gtile[31] = D_8742._npc._var[31] = 0;
			}
		}
	}
}

/*enter the abyss?*/
C_3FB9()
{
	if((
		(Party.mItems >> 3) &
		(Party.mItems >> 4) &
		(Party.mItems >> 2) &
		(Party.mItems >> 11) &
		(Party.mItems >> 12) &
		(Party.mItems >> 10)
	) & 1) {
		u4_puts(D_1E98[127 + Party._loc - 1]);
		C_3F03();
	} else {
		Party._loc = 0;
		w_Cant_t();
	}
}

/*C_4018*/CMD_Enter()
{
	register int si;

	u4_puts(/*D_1765*/"Enter ");
	if(Party._loc != 0 || Party._tile == TIL_18) {
		w_What();
		return;
	}
	si = 31;
	while(si >= 0) {
#ifdef WIN32
		if(Party._x == (unsigned char)D_0844[si] && Party._y == (unsigned char)D_0864[si])
#else
		if(Party._x == D_0844[si] && Party._y == D_0864[si])
#endif
			break;
		si--;
	}
	if(si == -1) {
		w_What();
		return;
	}
	Party._loc = si + 1;
	Party.out_x = Party._x;
	Party.out_y = Party._y;
	switch(D_8742._map.x32x32[D_959C.y][D_959C.x]) {
		case TIL_09:
			u4_puts(/*D_176C*/"dungeon!\n\n");
			u4_puts(D_1E98[127 + Party._loc - 1]);
			C_3F03();
		break;
		case TIL_0A:
			u4_puts(/*D_1777*/"towne!\n\n");
			C_3F4A();
		break;
		case TIL_0B: case TIL_0E:
			u4_puts(/*D_1780*/"castle!\n\n");
			u4_puts(D_1E98[127 + Party._loc - 1]);
			Gra_CR();
			Gra_CR();
			Party._y = D_959C.y = 0x1e;
			Party._x = D_959C.x = 0x0f;
			Party._z = 0;
			C_3E30(Party._loc);
		break;
		case TIL_0C:
			u4_puts(/*D_178A*/"village!\n\n");
			C_3F4A();
		break;
		case TIL_1D:
			u4_puts(/*D_1795*/"ruin!\n\n");
			C_3F4A();
		break;
		case TIL_4C:
			if(Party._x != 0xe9 || Party._y != 0xe9) {
				w_What();
				return;
			}
		case TIL_46:
			C_3FB9();
		break;
		case TIL_1E:
			u4_puts(/*D_179D*/"the Shrine of\n");
			u4_puts(D_1E98[151 + Party._loc - 0x19]);
			Gra_CR();
			C_E72C();
		break;
		default:
			w_What();
			return;
	}
}

C_4164()
{
	register int si;

	for(si = 31; si >= 8 ;si --) {
		if(D_8742._npc._tile[si] == 0)
			break;
	}
	if(si == 7)
		si = U4_RND1(15) | 0x10;
	D_8742._npc._gtile[si] = D_8742._npc._tile[si] = Party._tile;
	D_8742._npc._x[si] = Party._x;
	D_8742._npc._y[si] = Party._y;
	D_8742._npc._var[si] = D_8742._npc._tlkidx[si] = 0;
	Party._tile = TIL_1F;
	Gra_CR();
}

/*C_41C0*/CMD_X_it()
{
	u4_puts(/*D_17AC*/"X-it ");
	if(Party._tile < TIL_14) {
		ship_x = Party._x;
		ship_y = Party._y;
		C_4164();
	} else if(Party._tile < TIL_16) {
		D_95C6 = 0;
		C_4164();
	} else if(Party._tile == TIL_18 && Party.f_1dc == 0) {
		C_4164();
	} else {
		w_What();
	}
}

C_4206(bp04)
unsigned bp04;
{
	register int si;

	for(si = 31; si >= 8; si --) {
		if(
			Party._x == D_8742._npc._x[si] &&
			Party._y == D_8742._npc._y[si] &&
			bp04 == (D_8742._npc._tile[si] & ~3)
		) break;
	}
	if(si != 7)
		D_8742._npc._gtile[si] = D_8742._npc._tile[si] = 0;
		Party._tile = tile_cur;
}

/*C_4253*/CMD_Board()
{
	if(Party._tile != TIL_1F) {
		u4_puts(/*D_17B2*/"Board: ");
		w_Cant_t();
		return;
	}
	if(tile_cur == TIL_14 || tile_cur == TIL_15) {
		C_4206(TIL_14);
		u4_puts(/*D_17BA*/"Mount Horse!\n");
		return;
	}
	u4_puts(/*D_17C8*/"Board ");
	if(tile_cur == TIL_18) {
		C_4206(TIL_18);
		u4_puts(/*D_17CF*/"Balloon!\n");
		Party.f_1dc = 0;
		return;
	}
	if(tile_cur < TIL_10 || tile_cur > TIL_13) {
		w_What();
		return;
	}
	C_4206(TIL_10);
	u4_puts(/*D_17D9*/"Frigate!\n");
	if(ship_x != Party._x || ship_y != Party._y)
		Party._ship = 50;
}

/*C_42E8*/CMD_Yell()
{
	u4_puts(/*D_17E3*/"Yell ");
	if(Party._tile == TIL_14 || Party._tile == TIL_15) {
		if(D_95C6 ^= 1)
			u4_puts(/*D_17E9*/"Giddyup!\n");
		else
			u4_puts(/*D_17F3*/"Whoa!\n");
	} else {
		w_What();
	}
}

unsigned D_17FA = 0;/*current opened door's x*/
unsigned D_17FC = 0;/*current opened door's y*/
unsigned D_17FE = 0;/*current opened door's delay*/

/*automatic door close*/
C_431D()
{
	if(CurMode == MOD_BUILDING && D_17FE) {
		if(--D_17FE == 0)
			D_8742._map.x32x32[D_17FC][D_17FA] = TIL_3B;
	} else {
		D_17FE = 0;
	}
}

/*C_4353*/CMD_Open()
{
	unsigned bp_02, bp_04;

	while(D_17FE)
		C_431D();
	if(CurMode != MOD_BUILDING) {
		u4_puts(/*D_1800*/"Open; ");
		w_NotHere();
		return;
	}
	AskDir(/*D_1807*/"Open: ", &bp_02, &bp_04);
	if(!(bp_02 | bp_04))
		return;
	if((bp_02 + Party._x) > 0x1f || bp_04) {
		w_NotHere();
	} else {
		register unsigned char *si;

		si = &(D_8742._map.x32x32[Party._y][bp_02 + Party._x]);
		if(*si == TIL_3A) {
			w_Cant_t();
		} else if(*si == TIL_3B) {
			D_17FA = (bp_02 + Party._x);
			D_17FC = Party._y;
			D_17FE = 5;
			*si = TIL_3E;
			u4_puts(/*D_180E*/"\nOpened!\n");
		} else {
			w_NotHere();
		}
	}
}

/*C_43F8*/CMD_Jimmy()
{
	int bp_04, bp_02;

	u4_puts(/*D_1818*/"Jimmy lock!\n");
	AskDir(/*D_1825*/"Dir: ", &bp_02, &bp_04);
	if(!(bp_02 | bp_04))
		return;
	if(CurMode != MOD_BUILDING || (bp_02 + Party._x) > 0x1f || bp_04) {
		w_NotHere();
	} else {
		register unsigned char *si;

		si = &(D_8742._map.x32x32[Party._y][bp_02 + Party._x]);
		if(*si != TIL_3A) {
			w_NotHere();
			return;
		}
		if(Party._keys == 0) {
			u4_puts(/*D_182B*/"No keys left!\n");
			return;
		}
		Party._keys --;
		*si = TIL_3B;
	}
}

/*C_4477*/CMD_Klimb()
{
	u4_puts(/*D_183A*/"Klimb ");
	if(Party._loc == 0) {
		if(Party._tile != TIL_18) {
			w_What();
			return;
		}
		u4_puts(/*D_1841*/"altitude\n");
		Party.f_1dc = 1;
		D_9440 = 0;
		return;
	}
	if(Party._loc == 1 && tile_cur == TIL_1B) {
		if(Party._tile != TIL_1F) {
			Gra_CR();
			w_OnlyOnFoot();
			return;
		}
		u4_puts(/*D_184B*/"to second floor!\n");
		if(Load(/*D_185D*/"LCB_2.ULT", sizeof(struct t_500), &D_8742) == -1)
			exit(3);
	} else {
		w_What();
	}
}

/*C_44EE*/CMD_Descend()
{
	if(Party._tile == TIL_18) {
		u4_puts(/*D_1867*/"Land Balloon\n");
		if(tile_cur != TIL_04) {
			sound(1);
			w_NotHere();
			return;
		}
		if(Party.f_1dc == 0) {
			u4_puts(/*D_1875*/"Already Landed!\n");
			return;
		}
		Party.f_1dc = 0;
		D_9440 = 1;
		return;
	}
	if(Party._loc != 0x01) {
		u4_puts(/*D_1886*/"Descend ");
		w_What();
		return;
	}
	/*in LB's castle*/
	if(Party._tile != TIL_1F) {
		w_OnlyOnFoot();
		return;
	}
	u4_puts(/*D_188F*/"Descend ");
	if(tile_cur != TIL_1C) {
		w_What();
		return;
	}
	if(Party._y == 2) {
		u4_puts(/*D_1898*/"into the depths!\n");
		Party.out_x = 0xef;
		Party.out_y = 0xf0;
		Party._y = Party._x = 5;
		Party._loc = 0x17;
		C_3EE4();
		return;
	}
	u4_puts(/*D_18AA*/"to first floor!\n");
	if(Load(/*D_18BB*/"LCB_1.ULT", sizeof(struct t_500), &D_8742) == -1)
		exit(3);
}
