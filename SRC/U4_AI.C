/*
 * Ultima IV - Quest Of The Avatar
 * (c) Copyright 1987 Lord British
 * reverse-coded by Ergonomy Joe in 2012
 */

#include "u4.h"

C_93A5(bp08, bp06, bp04)
unsigned char bp08;
unsigned char bp06;
int bp04;
{
	unsigned char bp_02;

	bp_02 = D_8742._map.x8x8x8[Party._z][bp06][bp08];
	if((bp_02 & 0x0f) == 0) {
		if(
			(bp_02 & 0xe0) != 0x80 &&
			(bp_02 & 0xf0) != 0xa0 &&
			(bp_02 & 0xf0) != 0xd0 &&
			(bp_02 & 0xf0) != 0xf0
		) {
			if(U4_RND1(7) == 0 || D_8742._npc._old_x[bp04] != bp08 || D_8742._npc._old_y[bp04] != bp06)
				return 1;
		}
	}
	return 0;
}

C_9414()
{
	int loc_A, loc_B, loc_C, loc_D;
	unsigned char loc_E, loc_F;
	
	for(loc_B = 31; loc_B >= 0; loc_B --) {/*end:C_95A1*/
		if(
			D_8742._npc._tile[loc_B] != 0 &&
			D_8742._npc._var[loc_B] == Party._z &&
			D_8742._npc._tile[loc_B] != TIL_B0 &&
			D_8742._npc._tile[loc_B] != TIL_AC
		) {
			if(Party._x != D_8742._npc._x[loc_B] || Party._y != D_8742._npc._y[loc_B]) {
				for(loc_D = 7; loc_D >= 0; loc_D --) {/*end:C_94CB*/
					loc_A = u4_sign((char)u_rand_a());
					loc_C = u4_sign((char)u_rand_a());
					if(U4_RND1(1) && loc_A != 0) {
						loc_E = (D_8742._npc._x[loc_B] + loc_A) & 7;
						loc_F = D_8742._npc._y[loc_B];
						if(C_93A5(loc_E, loc_F, loc_B))
							break;
					}
					if(loc_C) {
						loc_E = D_8742._npc._x[loc_B];
						loc_F = (D_8742._npc._y[loc_B] + loc_C) & 7;
						if(C_93A5(loc_E, loc_F, loc_B))
							break;
					}
					loc_E = (D_8742._npc._x[loc_B] + loc_A) & 7;
					loc_F = D_8742._npc._y[loc_B];
					if(C_93A5(loc_E, loc_F, loc_B))
						break;
				}
				if(loc_D != -1) {
					D_8742._map.x8x8x8[Party._z][loc_F][loc_E] |= (D_8742._npc._tile[loc_B] - TIL_90) / 4 + 1;
					D_8742._map.x8x8x8[Party._z][D_8742._npc._y[loc_B]][D_8742._npc._x[loc_B]] &= 0xf0;
					D_8742._npc._old_x[loc_B] = D_8742._npc._x[loc_B];
					D_8742._npc._old_y[loc_B] = D_8742._npc._y[loc_B];
					D_8742._npc._x[loc_B] = loc_E;
					D_8742._npc._y[loc_B] = loc_F;
				}
			}
		}
	}
	t_callback();
}

C_95AA()
{
	int loc_A;
	unsigned char loc_B, loc_C, loc_D;

	for(loc_A = Party._z * 4 + 1; loc_A >= 0; loc_A --) {
		if((loc_A >> 2) < Party._z)
			break;
		if(D_8742._npc._tile[loc_A] == 0) {
			loc_B = U4_RND1(7);
			loc_D = U4_RND1(7);
			if(Party._x != loc_B && Party._y != loc_D) {
				if(D_8742._map.x8x8x8[Party._z][loc_D][loc_B] == 0) {
					loc_C = (U4_RND1(3) + Party._z) * 4 + TIL_90;
					if(loc_C != TIL_AC) {
						D_8742._npc._tile[loc_A] = loc_C;
						D_8742._npc._x[loc_A] = D_8742._npc._old_x[loc_A] = loc_B;
						D_8742._npc._y[loc_A] = D_8742._npc._old_y[loc_A] = loc_D;
						D_8742._npc._var[loc_A] = Party._z;
						D_8742._map.x8x8x8[Party._z][loc_D][loc_B] = ((loc_C - 0x90) >> 2) + 1;
					}
				}
			}
		}
	}
}

C_9683()
{
	register int si;

	for(si = Party.f_1d8; --si >= 0;  ) {
		if(isCharaAlive(si) && hit_x == Combat._charaX[si] && hit_y == Combat._charaY[si])
			return si;
	}
	return -1;
}

C_96B9(bp06, bp04)
int bp06;
int bp04;
{
	unsigned bp_02;

	Gra_11(bp06);
	C_3C54();
	sound(7);
	hit_tile = 0;
	C_3C54();
	bp_02 = U4_RND4(D_23D2[C_7C25((unsigned char)Fighters._tile[bp04])] >> 2);
	bp_02 = (bp_02 >> 4) * 10 + (bp_02 % 10);
	Gra_11(bp06);
	if(hitChara(bp06, bp_02) == 0) {
		dspl_Stats();
		return 0;
	}
	u4_puts(Party.chara[bp06]._name);
	u4_puts(/*D_29CA*/" is Killed!\n");
	karma_inc(&(Party._sacri), 1);
	dspl_Stats();
	C_10FD();

	return 1;
}

C_9764(bp04)
int bp04;
{
	Gra_11(bp04);
	C_3C54();
	sound(7);
	Gra_11(bp04);
	hit_tile = 0;
}

/*monster projectile?*/
C_978C(bp0a, bp08, bp06, bp04)
unsigned char bp0a;/*type*/
int bp08;/*monster id*/
int bp06;
int bp04;
{
	register int si;

	hit_tile = bp0a;
	hit_x = Combat._npcX[bp08];
	hit_y = Combat._npcY[bp08];
	sound(3);
	si = -1;
	do {
		if(COM_CheckHitable(bp06, bp04) == 0)
			break;
		C_3C54();
	} while((si = C_9683()) == -1);
	if(si == -1) {
		if(hit_tile == TIL_4C)
			Combat_MAP(hit_y, hit_x) = TIL_4C;
		hit_tile = 0;
		return;
	}
	Gra_CR();
	u4_puts(Party.chara[si]._name);
	u4_putc(' ');
	switch(hit_tile) {
		case TIL_44:
			u4_puts(/*D_29D7*/"Poisoned!\n");
			C_9764(si);
			if(U4_RND1(1) || Party.chara[si]._stat != 'G')
				u4_puts(/*D_29E2*/"Failed.\n");
			else
				Party.chara[si]._stat = 'P';
		break;
		case TIL_45:
			u4_puts(/*D_29EB*/"Electrified!\n");
			C_96B9(si, bp08);
		break;
		case TIL_46:
			u4_puts(/*D_29F9*/"Fiery Hit!\n");
			C_96B9(si, bp08);
		break;
		case TIL_47:
			u4_puts(/*D_2A05*/"Slept!\n");
			C_9764(si);
			if(U4_RND1(1) || Party.chara[si]._stat != 'G')
				u4_puts(/*D_2A0D*/"Failed.\n");
			else {
				Party.chara[si]._stat = 'S';
				Fighters._chtile[si] = TIL_38;
			}
		break;
		case TIL_4C:
			u4_puts(/*D_2A16*/"Lava Hit!\n");
			C_96B9(si, bp08);
		break;
		case TIL_4E:
			u4_puts(/*D_2A21*/"Magical Hit!\n");
			C_96B9(si, bp08);
		break;
		default:
			u4_puts(/*D_2A2F*/"Hit!\n");
			C_96B9(si, bp08);
	}
	hit_tile = 0;
	dspl_Stats();
}

C_98E4(bp08, bp06, bp04)
unsigned char bp08;
unsigned char bp06;
int bp04;
{
	unsigned char bp_02;
	int bp_04;

	bp_02 = Combat_MAP(bp06, bp08);
	if(C_29EF(bp_02))
		return 0;
	if(bp08 >= 11 || bp06 >= 11)
		return ((unsigned char)Fighters._HP[bp04] < 24);
	if(Fighters._x[bp04] == bp08 && Fighters._y[bp04] == bp06 && U4_RND1(3))
		return 0;

	for(bp_04 = 15; bp_04 >= 0; bp_04 --)
		if(Fighters._tile[bp_04] && Combat._npcX[bp_04] == bp08 && Combat._npcY[bp_04] == bp06)
			return 0;
	for(bp_04 = 7; bp_04 >= 0; bp_04 --)
		if(Fighters._chtile[bp_04] && Combat._charaX[bp_04] == bp08 && Combat._charaY[bp_04] == bp06)
			return 0;

	if((unsigned char)Fighters._tile[bp04] < 0x80)
		return C_2999(Combat_MAP(bp06, bp08));
	if((unsigned char)Fighters._tile[bp04] < 0x8e)
		return (bp_02 < 3);
	switch((unsigned char)Fighters._gtile[bp04]) {
		case TIL_B4:
		case TIL_8E:
		case TIL_94:
		case TIL_F0:
		case TIL_F8:
		case TIL_FC:
			return (bp_02 < 3) || C_2999(bp_02);
		case TIL_9C:
		case TIL_EC:
			return (bp_02 >= 3) && (bp_02 != 0x45);
		default:
			return C_2999(bp_02);
	}
}

unsigned char C_9A41(bp04)
unsigned char bp04;
{
	switch(bp04) {
		case TIL_20:
		case TIL_5E:
		case TIL_8A:
		case TIL_E0:
		case TIL_E4:
		case TIL_F0:
			return TIL_4E;/*magic sphere*/
		case TIL_84:
		case TIL_A4:
			return TIL_4D;/*Missile*/
		case TIL_86:
			return TIL_45;/*energy field*/
		case TIL_88:
		case TIL_F4:
		case TIL_F8:
			return TIL_4F;/*flash*/
		case TIL_98:
		case TIL_AC:
		case TIL_CC:
			return TIL_44;/*poison field*/
		case TIL_B8:
			return TIL_47;/*sleep field*/
		case TIL_D0:
		case TIL_D8:
			return TIL_37;/*rocks*/
		case TIL_E8:
			return TIL_4C;/*lava*/
		case TIL_B0:
		case TIL_FC:
			return U4_RND1(3) + TIL_44;/*[poison|energy|fire] field*/
		default:
			return 0;
	}
}

/*C_9B03*/CheckJinx(_x, _y)
unsigned char _x;
unsigned char _y;
{
	int bp_02;

	if(spell_sta == 'J') {
		if((bp_02 = COM_GetFighterId(_x, _y)) != -1) {
			hit_tile = TIL_4F;
			hit_x = _x;
			hit_y = _y;
			C_3C54();
			hit_tile = 0;
			sound(6);
			COM_DoDamage(bp_02, -1, U4_RND1(0x3f));
			C_3C54();
			return 1;
		}
	}
	return 0;
}

/*steal food*/
C_9B6B()
{
	Party._food = u4_max(Party._food - 2500, 0L);
	dspl_Stats();
	sound(8);
}

/*steal gold*/
C_9BA6()
{
	register int si;

	if(U4_RND1(3) == 0) {
		si = U4_RND1(0x3f);
		Party._gold = u4_max(Party._gold - si, 0);
		dspl_Stats();
		sound(8);
	}
}

/*contact attack?*/
C_9BE5(bp06, bp04)
int bp06;
int bp04;
{
	hit_x = Combat._charaX[bp04];
	hit_y = Combat._charaY[bp04];
	hit_tile = TIL_4D;
	C_3C54();
	sound(5);
	hit_tile = 0;
	if((spell_sta == 'P' && U4_RND1(1)) || D_2460[Party.chara[bp04]._armor] >= u_rand_a()) {
		C_3C54();
	} else if(C_96B9(bp04, bp06) == 0) {
		return 1;
	}
	return 0;
}

C_9C56(bp04)
int bp04;
{
	Gra_CR();
	u4_puts(C_1513((unsigned char)Fighters._tile[bp04]));
	u4_puts(/*D_2A35*/" Flees!\n");
	if(C_0AFE((unsigned char)Fighters._tile[bp04])) {
		karma_inc(&(Party._compa), 1);
		karma_inc(&(Party._justi), 1);
	}
	sound(8);
	Fighters._tile[bp04] = Fighters._HP[bp04] = 0;
}

/*move enemies during fight*/
C_9CBC(bp08, bp06, bp04)
int bp08;/*monster id*/
int bp06;/*chara id*/
int bp04;
{
	int loc_A, loc_B, loc_C;
	unsigned char loc_D, loc_E;

	loc_A = u4_sign((unsigned char)Combat._charaX[bp06] - (unsigned char)Combat._npcX[bp08]);
	loc_C = u4_sign((unsigned char)Combat._charaY[bp06] - (unsigned char)Combat._npcY[bp08]);
	/*Mimic*/
	if((unsigned char)Fighters._tile[bp08] == TIL_AC) {
		Fighters._gtile[bp08] = TIL_3C;
		if(bp04 >= 5)
			goto C_9D51;
		Fighters._gtile[bp08] = TIL_AC;
	}
	/*attempt projectile*/
	if(U4_RND1(3) == 0) {
		int bp_0c;

		if((bp_0c = C_9A41((unsigned char)Fighters._tile[bp08])) != 0) {
			if(bp_0c != TIL_4E || spell_sta != 'N') {
				C_978C(bp_0c, bp08, loc_A, loc_C);
				t_callback();
				return;
			}
		}
	}
	/* */
C_9D51:
	/*balron or reaper*/
	if(U4_RND1(3) == 0) {
		if((unsigned char)Fighters._tile[bp08] == TIL_FC || (unsigned char)Fighters._tile[bp08] == TIL_B0) {
			if(spell_sta != 'N') {
				t_callback();
				Gra_09(); sound(9, 0x80); Gra_09();
				for(loc_B = Party.f_1d8 - 1; loc_B >= 0; loc_B --) {
					if(Fighters._chtile[loc_B] != 0 && Party.chara[loc_B]._stat == 'G' && U4_RND1(1)) {
						Party.chara[loc_B]._stat = 'S';
						Fighters._chtile[loc_B] = TIL_38;
					}
				}
				dspl_Stats();
				return;
			}
		}
	}
	/* */
	if((unsigned char)Fighters._HP[bp08] < 24) {
		loc_A = -loc_A;
		loc_C = -loc_C;
C_9DE5:
		if((unsigned char)Fighters._tile[bp08] == TIL_AC || (unsigned char)Fighters._tile[bp08] == TIL_B0)
			return;
	} else if(bp04 >= 2) {
		goto C_9DE5;
	} else {
		/*contact?*/
		switch((unsigned char)Fighters._tile[bp08]) {
			case TIL_A8: C_9B6B(); break;
			case TIL_C8: C_9BA6(); break;
		}
		C_9BE5(bp08, bp06);/*contact attack?*/
		return;
	}
	/* */
	for(loc_B = 2; loc_B > 0; loc_B --) {
		if(U4_RND1(1) && loc_A != 0) {
			loc_D = (unsigned char)Combat._npcX[bp08] + loc_A;
			loc_E = (unsigned char)Combat._npcY[bp08];
			if(CheckJinx(loc_D, loc_E))
				return;
			if(C_98E4(loc_D, loc_E, bp08))
				break;
		}
		if(loc_C != 0) {
			loc_D = (unsigned char)Combat._npcX[bp08];
			loc_E = (unsigned char)Combat._npcY[bp08] + loc_C;
			if(CheckJinx(loc_D, loc_E))
				return;
			if(C_98E4(loc_D, loc_E, bp08))
				break;
		}
		if(loc_A != 0) {
			loc_D = (unsigned char)Combat._npcX[bp08] + loc_A;
			loc_E = (unsigned char)Combat._npcY[bp08];
			if(CheckJinx(loc_D, loc_E))
				return;
			if(C_98E4(loc_D, loc_E, bp08))
				break;
		}
		loc_A = u4_sign((char)u_rand_a());
		loc_C = u4_sign((char)u_rand_a());
	}
	if(loc_B != 0) {
		Fighters._x[bp08] = Combat._npcX[bp08];
		Fighters._y[bp08] = Combat._npcY[bp08];
		Combat._npcX[bp08] = loc_D;
		Combat._npcY[bp08] = loc_E;
		if(loc_D >= 11 || loc_E >= 11) {
			C_9C56(bp08);/*... Flees*/
			return;
		}
		C_3C54();
		return;
	}
	if(bp04 < 2)
		C_9BE5(bp08, bp06);/*contact attack?*/
}

/*combat ai*/
C_9F7B()
{
	int loc_A, loc_B, loc_C, loc_F;
	unsigned char loc_D, loc_E;

	t_callback();

	for(loc_A = 15; loc_A >= 0; loc_A --) {
		if(Fighters._tile[loc_A]) {
			if((unsigned char)Fighters._sleeping[loc_A] == 0 || U4_RND1(7) == 0) {
				Fighters._sleeping[loc_A] = 0;
				if((unsigned char)Fighters._tile[loc_A] == TIL_EC) {
					spell_sta = 'N';
					spell_cnt = 2;
					dspl_Stats();
				} else if((unsigned char)Fighters._tile[loc_A] == TIL_DC && U4_RND1(7) == 0) {
					do {
						loc_D = U4_RND3(11);
						loc_E = U4_RND3(11);
					} while(!C_98E4(loc_D, loc_E, loc_A));
					Combat._npcX[loc_A] = loc_D;
					Combat._npcY[loc_A] = loc_E;
				}
				loc_D = Combat._npcX[loc_A];
				loc_E = Combat._npcY[loc_A];
				loc_F = 99;
				loc_C = -1;
				for(loc_B = Party.f_1d8 - 1; loc_B >= 0; loc_B --) {
					if(isCharaAlive(loc_B) && Fighters._chtile[loc_B]) {
						register int si;

						si =
							u4_abs((unsigned char)Combat._charaX[loc_B] - loc_D) +
							u4_abs((unsigned char)Combat._charaY[loc_B] - loc_E)
						;
						if(loc_F > si) {
							loc_F = si;
							loc_C = loc_B;
						}
					}
				}
				if(loc_C != -1)
					C_9CBC(loc_A, loc_C, loc_F);
			}
			switch(Combat_MAP((unsigned char)Combat._npcY[loc_A], (unsigned char)Combat._npcX[loc_A])) {
				case TIL_46: case TIL_4C:
					if((unsigned char)Fighters._tile[loc_A] == TIL_E8 || (unsigned char)Fighters._tile[loc_A] >= TIL_F0)
						break;
				case TIL_44:
					sound(6);
					COM_DoDamage(loc_A, -1, U4_RND1(0x7f));
				break;
				case TIL_47:
					if(C_636D((unsigned char)Fighters._tile[loc_A]) == 0 && (unsigned char)Fighters._HP[loc_A] >= u_rand_a()) {
						Fighters._sleeping[loc_A] = 1;
						sound(6);
					}
				break;
			}
		}
	}
	MP_recover();
	Party._moves ++;
	if(spell_cnt) {
		if(--spell_cnt == 0)
			spell_sta = 7;
	}
}
