/*
 * Ultima IV - Quest Of The Avatar
 * (c) Copyright 1987 Lord British
 * reverse-coded by Ergonomy Joe in 2012
 */

#include "u4_file.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "u4_dos.h"

/*C_0812*/Console(bp04)
char *bp04;
{
	int bp_02;

	if((bp_02 = dwrite(1, bp04, strlen(bp04))) == -1 || strlen(bp04) != bp_02) {
		exit(3);
	}
}

/*C_0855*/Load(bp0a, bp08, bp04)
char *bp0a;
unsigned bp08;
void far *bp04;
{
	int bp_02, bp_04;

	if((bp_02 = dopen(bp0a, 0)) == -1) {
		Console("\r\nOpening ");
		Console(bp0a);
		return -1;
	}
	if((bp_04 = dread(bp_02, bp04, bp08)) == -1 || bp08 != bp_04) {
		Console("\r\nReading ");
		if(bp_04 == -1) {
			Console(bp0a);
		} else {
			Console(bp0a);
			Console(": File wrong size\r\n");
		}
		return -1;
	}
	if(dclose(bp_02) == -1) {
		Console("\r\nClosing ");
		Console(bp0a);
		return -1;
	}
	return 0;
}

/*C_08D1*/Save(bp0a, bp08, bp04)
char *bp0a;
unsigned bp08;
void far *bp04;
{
	int bp_02, bp_04;

	if((bp_02 = dopen(bp0a, 1)) == -1) {
		Console("\r\nOpening ");
		Console(bp0a);
		return -1;
	}
	if((bp_04 = dwrite(bp_02, bp04, bp08)) == -1 || bp08 != bp_04) {
		Console("\r\nWriting ");
		if(bp_04 == -1) {
			Console(bp0a);
		} else {
			Console(bp0a);
			Console(": File wrong size\r\n");
		}
		exit(1);
	}
	if(dclose(bp_02) == -1) {
		Console("\r\nClosing ");
		Console(bp0a);
		return -1;
	}
	return 0;
}
