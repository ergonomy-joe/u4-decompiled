/*
 * Ultima IV - Quest Of The Avatar
 * (c) Copyright 1987 Lord British
 * reverse-coded by Ergonomy Joe in 2012
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <dos.h>
#include <io.h>
#include <fcntl.h>

/*C_0010*/Console(bp04)
char *bp04;
{
	int bp_02;

	if((bp_02 = write(1, bp04, strlen(bp04))) == -1 || strlen(bp04) != bp_02) {
		exit(3);
	}
}

/*C_0051*/Load(bp0a, bp08, bp04)
char *bp0a;
unsigned bp08;
void far *bp04;
{
	void *loc_A;
	int loc_B;
	void far *loc_C;
	int loc_D;

	loc_A = malloc(bp08);
	loc_C = loc_A;
	if(loc_A == 0) {
		Console(/*D_003A*/"\r\nError allocating space\r\n");
		exit(0x13);
	}

	if((loc_B = open(bp0a, O_BINARY|O_RDONLY)) == -1) {
		Console("\r\nOpening ");
		Console(bp0a);
		return -1;
	}
	if((loc_D = read(loc_B, loc_A, bp08)) == -1 || bp08 != loc_D) {
		Console("\r\nReading ");
		if(loc_D == -1) {
			Console(bp0a);
		} else {
			Console(bp0a);
			Console(": File wrong size\r\n");
		}
		return -1;
	}
	if(close(loc_B) == -1) {
		Console("\r\nClosing ");
		Console(bp0a);
		return -1;
	}
	movedata(FP_SEG(loc_C), FP_OFF(loc_C), FP_SEG(bp04), FP_OFF(bp04), bp08);
	free(loc_A);

	return 0;
}

/*unlike the avatar.exe's version
the source buffer is not far*/
/*C_0110*/Save(bp0a, bp08, bp04)
char *bp0a;
unsigned bp08;
void /*far */*bp04;
{
	int bp_02, bp_04;

	if((bp_02 = open(bp0a, O_BINARY|O_WRONLY)) == -1) {
		Console("\r\nOpening ");
		Console(bp0a);
		return -1;
	}
	if((bp_04 = write(bp_02, bp04, bp08)) == -1 || bp08 != bp_04) {
		Console("\r\nWriting ");
		if(bp_04 == -1) {
			Console(bp0a);
		} else {
			Console(bp0a);
			Console(": File wrong size\r\n");
		}
		exit(1);
	}
	if(close(bp_02) == -1) {
		Console("\r\nClosing ");
		Console(bp0a);
		return -1;
	}
	return 0;
}
