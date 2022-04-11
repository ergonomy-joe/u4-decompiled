;----------------------------------------
X	EQU 2
X_FAR	EQU 4
;########################################
_TEXT	SEGMENT
	ASSUME CS:_TEXT
;----------------------------------------
C_0000	dw OFFSET _TEXT:C_0C5B	;called through Gra_00
C_0002	dw OFFSET _TEXT:C_01E6	;called through Gra_01 
C_0004	dw OFFSET _TEXT:C_027A	;called through Gra_02
C_0006	dw OFFSET _TEXT:C_02EE	;called through Gra_03
C_0008	dw OFFSET _TEXT:C_033E	;called through Gra_04
C_000A	dw OFFSET _TEXT:C_0392	;called through Gra_05
C_000C	dw OFFSET _TEXT:C_05A8	;called through Gra_dot
C_000E	dw 0
C_0010	dw OFFSET _TEXT:C_0404	;called through Gra_CR
C_0012	dw OFFSET _TEXT:C_0449	;called through Gra_09
C_0014	dw OFFSET _TEXT:C_046D	;called through Gra_10
C_0016	dw OFFSET _TEXT:C_0493	;called through Gra_11
C_0018	dw OFFSET _TEXT:C_04D7	;called through Gra_12(uncalled)
C_001A	dw OFFSET _TEXT:C_050E	;called through Gra_13
C_001C	dw OFFSET _TEXT:C_0534	;called through Gra_dot_OR
C_001E	dw OFFSET _TEXT:C_056E	;called through Gra_dot_XOR
C_0020	dw OFFSET _TEXT:_pic_inflate	;called through Gra_16
C_0022	dw OFFSET _TEXT:C_074D	;called through Gra_17
C_0024	dw OFFSET _TEXT:C_0815	;called through Gra_18
C_0026	dw OFFSET _TEXT:C_0910	;called throuch Gra_19
C_0028	dw OFFSET _TEXT:C_095B	;called through Gra_animSpit
C_002A	dw OFFSET _TEXT:C_09C6	;called through Gra_init
C_002C	dw OFFSET _TEXT:C_0A15	;called through Gra_clrscr
C_002E	dw OFFSET _TEXT:C_0B1A	;called through Gra_animFlow
C_0030	dw OFFSET _TEXT:C_0B55	;called through Gra_animFlag
C_0032	dw OFFSET _TEXT:C_0BDF	;called through Gra_putchar
;----------------------------------------
GR_SEGMENT	dw 0B800h	;C_0034
C_0036	db 12h,34h,56h,78h	;random seed
__003A	db 0D5h,0AAh,0C3h,3Ch	;random seed too?(unused?)
__003E	db 01h,02h,04h,08h 	;random seed too?(unused?)
__0042	db 10h,20h,40h,80h	;random seed too?(unused?)
pShapes	dw 0,0	;C_0046
pCharset	dw 0,0	;C_004A
pExit	dw 0,0	;C_004E
Lines	dw  0*50h, 0*50h+2000h, 1*50h, 1*50h+2000h, 2*50h, 2*50h+2000h, 3*50h, 3*50h+2000h	;C_0052
	dw  4*50h, 4*50h+2000h, 5*50h, 5*50h+2000h, 6*50h, 6*50h+2000h, 7*50h, 7*50h+2000h
	dw  8*50h, 8*50h+2000h, 9*50h, 9*50h+2000h,10*50h,10*50h+2000h,11*50h,11*50h+2000h
	dw 12*50h,12*50h+2000h,13*50h,13*50h+2000h,14*50h,14*50h+2000h,15*50h,15*50h+2000h
	dw 16*50h,16*50h+2000h,17*50h,17*50h+2000h,18*50h,18*50h+2000h,19*50h,19*50h+2000h
	dw 20*50h,20*50h+2000h,21*50h,21*50h+2000h,22*50h,22*50h+2000h,23*50h,23*50h+2000h
	dw 24*50h,24*50h+2000h,25*50h,25*50h+2000h,26*50h,26*50h+2000h,27*50h,27*50h+2000h
	dw 28*50h,28*50h+2000h,29*50h,29*50h+2000h,30*50h,30*50h+2000h,31*50h,31*50h+2000h
	dw 32*50h,32*50h+2000h,33*50h,33*50h+2000h,34*50h,34*50h+2000h,35*50h,35*50h+2000h
	dw 36*50h,36*50h+2000h,37*50h,37*50h+2000h,38*50h,38*50h+2000h,39*50h,39*50h+2000h
	dw 40*50h,40*50h+2000h,41*50h,41*50h+2000h,42*50h,42*50h+2000h,43*50h,43*50h+2000h
	dw 44*50h,44*50h+2000h,45*50h,45*50h+2000h,46*50h,46*50h+2000h,47*50h,47*50h+2000h
	dw 48*50h,48*50h+2000h,49*50h,49*50h+2000h,50*50h,50*50h+2000h,51*50h,51*50h+2000h
	dw 52*50h,52*50h+2000h,53*50h,53*50h+2000h,54*50h,54*50h+2000h,55*50h,55*50h+2000h
	dw 56*50h,56*50h+2000h,57*50h,57*50h+2000h,58*50h,58*50h+2000h,59*50h,59*50h+2000h
	dw 60*50h,60*50h+2000h,61*50h,61*50h+2000h,62*50h,62*50h+2000h,63*50h,63*50h+2000h
	dw 64*50h,64*50h+2000h,65*50h,65*50h+2000h,66*50h,66*50h+2000h,67*50h,67*50h+2000h
	dw 68*50h,68*50h+2000h,69*50h,69*50h+2000h,70*50h,70*50h+2000h,71*50h,71*50h+2000h
	dw 72*50h,72*50h+2000h,73*50h,73*50h+2000h,74*50h,74*50h+2000h,75*50h,75*50h+2000h
	dw 76*50h,76*50h+2000h,77*50h,77*50h+2000h,78*50h,78*50h+2000h,79*50h,79*50h+2000h
	dw 80*50h,80*50h+2000h,81*50h,81*50h+2000h,82*50h,82*50h+2000h,83*50h,83*50h+2000h
	dw 84*50h,84*50h+2000h,85*50h,85*50h+2000h,86*50h,86*50h+2000h,87*50h,87*50h+2000h
	dw 88*50h,88*50h+2000h,89*50h,89*50h+2000h,90*50h,90*50h+2000h,91*50h,91*50h+2000h
	dw 92*50h,92*50h+2000h,93*50h,93*50h+2000h,94*50h,94*50h+2000h,95*50h,95*50h+2000h
	dw 96*50h,96*50h+2000h,97*50h,97*50h+2000h,98*50h,98*50h+2000h,99*50h,99*50h+2000h
C_01E2	db 00h,40h,80h,0C0h
;----------------------------------------
;Gra_01(cdecl)
;----------------------------------------
C_01E6	PROC FAR
	PUSH	BP
	MOV	BP,SP
	SUB	SP,2
	PUSH	SI
	PUSH	DI
	PUSH	DS
	PUSH	ES
	;--
	MOV	DS,CS:pShapes+2
	MOV	ES,CS:GR_SEGMENT
	MOV	SI,[BP+X_FAR+2]	;Tile
	SHL	SI,1
	SHL	SI,1
	SHL	SI,1
	SHL	SI,1
	SHL	SI,1
	SHL	SI,1
	ADD	SI,CS:pShapes
	MOV	AX,[BP+X_FAR+4]	;TRow
	MOV	BX,AX
	SHR	AX,1
	AND	BX,1
	SHL	BX,1
	SHL	BX,1
	SHL	BX,1
	ADD	AX,BX
	SHL	AX,1
	SHL	AX,1
	ADD	SI,AX
	MOV	DI,[BP+X_FAR+8]	;SCol
	MOV	BX,[BP+X_FAR+6]	;SRow
	SHL	BX,1
	ADD	DI,CS:Lines[BX]
	MOV	BX,[BP+X_FAR+0Ah]	;Exp
	MOV	BH,BL
	MOV	AX,4
	MOV	[BP-02],AX
C_023E:
	LODSB	
	MOV	DH,BH
C_0241:
	MOV	CL,BH
	XOR	CL,3
	MOV	BL,1
	SHL	BL,CL
	MOV	DL,0
C_024C:
	MOV	CL,BH
	MOV	AH,AL
C_0250:
	RCL	AL,1
	RCL	DL,1
	RCL	AL,1
	RCL	DL,1
	DEC	CL
	JZ	C_0260
	MOV	AL,AH
	JMP	C_0250
C_0260:
	DEC	BL
	JNZ	C_024C
	MOV	ES:[DI],DL
	INC	DI
	DEC	DH
	JNZ	C_0241
	DEC	BYTE PTR [BP-02]
	JNZ	C_023E
	;--
	POP	ES
	POP	DS
	POP	DI
	POP	SI
	ADD	SP,2
	POP	BP
	RET
C_01E6	ENDP
;----------------------------------------
;Gra_02(cdecl)
;----------------------------------------
C_027A	PROC FAR
	PUSH	BP
	MOV	BP,SP
	PUSH	SI
	PUSH	DI
	PUSH	DS
	PUSH	ES
	;--
	MOV	AH,[BP+X_FAR+2]
	MOV	AL,[BP+X_FAR+4]
	MOV	DI,[BP+X_FAR+0Ah]
	MOV	BX,[BP+X_FAR+8]
	SHL	BX,1
	ADD	DI,CS:Lines[BX]
	MOV	ES,CS:GR_SEGMENT
	MOV	DS,CS:pShapes+2
	MOV	DH,AL
	SHL	DH,1
	SHL	DH,1
C_02A4:
	MOV	DL,AL
C_02A6:
	MOV	CX,8
	MOV	SI,[BP+X_FAR+6]
	SHL	SI,1
	SHL	SI,1
	SHL	SI,1
	SHL	SI,1
	SHL	SI,1
	SHL	SI,1
	ADD	SI,CS:pShapes
C_02BD:
	MOVSW	
	MOVSW	
	ADD	DI,4Ch
	LOOP	C_02BD
	;--
	ADD	DI,1D80h
	;--
	MOV	CX,8
C_02CB:
	MOVSW	
	MOVSW	
	ADD	DI,4Ch
	LOOP	C_02CB
	;--
	SUB	DI,227Ch
	;--
	DEC	DL
	JNZ	C_02A6
	ADD	DI,280h
	MOV	CL,DH
	MOV	CH,0
	SUB	DI,CX
	DEC	AH
	JNZ	C_02A4
	;--
	POP	ES
	POP	DS
	POP	DI
	POP	SI
	POP	BP
	RET
C_027A	ENDP
;----------------------------------------
;Gra_03(pascal)
;----------------------------------------
C_02EE	PROC FAR
	PUSH	BP
	MOV	BP,SP
	PUSH	DI
	PUSH	SI
	PUSH	DS
	PUSH	ES
	;--
	MOV	AX,CS:GR_SEGMENT
	MOV	ES,AX
	MOV	DS,AX
	;--
	IN	AL,61h
	PUSH	AX
	;--
	MOV	DH,AL
	AND	DH,NOT 3
	MOV	BX,15Ah
C_0308:
	MOV	DI,CS:Lines[BX+0Ah*2]
	MOV	SI,CS:Lines[BX+  8*2]
	INC	SI
	INC	SI
	INC	DI
	INC	DI
	MOV	CX,16h
	REPZ	MOVSW
	;-- --
	CMP	BYTE PTR [BP+X_FAR+2],0	;soundFlag
	JZ	C_032F
	CALL	random
	AND	AL,1
	JZ	C_032F
	XOR	DH,2
	MOV	AL,DH
	OUT	61h,AL
C_032F:	;--
	DEC	BX
	DEC	BX

	JNZ	C_0308
	;--
	POP	AX
	OUT	61h,AL
	;--
	POP	ES
	POP	DS
	POP	SI
	POP	DI
	POP	BP
	RET	2
C_02EE	ENDP
;----------------------------------------
;Gra_04(pascal)
;----------------------------------------
C_033E	PROC FAR
	PUSH	BP
	MOV	BP,SP
	PUSH	DI
	PUSH	SI
	PUSH	DS
	PUSH	ES
	;--
	MOV	AX,CS:GR_SEGMENT
	MOV	ES,AX
	MOV	DS,AX
	;--
	IN	AL,61h
	PUSH	AX
	;--
	MOV	DH,AL
	AND	DH,NOT 3
	MOV	BX,0
C_0358:
	MOV	DI,CS:Lines[BX+  8*2]
	MOV	SI,CS:Lines[BX+0Ah*2]
	INC	SI
	INC	SI
	INC	DI
	INC	DI
	MOV	CX,16h
	REPZ	MOVSW
	;-- --
	CMP	BYTE PTR [BP+X_FAR+2],0	;soundFlag
	JZ	C_037F
	CALL	random
	AND	AL,1
	JZ	C_037F
	XOR	DH,2
	MOV	AL,DH
	OUT	61h,AL
C_037F:	;-- --
	INC	BX
	INC	BX
	CMP	BX,15Ah
	JNZ	C_0358
	;--
	POP	AX
	OUT	61h,AL
	;--
	POP	ES
	POP	DS
	POP	SI
	POP	DI
	POP	BP
	RET	2
C_033E	ENDP
;----------------------------------------
;Gra_05(cdecl)
;----------------------------------------
C_0392	PROC FAR
	PUSH	BP
	MOV	BP,SP
	PUSH	SI
	PUSH	DI
	PUSH	DS
	PUSH	ES
	;--
	MOV	AH,[BP+X_FAR+2]	;height
	MOV	AL,[BP+X_FAR+4]	;width
	MOV	BX,[BP+X_FAR+6]	;src offset
	MOV	DI,[BP+X_FAR+8]	;dest offset
	MOV	ES,CS:GR_SEGMENT
	MOV	DS,CS:pShapes+2
	MOV	DH,AL
	SHL	DH,1
	SHL	DH,1
C_03B5:
	MOV	DL,AL
C_03B7:
	MOV	SI,SS:[BX]
	INC	BX
	AND	SI,0FFh
	SHL	SI,1
	SHL	SI,1
	SHL	SI,1
	SHL	SI,1
	SHL	SI,1
	SHL	SI,1
	ADD	SI,CS:pShapes
	;--
	MOV	CX,8
C_03D3:
	MOVSW	
	MOVSW	
	ADD	DI,4Ch
	LOOP	C_03D3
	;--
	ADD	DI,1D80h
	;--
	MOV	CX,8
C_03E1:
	MOVSW	
	MOVSW	
	ADD	DI,4Ch
	LOOP	C_03E1
	;--
	SUB	DI,227Ch
	;--
	DEC	DL
	JNZ	C_03B7
	ADD	DI,280h
	MOV	CL,DH
	MOV	CH,0
	SUB	DI,CX
	DEC	AH
	JNZ	C_03B5
	;--
	POP	ES
	POP	DS
	POP	DI
	POP	SI
	POP	BP
	RET
C_0392	ENDP
;----------------------------------------
;Gra_CR
;----------------------------------------
C_0404	PROC FAR
	PUSH	DS
	MOV	DS,CS:GR_SEGMENT
	MOV	BX,0F30h
	;-- 88 * 64 ?
	MOV	DX,2Ch
C_0410:
	MOV	CX,10h
C_0413:
	MOV	AX,[BX+4*50h]
	MOV	[BX],AX
	MOV	AX,[BX+4*50h+2000h]
	MOV	[BX+2000h],AX
	ADD	BX,2
	LOOP	C_0413
	ADD	BX,30h
	DEC	DX
	JNZ	C_0410
	;-- 8 * 64 ?
	MOV	DX,4
C_042F:
	MOV	CX,10h
C_0432:
	MOV	WORD PTR [BX],0
	MOV	WORD PTR [BX+2000h],0
	ADD	BX,2
	LOOP	C_0432
	ADD	BX,30h
	DEC	DX
	JNZ	C_042F
	;--
	POP	DS
	RET
C_0404	ENDP
;----------------------------------------
;Gra_09
;----------------------------------------
;invert main window
C_0449	PROC FAR
	PUSH	DS
	;--
	MOV	DS,CS:GR_SEGMENT
	MOV	BX,142h
	MOV	DX,58h
C_0455:
	MOV	CX,16h
C_0458:
	XOR	WORD PTR [BX],0FFFFh
	XOR	WORD PTR [BX+2000h],0FFFFh
	ADD	BX,2
	LOOP	C_0458
	ADD	BX,24h
	DEC	DX
	JNZ	C_0455
	;--
	POP	DS
	RET
C_0449	ENDP
;----------------------------------------
;Gra_10
;----------------------------------------
;clear main window
C_046D	PROC FAR
	PUSH	DS
	;--
	MOV	DS,CS:GR_SEGMENT
	MOV	BX,142h
	MOV	DX,58h
C_0479:
	MOV	CX,16h
C_047C:
	MOV	WORD PTR [BX],0
	MOV	WORD PTR [BX+2000h],0
	ADD	BX,2
	LOOP	C_047C
	ADD	BX,24h
	DEC	DX
	JNZ	C_0479
	;--
	POP	DS
	RET
C_046D	ENDP
;----------------------------------------
;Gra_11(pascal)
;----------------------------------------
;invert one text line(status box)
C_0493	PROC FAR
	PUSH	BP
	MOV	BP,SP
	PUSH	DS
	;--
	MOV	DS,CS:GR_SEGMENT
	MOV	DL,4
	MOV	BL,[BP+X_FAR+2]
	INC	BL
	MOV	BH,0
	SHL	BX,1
	SHL	BX,1
	SHL	BX,1
	SHL	BX,1
	MOV	AX,BX
	SHL	BX,1
	SHL	BX,1
	ADD	BX,AX
	SHL	BX,1
	SHL	BX,1
	ADD	BX,30h
C_04BC:
	MOV	CX,0Fh
C_04BF:
	XOR	WORD PTR [BX],0FFFFh
	XOR	WORD PTR [BX+2000h],0FFFFh
	INC	BX
	INC	BX
	LOOP	C_04BF
	ADD	BX,32h
	DEC	DL
	JNZ	C_04BC
	;--
	POP	DS
	POP	BP
	RET	2
C_0493	ENDP
;----------------------------------------
;Gra_12(cdecl)(uncalled)
;----------------------------------------
;invert one char(status box)
C_04D7	PROC FAR
	PUSH	BP
	MOV	BP,SP
	PUSH	ES
	PUSH	DI
	PUSH	SI
	;--
	MOV	AL,[BP+X_FAR+4]
	MOV	BL,[BP+X_FAR+2]
	MOV	ES,CS:GR_SEGMENT
	SHL	BL,1
	SHL	AL,1
	SHL	AL,1
	SHL	AL,1
	MOV	AH,0
	MOV	BH,AH
	MOV	DI,AX
	SHL	DI,1
	MOV	CX,8
C_04FB:
	MOV	SI,CS:Lines[DI]
	;;;;XOR	WORD PTR ES:[BX+SI],0FFFFh
	db 26h,81h,30h,0FFh,0FFh
	INC	DI
	INC	DI
	LOOP	C_04FB
	;--
	POP	SI
	POP	DI
	POP	ES
	POP	BP
	RET
C_04D7	ENDP
;----------------------------------------
;Gra_13
;----------------------------------------
;clear status box
C_050E	PROC FAR
	PUSH	DS
	;--
	MOV	DS,CS:GR_SEGMENT
	MOV	BX,170h
	MOV	DX,20h
C_051A:	;--
	MOV	CX,0Fh
C_051D:	;--
	MOV	WORD PTR [BX],0
	MOV	WORD PTR [BX+2000h],0
	ADD	BX,2
	LOOP	C_051D
	ADD	BX,32h
	DEC	DX
	JNZ	C_051A
	;--
	POP	DS
	RET
C_050E	ENDP
;----------------------------------------
;Gra_dot_OR(cdecl)
;----------------------------------------
C_0534	PROC FAR
	PUSH	BP
	MOV	BP,SP
	PUSH	ES
	;--
	MOV	ES,CS:GR_SEGMENT
	;--
	MOV	AL,[BP+X_FAR+4]
	MOV	CL,AL
	SHR	AL,1
	SHR	AL,1
	;--
	MOV	BL,[BP+X_FAR+6]
	MOV	BH,0
	MOV	AH,CS:C_01E2[BX]

	AND	CL,3
	SHL	CL,1
	SHR	AH,CL


	;--
	MOV	BL,[BP+X_FAR+2]
	MOV	BH,0
	SHL	BX,1
	MOV	BX,CS:Lines[BX]
	ADD	BL,AL
	ADC	BH,0

	OR	ES:[BX],AH
	;--
	POP	ES
	POP	BP
	RET
C_0534	ENDP
;----------------------------------------
;Gra_dot_XOR(cdecl)
;----------------------------------------
C_056E	PROC FAR
	PUSH	BP
	MOV	BP,SP
	PUSH	ES
	;--
	MOV	ES,CS:GR_SEGMENT
	;--
	MOV	AL,[BP+X_FAR+4]
	MOV	CL,AL
	SHR	AL,1
	SHR	AL,1
	;--
	MOV	BL,[BP+X_FAR+6]
	MOV	BH,0
	MOV	AH,CS:C_01E2[BX]

	AND	CL,3
	SHL	CL,1
	SHR	AH,CL


	;--
	MOV	BL,[BP+X_FAR+2]
	MOV	BH,0
	SHL	BX,1
	MOV	BX,CS:Lines[BX]
	ADD	BL,AL
	ADC	BH,0

	XOR	ES:[BX],AH
	;--
	POP	ES
	POP	BP
	RET
C_056E	ENDP
;----------------------------------------
;Gra_dot(cdecl)
;----------------------------------------
C_05A8	PROC FAR
	PUSH	BP
	MOV	BP,SP
	PUSH	ES
	;--
	MOV	ES,CS:GR_SEGMENT
	;--
	MOV	AL,[BP+X_FAR+4]
	MOV	CL,AL
	SHR	AL,1
	SHR	AL,1
	;--
	MOV	BL,[BP+X_FAR+6]
	MOV	BH,0
	MOV	AH,CS:C_01E2[BX]
	MOV	CH,0C0h
	AND	CL,3
	SHL	CL,1
	SHR	AH,CL
	SHR	CH,CL
	NOT	CH
	;--
	MOV	BL,[BP+X_FAR+2]
	MOV	BH,0
	SHL	BX,1
	MOV	BX,CS:Lines[BX]
	ADD	BL,AL
	ADC	BH,0
	AND	ES:[BX],CH
	OR	ES:[BX],AH
	;--
	POP	ES
	POP	BP
	RET
C_05A8	ENDP
;----------------------------------------
;Gra_16(cdecl)
;----------------------------------------
;(PCPaint format)
_pic_inflate	PROC FAR
	PUSH	BP
	MOV	BP,SP
	SUB	SP,0Bh
	PUSH	SI
	PUSH	DI
	PUSH	DS
	PUSH	ES
	;--
	MOV	AX,SS
	MOV	DS,AX
	;--
	MOV	AX,1F40h
	PUSH	AX
	CALL	_dalloc
	ADD	SP,2
	MOV	[BP-04+2],DX
	MOV	[BP-04],AX
	;--
	MOV	AX,0
	PUSH	AX
	PUSH	[BP+X_FAR+2]
	CALL	_dopen
	ADD	SP,4
	MOV	[BP-06],AX
	;%%
	INC	AX
	JNZ	C_0626
C_061C:	;-- exit callback?
	MOV	AX,3
	PUSH	AX
	PUSH	AX
	CALL	Dword Ptr CS:pExit
C_0626:	;--
	DEC	AX
	;-- load header
	MOV	BX,11h
	PUSH	BX
	PUSH	[BP-04+2]
	PUSH	[BP-04]
	PUSH	AX
	CALL	_dread
	ADD	SP,8
	;-- inflate to memory or vram
	MOV	ES,[BP+X_FAR+6]
	TEST	WORD PTR [BP+X_FAR+6],0FFFFh
	JNZ	C_0647
	MOV	ES,CS:GR_SEGMENT
C_0647:	;--
	LDS	BX,[BP-04]
	CMP	WORD PTR [BX],1234h	;marker(always 0x1234)
	JNZ	C_061C	;error!
	CMP	WORD PTR [BX+02],320	;xsize
	JNZ	C_061C	;error!
	CMP	WORD PTR [BX+04],200	;yize
	JNZ	C_061C	;error!
	CMP	BYTE PTR [BX+0Ah],2	;bitsinf
	JNZ	C_061C	;error!
	CMP	BYTE PTR [BX+0Bh],0FFh	;emark(always 0xff)
	JNZ	C_061C	;error!
	CMP	BYTE PTR [BX+0Ch],'A'	;evideo
	JNZ	C_061C	;error!
	CMP	WORD PTR [BX+0Dh],1	;edesc[1 = edata is pallet]
	JNZ	C_061C	;error!
	;-- read edata
	PUSH	[BX+0Fh]	;esize
	PUSH	DS
	PUSH	BX
	PUSH	[BP-06]
	CALL	_dread
	ADD	SP,8
	;-- numblks
	MOV	AX,2
	PUSH	AX
	PUSH	[BP-04+2]
	PUSH	[BP-04]
	PUSH	[BP-06]
	CALL	_dread
	ADD	SP,8
	;--
	MOV	BX,[BP-04]
	MOV	AX,[BX]
	MOV	[BP-08],AX
	;--
	MOV	DX,199
	MOV	DI,DX
	SHL	DI,1
	MOV	DI,CS:Lines[DI]
	ADD	DI,[BP+X_FAR+4]
	MOV	BX,0
C_06B1:	;-- next packed block --
	PUSH	BX
	PUSH	DX
	;-- packed block header --
	MOV	AX,5
	PUSH	AX
	PUSH	[BP-04+2]
	PUSH	[BP-04]
	PUSH	[BP-06]
	CALL	_dread
	ADD	SP,8
	;--
	MOV	BX,[BP-04]
	MOV	AL,[BX+04]
	MOV	[BP-0Bh],AL	;MBYTE
	;--
	MOV	AX,[BX]
	SUB	AX,5
	MOV	[BP-0Ah],AX	;PBSIZE - packed block size
	;%%
	PUSH	AX
	PUSH	[BP-04+2]
	PUSH	[BP-04]
	PUSH	[BP-06]
	CALL	_dread
	ADD	SP,8
	;--
	MOV	BX,[BP-04]
	MOV	SI,[BP-04]
	ADD	[BP-0Ah],SI
	;--
	POP	DX
	POP	BX
C_06F2:	;-- next packed block data --
	MOV	CX,1
	LODSB
	CMP	AL,[BP-0Bh]
	JNZ	C_0709
	;-- found MBYTE --
	LODSB	;LENGTH
	CMP	AL,0
	JNZ	C_0706
	;-- LENGTH is 0 --
	LODSW	;BIGLEN
	MOV	CX,AX
	LODSB
	;--
	JMP	SHORT C_0709
C_0706:	;-- LENGTH is not 0 --
	MOV	CL,AL
	LODSB
C_0709:	;-- AL x CX --
	OR	ES:[BX+DI],AL
	INC	BX
	CMP	BX,50h
	JB	C_0722
	;--
	DEC	DX
	MOV	DI,DX
	SHL	DI,1
	MOV	DI,CS:Lines[DI]
	ADD	DI,[BP+X_FAR+4]
	MOV	BX,0
C_0722:
	LOOP	C_0709
	;--
	CMP	SI,[BP-0Ah]
	JB	C_06F2	;next packed block data
	;--
	DEC	WORD PTR [BP-08]
	JZ	C_0730
	JMP	C_06B1	;next packed block
C_0730:	;-- finished --
	PUSH	[BP-06]
	CALL	_dclose
	ADD	SP,2
	;--
	PUSH	[BP-04+2]
	PUSH	[BP-04]
	CALL	_dfree
	ADD	SP,4
	;--
	POP	ES
	POP	DS
	POP	DI
	POP	SI
	MOV	SP,BP
	POP	BP
	RET
_pic_inflate	ENDP
;----------------------------------------
;Gra_17(pascal)
;----------------------------------------
C_074D	PROC FAR
	PUSH	BP
	MOV	BP,SP
	PUSH	SI
	PUSH	DI
	PUSH	DS
	PUSH	ES
	;--
	MOV	AX,SS
	MOV	DS,AX
	;--
	MOV	AX,4000h
	PUSH	AX
	CALL	_dalloc
	ADD	SP,2
	;--
	PUSH	DX
	PUSH	AX
	;-- clear buffer
	MOV	ES,DX
	MOV	DI,AX
	MOV	CX,2000h
	MOV	AX,0
	REPZ	STOSW
	;-- --
	POP	AX
	PUSH	AX
	;-- inflate file to memory
	PUSH	DX
	PUSH	AX
	PUSH	[BP+X_FAR+2]
	PUSH	CS
	CALL	NEAR PTR _pic_inflate
	ADD	SP,6
	;--
	POP	AX
	POP	DS
	;-- push far ptr for _dfree
	PUSH	DS
	PUSH	AX
	;--
	MOV	ES,CS:GR_SEGMENT
	MOV	AH,15h
C_0789:
	MOV	CH,AH
	MOV	SI,2
	MOV	DI,2Dh
C_0791:
	MOV	CL,8
C_0793:
	MOV	BL,CL
	MOV	BH,0
	SHL	BX,1
	MOV	BX,CS:Lines[BX]
	MOV	AL,ES:[BX+SI+01]
	MOV	ES:[BX+SI],AL
	MOV	AL,ES:[BX+DI-01]
	MOV	ES:[BX+DI],AL
	INC	CL
	CMP	CL,0B8h
	JB	C_0793
	INC	SI
	DEC	DI
	DEC	CH
	JNZ	C_0791
C_07B9:	;--
	MOV	CL,8
C_07BB:
	MOV	BL,CL
	MOV	BH,0
	SHL	BX,1
	MOV	BX,CS:Lines[BX]
	MOV	AL,[BX+SI]
	MOV	ES:[BX+SI],AL
	MOV	AL,[BX+DI]
	MOV	ES:[BX+DI],AL
	INC	CL
	CMP	CL,0B8h
	JB	C_07BB
	INC	SI
	DEC	DI
	CMP	SI,DI
	JB	C_07B9
	DEC	AH
	JNZ	C_0789
	;--
	MOV	CL,8
C_07E3:
	MOV	BL,CL
	MOV	BH,0
	SHL	BX,1
	MOV	BX,CS:Lines[BX]
	MOV	AL,[BX+02]
	MOV	ES:[BX+02h],AL
	MOV	AL,[BX+2Dh]
	MOV	ES:[BX+2Dh],AL
	INC	CL
	CMP	CL,0B8h
	JB	C_07E3
	;--
	MOV	AX,SS
	MOV	DS,AX
	;--
	CALL	_dfree
	ADD	SP,4
	;--
	POP	ES
	POP	DS
	POP	DI
	POP	SI
	POP	BP
	RET	2
C_074D	ENDP
;----------------------------------------
;Gra_18(cdecl)
;----------------------------------------
C_0815	PROC FAR
	PUSH	BP
	MOV	BP,SP
	SUB	SP,10h
	PUSH	SI
	PUSH	DI
	PUSH	DS
	;--
	MOV	AX,[BP+X_FAR+2]
	MOV	[BP-10h],AX
	;--
	MOV	AX,[BP+X_FAR+6]
	MOV	[BP-06],AX
	;--
	MOV	AX,[BP+X_FAR+8]
	MOV	[BP-0Ah],AX
	;--
	MOV	SI,[BP+X_FAR+4]
	SUB	SI,[BP+X_FAR+2]
	;--
	PUSH	SI
	CALL	C_0A5C	;test sign
	ADD	SP,2
	MOV	[BP-02],AX
	;--
	MOV	AX,[BP+X_FAR+0Ah]
	SUB	AX,[BP+X_FAR+6]
	PUSH	AX
	CALL	C_0A5C	;test sign
	ADD	SP,2
	MOV	[BP-08],AX
	;--
	MOV	AX,[BP+X_FAR+0Ch]
	SUB	AX,[BP+X_FAR+8]
	PUSH	AX
	CALL	C_0A5C	;test sign
	ADD	SP,2
	MOV	[BP-0Eh],AX
	;--
	PUSH	SI
	CALL	_abs
	ADD	SP,2
	SHR	AX,1
	MOV	[BP-0Ch],AX
	MOV	[BP-04],AX
	;--
	MOV	DS,CS:GR_SEGMENT
C_0874:
	MOV	AL,[BP-10h]
	MOV	CL,AL
	SHR	AL,1
	SHR	AL,1
	MOV	AH,0
	MOV	SI,AX
	MOV	DI,[BP-06]
	SHL	DI,1

	MOV	BL,[BP+X_FAR+10h]	;color #2
	MOV	BH,0
	MOV	AL,CS:C_01E2[BX]
	MOV	BL,[BP+X_FAR+0Eh]	;color #1
	MOV	BH,0
	MOV	AH,CS:C_01E2[BX]

	AND	CL,3
	SHL	CL,1
	SHR	AL,CL
	SHR	AH,CL
	NOT	AL
	MOV	CX,[BP-0Ah]
	SUB	CX,[BP-06]
	INC	CX
C_08AC:
	MOV	BX,CS:Lines[DI]
	ADD	DI,2
	AND	[BX+SI],AL
	OR	[BX+SI],AH
	LOOP	C_08AC
	;--
	MOV	AX,[BP-02]
	ADD	[BP-10h],AX
	;--
	MOV	AX,[BP+X_FAR+0Ah]
	SUB	AX,[BP+X_FAR+6]
	JNS	C_08CA
	NEG	AX
C_08CA:
	SUB	[BP-0Ch],AX
	MOV	AX,[BP+X_FAR+0Ch]
	SUB	AX,[BP+X_FAR+8]
	JNS	C_08D7
	NEG	AX
C_08D7:
	SUB	[BP-04],AX
	JNS	C_08EF
	MOV	AX,[BP-08]
	ADD	[BP-06],AX
	MOV	SI,[BP+X_FAR+4]
	SUB	SI,[BP+X_FAR+2]
	JNS	C_08EC
	NEG	SI
C_08EC:
	ADD	[BP-0Ch],SI
C_08EF:
	CMP	WORD PTR [BP-04],0
	JNS	C_08FE
	MOV	AX,[BP-0Eh]
	ADD	[BP-0Ah],AX
	ADD	[BP-04],SI
C_08FE:
	MOV	AX,[BP-10h]
	CMP	AX,[BP+X_FAR+4]
	JZ	C_0909
	JMP	C_0874
C_0909:	;--
	POP	DS
	POP	DI
	POP	SI
	MOV	SP,BP
	POP	BP
	RET
C_0815	ENDP
;----------------------------------------
;Gra_19(pascal)
;----------------------------------------
C_0910	PROC FAR
	PUSH	BP
	MOV	BP,SP
	PUSH	SI
	PUSH	ES
	;--
	LES	BX,Dword Ptr CS:pCharset
	MOV	SI,7
C_091D:
	MOV	AX,SI
	SHL	AX,1
	MOV	DI,AX
	ADD	DI,[BP+X_FAR+2]
	MOV	DI,SS:[DI]
	CMP	WORD PTR SS:[DI],+0
	JNZ	C_0942
	MOV	DI,AX
	;--
	MOV	AL,ES:[BX+DI]
	MOV	ES:[BX+DI+70h],AL
	;--
	MOV	AL,ES:[BX+DI+01]
	MOV	ES:[BX+DI+71h],AL
	;--
	JMP	SHORT C_0952
C_0942:
	MOV	AX,SI
	SHL	AX,1
	MOV	DI,AX
	MOV	BYTE PTR ES:[BX+DI+70h],0
	MOV	BYTE PTR ES:[BX+DI+71h],0
C_0952:
	DEC	SI
	JNS	C_091D
	;--
	POP	ES
	POP	SI
	POP	BP
	RET	2
C_0910	ENDP
;----------------------------------------
;Gra_animSpit
;----------------------------------------
;fire FX?
;________________ ;0
;________________ ;1
;________________ ;2
;____0___________ ;3
;____22_23_______ ;4
;_____666________ ;5
;____9_9_A_______ ;6
;________________ ;7
;________________ ;8
;________________ ;9
;________________ ;a
;____1___________ ;b
;____44445_______ ;c
;____77778_______ ;d
;________________ ;e
;________________ ;f
C_095B	PROC FAR
	PUSH	DS
	LDS	BX,Dword Ptr CS:pShapes
	;-- 0/1 --
	CALL	random
	AND	AL,80h
	XOR	[BX+4Bh*40h+  3*4+1],AL
	CALL	random
	AND	AL,80h
	XOR	[BX+4Bh*40h+0Bh*4+1],AL
	;-- 2/3/4/5 --
	CALL	random
	AND	AL,0A2h
	XOR	[BX+4Bh*40h+  4*4+1],AL
	CALL	random
	AND	AL,80h
	XOR	[BX+4Bh*40h+  4*4+2],AL
	CALL	random
	AND	AL,0AAh
	XOR	[BX+4Bh*40h+0Ch*4+1],AL
	CALL	random
	AND	AL,80h
	XOR	[BX+4Bh*40h+0Ch*4+2],AL
	;-- 6/7/8 --
	CALL	random
	AND	AL,2Ah
	XOR	[BX+4Bh*40h+  5*4+1],AL
	CALL	random
	AND	AL,0AAh
	XOR	[BX+4Bh*40h+0Dh*4+1],AL
	CALL	random
	AND	AL,80h
	XOR	[BX+4Bh*40h+0Dh*4+2],AL
	;-- 9/A --
	CALL	random
	AND	AL,88h
	XOR	[BX+4Bh*40h+  6*4+1],AL
	CALL	random
	AND	AL,80h
	XOR	[BX+4Bh*40h+  6*4+2],AL
	;--
	POP	DS
	RET
C_095B	ENDP
;----------------------------------------
;Gra_init(cdecl)
;----------------------------------------
C_09C6	PROC FAR
	PUSH	BP
	MOV	BP,SP
	;--
	MOV	AH,0
	MOV	AL,4
	PUSH	BP
	INT	10h
	MOV	AH,0Bh
	MOV	BH,0
	MOV	BL,0
	INT	10h
	MOV	AH,0Bh
	MOV	BH,1
	MOV	BL,1
	INT	10h
	POP	BP
	;--
	MOV	BX,[BP+X_FAR+2]
	MOV	AX,SS:[BX]
	MOV	CS:pShapes,AX
	MOV	AX,SS:[BX+02]
	MOV	CS:pShapes+2,AX
	;--
	MOV	BX,[BP+X_FAR+4]
	MOV	AX,SS:[BX]
	MOV	CS:pCharset,AX
	MOV	AX,SS:[BX+02]
	MOV	CS:pCharset+2,AX
	;--
	MOV	AX,[BP+X_FAR+6]
	MOV	CS:pExit,AX
	MOV	AX,[BP+X_FAR+0]
	MOV	CS:pExit+2,AX
	;--
	POP	BP
	RET
C_09C6	ENDP
;----------------------------------------
;Gra_clrscr
;----------------------------------------
C_0A15	PROC FAR
	PUSH	DI
	PUSH	ES
	;--
	MOV	AX,0
	MOV	ES,CS:GR_SEGMENT
	MOV	BX,199*2	;18Eh
C_0A22:
	MOV	DI,CS:Lines[BX]
	MOV	CX,50h
	REPZ	STOSW
	SUB	BX,2
	JNS	C_0A22
	;--
	POP	ES
	POP	DI
	RET
C_0A15	ENDP
;----------------------------------------
;########################################
;----------------------------------------C_0A34
random	PROC NEAR
	MOV	AL,CS:C_0036[3]
	ADC	AL,CS:C_0036[2]
	MOV	CS:C_0036[2],AL
	XOR	CS:C_0036[1],AL
	MOV	AL,CS:C_0036[1]
	ADC	AL,CS:C_0036[0]
	ROR	AL,1
	MOV	CS:C_0036[0],AL
	MOV	CS:C_0036[3],AL
	;
	TEST	AL,0FFh
	RET
random	ENDP
;----------------------------------------
;test sign
C_0A5C	PROC NEAR
	PUSH	BP
	MOV	BP,SP
	;--
	TEST	WORD PTR [BP+X+2],0FFFFh
	JZ	C_0A72
	JNS	C_0A6D
	;-- < 0 --
	MOV	AX,-1
	JMP	SHORT C_0A75
C_0A6D:	;-- > 0 --
	MOV	AX,1
	JMP	SHORT C_0A75
C_0A72:	;-- 0 --
	MOV	AX,0
C_0A75:	;--
	POP	BP
	RET
C_0A5C	ENDP
;----------------------------------------C_0A77
_abs	PROC NEAR
	PUSH	BP
	MOV	BP,SP
	;--
	MOV	AX,[BP+X+2]
	TEST	AX,-1
	JNS	C_0A84
	NEG	AX
C_0A84:	;--
	POP	BP
	RET
_abs	ENDP
;----------------------------------------
;########################################
;----------------------------------------
;dos functions
;----------------------------------------
_dalloc:
	PUSH	BP
	MOV	BP,SP
	;--
	MOV	BX,[BP+X+2]
	SHR	BX,1
	SHR	BX,1
	SHR	BX,1
	SHR	BX,1
	TEST	WORD PTR [BP+X+2],0Fh
	JZ	C_0A9C
	INC	BX
C_0A9C:
	MOV	AH,48h	;allocate memory
	INT	21h
	MOV	DX,AX
	MOV	AX,0
	JNB	C_0AB1
	;-- exit callback?
	PUSH	AX
	PUSH	AX
	JMP	Dword Ptr CS:pExit
	;--
	MOV	DX,0
C_0AB1:	;--
	MOV	SP,BP
	POP	BP
	RET	
;----------------------------------------
_dfree:
	PUSH	ES
	PUSH	BP
	MOV	BP,SP
	;--
	MOV	ES,[BP+X+6]
	MOV	AH,49h	;free allocated memory
	INT	21h
	MOV	AX,0
	JNB	C_0AC8
	MOV	AX,-1
C_0AC8:
	MOV	SP,BP
	POP	BP
	POP	ES
	RET	
;----------------------------------------
_dopen:
	PUSH	BP
	MOV	BP,SP
	;--
	MOV	DX,[BP+X+2]
	MOV	AL,[BP+X+4]
	MOV	AH,3Dh	;open file
	INT	21h
	JNB	C_0ADF
	MOV	AX,-1
C_0ADF:
	MOV	SP,BP
	POP	BP
	RET	
;----------------------------------------
_dread:
	PUSH	BP
	MOV	BP,SP
	PUSH	DS
	PUSH	SI
	PUSH	DI
	;--
	MOV	BX,[BP+X+2]
	MOV	CX,[BP+X+8]
	MOV	DX,[BP+X+4]
	MOV	AX,[BP+X+6]
	MOV	DS,AX
	MOV	AH,3Fh	;read from file
	INT	21h
	JNB	C_0B00
	MOV	AX,-1
C_0B00:
	POP	DI
	POP	SI
	POP	DS
	MOV	SP,BP
	POP	BP
	RET	
;----------------------------------------
_dclose:
	PUSH	BP
	MOV	BP,SP

	MOV	BX,[BP+X+2]
	MOV	AH,3Eh	;close file
	INT	21h
	JNB	C_0B16
	MOV	AX,-1
C_0B16:
	MOV	SP,BP
	POP	BP
	RET	
;########################################
;----------------------------------------
;Gra_animFlow(pascal)
;----------------------------------------
C_0B1A	PROC FAR
	PUSH	BP
	MOV	BP,SP
	PUSH	DS
	;--
	MOV	DS,CS:pShapes+2
	MOV	BX,[BP+X_FAR+2]
	SHL	BX,1
	SHL	BX,1
	SHL	BX,1
	SHL	BX,1
	SHL	BX,1
	SHL	BX,1
	ADD	BX,CS:pShapes
	MOV	AX,[BX+3Ch]
	MOV	DX,[BX+3Eh]
	MOV	CX,8
C_0B40:
	XCHG	AX,[BX]
	XCHG	AX,[BX+20h]
	XCHG	DX,[BX+2]
	XCHG	DX,[BX+22h]
	ADD	BX,4
	LOOP	C_0B40
	;--
	POP	DS
	POP	BP
	RET	2
C_0B1A	ENDP
;----------------------------------------
;Gra_animFlag
;----------------------------------------
C_0B55	PROC FAR
	PUSH	ES
	;--
	LES	BX,Dword Ptr CS:pShapes
	;--
	CALL	random
	JS	C_0B6F
	;--
	MOV	AX,ES:[BX+02A4h]
	XCHG	AX,ES:[BX+0288h]
	MOV	ES:[BX+02A4h],AX
C_0B6F:	;--
	CALL	random
	JS	C_0B83
	;--
	MOV	AX,ES:[BX+02E2h]
	XCHG	AX,ES:[BX+02C6h]
	MOV	ES:[BX+02E2h],AX
C_0B83:	;--
	CALL	random
	JS	C_0BA6
	;--
	MOV	AX,ES:[BX+0404h]
	XCHG	AX,ES:[BX+0424h]
	MOV	ES:[BX+0404h],AX
	;--
	MOV	AX,ES:[BX+0406h]
	XCHG	AX,ES:[BX+0426h]
	MOV	ES:[BX+0406h],AX
C_0BA6:
	CALL	random
	JS	C_0BC9
	;--
	MOV	AX,ES:[BX+0484h]
	XCHG	AX,ES:[BX+04A4h]
	MOV	ES:[BX+0484h],AX
	;--
	MOV	AX,ES:[BX+0486h]
	XCHG	AX,ES:[BX+04A6h]
	MOV	ES:[BX+0486h],AX
C_0BC9:	;--
	CALL	random
	JS	C_0BDD
	;--
	MOV	AX,ES:[BX+03A0h]
	XCHG	AX,ES:[BX+0384h]
	MOV	ES:[BX+03A0h],AX
C_0BDD:	;--
	POP	ES
	RET
C_0B55	ENDP
;----------------------------------------
;Gra_putchar(pascal)
;----------------------------------------
C_0BDF	PROC FAR
	PUSH	BP
	MOV	BP,SP
	PUSHF	
	PUSH	AX
	PUSH	BX
	PUSH	SI
	PUSH	ES
	PUSH	DS
	;--
	MOV	AL,[BP+X_FAR+6]
	MOV	ES,CS:GR_SEGMENT
	MOV	AH,0
	SHL	AX,1
	SHL	AX,1
	SHL	AX,1
	SHL	AX,1
	MOV	SI,AX
	ADD	SI,CS:pCharset
	MOV	DS,CS:pCharset+2
	MOV	BX,[BP+X_FAR+2]
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
	MOV	AX,[BP+X_FAR+4]
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
	MOV	ES:[BX+0*50h+2000h],AX
	LODSW
	MOV	ES:[BX+1*50h+2000h],AX
	LODSW
	MOV	ES:[BX+2*50h+2000h],AX
	LODSW
	MOV	ES:[BX+3*50h+2000h],AX
	;--
	POP	DS
	POP	ES
	POP	SI
	POP	BX
	POP	AX
	POPF	
	POP	BP
	RET	6
C_0BDF	ENDP
;----------------------------------------
;Gra_00
;----------------------------------------
C_0C5B	PROC FAR
	PUSH	BP
	MOV	BP,SP
	PUSH	SI
	PUSH	DI
	PUSH	ES
	;--
	MOV	ES,CS:GR_SEGMENT
	MOV	SI,[BP+X_FAR+2]
	SHL	SI,1
	SHL	SI,1
	SHL	SI,1
	SHL	SI,1
	ADD	SI,8
	SHL	SI,1
	;--
	MOV	DX,[BP+X_FAR+4]
	SHL	DX,1
	SHL	DX,1
	ADD	DX,2
	;--
	MOV	DI,DX
	ADD	DI,CS:Lines[SI]
	ADD	SI,2
	MOV	WORD PTR ES:[DI],0FFFFh
	MOV	WORD PTR ES:[DI+02],0FFFFh
	;--
	MOV	DI,CS:Lines[SI]
	ADD	SI,2
	ADD	DI,DX
	MOV	WORD PTR ES:[DI],0FFFFh
	MOV	WORD PTR ES:[DI+02],0FFFFh
	;--
	MOV	DI,CS:Lines[SI]
	ADD	SI,2
	ADD	DI,DX
	MOV	CX,0Ch
C_0CB7:
	OR	BYTE PTR ES:[DI],0F0h
	OR	BYTE PTR ES:[DI+03],0Fh
	MOV	DI,CS:Lines[SI]
	ADD	SI,2
	ADD	DI,DX
	LOOP	C_0CB7
	;--
	MOV	WORD PTR ES:[DI],0FFFFh
	MOV	WORD PTR ES:[DI+02],0FFFFh
	MOV	DI,CS:Lines[SI]
	ADD	SI,2
	ADD	DI,DX
	MOV	WORD PTR ES:[DI],0FFFFh
	MOV	WORD PTR ES:[DI+02],0FFFFh
	;--
	POP	ES
	POP	DI
	POP	SI
	POP	BP
	RET
C_0C5B	ENDP
;----------------------------------------
_TEXT	ENDS
;########################################
END
