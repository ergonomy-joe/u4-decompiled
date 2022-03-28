/*
 * Ultima IV - Quest Of The Avatar
 * (c) Copyright 1987 Lord British
 * reverse-coded by Ergonomy Joe in 2012
 */

#include "u4.h"

char D_1FD8[] = "\nAttacked by ";

/*can npc move?*/
C_4E94(bp0a, bp08, bp06, bp04)
unsigned bp0a;
unsigned char bp08;/*new x*/
unsigned char bp06;/*new y*/
unsigned char bp04;
{
	register int si, di;

	if(CurMode == MOD_BUILDING)
		if(bp08 >= 32 || bp06 >= 32)
			return 0;
	di = D_8742._npc._tile[bp0a];
	if(C_29EF(bp04))
		return 0;
	if(di != TIL_8C && di != TIL_8E) {
		for(si = 31; si >= 0; si --) {
			if(
				D_8742._npc._tile[si] &&
				D_8742._npc._x[si] == bp08 &&
				D_8742._npc._y[si] == bp06 &&
				D_8742._npc._tile[si] != TIL_3C
			) return 0;
		}
		if(Party._x == bp08 && Party._y == bp06)
			return 0;
	}
	if(
		di != TIL_80 &&
		bp08 == D_8742._npc._old_x[bp0a] &&
		bp06 == D_8742._npc._old_y[bp0a] &&
		U4_RND1(3) == 0
	) return 0;
	if(di < TIL_80)
		return C_2999(bp04);
	if(di < TIL_8E)
		return (di == TIL_80)?(bp04 <= TIL_01):(bp04 <= TIL_02);
	if(di == TIL_8E || di == TIL_94 || di == TIL_B4 || di == TIL_F0 || di == TIL_F8 || di == TIL_FC)
		return (bp04 <= TIL_02) || C_2999(bp04);
	if(di == TIL_EC || di == TIL_9C)
		return (bp04 >= TIL_03) && (bp04 != TIL_45);
	return C_2999(bp04);
}

/*C_4FBE*/u4_abs(bp04)
int bp04;
{
	return (bp04 < 0)?-bp04:bp04;
}

/*test parameter's sign
<  0 -> -1
== 0 ->  0
>  0 ->  1*/
/*C_4FD7*/u4_sign(bp04)
int bp04;
{
	return (bp04 < 0)?-1:(bp04 > 0)?1:0;
}

C_4FF8(si/*bp08*/, bp06, bp04)
register int si;
unsigned char bp06;
unsigned char bp04;
{
	if((unsigned)bp06 < 32 || (unsigned)bp04 < 32) {
		D_8742._npc._old_x[si] = D_8742._npc._x[si];
		D_8742._npc._x[si] = bp06;
		D_8742._npc._old_y[si] = D_8742._npc._y[si];
		D_8742._npc._y[si] = bp04;
	}
}

C_5036(si/*bp08*/, bp06, bp04)
register int si;
unsigned char bp06;
unsigned char bp04;
{
	D_8742._npc._old_x[si] = D_8742._npc._x[si];
	D_8742._npc._x[si] = bp06;
	D_8742._npc._old_y[si] = D_8742._npc._y[si];
	D_8742._npc._y[si] = bp04;
}

/*NPC attempts move[MOD_OUTDOORS]*/
C_5062(bp0a, bp08, bp06, bp04)
int bp0a;
int bp08;
int bp06;
int bp04;
{
	unsigned char loc_A, loc_B;
	unsigned char loc_C, loc_D;

	loc_B = D_8742._npc._x[bp0a]; loc_A = (bp08 + loc_B) - (D_95A5.x << 4);
	loc_D = D_8742._npc._y[bp0a]; loc_C = (bp06 + loc_D) - (D_95A5.y << 4);
	if(loc_A  > 31 || loc_C > 31) {
		if(bp04 >= 0)
			C_5062(bp0a, u4_sign((char)u_rand_a()), (char)u4_sign(u_rand_a()), bp04 - 1);
		return;
	}
	if(U4_RND1(1) && bp08 && C_4E94(bp0a, loc_B + bp08, loc_D, D_8742._map.x32x32[loc_C-bp06][loc_A])) {
		C_5036(bp0a, loc_B + bp08, loc_D);
		return;
	}
	if(bp06 && C_4E94(bp0a, loc_B, loc_D + bp06, D_8742._map.x32x32[loc_C][loc_A - bp08])) {
		C_5036(bp0a, loc_B, loc_D + bp06);
		return;
	}
	if(C_4E94(bp0a, loc_B + bp08, loc_D, D_8742._map.x32x32[loc_C - bp06][loc_A])) {
		C_5036(bp0a, loc_B + bp08, loc_D);
		return;
	}
	if(bp04 >= 0)
		C_5062(bp0a, u4_sign((char)u_rand_a()), u4_sign((char)u_rand_a()), bp04 - 1);
}

/*NPC attempts move[MOD_BUILDING]*/
C_51A7(bp0a, bp08, bp06, bp04)
int bp0a;
int bp08;
int bp06;
int bp04;/*# of tries*/
{
	unsigned bp_02, bp_04;

	bp_02 = D_8742._npc._x[bp0a];
	bp_04 = D_8742._npc._y[bp0a];
	/*D_8742._map.x32x32 is accessed without any out-of-bounds control.
Fortunately, there is some control in C_4E94 so any faultly-accessed
value will be discarded anyway.
It doesn't seem to cause any problem on the original environment, but
programmers attempting to build the code for a more recent environment
might experience an exception here
(issue raised by @plaidpants)*/
	if(U4_RND1(1) && bp08) {
		if(C_4E94(bp0a, bp08+bp_02, bp_04, D_8742._map.x32x32[bp_04][bp08+bp_02]))
			C_4FF8(bp0a, bp08+bp_02, bp_04);
		return;
	}
	if(bp06) {
		if(C_4E94(bp0a, bp_02, bp06+bp_04, D_8742._map.x32x32[bp06+bp_04][bp_02]))
			C_4FF8(bp0a, bp_02, bp06+bp_04);
		return;
	}
	if(C_4E94(bp0a, bp08+bp_02, bp_04, D_8742._map.x32x32[bp_04][bp08+bp_02])) {
		C_4FF8(bp0a, bp08+bp_02, bp_04);
		return;
	}
	if(D_8742._npc._var[bp0a] != 0x80 && bp04 >= 0)
		C_51A7(bp0a, u4_sign((char)u_rand_a()), u4_sign((char)u_rand_a()), bp04 - 1);
}

/*move NPCs[MOD_BUILDING]*/
C_5293()
{
	int bp_02, bp_04;

	{register int si; for(si = 31; si >= 0; si --) {
		if(D_8742._npc._tile[si] && D_8742._npc._var[si]) {
			if((char)D_8742._npc._var[si] >= 0) {
				/*random mode*/
				if(U4_RND1(1))
					C_51A7(si, u4_sign((char)u_rand_a()), u4_sign((char)u_rand_a()), 2);
			} else {
				/*following mode*/
				bp_02 = u4_sign((char)(Party._x - D_8742._npc._x[si]));
				bp_04 = u4_sign((char)(Party._y - D_8742._npc._y[si]));
				if(u4_abs((char)(Party._x - D_8742._npc._x[si])) + u4_abs((char)(Party._y - D_8742._npc._y[si])) >= 2)
					C_51A7(si, bp_02, bp_04, 2);
				else if(D_8742._npc._var[si] == 0xff) {
					/*agressive mode*/
					/*-- attacked by --*/
					t_callback();
					u4_puts(D_1FD8); u4_puts(C_1513(D_8742._npc._tile[si]));
					Gra_CR();
					C_7DFE(si);
				}
			}
		}
	}}
}

/*creature/party distance ?*/
C_535B(bp0c, bp0a, bp08, bp06, bp04)
int bp0c;/*index*/
int *bp0a;/*x sign*/
int *bp08;/*y sign*/
int *bp06;/*x distance*/
int *bp04;/*y distance*/
{
	*bp04 = (char)(Party._y - D_8742._npc._y[bp0c]);
	*bp08 = u4_sign(*bp04);
	*bp06 = (char)(Party._x - D_8742._npc._x[bp0c]);
	*bp0a = u4_sign(*bp06);
	return u4_abs(*bp06) + u4_abs(*bp04);
}

C_53AF(si/*bp08*/, bp06, bp04)
register int si;
unsigned char bp06;
unsigned char bp04;
{
	if(C_4E94(si, bp06, bp04, D_8742._map.x32x32[bp04-D_95A5.y*16][bp06-D_95A5.x*16])) {
		if(C_2A5A(D_8742._npc._gtile[si] & 3)) {
			D_8742._npc._old_x[si] = D_8742._npc._x[si];
			D_8742._npc._x[si] = bp06;
			D_8742._npc._old_y[si] = D_8742._npc._y[si];
			D_8742._npc._y[si] = bp04;
		}
	} else {
		D_8742._npc._gtile[si] = ((u4_sign((char)u_rand_a()) + D_8742._npc._gtile[si]) & 3) | TIL_80;
	}
}

C_5443(si/*bp04*/)
register int si;
{
	int loc_A, loc_B, loc_C, loc_D;

	if(C_535B(si, &loc_A, &loc_B, &loc_C, &loc_D) > 5 || U4_RND1(3) == 0) {
		if(u4_abs(loc_C) < u4_abs(loc_D)) {
			if(loc_D >= 0)
				D_8742._npc._gtile[si] = TIL_83;
			else
				D_8742._npc._gtile[si] = TIL_81;
		} else {
			if(loc_C >= 0)
				D_8742._npc._gtile[si] = TIL_82;
			else
				D_8742._npc._gtile[si] = TIL_80;
		}
	} else if(D_8742._npc._gtile[si] == TIL_80) {
		C_53AF(si, D_8742._npc._x[si] - 1, D_8742._npc._y[si]);
	} else if(D_8742._npc._gtile[si] == TIL_81) {
		C_53AF(si, D_8742._npc._x[si], D_8742._npc._y[si] - 1);
	} else if(D_8742._npc._gtile[si] == TIL_82) {
		C_53AF(si, D_8742._npc._x[si]+1, D_8742._npc._y[si]);
	} else {
		C_53AF(si, D_8742._npc._x[si], D_8742._npc._y[si]+1);
	}
}

C_5500(si/*bp08*/, bp06, bp04)
register int si;
int bp06;
int bp04;
{
	if(D_8742._npc._gtile[si] == TIL_80) {
		if(bp06 < 0) {
			C_53AF(si, D_8742._npc._x[si]+bp06, D_8742._npc._y[si]);
			return;
		}
	} else if(D_8742._npc._gtile[si] == TIL_81) {
		if(bp04 < 0) {
			C_53AF(si, D_8742._npc._x[si], D_8742._npc._y[si]+bp04);
			return;
		}
	} else if(D_8742._npc._gtile[si] == TIL_82) {
		if(bp06 > 0) {
			C_53AF(si, D_8742._npc._x[si]+bp06, D_8742._npc._y[si]);
			return;
		}
	} else {
		if(bp04 > 0) {
			C_53AF(si, D_8742._npc._x[si], D_8742._npc._y[si]+bp04);
			return;
		}
	}
	C_5443(si);
}

C_5569(bp0a, bp08, bp06, bp04)
int bp0a;
unsigned char bp08;
unsigned char bp06;
unsigned char bp04;
{
	unsigned char loc_E, loc_A;
	int loc_D, loc_C, loc_B;

	loc_E = D_8742._npc._x[bp0a] + bp08;
	loc_A = D_8742._npc._y[bp0a] + bp06;
	sound(3);
	for(loc_C = 1; loc_C <= 3; loc_E += bp08, loc_A += bp06, loc_C++) {
		if(Party._x == loc_E && Party._y == loc_A)
			return 1;
		if((loc_B = C_0A58(31, loc_E, loc_A)) != -1) {
			sound(6);
			if(loc_B >= 8 || U4_RND1(3) == 0) {
				D_8742._npc._tile[loc_B] = D_8742._npc._gtile[loc_B] = 0;
			}
			return 0;
		}
		{
			register unsigned char *si;

			si = &(D_8742._map.x32x32[loc_A - (D_95A5.y*16)][loc_E - (D_95A5.x*16)]);
			loc_D = *si;
			*si = bp04;
			t_callback();
			*si = loc_D;
		}
	}
	return 0;
}

C_564B(bp0a, bp08, bp06, bp04)
int bp0a;
int bp08;
int bp06;
int bp04;
{
	if(C_5569(bp0a, bp08, bp06, bp04) == 0) {
		hit_tile = 0;
		return;
	}
	t_callback();
	hit_y = hit_x = 5;
	hit_tile = TIL_4F;
	C_36C7();
	C_1584();
	hit_tile = 0;
	t_callback();
}

C_568F(bp08, bp06, bp04)
int bp08;
int bp06;
int bp04;
{
	if(D_8742._npc._gtile[bp08] == TIL_80 || D_8742._npc._gtile[bp08] == TIL_82)
		if(bp06)
			C_5500(bp08, bp06, bp04);
		else
			C_564B(bp08, bp06, bp04, TIL_4D);
	else
		if(bp04)
			C_5500(bp08, bp06, bp04);
		else
			C_564B(bp08, bp06, bp04, TIL_4D);
}

C_56D3(bp04)
int bp04;
{
	return
		(D_8742._npc._x[bp04] - D_95A5.x*16) >= 32 ||
		(D_8742._npc._y[bp04] - D_95A5.y*16) >= 32
	;
}

/*move NPCs[MOD_OUTDOORS]*/
C_5712()
{
	int loc_A, loc_B, loc_C, loc_D;
	register int loc_F;

	loc_F = 7; do {
		int loc_G;
		register int loc_H;

		loc_H = D_8742._npc._tile[loc_F];
		if(loc_H == 0)
			continue;
		/*is out of range?*/
		if(C_56D3(loc_F)) {
			D_8742._npc._tile[loc_F] = D_8742._npc._gtile[loc_F] = 0;
			continue;
		}
		/* */
		if(loc_H != TIL_8C && loc_H != TIL_8E) {
			loc_G = C_535B(loc_F, &loc_A, &loc_B, &loc_C, &loc_D);
			if(loc_G < 2) {
				/*-- attacked by --*/
				t_callback();
				u4_puts(D_1FD8); u4_puts(C_1513(loc_H));
				Gra_CR();
				C_7DFE(loc_F);
				continue;
			}
		}
		if(loc_H == TIL_80) {
			if(loc_G < 4)
				C_568F(loc_F, loc_A, loc_B);
			else
				C_5500(loc_F, loc_A, loc_B);
			continue;
		}
		if(loc_H == TIL_88 || loc_H == TIL_E8 || loc_H >= TIL_F4) {
			if(u4_abs(loc_C) < 5 && u4_abs(loc_D) < 5 && U4_RND1(1))
				C_564B(loc_F, loc_A, loc_B, TIL_4F);
		}
		if(loc_H == TIL_8C || loc_H == TIL_8E || (C_0AFE(loc_H) && U4_RND1(3)))
			C_5062(loc_F, u4_sign((char)u_rand_a()), u4_sign((char)u_rand_a()), 1);
		else
			C_5062(loc_F, loc_A, loc_B, 2);
	} while(--loc_F >= 0);
}

/*move npc?*/
C_5834()
{
	if(CurMode == MOD_BUILDING)
		C_5293();
	else if(CurMode == MOD_OUTDOORS)
		C_5712();
}

/*spawn creatures?*/
C_5851()
{
	register int si;
	register unsigned char *loc_B;
	unsigned char loc_C, loc_A;

	if(CurMode != MOD_OUTDOORS || U4_RND1(15))
		return;
	for(si = 3; si >= 0; si--) {
		if(D_8742._npc._tile[si] != 0)
			continue;
		loc_A = U4_RND1(31);
		loc_C = U4_RND1(31);
		loc_B = &(D_8742._map.x32x32[loc_C][loc_A]);
		if(u4_abs(loc_A - D_959C.x) >= 6 && u4_abs(loc_C - D_959C.y) >= 6) {
			if(*loc_B < TIL_02) {/*at sea*/
				if(U4_RND1(7) == 0) {
					D_8742._npc._x[si] = loc_A + D_95A5.x*16;
					D_8742._npc._y[si] = loc_C + D_95A5.y*16;
					D_8742._npc._tile[si] = D_8742._npc._gtile[si] = (unsigned char)TIL_80 + (U4_RND1(7) * 2);
					if(D_8742._npc._gtile[si] == TIL_82)
						D_8742._npc._tile[si] = D_8742._npc._gtile[si] = TIL_80;
				}
			} else if(*loc_B >= TIL_04 && *loc_B < TIL_08) {/*on earth*/
				unsigned bp_0a;

				D_8742._npc._x[si] = loc_A + D_95A5.x*16;
				D_8742._npc._y[si] = loc_C + D_95A5.y*16;
				if(Party._moves > 100000L)
					bp_0a = 15;
				else if(Party._moves < 10000L)
					bp_0a = 3;
				else if(Party._moves < 20000L)
					bp_0a = 7;
				else if (Party._moves >= 30000L)
					bp_0a = 15;
				else
					bp_0a = 7;
/*
:599A E8D4BD    CALL	u_rand_a
:599D 8946F4    MOV	[BP-0Ch],AX
:59A0 E8CEBD    CALL	u_rand_a
:59A3 8A4EF6    MOV	CL,[BP-0Ah]
:59A6 22C8      AND	CL,AL
:59A8 224EF4    AND	CL,[BP-0Ch]
:59AB D0E1      SHL	CL,1
:59AD D0E1      SHL	CL,1
:59AF 80C1C0    ADD	CL,0C0h
:59B2 888C428B  MOV	__8B42[SI],CL
:59B6 888CA28B  MOV	__8B42[SI+60h],CL*/
				D_8742._npc._tile[si] =
				D_8742._npc._gtile[si] =
					U4_RND1(U4_RND1(bp_0a)) * 4 + TIL_C0;
			}
		}
	}
}
