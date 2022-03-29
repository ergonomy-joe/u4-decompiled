/*
 * Ultima IV - Quest Of The Avatar
 * (c) Copyright 1987 Lord British
 * reverse-coded by Ergonomy Joe in 2012
 */

#include "u4.h"

unsigned D_07F8 = 1;

/*karmas*/
U16 /*D_07FA*/*pKarmas[] = {
	&(Party._hones),
	&(Party._compa),
	&(Party._valor),
	&(Party._justi),
	&(Party._sacri),
	&(Party._honor),
	&(Party._spiri),
	&(Party._humil),
};

int /*D_080A*/activeCharaX = -1;

char D_080C[] = {-1,0,1,0};
char D_0810[] = {0,-1,0,1};

/*moongates positions*/
unsigned char D_0814[] = {0xE0,0x60,0x26,0x32,0xA6,0x68,0x17,0xBB};
unsigned char D_081C[] = {0x85,0x66,0xE0,0x25,0x13,0xC2,0x7E,0xA7};

/*towns/castles files*/
char *D_0824[] = {
	/*Castles*/
	/*D_06C2*/"LCB_1.ULT",
	/*D_06CC*/"LYCAEUM.ULT",
	/*D_06D8*/"EMPATH.ULT",
	/*D_06E3*/"SERPENT.ULT",
	/*Townes*/
	/*D_06EF*/"MOONGLOW.ULT",
	/*D_06FC*/"BRITAIN.ULT",
	/*D_0708*/"JHELOM.ULT",
	/*D_0713*/"YEW.ULT",
	/*D_071B*/"MINOC.ULT",
	/*D_0725*/"TRINSIC.ULT",
	/*D_0731*/"SKARA.ULT",
	/*D_073B*/"MAGINCIA.ULT",
	/*Villages*/
	/*D_0748*/"PAWS.ULT",
	/*D_0751*/"DEN.ULT",
	/*D_0759*/"VESPER.ULT",
	/*D_0764*/"COVE.ULT"
};

/*places world's coordinates*/
char D_0844[] = {0x56,0xDA,0x1C,0x92,0xE8,0x52,0x24,0x3A,0x9F,0x6A,0x16,0xBB,0x62,0x88,0xC9,0x88,0xF0,0x5B,0x48,0x7E,0x9C,0x3A,0xEF,0xE9, 0xE9,0x80,0x24,0x49,0xCD,0x51,0xE7,0xE7};
char D_0864[] = {0x6B,0x6B,0x32,0xF1,0x87,0x6A,0xDE,0x2B,0x14,0xB8,0x80,0xA9,0x91,0x9E,0x3B,0x5A,0x49,0x43,0xA8,0x14,0x1B,0x66,0xF0,0xE9, 0x42,0x5C,0xE5,0x0B,0x2D,0xCF,0xD8,0xD8};

/*colors*/
char *D_0884[] = {
	/*D_076D*/"Blue",
	/*D_0772*/"Yellow",
	/*D_0779*/"Red",
	/*D_077D*/"Green",
	/*D_0783*/"Orange",
	/*D_078A*/"Purple",
	/*D_0791*/"White",
	/*D_0797*/"Black"
};

/*dungeons files*/
char *D_0894[] = {
	/*D_079D*/"Deceit.Dng",
	/*D_07A8*/"Despise.Dng",
	/*D_07B4*/"Destard.Dng",
	/*D_07C0*/"Wrong.Dng",
	/*D_07CA*/"Covetous.Dng",
	/*D_07D7*/"Shame.Dng",
	/*D_07E1*/"Hythloth.Dng",
	/*D_07EE*/"Abyss.Dng"
};
