EXTRN _exit:NEAR

EXTRN _C_23C3:NEAR

DGROUP	GROUP _DATA,CONST,_BSS

;----------------------------------------
;NOTE: DGROUP is accessed with SS ?!?
;----------------------------------------

;########################################
_DATA	SEGMENT PUBLIC WORD 'DATA'
	ASSUME SS:DGROUP
;----------------------------------------
;scanlines offsets(D_023C)
Lines	dw 0000h,2000h,0050h,2050h,00A0h,20A0h,00F0h,20F0h	;  0~  7
	dw 0140h,2140h,0190h,2190h,01E0h,21E0h,0230h,2230h	;  8~ 15
	dw 0280h,2280h,02D0h,22D0h,0320h,2320h,0370h,2370h	; 16~ 23
	dw 03C0h,23C0h,0410h,2410h,0460h,2460h,04B0h,24B0h	; 24~ 31
	dw 0500h,2500h,0550h,2550h,05A0h,25A0h,05F0h,25F0h	; 32~ 39
	dw 0640h,2640h,0690h,2690h,06E0h,26E0h,0730h,2730h	; 40~ 47
	dw 0780h,2780h,07D0h,27D0h,0820h,2820h,0870h,2870h	; 48~ 55
	dw 08C0h,28C0h,0910h,2910h,0960h,2960h,09B0h,29B0h	; 56~ 63
	dw 0A00h,2A00h,0A50h,2A50h,0AA0h,2AA0h,0AF0h,2AF0h	; 64~ 71
	dw 0B40h,2B40h,0B90h,2B90h,0BE0h,2BE0h,0C30h,2C30h	; 72~ 79
	dw 0C80h,2C80h,0CD0h,2CD0h,0D20h,2D20h,0D70h,2D70h	; 80~ 87
	dw 0DC0h,2DC0h,0E10h,2E10h,0E60h,2E60h,0EB0h,2EB0h	; 88~ 95
	dw 0F00h,2F00h,0F50h,2F50h,0FA0h,2FA0h,0FF0h,2FF0h	; 96~103
	dw 1040h,3040h,1090h,3090h,10E0h,30E0h,1130h,3130h	;104~111
	dw 1180h,3180h,11D0h,31D0h,1220h,3220h,1270h,3270h	;112~119
	dw 12C0h,32C0h,1310h,3310h,1360h,3360h,13B0h,33B0h	;120~127
	dw 1400h,3400h,1450h,3450h,14A0h,34A0h,14F0h,34F0h	;128~135
	dw 1540h,3540h,1590h,3590h,15E0h,35E0h,1630h,3630h	;136~143
	dw 1680h,3680h,16D0h,36D0h,1720h,3720h,1770h,3770h	;144~151
	dw 17C0h,37C0h,1810h,3810h,1860h,3860h,18B0h,38B0h	;152~159
	dw 1900h,3900h,1950h,3950h,19A0h,39A0h,19F0h,39F0h	;160~167
	dw 1A40h,3A40h,1A90h,3A90h,1AE0h,3AE0h,1B30h,3B30h	;168~175
	dw 1B80h,3B80h,1BD0h,3BD0h,1C20h,3C20h,1C70h,3C70h	;176~183
	dw 1CC0h,3CC0h,1D10h,3D10h,1D60h,3D60h,1DB0h,3DB0h	;184~191
	dw 1E00h,3E00h,1E50h,3E50h,1EA0h,3EA0h,1EF0h,3EF0h	;192~199
D_03CC	db 35h
D_03CD	db 9Bh
D_03CE	dw OFFSET _TEXT:GR_0_CGA
	dw OFFSET _TEXT:GR_0_EGA
	dw OFFSET _TEXT:GR_0_TANDY
	dw OFFSET _TEXT:GR_DOT_CGA
	dw OFFSET _TEXT:GR_DOT_EGA
	dw OFFSET _TEXT:GR_DOT_TANDY
	dw OFFSET _TEXT:GR_2_CGA
	dw OFFSET _TEXT:GR_2_EGA
	dw OFFSET _TEXT:GR_2_TANDY
	dw OFFSET _TEXT:GR_3_CGA
	dw OFFSET _TEXT:GR_3_EGA
	dw OFFSET _TEXT:GR_3_TANDY
	dw OFFSET _TEXT:GR_INFLATE_CGA
	dw OFFSET _TEXT:GR_INFLATE_EGA
	dw OFFSET _TEXT:GR_INFLATE_TANDY
	dw OFFSET _TEXT:GR_5_CGA
	dw OFFSET _TEXT:GR_5_EGA
	dw OFFSET _TEXT:GR_5_TANDY
	dw OFFSET _TEXT:GR_INIT_CGA
	dw OFFSET _TEXT:GR_INIT_EGA
	dw OFFSET _TEXT:GR_INIT_TANDY
	dw OFFSET _TEXT:GR_ANIMFLOW_CGA
	dw OFFSET _TEXT:GR_ANIMFLOW_EGA
	dw OFFSET _TEXT:GR_ANIMFLOW_TANDY
	dw OFFSET _TEXT:GR_ANIMFLAG_CGA
	dw OFFSET _TEXT:GR_ANIMFLAG_EGA
	dw OFFSET _TEXT:GR_ANIMFLAG_TANDY
	dw OFFSET _TEXT:GR_PUTCHAR_CGA
	dw OFFSET _TEXT:GR_PUTCHAR_EGA
	dw OFFSET _TEXT:GR_PUTCHAR_TANDY
	dw OFFSET _TEXT:GR_CLRSCR_CGA
	dw OFFSET _TEXT:GR_CLRSCR_EGA
	dw OFFSET _TEXT:GR_CLRSCR_TANDY
	dw OFFSET _TEXT:GR_3_CGA
	dw OFFSET _TEXT:GR_B_EGA
	dw OFFSET _TEXT:GR_B_TANDY
	dw OFFSET _TEXT:GR_0_CGA
	dw OFFSET _TEXT:GR_C_EGA
	dw OFFSET _TEXT:GR_0_TANDY
;----------------------------------------
_DATA	ENDS
;########################################
CONST	SEGMENT PUBLIC WORD 'CONST'
;----------------------------------------
D_32D0	dw 00000h,00000h,00000h,00000h,00000h,00000h,00000h,00000h
	dw 00000h,00001h,0C004h,00010h,00080h,00104h,00400h,00401h
	dw 00100h,0C3C0h,01000h,0C410h,01004h,00411h,00110h,003C4h
	dw 01080h,0C481h,00110h,0C104h,01010h,0D101h,01084h,013C1h
	dw 01010h,01304h,0C484h,03CF0h,00F3Ch,00F3Fh,03C84h,03C3Fh
	dw 010F1h,013FCh,0CFC1h,03CF1h,0CFCFh,03CFFh,0D13Fh,03FF1h
	dw 0D3F1h,0F3FCh,03C8Fh,0CF8Fh,03F3Fh,0FFCFh,013FCh,0CFFFh
	dw 0FFFFh,0FFFFh,0FFFFh,0FFFFh,0FFFFh,0FFFFh,0FFFFh,0FFFFh
D_3350	db 00h,01h,02h,03h,04h,05h,06h,07h,38h,39h,3Ah,3Bh,3Ch,3Dh,3Eh,3Fh,00h
D_3361	db 00h,02h,04h,0Bh
D_3365	db 00h,40h,80h,0C0h
D_3369	db 00h,01h,02h,03h,04h,05h,06h,07h,38h,39h,3Ah,3Bh,3Ch,3Dh,3Eh,3Fh,00h
D_337A	db 00h,02h,04h,0Bh
GR_SEGMENT	dw 0B800h	;D_337E
;----------------------------------------
CONST	ENDS
;########################################
_BSS	SEGMENT PUBLIC WORD 'BSS'
;----------------------------------------
D_3A86	db 10h dup(?)	;random seed[only 4 bytes used]
;-- sizzle --
sizzleBuff	db 80h dup(?)	;D_3A96
;-- --
D_3B16	dw ?,?	;inflated file buffer far
D_3B1A	dw ?	;counter
D_3B1C	dw ?	;counter
D_3B1E	dw ?	;inflated file buffer near
;----------------------------------------
EXTRN patch_tandy:DWORD

EXTRN D_7078:WORD	;graphic adapter?
EXTRN pShapes:DWORD
EXTRN pCharset:DWORD
EXTRN txt_X:WORD
EXTRN txt_Y:WORD
;----------------------------------------
_BSS	ENDS
;########################################
_TEXT	SEGMENT PUBLIC BYTE 'CODE'
	ASSUME CS:_TEXT
;----------------------------------------
PUBLIC _Gra_0
_Gra_0:	;1186
	MOV	BX,0
	JMP	SHORT C_11C5
PUBLIC _Gra_dot
_Gra_dot:	;118B
	MOV	BX,1
	JMP	SHORT C_11C5
PUBLIC Gra_2
Gra_2:	;1190
	MOV	BX,2
	JMP	SHORT C_11C5
PUBLIC _Gra_3
_Gra_3:	;1195
	MOV	BX,3
	JMP	SHORT C_11C5
PUBLIC _Gra_inflate
_Gra_inflate:	;119A
	MOV	BX,4
	JMP	SHORT C_11C5
PUBLIC Gra_5
Gra_5:	;119F
	MOV	BX,5
	JMP	SHORT C_11C5
PUBLIC Gra_init
Gra_init:	;11A4
	MOV	BX,6
	JMP	SHORT C_11C5
PUBLIC Gra_animFlow
Gra_animFlow:	;11A9
	MOV	BX,7
	JMP	SHORT C_11C5
PUBLIC Gra_animFlag
Gra_animFlag:	;11AE
	MOV	BX,8
	JMP	SHORT C_11C5
PUBLIC Gra_putchar
Gra_putchar:	;11B3
	MOV	BX,9
	JMP	SHORT C_11C5
PUBLIC Gra_clrscr
Gra_clrscr:	;11B8
	MOV	BX,0Ah
	JMP	SHORT C_11C5
PUBLIC _Gra_C
_Gra_C:	;11BD
	MOV	BX,0Ch
	JMP	SHORT C_11C5
PUBLIC _Gra_B
_Gra_B:	;11C2
	MOV	BX,0Bh
;----
C_11C5:
	MOV	AX,BX
	SHL	BX,1
	ADD	BX,AX	;BX *= 3
	ADD	BX,[D_7078]
	DEC	BX
	SHL	BX,1
	JMP	D_03CE[BX]
;----------------------------------------
GR_0_TANDY:	;11D8
	PUSH	BP
	MOV	BP,SP
	PUSH	SI
	PUSH	DI
	PUSH	DS
	PUSH	ES
	;--
	MOV	DS,WORD PTR pShapes+2
	MOV	ES,GR_SEGMENT
	TEST	WORD PTR [BP+0Eh],0FFFFh
	JZ	C_11F3
	MOV	ES,[BP+0Eh]
C_11F3:
	MOV	BX,[BP+0Ah]
	SHL	BX,1
C_11F8:
	MOV	DX,[BP+10h]
	SHL	DX,1
	ADD	DX,[BP+0Ch]
	MOV	AX,[BP+06]
C_1203:
	MOV	SI,[BP+08]
	INC	WORD PTR [BP+08]
	MOV	SI,DGROUP:[SI]
	AND	SI,0FFh
	SHL	SI,1
	SHL	SI,1
	SHL	SI,1
	SHL	SI,1
	SHL	SI,1
	SHL	SI,1
	SHL	SI,1
	ADD	SI,WORD PTR pShapes
	MOV	CX,10h
C_1226:
	MOV	DI,Lines[BX]
	ADD	BX,2
	ADD	DI,DX
	MOVSW
	MOVSW
	MOVSW
	MOVSW
	LOOP	C_1226
	SUB	BX,20h
	ADD	DX,8
	DEC	AX
	JNZ	C_1203
	ADD	BX,20h
	DEC	WORD PTR [BP+04]
	JNZ	C_11F8
	;--
	POP	ES
	POP	DS
	POP	DI
	POP	SI
	POP	BP
	RET
;----------------------------------------124D
GR_0_EGA:
	PUSH	BP
	MOV	BP,SP
	SUB	SP,2
	PUSH	SI
	PUSH	DI
	PUSH	DS
	PUSH	ES
	;--
	MOV	DX,3C4h
	MOV	AL,2
	OUT	DX,AL
	;--
	MOV	DX,3C5h
	MOV	DS,WORD PTR pShapes+2
	MOV	ES,GR_SEGMENT
	MOV	BX,[BP+0Ah]
	SHL	BX,1
C_126F:
	MOV	DI,[BP+06]
	MOV	[BP-02],DI
	MOV	DI,Lines[BX]
	ADD	DI,1
C_127D:
	MOV	SI,[BP+08]
	INC	WORD PTR [BP+08]
	MOV	SI,DGROUP:[SI]
	AND	SI,0FFh
	SHL	SI,1
	SHL	SI,1
	SHL	SI,1
	SHL	SI,1
	SHL	SI,1
	SHL	SI,1
	SHL	SI,1
	ADD	SI,WORD PTR pShapes
	MOV	CH,8
C_129F:
	MOV	AL,CH
	OUT	DX,AL
	LODSW
	MOV	ES:[DI+0*28h],AX
	LODSW
	MOV	ES:[DI+1*28h],AX
	LODSW
	MOV	ES:[DI+2*28h],AX
	LODSW
	MOV	ES:[DI+3*28h],AX
	LODSW
	MOV	ES:[DI+4*28h],AX
	LODSW
	MOV	ES:[DI+5*28h],AX
	LODSW
	MOV	ES:[DI+6*28h],AX
	LODSW
	MOV	ES:[DI+7*28h],AX
	LODSW
	MOV	ES:[DI+8*28h],AX
	LODSW
	MOV	ES:[DI+9*28h],AX
	LODSW
	MOV	ES:[DI+0Ah*28h],AX
	LODSW
	MOV	ES:[DI+0Bh*28h],AX
	LODSW
	MOV	ES:[DI+0Ch*28h],AX
	LODSW
	MOV	ES:[DI+0Dh*28h],AX
	LODSW
	MOV	ES:[DI+0Eh*28h],AX
	LODSW
	MOV	ES:[DI+0Fh*28h],AX
	SHR	CH,1
	JNZ	C_129F
	ADD	DI,2
	DEC	BYTE PTR [BP-02]
	JZ	C_130C
	JMP	C_127D
C_130C:
	ADD	BX,20h
	DEC	WORD PTR [BP+04]
	JZ	C_1317
	JMP	C_126F
C_1317:
	POP	ES
	POP	DS
	POP	DI
	POP	SI
	MOV	SP,BP
	POP	BP
	RET	
;----------------------------------------
GR_C_EGA:
	PUSH	BP
	MOV	BP,SP
	SUB	SP,2
	PUSH	SI
	PUSH	DI
	PUSH	DS
	PUSH	ES
	;--
	MOV	DS,WORD PTR pShapes+2
	MOV	ES,[BP+0Eh]
	MOV	BX,[BP+0Ah]
	SHL	BX,1
C_1336:
	MOV	DI,[BP+06]
	MOV	[BP-02],DI
	MOV	DI,Lines[BX]
	ADD	DI,[BP+0Ch]
	ADD	DI,1
C_1347:
	MOV	SI,[BP+08]
	INC	WORD PTR [BP+08]
	MOV	SI,DGROUP:[SI]
	AND	SI,0FFh
	SHL	SI,1
	SHL	SI,1
	SHL	SI,1
	SHL	SI,1
	SHL	SI,1
	SHL	SI,1
	SHL	SI,1
	ADD	SI,WORD PTR pShapes
	MOV	CH,08
C_1369:
	LODSW
	MOV	ES:[DI+0*28h],AX
	LODSW
	MOV	ES:[DI+1*28h],AX
	LODSW
	MOV	ES:[DI+2*28h],AX
	LODSW
	MOV	ES:[DI+3*28h],AX
	LODSW
	MOV	ES:[DI+4*28h],AX
	LODSW
	MOV	ES:[DI+5*28h],AX
	LODSW
	MOV	ES:[DI+6*28h],AX
	LODSW
	MOV	ES:[DI+7*28h],AX
	LODSW
	MOV	ES:[DI+8*28h],AX
	LODSW
	MOV	ES:[DI+9*28h],AX
	LODSW
	MOV	ES:[DI+0Ah*28h],AX
	LODSW
	MOV	ES:[DI+0Bh*28h],AX
	LODSW
	MOV	ES:[DI+0Ch*28h],AX
	LODSW
	MOV	ES:[DI+0Dh*28h],AX
	LODSW
	MOV	ES:[DI+0Eh*28h],AX
	LODSW
	MOV	ES:[DI+0Fh*28h],AX
	ADD	DI,1F40h
	SHR	CH,1
	JNZ	C_1369
	SUB	DI,7D00h
	ADD	DI,2
	DEC	BYTE PTR [BP-02]
	JZ	C_13DB
	JMP	C_1347
C_13DB:
	ADD	BX,20h
	DEC	WORD PTR [BP+04]
	JZ	C_13E6
	JMP	C_1336
C_13E6:
	POP	ES
	POP	DS
	POP	DI
	POP	SI
	MOV	SP,BP
	POP	BP
	RET	
;----------------------------------------13EE
;close to CGA_DRV.C_027A
GR_0_CGA:
	PUSH	BP
	MOV	BP,SP
	PUSH	SI
	PUSH	DI
	PUSH	DS
	PUSH	ES
	;--
	MOV	DS,WORD PTR pShapes+2
	MOV	AH,[BP+04]
	MOV	AL,[BP+06]
	MOV	BX,[BP+08]
	MOV	DI,[BP+0Ah]
	SHL	DI,1
	MOV	DI,Lines[DI]
	ADD	DI,[BP+10h]
	ADD	DI,[BP+0Ch]
	MOV	ES,GR_SEGMENT
	TEST	WORD PTR [BP+0Eh],0FFFFh
	JZ	C_1422
	MOV	ES,[BP+0Eh]
C_1422:
	MOV	DH,AL
	SHL	DH,1
	SHL	DH,1
C_1428:
	MOV	DL,AL
C_142A:
	MOV	SI,DGROUP:[BX]
	INC	BX
	AND	SI,0FFh
	SHL	SI,1
	SHL	SI,1
	SHL	SI,1
	SHL	SI,1
	SHL	SI,1
	SHL	SI,1
	ADD	SI,WORD PTR pShapes
	MOV	CX,8
C_1446:
	MOVSW	
	MOVSW	
	ADD	DI,4Ch
	LOOP	C_1446
	ADD	DI,1D80h
	MOV	CX,8
C_1454:
	MOVSW	
	MOVSW	
	ADD	DI,4Ch
	LOOP	C_1454
	SUB	DI,227Ch
	DEC	DL
	JNZ	C_142A
	ADD	DI,280h
	MOV	CL,DH
	MOV	CH,0
	SUB	DI,CX
	DEC	AH
	JNZ	C_1428
	;--
	POP	ES
	POP	DS
	POP	DI
	POP	SI
	POP	BP
	RET	
;----------------------------------------
GR_DOT_TANDY:
	PUSH	BP
	MOV	BP,SP
	PUSH	ES
	;--
	MOV	ES,GR_SEGMENT
	MOV	BL,[BP+08]
	MOV	BH,0
	MOV	AL,D_3361[BX]
	MOV	BX,[BP+04]
	SHL	BX,1
	MOV	BX,Lines[BX]
	MOV	DX,[BP+06]
	SHR	DX,1
	JB	C_14A3
	SHL	AL,1
	SHL	AL,1
	SHL	AL,1
	SHL	AL,1
C_14A3:
	ADD	BX,DX
	OR	ES:[BX],AL
	;--
	POP	ES
	POP	BP
	RET	
;----------------------------------------14AB
GR_DOT_EGA:
	PUSH	BP
	MOV	BP,SP
	PUSH	ES
	;--
	MOV	ES,GR_SEGMENT
	MOV	CX,[BP+06]
	db 83h,0e1h,7	;AND	CX,7
	;--
	MOV	DX,3CEh
	MOV	AL,08
	OUT	DX,AL
	;--
	MOV	DX,3CFh
	MOV	AL,80h
	SHR	AL,CL
	OUT	DX,AL
	;--
	MOV	DX,3C4h
	MOV	AL,02
	OUT	DX,AL
	;--
	MOV	DX,3C5h
	MOV	BL,[BP+08]
	MOV	BH,00
	MOV	AL,D_337A[BX]
	OUT	DX,AL
	;--
	MOV	BX,[BP+04]
	SHL	BX,1
	MOV	BX,Lines[BX]
	MOV	AX,[BP+06]
	SHR	AX,1
	SHR	AX,1
	SHR	AX,1
	ADD	BX,AX
	OR	BYTE PTR ES:[BX],0FFh
	;--
	MOV	DX,3CFh
	MOV	AL,0FFh
	OUT	DX,AL
	;--
	POP	ES
	POP	BP
	RET	
;----------------------------------------14FE
GR_DOT_CGA:
	PUSH	BP
	MOV	BP,SP
	PUSH	ES
	;--
	MOV	ES,GR_SEGMENT
	MOV	BL,[BP+08]
	MOV	BH,0
	MOV	AH,D_3365[BX]
	MOV	DX,[BP+06]
	MOV	CL,DL
	SHR	DX,1
	SHR	DX,1
	MOV	BX,[BP+04]
	SHL	BX,1
	MOV	BX,Lines[BX]
	ADD	BX,DX
	AND	CL,3
	SHL	CL,1
	SHR	AH,CL
	OR	ES:[BX],AH
	;--
	POP	ES
	POP	BP
	RET	
;----------------------------------------
GR_2_TANDY:
	PUSH	DI
	PUSH	SI
	PUSH	ES
	;--
	MOV	AX,0
	MOV	ES,GR_SEGMENT
	LEA	BX,[Lines]
	MOV	SI,0D0h
C_1545:
	MOV	DI,[BX+SI]
	ADD	DI,4
	MOV	CX,4Ch
	REPZ	STOSW
	INC	SI
	INC	SI
	CMP	SI,170h
	JNZ	C_1545
	;--
	POP	ES
	POP	SI
	POP	DI
	RET	
;----------------------------------------155B
GR_2_EGA:
	PUSH	DI
	PUSH	SI
	PUSH	ES
	;--
	MOV	DX,3C4h
	MOV	AL,02
	OUT	DX,AL
	;--
	MOV	DX,3C5h
	MOV	AL,0Fh
	OUT	DX,AL
	;--
	MOV	AX,0
	MOV	ES,GR_SEGMENT
	LEA	BX,[Lines]
	MOV	SI,0D0h
C_1579:
	MOV	DI,[BX+SI]
	INC	DI
	MOV	CX,13h
	REPZ	STOSW	
	INC	SI
	INC	SI
	CMP	SI,170h
	JNZ	C_1579
	;--
	POP	ES
	POP	SI
	POP	DI
	RET	
;----------------------------------------
;clean the animation/menu zone?
GR_2_CGA:
	PUSH	DI
	PUSH	SI
	PUSH	ES
	;--
	MOV	AX,0
	MOV	ES,GR_SEGMENT
	LEA	BX,[Lines]
	MOV	SI,0D0h
C_159F:
	MOV	DI,[BX+SI]
	ADD	DI,2
	MOV	CX,26h
	REPZ	STOSW	
	INC	SI
	INC	SI
	CMP	SI,170h
	JNZ	C_159F
	;--
	POP	ES
	POP	SI
	POP	DI
	RET	
;----------------------------------------15B5
GR_3_TANDY:
	PUSH	BP
	MOV	BP,SP
	PUSH	DI
	PUSH	SI
	PUSH	DS
	PUSH	ES
	;--
	MOV	ES,GR_SEGMENT
	MOV	DS,[BP+0Eh]
	MOV	BX,[BP+0Ah]
	SHL	BX,1
	ADD	BX,23Ch
	MOV	DX,[BP+10h]
	SHL	DX,1
	ADD	DX,23Ch
C_15D6:
	MOV	SI,DGROUP:[BX]
	ADD	SI,[BP+0Ch]
	MOV	AX,[BP+08]
	SHL	AX,1
	SHL	AX,1
	ADD	SI,AX
	MOV	DI,DX
	MOV	DI,DGROUP:[DI]
	MOV	AX,[BP+14h]
	SHL	AX,1
	SHL	AX,1
	ADD	DI,AX
	MOV	CX,[BP+04]
	SHL	CX,1
	REPZ	MOVSW	
	ADD	BX,2
	ADD	DX,2
	DEC	WORD PTR [BP+06]
	JNZ	C_15D6
	;--
	POP	ES
	POP	DS
	POP	SI
	POP	DI
	MOV	SP,BP
	POP	BP
	RET	
;----------------------------------------160D
GR_B_TANDY:
	PUSH	BP
	MOV	BP,SP
	SUB	SP,2
	PUSH	DI
	PUSH	SI
	PUSH	DS
	PUSH	ES
	;-- backup port 61h
	IN	AL,61h
	MOV	[BP-02],AX
	;--
	MOV	ES,GR_SEGMENT
	MOV	DS,[BP+0Eh]
C_1624:
	MOV	SI,[BP+0Ah]
	ADD	SI,[BP+06]
	DEC	SI
	SHL	SI,1
	MOV	SI,Lines[SI]
	ADD	SI,[BP+0Ch]
	ADD	SI,[BP+08]
	ADD	SI,[BP+08]
	ADD	SI,[BP+08]
	ADD	SI,[BP+08]
	MOV	DI,[BP+10h]
	ADD	DI,[BP+06]
	DEC	DI
	SHL	DI,1
	MOV	DI,Lines[DI]
	ADD	DI,[BP+14h]
	ADD	DI,[BP+14h]
	ADD	DI,[BP+14h]
	ADD	DI,[BP+14h]
	MOV	BX,[BP+04]
	SHL	BX,1
	DEC	BX
	SHL	BX,1
C_1663:
	MOV	AX,[BX+SI]
	TEST	WORD PTR [BP+12h],0FFFFh
	JS	C_16AE
	TEST	AX,0FFFFh
	JZ	C_16B1
	MOV	DL,D_03CC
	ADD	DL,1Dh
	MOV	DH,DL
	ADC	DL,D_03CD
	MOV	D_03CC,DL
	MOV	D_03CD,DH
	MOV	DH,DL
	AND	DH,7
	ADD	DL,[BP+12h]
	JNB	C_169C
	;--
	PUSH	AX
	IN	AL,61h
	XOR	AL,2
	OUT	61h,AL
	POP	AX
C_169C:	;--
	MOV	DL,[BP+12h]
	ADD	DL,DH
	XCHG	BX,DX
	MOV	BH,00
	SHL	BX,1
	AND	AX,D_32D0[BX]
	XCHG	BX,DX
C_16AE:
	MOV	ES:[BX+DI],AX
C_16B1:
	DEC	BX
	DEC	BX
	JNS	C_1663
	DEC	WORD PTR [BP+06]
	JZ	C_16BD
	JMP	C_1624
C_16BD:
	TEST	WORD PTR [BP+12h],0FFFFh
	JS	C_16C9
	;-- restore port 61h
	MOV	AX,[BP-02]
	OUT	61h,AL
C_16C9:	;--
	POP	ES
	POP	DS
	POP	SI
	POP	DI
	MOV	SP,BP
	POP	BP
	RET	
;----------------------------------------16D1
GR_3_EGA:
	PUSH	BP
	MOV	BP,SP
	SUB	SP,2
	PUSH	SI
	PUSH	DI
	PUSH	DS
	PUSH	ES
	;--
	MOV	ES,GR_SEGMENT
	MOV	DS,[BP+0Eh]
	;--
	MOV	DX,3C4h
	MOV	AL,02
	OUT	DX,AL
	;--
	MOV	WORD PTR [BP-02],0000
	MOV	AL,08
C_16F0:
	MOV	DX,3C5h
	OUT	DX,AL
	;--
	MOV	BX,[BP+0Ah]
	SHL	BX,1
	LEA	DX,Lines[BX]
	MOV	BX,[BP+10h]
	SHL	BX,1
	LEA	BX,Lines[BX]
	MOV	AH,[BP+06]
C_1709:
	MOV	DI,[BP+14h]
	ADD	DI,DGROUP:[BX]
	ADD	BX,2
	XCHG	BX,DX
	MOV	SI,[BP+08]
	ADD	SI,DGROUP:[BX]
	ADD	SI,[BP+0Ch]
	ADD	SI,[BP-02]
	ADD	BX,2
	XCHG	BX,DX
	MOV	CX,[BP+04]
	REPZ	MOVSB	
	DEC	AH
	JNZ	C_1709
	ADD	WORD PTR [BP-02],1F40h
	SHR	AL,1
	JNB	C_16F0
	;--
	POP	ES
	POP	DS
	POP	DI
	POP	SI
	MOV	SP,BP
	POP	BP
	RET	
;----------------------------------------173F
GR_B_EGA:
	PUSH	BP
	MOV	BP,SP
	SUB	SP,4
	PUSH	SI
	PUSH	DI
	PUSH	DS
	PUSH	ES
	;-- backup port 61h
	IN	AL,61h
	MOV	[BP-02],AX
	;--
	MOV	ES,GR_SEGMENT
	MOV	DS,[BP+0Eh]
	;--
	MOV	DX,3C4h
	MOV	AL,02
	OUT	DX,AL
C_175C:	;--
	MOV	DI,[BP+10h]
	ADD	DI,[BP+06]
	DEC	DI
	SHL	DI,1
	MOV	DI,Lines[DI]
	ADD	DI,[BP+14h]
	MOV	SI,[BP+0Ah]
	ADD	SI,[BP+06]
	DEC	SI
	SHL	SI,1
	MOV	SI,Lines[SI]
	ADD	SI,[BP+0Ch]
	ADD	SI,[BP+08]
	MOV	CX,[BP+04]
C_1784:
	MOV	AL,[SI]
	OR	AL,[SI+1F40h]
	OR	AL,[SI+3E80h]
	OR	AL,[SI+5DC0h]
	TEST	AL,0FFh
	JZ	C_1809
	MOV	DL,D_03CC
	ADD	DL,1Dh
	MOV	DH,DL
	ADC	DL,D_03CD
	MOV	D_03CC,DL
	MOV	D_03CD,DH
	MOV	DH,DL
	AND	DH,7
	ADD	DL,[BP+12h]
	JNB	C_17C1
	;--
	PUSH	AX
	IN	AL,61h
	XOR	AL,2
	OUT	61h,AL
	POP	AX
C_17C1:	;--
	MOV	DL,[BP+12h]
	ADD	DL,DH
	XCHG	BX,DX
	MOV	BH,00
	SHL	BX,1
	;--
	MOV	DX,3C5h
	;--
	MOV	AL,08
	OUT	DX,AL
	;--
	MOV	AL,[SI]
	AND	AL,BYTE PTR D_32D0[BX]
	MOV	ES:[DI],AL
	;--
	MOV	AL,04
	OUT	DX,AL
	;--
	MOV	AL,[SI+1F40h]
	AND	AL,BYTE PTR D_32D0[BX]
	MOV	ES:[DI],AL
	;--
	MOV	AL,02
	OUT	DX,AL
	;--
	MOV	AL,[SI+3E80h]
	AND	AL,BYTE PTR D_32D0[BX]
	MOV	ES:[DI],AL
	;--
	MOV	AL,01
	OUT	DX,AL
	;--
	MOV	AL,[SI+5DC0h]
	AND	AL,BYTE PTR D_32D0[BX]
	MOV	ES:[DI],AL
C_1809:	;--
	INC	SI
	INC	DI
	DEC	CX
	JZ	C_1811
	JMP	C_1784
C_1811:
	DEC	WORD PTR [BP+06]
	JZ	C_1819
	JMP	C_175C
C_1819:	;-- restore port 61h
	MOV	AX,[BP-02]
	OUT	61h,AL
	;--
	POP	ES
	POP	DS
	POP	DI
	POP	SI
	MOV	SP,BP
	POP	BP
	RET	
;----------------------------------------1826
GR_3_CGA:
	PUSH	BP
	MOV	BP,SP
	SUB	SP,2
	PUSH	DI
	PUSH	SI
	PUSH	DS
	PUSH	ES
	;-- backup port 61h
	IN	AL,61h
	MOV	[BP-02],AX
	;--
	MOV	ES,GR_SEGMENT
	MOV	DS,[BP+0Ch+2]	;param_4.seg
C_183D:
	MOV	SI,[BP+0Ah]	;param_3
	ADD	SI,[BP+06]	;param_1
	DEC	SI
	SHL	SI,1
	MOV	SI,Lines[SI]
	ADD	SI,[BP+0Ch]	;param_4.off
	ADD	SI,[BP+08]	;param_2
	ADD	SI,[BP+08]	;param_2
	;--
	MOV	DI,[BP+10h]	;param_5
	ADD	DI,[BP+06]	;param_1
	DEC	DI
	SHL	DI,1
	MOV	DI,Lines[DI]
	ADD	DI,[BP+14h]	;param_7
	ADD	DI,[BP+14h]	;param_7
	;--
	MOV	BX,[BP+04]	;param_0
	DEC	BX
	SHL	BX,1
C_186E:	;--
	MOV	AX,[BX+SI]
	;---------------------
	;-- sound related ? --
	;---------------------
	TEST	WORD PTR [BP+12h],0FFFFh	;param_6
	JS	C_18B9
	TEST	AX,0FFFFh
	JZ	C_18BC
	MOV	DL,D_03CC
	ADD	DL,1Dh
	MOV	DH,DL
	ADC	DL,D_03CD
	MOV	D_03CC,DL
	MOV	D_03CD,DH
	MOV	DH,DL
	AND	DH,7
	ADD	DL,[BP+12h]	;param_6
	JNB	C_18A7
	;--
	PUSH	AX
	IN	AL,61h
	XOR	AL,2
	OUT	61h,AL
	POP	AX
C_18A7:	;--
	MOV	DL,[BP+12h]	;param_6
	ADD	DL,DH
	XCHG	BX,DX
	MOV	BH,0
	SHL	BX,1
	AND	AX,D_32D0[BX]
	XCHG	BX,DX
	;-------
C_18B9:	;--   --
	;-------
	MOV	ES:[BX+DI],AX
C_18BC:	DEC	BX
	DEC	BX
	JNS	C_186E
	;--
	DEC	WORD PTR [BP+06]	;param_1
	JZ	C_18C8
	JMP	C_183D
C_18C8:	;--
	TEST	WORD PTR [BP+12h],0FFFFh	;param_6
	JS	C_18D4
	;-- restore port 61h
	MOV	AX,[BP-02]
	OUT	61h,AL
C_18D4:	;--
	POP	ES
	POP	DS
	POP	SI
	POP	DI
	MOV	SP,BP
	POP	BP
	RET	
;----------------------------------------
GR_INFLATE_TANDY:
	PUSH	BP
	MOV	BP,SP
	;--
	MOV	WORD PTR [D_3B1C],0A0h
	MOV	WORD PTR [D_3B1A],0
	;--
	MOV	AX,[BP+06]
	MOV	[D_3B16],AX
	MOV	[D_3B1E],AX
	MOV	AX,[BP+08]
	MOV	[D_3B16+2],AX
	;--
	LEA	AX,[CB_tandy]
	PUSH	AX
	PUSH	[BP+04]
	CALL	_C_23C3	;load&inflate?
	ADD	SP,4
	;%%
	CMP	AX,-1
	JNZ	C_1919
	;--
	MOV	AX,36h
	PUSH	AX
	CALL	_exit
C_1919:	;-- ??
	MOV	AX,[D_3B1C]
	MOV	DX,[D_3B1A]
	;--
	POP	BP
	RET	
;----------------------------------------C_1924
CB_tandy:
	PUSH	ES
	PUSH	BX
	;-- put the byte at *(D_3B16 ++)
	LES	BX,DWORD PTR [D_3B16]
	INC	WORD PTR [D_3B16]
	MOV	ES:[BX],AL
	;--
	DEC	WORD PTR [D_3B1C]
	JNZ	C_195C
	;-- compute next scanline
	INC	WORD PTR [D_3B1A]
	MOV	BX,[D_3B1A]
	SHL	BX,1
	MOV	BX,Lines[BX]
	ADD	BX,[D_3B1E]
	MOV	[D_3B16],BX
	MOV	WORD PTR [D_3B1C],00A0h
C_195C:	;--
	POP	BX
	POP	ES
	RET	
;----------------------------------------
GR_INFLATE_EGA:
	PUSH	BP
	MOV	BP,SP
	PUSH	DI
	PUSH	ES
	;--
	MOV	WORD PTR [D_3B1C],80h
	;--
	LES	DI,[BP+06]
	MOV	[D_3B16],DI
	MOV	[D_3B16+2],ES
	MOV	AX,0
	MOV	CX,3E80h
	REPZ	STOSW	
	;--
	LEA	AX,[CB_ega]
	PUSH	AX
	PUSH	[BP+04]
	CALL	_C_23C3	;load&inflate?
	ADD	SP,4
	;%%
	CMP	AX,-1
	JNZ	C_199A
	;--
	MOV	AX,36h
	PUSH	AX
	CALL	_exit
C_199A:	;--
	POP	ES
	POP	DI
	POP	BP
	RET	
;----------------------------------------C_199E
CB_ega:
	PUSH	AX
	PUSH	DI
	PUSH	ES
	;--
	LES	DI,DWORD PTR [D_3B16]
	MOV	AH,BYTE PTR [D_3B1C]
	;--
	SHL	AL,1
	JNB	C_19B2
	OR	ES:[DI],AH
C_19B2:	;--
	SHL	AL,1
	JNB	C_19BB
	OR	ES:[DI+1F40h],AH
C_19BB:	;--
	SHL	AL,1
	JNB	C_19C4
	OR	ES:[DI+3E80h],AH
C_19C4:	;--
	SHL	AL,1
	JNB	C_19CD
	OR	ES:[DI+5DC0h],AH
C_19CD:	;--
	SHR	AH,1
	;--
	SHL	AL,1
	JNB	C_19D6
	OR	ES:[DI],AH
C_19D6:	;--
	SHL	AL,1
	JNB	C_19DF
	OR	ES:[DI+1F40h],AH
C_19DF:	;--
	SHL	AL,1
	JNB	C_19E8
	OR	ES:[DI+3E80h],AH
C_19E8:	;--
	SHL	AL,1
	JNB	C_19F1
	OR	ES:[DI+5DC0h],AH
C_19F1:	;--
	ROR	BYTE PTR [D_3B1C],1
	ROR	BYTE PTR [D_3B1C],1
	ADC	WORD PTR [D_3B16],0
	;--
	POP	ES
	POP	DI
	POP	AX
	RET	
;----------------------------------------1A05
GR_INFLATE_CGA:
	PUSH	BP
	MOV	BP,SP
	;-- to skip the first 7 bytes [bsave header]
	MOV	WORD PTR [D_3B1C],8
	;--
	MOV	AX,[BP+06]
	MOV	[D_3B16],AX
	MOV	AX,[BP+06+2]
	MOV	[D_3B16+2],AX
	;--
	LEA	AX,[CB_cga]
	PUSH	AX
	PUSH	[BP+04]
	CALL	_C_23C3	;load&inflate?
	ADD	SP,4
	;%%
	CMP	AX,-1
	JNZ	C_1A37
	;--
	MOV	AX,36h
	PUSH	AX
	CALL	_exit
C_1A37:	;--
	POP	BP
	RET	
;----------------------------------------C_1A39
CB_cga:
	DEC	WORD PTR [D_3B1C]
	JNZ	C_1A56	;skip this byte
	;--
	PUSH	ES
	PUSH	BX
	;--
	INC	WORD PTR [D_3B1C]
	;-- put the byte at *(D_3B16 ++)
	LES	BX,DWORD PTR [D_3B16]
	INC	WORD PTR [D_3B16]
	MOV	ES:[BX],AL
	;--
	POP	BX
	POP	ES
C_1A56:	;--
	RET	
;----------------------------------------
GR_5_TANDY:
	PUSH	DI
	PUSH	ES
	;--
	MOV	AX,0
	MOV	ES,GR_SEGMENT
	MOV	BX,130h
C_1A64:
	MOV	DI,Lines[BX]
	MOV	CX,50h
	REPZ	STOSW	
	INC	BX
	INC	BX
	CMP	BX,190h
	JB	C_1A64
	;--
	POP	ES
	POP	DI
	RET	
;----------------------------------------
GR_5_EGA:
	PUSH	DI
	PUSH	ES
	;--
	MOV	DX,3C4h
	MOV	AL,02
	OUT	DX,AL
	;--
	MOV	DX,3C5h
	MOV	AL,0Fh
	OUT	DX,AL
	;--
	MOV	AX,0
	MOV	ES,GR_SEGMENT
	MOV	BX,130h
C_1A92:
	MOV	DI,Lines[BX]
	MOV	CX,14h
	REPZ	STOSW	
	INC	BX
	INC	BX
	CMP	BX,190h
	JB	C_1A92
	;--
	POP	ES
	POP	DI
	RET	
;----------------------------------------1AA7
GR_5_CGA:
	PUSH	DI
	PUSH	ES
	MOV	AX,0
	;--
	MOV	ES,GR_SEGMENT
	MOV	BX,130h
C_1AB4:
	MOV	DI,Lines[BX]
	MOV	CX,28h
	REPZ	STOSW	
	INC	BX
	INC	BX
	CMP	BX,190h
	JB	C_1AB4
	;--
	POP	ES
	POP	DI
	RET	
;----------------------------------------
GR_INIT_TANDY:
	PUSH	ES
	;--
	MOV	AH,0
	MOV	AL,9
	INT	10h
	;--
	MOV	AX,SS
	MOV	ES,AX
	LEA	DX,[D_3350]
	MOV	AH,10h
	MOV	AL,02
	INT	10h
	;--
	MOV	BX,23Ch
	MOV	CX,0C7h
	ADD	BX,CX
	ADD	BX,CX
C_1AE8:
	PUSH	CX
	MOV	AX,CX
	MOV	DX,CX
	AND	AX,3
	MOV	AH,AL
	XOR	AL,AL
	MOV	CL,5
	SHL	AH,CL
	SHR	DX,1
	SHR	DX,1
	MOV	CL,5
	SHL	DX,CL
	ADD	AX,DX
	SHL	DX,1
	SHL	DX,1
	ADD	AX,DX
	MOV	[BX],AX
	SUB	BX,2
	POP	CX
	LOOP	C_1AE8
	;--
	POP	ES
	RET	
;----------------------------------------1B12
GR_INIT_CGA:
	PUSH	BP
	PUSH	ES
	;--
	MOV	ES,WORD PTR patch_tandy+2
	MOV	AH,49h	;free allocated memory
	INT	21h
	;--
	MOV	WORD PTR patch_tandy+2,0
	;--
	MOV	AH,0
	MOV	AL,4
	INT	10h
	;--
	MOV	AH,0Bh
	MOV	BH,0
	MOV	BL,0
	INT	10h
	;--
	MOV	AH,0Bh
	MOV	BH,1
	MOV	BL,1
	INT	10h
	;--
	POP	ES
	POP	BP
	RET	
;----------------------------------------1B3D
GR_INIT_EGA:
	PUSH	BP
	MOV	BP,SP
	PUSH	ES
	;--
	MOV	ES,WORD PTR patch_tandy+2
	MOV	AH,49h	;free allocated memory
	INT	21h
	;--
	MOV	WORD PTR patch_tandy+2,0
	;--
	MOV	AH,0
	MOV	AL,0Dh
	INT	10h
	;--
	MOV	AX,0A000h
	MOV	GR_SEGMENT,AX
	;--
	PUSH	DS
	POP	ES
	LEA	DX,[D_3369]
	;--
	MOV	AH,10h
	MOV	AL,2
	INT	10h
	;--
	MOV	DX,3C4h
	MOV	AL,2
	OUT	DX,AL
	;--
	MOV	DX,3C5h
	MOV	AL,0Fh
	OUT	DX,AL
	;--
	MOV	DX,3CEh
	MOV	AL,8
	OUT	DX,AL
	;--
	MOV	DX,3CFh
	MOV	AL,0FFh
	OUT	DX,AL
	;--
	MOV	AX,0
	MOV	CX,0C8h
	LEA	BX,[Lines]
C_1B8C:
	MOV	[BX],AX
	ADD	BX,2
	ADD	AX,28h
	LOOP	C_1B8C
	;--
	CALL	sizzleCharset
	CALL	sizzleShapes
	;--
	POP	ES
	POP	BP
	RET	
;----------------------------------------1B9F
GR_ANIMFLOW_TANDY:
	PUSH	BP
	MOV	BP,SP
	PUSHF	
	PUSH	AX
	PUSH	BX
	PUSH	CX
	PUSH	DX
	PUSH	SI
	PUSH	DI
	PUSH	DS
	PUSH	ES
	;--
	MOV	DS,WORD PTR SS:pShapes+2
	MOV	AX,DS
	MOV	ES,AX
	MOV	BX,[BP+04]
	SHL	BX,1
	SHL	BX,1
	SHL	BX,1
	SHL	BX,1
	SHL	BX,1
	SHL	BX,1
	SHL	BX,1
	ADD	BX,WORD PTR pShapes
	PUSH	[BX+78h]
	PUSH	[BX+7Ah]
	PUSH	[BX+7Ch]
	PUSH	[BX+7Eh]
	STD	
	LEA	SI,[BX+76h]
	LEA	DI,[BX+7Eh]
	MOV	CX,3Ch
	REPZ	MOVSW	
	POP	[BX+06]
	POP	[BX+04]
	POP	[BX+02]
	POP	[BX]
	;--
	POP	ES
	POP	DS
	POP	DI
	POP	SI
	POP	DX
	POP	CX
	POP	BX
	POP	AX
	POPF	
	POP	BP
	RET	2
;----------------------------------------
GR_ANIMFLOW_EGA:
	PUSH	BP
	MOV	BP,SP
	PUSHF	
	PUSH	SI
	PUSH	DI
	PUSH	DS
	PUSH	ES
	;--
	MOV	DS,WORD PTR pShapes+2
	MOV	AX,DS
	MOV	ES,AX
	MOV	BX,[BP+04]
	SHL	BX,1
	SHL	BX,1
	SHL	BX,1
	SHL	BX,1
	SHL	BX,1
	SHL	BX,1
	SHL	BX,1
	ADD	BX,WORD PTR pShapes
	PUSH	[BX+1Eh]
	PUSH	[BX+3Eh]
	PUSH	[BX+5Eh]
	PUSH	[BX+7Eh]
	STD	
	LEA	SI,[BX+7Ch]
	LEA	DI,[BX+7Eh]
	MOV	CX,3Fh
	REPZ	MOVSW	
	POP	[BX+60h]
	POP	[BX+40h]
	POP	[BX+20h]
	POP	[BX]
	;--
	POP	ES
	POP	DS
	POP	DI
	POP	SI
	POPF	
	POP	BP
	RET	2
;----------------------------------------1C4D
;close to CGA_DRV.C_0B1A
GR_ANIMFLOW_CGA:
	PUSH	BP
	MOV	BP,SP
	PUSH	DS
	;--
	MOV	DS,WORD PTR pShapes+2
	MOV	BX,[BP+04]
	SHL	BX,1
	SHL	BX,1
	SHL	BX,1
	SHL	BX,1
	SHL	BX,1
	SHL	BX,1
	;--
	ADD	BX,WORD PTR pShapes
	MOV	AX,[BX+3Ch]
	MOV	DX,[BX+3Eh]
	MOV	CX,8
C_1C73:
	XCHG	AX,[BX]
	XCHG	AX,[BX+20h]
	XCHG	DX,[BX+2]
	XCHG	DX,[BX+22h]
	ADD	BX,4
	LOOP	C_1C73
	;--
	POP	DS
	POP	BP
	RET	2
;----------------------------------------
GR_ANIMFLAG_TANDY:
	PUSH	ES
	;--
	LES	BX,pShapes
	CALL	C_208A	;random?
	JS	C_1CA2
	MOV	AX,ES:[BX+051Ah]
	XCHG	AX,ES:[BX+0522h]
	MOV	ES:[BX+051Ah],AX
C_1CA2:
	CALL	C_208A	;random?
	JS	C_1CB6
	MOV	AX,ES:[BX+058Ch]
	XCHG	AX,ES:[BX+0594h]
	MOV	ES:[BX+058Ch],AX
C_1CB6:
	CALL	C_208A	;random?
	JS	C_1CCA
	MOV	AX,ES:[BX+0813h]
	XCHG	AX,ES:[BX+081Bh]
	MOV	ES:[BX+0813h],AX
C_1CCA:
	CALL	C_208A	;random?
	JS	C_1CDE
	MOV	AX,ES:[BX+0913h]
	XCHG	AX,ES:[BX+091Bh]
	MOV	ES:[BX+0913h],AX
C_1CDE:
	CALL	C_208A	;random?
	JS	C_1CF2
	MOV	AX,ES:[BX+070Ah]
	XCHG	AX,ES:[BX+0712h]
	MOV	ES:[BX+070Ah],AX
C_1CF2:
	POP	ES
	RET
;----------------------------------------1CF4
GR_ANIMFLAG_EGA:
	PUSH	ES
	;--
	LES	BX,pShapes
	CALL	C_208A	;random?
	JS	C_1D3B
	MOV	AX,ES:[BX+0506h]
	XCHG	AX,ES:[BX+0508h]
	MOV	ES:[BX+0506h],AX
	MOV	AX,ES:[BX+0526h]
	XCHG	AX,ES:[BX+0528h]
	MOV	ES:[BX+0526h],AX
	MOV	AX,ES:[BX+0546h]
	XCHG	AX,ES:[BX+0548h]
	MOV	ES:[BX+0546h],AX
	MOV	AX,ES:[BX+0566h]
	XCHG	AX,ES:[BX+0568h]
	MOV	ES:[BX+0566h],AX
C_1D3B:
	CALL	C_208A	;random?
	JS	C_1D7C
	MOV	AX,ES:[BX+0582h]
	XCHG	AX,ES:[BX+0584h]
	MOV	ES:[BX+0582h],AX
	MOV	AX,ES:[BX+05A2h]
	XCHG	AX,ES:[BX+05A4h]
	MOV	ES:[BX+05A2h],AX
	MOV	AX,ES:[BX+05C2h]
	XCHG	AX,ES:[BX+05C4h]
	MOV	ES:[BX+05C2h],AX
	MOV	AX,ES:[BX+05E2h]
	XCHG	AX,ES:[BX+05E4h]
	MOV	ES:[BX+05E2h],AX
C_1D7C:
	CALL	C_208A	;random?
	JS	C_1DBD
	MOV	AX,ES:[BX+0804h]
	XCHG	AX,ES:[BX+0806h]
	MOV	ES:[BX+0804h],AX
	MOV	AX,ES:[BX+0824h]
	XCHG	AX,ES:[BX+0826h]
	MOV	ES:[BX+0824h],AX
	MOV	AX,ES:[BX+0844h]
	XCHG	AX,ES:[BX+0846h]
	MOV	ES:[BX+0844h],AX
	MOV	AX,ES:[BX+0864h]
	XCHG	AX,ES:[BX+0866h]
	MOV	ES:[BX+0864h],AX
C_1DBD:
	CALL	C_208A	;random?
	JS	C_1DFE
	MOV	AX,ES:[BX+0904h]
	XCHG	AX,ES:[BX+0906h]
	MOV	ES:[BX+0904h],AX
	MOV	AX,ES:[BX+0924h]
	XCHG	AX,ES:[BX+0926h]
	MOV	ES:[BX+0924h],AX
	MOV	AX,ES:[BX+0944h]
	XCHG	AX,ES:[BX+0946h]
	MOV	ES:[BX+0944h],AX
	MOV	AX,ES:[BX+0964h]
	XCHG	AX,ES:[BX+0966h]
	MOV	ES:[BX+0964h],AX
C_1DFE:
	CALL	C_208A	;random?
	JS	C_1E3F
	MOV	AX,ES:[BX+0702h]
	XCHG	AX,ES:[BX+0704h]
	MOV	ES:[BX+0702h],AX
	MOV	AX,ES:[BX+0722h]
	XCHG	AX,ES:[BX+0724h]
	MOV	ES:[BX+0722h],AX
	MOV	AX,ES:[BX+0742h]
	XCHG	AX,ES:[BX+0744h]
	MOV	ES:[BX+0742h],AX
	MOV	AX,ES:[BX+0762h]
	XCHG	AX,ES:[BX+0764h]
	MOV	ES:[BX+0762h],AX
C_1E3F:
	POP	ES
	RET	
;----------------------------------------1E41
;close to CGA_DRV.C_0B55
GR_ANIMFLAG_CGA:
	PUSH	ES
	;--
	LES	BX,pShapes
	;--
	CALL	C_208A	;random?
	JS	C_1E5B
	MOV	AX,WORD PTR ES:[BX+02A4h]
	XCHG	AX,WORD PTR ES:[BX+0288h]
	MOV	WORD PTR ES:[BX+02A4h],AX
C_1E5B:
	CALL	C_208A	;random?
	JS	C_1E6F
	MOV	AX,WORD PTR ES:[BX+02E2h]
	XCHG	AX,WORD PTR ES:[BX+02C6h]
	MOV	WORD PTR ES:[BX+02E2h],AX
C_1E6F:
	CALL	C_208A	;random?
	JS	C_1E92
	MOV	AX,WORD PTR ES:[BX+0404h]
	XCHG	AX,WORD PTR ES:[BX+0424h]
	MOV	WORD PTR ES:[BX+0404h],AX
	MOV	AX,WORD PTR ES:[BX+0406h]
	XCHG	AX,WORD PTR ES:[BX+0426h]
	MOV	WORD PTR ES:[BX+0406h],AX
C_1E92:
	CALL	C_208A	;random?
	JS	C_1EB5
	MOV	AX,WORD PTR ES:[BX+0484h]
	XCHG	AX,WORD PTR ES:[BX+04A4h]
	MOV	WORD PTR ES:[BX+0484h],AX
	MOV	AX,WORD PTR ES:[BX+0486h]
	XCHG	AX,WORD PTR ES:[BX+04A6h]
	MOV	WORD PTR ES:[BX+0486h],AX
C_1EB5:
	CALL	C_208A	;random?
	JS	C_1EC9
	MOV	AX,WORD PTR ES:[BX+03A0h]
	XCHG	AX,WORD PTR ES:[BX+0384h]
	MOV	WORD PTR ES:[BX+03A0h],AX
C_1EC9:
	POP	ES
	RET	
;----------------------------------------1ECB
GR_PUTCHAR_TANDY:
	PUSH	BP
	MOV	BP,SP
	PUSHF	
	PUSH	AX
	PUSH	BX
	PUSH	SI
	PUSH	DI
	PUSH	ES
	PUSH	DS
	;--
	MOV	AL,[BP+04]
	MOV	ES,GR_SEGMENT
	MOV	AH,0
	SHL	AX,1
	SHL	AX,1
	SHL	AX,1
	SHL	AX,1
	SHL	AX,1
	MOV	SI,AX
	ADD	SI,WORD PTR pCharset
	MOV	DS,WORD PTR pCharset+2
	MOV	BX,txt_Y
	SHL	BX,1
	SHL	BX,1
	SHL	BX,1
	SHL	BX,1
	MOV	DX,txt_X
	SHL	DX,1
	SHL	DX,1
	MOV	CX,8
C_1F0E:
	MOV	DI,Lines[BX]
	ADD	BX,2
	ADD	DI,DX
	LODSW
	MOV	ES:[DI],AX
	LODSW
	MOV	ES:[DI+02],AX
	LOOP	C_1F0E
	;--
	POP	DS
	POP	ES
	POP	DI
	POP	SI
	POP	BX
	POP	AX
	POPF	
	POP	BP
	RET	2
;----------------------------------------1F2E
GR_PUTCHAR_EGA:
	PUSH	BP
	MOV	BP,SP
	PUSH	SI
	PUSH	DI
	PUSH	DS
	PUSH	ES
	;--
	MOV	ES,GR_SEGMENT
	MOV	AL,[BP+04]
	MOV	AH,0
	SHL	AX,1
	SHL	AX,1
	SHL	AX,1
	SHL	AX,1
	SHL	AX,1
	LDS	SI,pCharset
	ADD	SI,AX
	;--
	MOV	BX,txt_Y
	SHL	BX,1
	SHL	BX,1
	SHL	BX,1
	SHL	BX,1
	MOV	BX,Lines[BX]
	ADD	BX,txt_X
	;--
	MOV	DX,3C4h
	MOV	AL,2
	OUT	DX,AL
	;--
	MOV	DX,3C5h
	;--
	MOV	CL,8
C_1F72:
	MOV	AL,CL
	OUT	DX,AL
	;--
	LODSB	
	MOV	ES:[BX+0*28h],AL
	LODSB	
	MOV	ES:[BX+1*28h],AL
	LODSB	
	MOV	ES:[BX+2*28h],AL
	LODSB	
	MOV	ES:[BX+3*28h],AL
	LODSB	
	MOV	ES:[BX+4*28h],AL
	LODSB	
	MOV	ES:[BX+5*28h],AL
	LODSB	
	MOV	ES:[BX+6*28h],AL
	LODSB	
	MOV	ES:[BX+7*28h],AL
	SHR	CL,1
	JNZ	C_1F72
	;--
	POP	ES
	POP	DS
	POP	DI
	POP	SI
	POP	BP
	RET	2
;----------------------------------------1FAC
;close to CGA_DRV.C_0BDF
GR_PUTCHAR_CGA:
	PUSH	BP
	MOV	BP,SP
	PUSHF	
	PUSH	AX
	PUSH	BX
	PUSH	SI
	PUSH	ES
	PUSH	DS
	;--
	MOV	AL,[BP+04]
	MOV	ES,GR_SEGMENT
	MOV	AH,0
	SHL	AX,1
	SHL	AX,1
	SHL	AX,1
	SHL	AX,1
	MOV	SI,AX
	ADD	SI,WORD PTR pCharset
	MOV	DS,WORD PTR pCharset+2
	MOV	BX,txt_Y
	SHL	BX,1
	SHL	BX,1
	SHL	BX,1
	SHL	BX,1
	SHL	BX,1
	SHL	BX,1
	MOV	AX,BX
	SHL	BX,1
	SHL	BX,1
	ADD	BX,AX
	MOV	AX,txt_X
	SHL	AX,1
	ADD	BX,AX
	LODSW
	MOV	ES:[BX+0*50h],AX
	LODSW
	MOV	ES:[BX+1*50h],AX
	LODSW
	MOV	ES:[BX+2*50h],AX
	LODSW
	MOV	ES:[BX+3*50h],AX
	LODSW
	MOV	ES:[BX+2000h+0*50h],AX
	LODSW
	MOV	ES:[BX+2000h+1*50h],AX
	LODSW
	MOV	ES:[BX+2000h+2*50h],AX
	LODSW
	MOV	ES:[BX+2000h+3*50h],AX
	;--
	POP	DS
	POP	ES
	POP	SI
	POP	BX
	POP	AX
	POPF	
	POP	BP
	RET	2
;----------------------------------------
GR_CLRSCR_TANDY:
	PUSH	DI
	PUSH	ES
	;--
	MOV	AX,0
	MOV	ES,GR_SEGMENT
	MOV	BX,18Eh
C_2038:
	MOV	DI,Lines[BX]
	MOV	CX,50h
	REPZ	STOSW	
	SUB	BX,2
	JNS	C_2038
	;--
	POP	ES
	POP	DI
	RET	
;----------------------------------------
GR_CLRSCR_EGA:
	PUSH	DI
	PUSH	ES
	;--
	MOV	DX,3C4h
	MOV	AL,2
	OUT	DX,AL
	;--
	MOV	DX,3C5h
	MOV	AL,0Fh
	OUT	DX,AL
	;--
	MOV	AX,0
	MOV	ES,GR_SEGMENT
	MOV	DI,0
	MOV	CX,0FA0h
	REPZ	STOSW	
	;--
	POP	ES
	POP	DI
	RET	
;----------------------------------------
;close to CGA_DRV.C_0A15
GR_CLRSCR_CGA:
	PUSH	DI
	PUSH	ES
	MOV	AX,0
	;--
	MOV	ES,GR_SEGMENT
	MOV	BX,18Eh
C_2078:
	MOV	DI,Lines[BX]
	MOV	CX,50h
	REPZ	STOSW	
	SUB	BX,2
	JNS	C_2078
	;--
	POP	ES
	POP	DI
	RET	
;----------------------------------------
;random?
C_208A	PROC NEAR
	MOV	AL,D_3A86[3]
	ADC	AL,D_3A86[2]
	MOV	D_3A86[2],AL
	XOR	D_3A86[1],AL
	MOV	AL,D_3A86[1]
	ADC	AL,D_3A86[0]
	ROR	AL,1
	MOV	D_3A86[0],AL
	MOV	D_3A86[3],AL
	MOV	AH,0
	TEST	AL,0FFh
	RET	
C_208A	ENDP
;----------------------------------------

;----------------------------------------
ASSUME DS:DGROUP,SS:NOTHING
;----------------------------------------
;(TITLE.EXE:_C_20B4/AVATAR.EXE:C_2341)
PUBLIC sizzleCharset
sizzleCharset	PROC NEAR
	PUSH	SI
	PUSH	DI
	PUSH	ES
	;--
	LES	SI,pCharset
	MOV	DI,SI
	MOV	CX,80h
C_20C0:
	MOV	DH,8
	MOV	BX,OFFSET DGROUP:sizzleBuff
C_20C5:
	MOV	DL,4
C_20C7:
	LODS	BYTE PTR ES:[SI]
	SHL	AL,1
	RCL	BYTE PTR [BX+00h],1
	SHL	AL,1
	RCL	BYTE PTR [BX+08h],1
	SHL	AL,1
	RCL	BYTE PTR [BX+10h],1
	SHL	AL,1
	RCL	BYTE PTR [BX+18h],1
	SHL	AL,1
	RCL	BYTE PTR [BX+00h],1
	SHL	AL,1
	RCL	BYTE PTR [BX+08h],1
	SHL	AL,1
	RCL	BYTE PTR [BX+10h],1
	SHL	AL,1
	RCL	BYTE PTR [BX+18h],1
	DEC	DL
	JNZ	C_20C7
	INC	BX
	DEC	DH
	JNZ	C_20C5
	MOV	DX,CX
	;--
	MOV	SI,OFFSET DGROUP:sizzleBuff
	MOV	CX,10h
	REPZ	MOVSW
	;--
	MOV	CX,DX
	MOV	SI,DI
	LOOP	C_20C0
	;--
	POP	ES
	POP	DI
	POP	SI
	RET	
sizzleCharset	ENDP
;----------------------------------------C_210C
;(TITLE.EXE:_C_210C/AVATAR.EXE:C_22CF)
PUBLIC sizzleShapes
sizzleShapes	PROC NEAR
	PUSH	SI
	PUSH	DI
	PUSH	ES
	;--
	LES	SI,pShapes
	MOV	DI,SI
	MOV	CX,100h
C_2118:
	MOV	DH,10h
	MOV	BX,OFFSET DGROUP:sizzleBuff
C_211D:
	MOV	DL,8
C_211F:
	LODS	BYTE PTR ES:[SI]
	SHL	AL,1
	RCL	BYTE PTR [BX+01h],1
	RCL	BYTE PTR [BX+00h],1
	SHL	AL,1
	RCL	BYTE PTR [BX+21h],1
	RCL	BYTE PTR [BX+20h],1
	SHL	AL,1
	RCL	BYTE PTR [BX+41h],1
	RCL	BYTE PTR [BX+40h],1
	SHL	AL,1
	RCL	BYTE PTR [BX+61h],1
	RCL	BYTE PTR [BX+60h],1
	SHL	AL,1
	RCL	BYTE PTR [BX+01h],1
	RCL	BYTE PTR [BX+00h],1
	SHL	AL,1
	RCL	BYTE PTR [BX+21h],1
	RCL	BYTE PTR [BX+20h],1
	SHL	AL,1
	RCL	BYTE PTR [BX+41h],1
	RCL	BYTE PTR [BX+40h],1
	SHL	AL,1
	RCL	BYTE PTR [BX+61h],1
	RCL	BYTE PTR [BX+60h],1
	DEC	DL
	JNZ	C_211F
	ADD	BX,2
	DEC	DH
	JNZ	C_211D
	MOV	DX,CX
	;--
	MOV	SI,OFFSET DGROUP:sizzleBuff
	MOV	CX,40h
	REPZ	MOVSW
	;--
	MOV	CX,DX
	MOV	SI,DI
	LOOP	C_2118
	;--
	POP	ES
	POP	DI
	POP	SI
	RET
sizzleShapes	ENDP
;----------------------------------------

;----------------------------------------
ASSUME DS:NOTHING,SS:DGROUP
;----------------------------------------
;inflate[frontend]
;[bp+08] file name
;[bp+04] far pointer
PUBLIC C_217E
C_217E	PROC NEAR
	PUSH	BP
	MOV	BP,SP
	;--
	MOV	AX,[BP+04]
	MOV	[D_3B16],AX
	MOV	AX,[BP+04+2]
	MOV	[D_3B16+2],AX
	;--
	LEA	AX,[CB_dummy]
	PUSH	AX
	PUSH	[BP+08]
	CALL	_C_23C3	;load&inflate?
	ADD	SP,4
	;%%
	CMP	AX,-1
	JNZ	C_21A9
	;--
	MOV	AX,36h
	PUSH	AX
	CALL	_exit
C_21A9:	;--
	POP	BP
	RET	6
C_217E	ENDP
;----------------------------------------C_21AD
CB_dummy:
	PUSH	ES
	PUSH	BX
	;-- put the byte at *(D_3B16 ++)
	LES	BX,DWORD PTR [D_3B16]
	INC	WORD PTR [D_3B16]
	MOV	ES:[BX],AL
	;--
	POP	BX
	POP	ES
	RET	
;----------------------------------------
_TEXT	ENDS
;########################################
END
