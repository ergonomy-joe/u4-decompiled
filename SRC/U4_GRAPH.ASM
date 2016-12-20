EXTRN _exit:NEAR

EXTRN _SoundFlag:BYTE
EXTRN pKarmas:WORD

;from U4_DOS
EXTRN _dalloc:NEAR
EXTRN _dopen:NEAR
EXTRN _dread:NEAR
EXTRN _dclose:NEAR

EXTRN C_A842:NEAR	;drawLine

EXTRN D_943A:WORD
EXTRN pShapes:DWORD
EXTRN pCharset:DWORD
EXTRN txt_X:WORD
EXTRN txt_Y:WORD

DGROUP	GROUP _DATA,_BSS
;########################################
_DATA	SEGMENT PUBLIC WORD 'DATA'
	ASSUME DS:DGROUP
;----------------------------------------
D_08A4	db "start.pic",0
D_08AE	db "start.ega",0
D_08B8	db "rune_5.pic",0
D_08C3	db "rune_5.ega",0
;----------------------------------------
_DATA	ENDS
;########################################
_BSS	SEGMENT PUBLIC WORD 'BSS'
;----------------------------------------
D_8C46	dw ?,?	;loading buffer for graphic lib
;----------------------------------------
sizzleBuff	db 80h dup(?)	;D_8C4A
;----------------------------------------
_BSS	ENDS
;########################################
_TEXT	SEGMENT PUBLIC BYTE 'CODE'
	ASSUME CS:_TEXT
;----------------------------------------
;load graphic lib
PUBLIC C_20C1
C_20C1	PROC NEAR
	PUSH	BP
	MOV	BP,SP
	SUB	SP,4
	PUSH	ES
	;--
	MOV	AX,0
	PUSH	AX
	PUSH	[BP+04]
	CALL	_dopen
	ADD	SP,4
	MOV	[BP-02],AX
	;%%
	INC	AX
	JNZ	C_20E2
C_20DB:	;--
	MOV	AX,49h
	PUSH	AX
	CALL	_exit
C_20E2:	;** inline seek? **
	MOV	BX,[BP-02]
	MOV	AL,2	;SEEK_END
	MOV	CX,0
	MOV	DX,0
	MOV	AH,42h	; move file pointer using handle
	INT	21h
	;** **
	MOV	[BP-04],AX
	;%%
	PUSH	AX
	CALL	_dalloc
	ADD	SP,2
	MOV	D_8C46,AX
	MOV	D_8C46+2,DX
	;** inline seek? **
	MOV	BX,[BP-02]
	MOV	AL,0	;SEEK_SET
	MOV	CX,0
	MOV	DX,0
	MOV	AH,42h	; move file pointer using handle
	INT	21h
	;** **
	PUSH	[BP-04]
	PUSH	D_8C46+2
	PUSH	D_8C46
	PUSH	[BP-02]
	CALL	_dread
	ADD	SP,8
	;%%
	CMP	AX,[BP-04]
	JNZ	C_20DB
	;--
	PUSH	[BP-02]
	CALL	_dclose
	ADD	SP,2
	;--
	POP	ES
	ADD	SP,4
	POP	BP
	RET	2
C_20C1	ENDP
;----------------------------------------
;draw game screen frame
PUBLIC C_213B
C_213B PROC NEAR
	CALL    _Gra_clrscr
	;-- BX := (D_943A == 1)?"start.pic":"start.ega"
	LEA     BX,[D_08A4]	;"start.pic"
	CMP     D_943A,1
	JZ      C_214D
	LEA     BX,[D_08AE]	;"start.ega"
C_214D:	;-- Gra_16(BX, 0, 0)
	MOV     AX,0
	PUSH    AX
	PUSH    AX
	PUSH	BX
	CALL	_Gra_16	;display image
	ADD	SP,6
	;--
	RET
C_213B ENDP
;----------------------------------------C_215A
PUBLIC _Gra_line
_Gra_line PROC NEAR
	PUSH	BP
	MOV	BP,SP
	;-- other line ? --
	MOV	AX,[BP+04]
	CMP	AX,[BP+08]
	JZ	C_217E
	MOV	AX,[BP+06]
	CMP	AX,[BP+0Ah]
	JZ	C_217E
	PUSH	[BP+04]
	PUSH	[BP+06]
	PUSH	[BP+08]
	PUSH	[BP+0Ah]
	CALL	C_A842	;drawLine
	POP	BP
	RET
C_217E:	;-- straight line --
	SUB	SP,+02
	PUSH	SI
	PUSH	DI
	;--
	MOV	AX,[BP+04]
	CMP	AX,[BP+08]
	JNZ	C_21C4
	;----
	;
	;----
	MOV	AX,[BP+0Ah]
	SUB	AX,[BP+06]
	CWD
	MOV	SI,DX
	TEST	AX,0FFFFh
	JLE	C_219C
	MOV	SI,1
C_219C:	;--
	PUSH	[BP+0Ch]
	PUSH	[BP+04]
	PUSH	[BP+06]
	MOV	AX,[BP+0Ah]
	SUB	AX,[BP+06]
	JGE	C_21AF
	NEG	AX
C_21AF:	INC	AX
	MOV	[BP-02],AX
C_21B3:	;--
	CALL	_Gra_dot_OR
	;--
	ADD	[BP-0Ch],SI
	DEC	WORD PTR [BP-02]
	JNZ	C_21B3
	ADD	SP,6
	;----
	;
	;----
	JMP	C_21FA	;(+nop)
	;----
C_21C4:	;
	;----
	MOV	AX,[BP+08]
	SUB	AX,[BP+04]
	CWD
	MOV	SI,DX
	TEST	AX,0FFFFh
	JLE	C_21D5
	MOV	SI,1
C_21D5:	;--
	PUSH	[BP+0Ch]
	PUSH	[BP+04]
	PUSH	[BP+06]
	MOV	AX,[BP+08]
	SUB	AX,[BP+04]
	JGE	C_21E8
	NEG	AX
C_21E8:	INC	AX
	MOV	[BP-02],AX
C_21EC:	;--
	CALL	_Gra_dot_OR
	;--
	ADD	[BP-0Ah],SI
	DEC	WORD PTR [BP-02]
	JNZ	C_21EC
	ADD	SP,6
	;----
C_21FA:	;
	;----
	POP	DI
	POP	SI
	ADD	SP,2
	POP	BP
	RET
_Gra_line ENDP
;----------------------------------------
; handler to extern graphic library
;----------------------------------------
;----C_2201
PUBLIC _Gra_00	;active character square
_Gra_00 PROC NEAR
	MOV	DX,0*2
	JMP	SHORT C_2255
_Gra_00 ENDP
;----C_2206
PUBLIC _Gra_01
_Gra_01 PROC NEAR
	MOV	DX,1*2
	JMP	SHORT C_2255
_Gra_01 ENDP
;----C_220B
PUBLIC _Gra_02
_Gra_02 PROC NEAR
	MOV	DX,2*2
	JMP	SHORT C_2255
_Gra_02 ENDP
;----C_2210
PUBLIC _Gra_03
_Gra_03 PROC NEAR
	POP	AX
	PUSH	WORD PTR _SoundFlag
	PUSH	AX
	MOV	DX,3*2
	JMP	SHORT C_2255
_Gra_03  ENDP
;----C_221B
PUBLIC _Gra_04
_Gra_04 PROC NEAR
	POP	AX
	PUSH	WORD PTR _SoundFlag
	PUSH	AX
	MOV	DX,4*2
	JMP	SHORT C_2255
_Gra_04 ENDP
;---- C_2226
;display tile map?
PUBLIC _Gra_05
_Gra_05 PROC NEAR
	MOV	DX,5*2
	JMP	SHORT C_2255
_Gra_05 ENDP
;----C_222B
PUBLIC _Gra_dot
_Gra_dot PROC NEAR
	MOV	DX,6*2
	JMP	SHORT C_2255
_Gra_dot ENDP
;----C_2230
PUBLIC Gra_CR
Gra_CR PROC NEAR
	MOV	txt_Y,23
	MOV	txt_X,24
	MOV	DX,8*2
	JMP	SHORT C_2255
Gra_CR ENDP
;----C_2241
PUBLIC Gra_09
Gra_09 PROC NEAR
	MOV	DX,9*2
	JMP	SHORT C_2255
Gra_09 ENDP
;----C_2246
PUBLIC Gra_10
Gra_10 PROC NEAR
	MOV	DX,10*2
	JMP	SHORT C_2255
Gra_10 ENDP
;----C_224B
PUBLIC Gra_11
Gra_11 PROC NEAR
	MOV	DX,11*2
	JMP	SHORT C_2255
Gra_11 ENDP
;----C_2250
;(uncalled?)
Gra_12 PROC NEAR
	MOV	DX,12*2
	JMP	SHORT C_2255
Gra_12 ENDP
;----
C_2255:	;-- create far ret
	POP	AX	;return address
	PUSH	CS
	PUSH	AX
	;--
	MOV	CX,ES	;backup ES
	LES	BX,DWORD PTR D_8C46
	ADD	BX,DX
	PUSH	ES
	MOV	AX,ES:[BX]
	ADD	AX,D_8C46
	PUSH	AX
	MOV	ES,CX	;restore ES
	db	0CBh;	RETF
;----C_226C
PUBLIC Gra_13
Gra_13 PROC NEAR
	MOV	DX,13*2
	JMP	C_2255
Gra_13 ENDP
;----C_2271
PUBLIC _Gra_dot_OR
_Gra_dot_OR PROC NEAR
	MOV	DX,14*2
	JMP	C_2255
_Gra_dot_OR ENDP
;----C_2276
PUBLIC _Gra_dot_XOR
_Gra_dot_XOR PROC NEAR
	MOV	DX,15*2
	JMP	C_2255
_Gra_dot_XOR ENDP
;----C_227B
PUBLIC _Gra_16
_Gra_16 PROC NEAR
	MOV	DX,16*2
	JMP	C_2255
_Gra_16 ENDP
;----C_2280
PUBLIC _Gra_17
_Gra_17 PROC NEAR
	POP	AX
	;--
	LEA	BX,[D_08B8]
	CMP	D_943A,1
	JZ	C_2290
	LEA	BX,[D_08C3]
C_2290:	PUSH	BX
	;--
	PUSH	AX
	MOV	DX,17*2
	JMP	C_2255
_Gra_17 ENDP
;----C_2297
;draw some quad?
PUBLIC _Gra_18
_Gra_18 PROC NEAR
	MOV	DX,18*2
	JMP	C_2255
_Gra_18 ENDP
;----C_229C
;draw the ankh?
PUBLIC _Gra_19
_Gra_19 PROC NEAR
	POP	AX
	MOV	BX,OFFSET DGROUP:pKarmas
	PUSH	BX
	PUSH	AX
	MOV	DX,19*2
	JMP	C_2255
_Gra_19 ENDP
;----C_22A7
PUBLIC _Gra_animSpit
_Gra_animSpit PROC NEAR
	MOV	DX,20*2
	JMP	C_2255
_Gra_animSpit ENDP
;----C_22AC
PUBLIC _Gra_init
_Gra_init PROC NEAR
	MOV	DX,21*2
	JMP	C_2255
_Gra_init ENDP
;----C_22B1
PUBLIC _Gra_clrscr
_Gra_clrscr PROC NEAR
	MOV	DX,22*2
	JMP	C_2255
_Gra_clrscr ENDP
;----C_22B6
PUBLIC Gra_animFlow
Gra_animFlow PROC NEAR
	MOV	DX,23*2
	JMP	C_2255
Gra_animFlow ENDP
;----C_22BB
PUBLIC Gra_animFlag
Gra_animFlag PROC NEAR
	MOV	DX,24*2
	JMP	C_2255
Gra_animFlag ENDP
;----C_22C0
PUBLIC Gra_putchar
Gra_putchar PROC NEAR
	POP	AX
	PUSH	txt_X
	PUSH	txt_Y
	PUSH	AX
	MOV	DX,25*2
	JMP	C_2255
Gra_putchar ENDP
;----------------------------------------
;
;----------------------------------------
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
C_22DB:
	MOV	DH,10h
	MOV	BX,OFFSET DGROUP:sizzleBuff
C_22E0:
	MOV	DL,8
C_22E2:
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
	JNZ	C_22E2
	ADD	BX,2
	DEC	DH
	JNZ	C_22E0
	MOV	DX,CX
	;--
	MOV	SI,OFFSET DGROUP:sizzleBuff
	MOV	CX,40h
	REPZ	MOVSW
	;--
	MOV	CX,DX
	MOV	SI,DI
	LOOP	C_22DB
	;--
	POP	ES
	POP	DI
	POP	SI
	RET
sizzleShapes	ENDP
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
C_234D:
	MOV	DH,8
	MOV	BX,OFFSET DGROUP:sizzleBuff
C_2352:
	MOV	DL,4
C_2354:
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
	JNZ	C_2354
	INC	BX
	DEC	DH
	JNZ	C_2352
	MOV	DX,CX
	;--
	MOV	SI,OFFSET DGROUP:sizzleBuff
	MOV	CX,10h
	REPZ	MOVSW
	;--
	MOV	CX,DX
	MOV	SI,DI
	LOOP	C_234D
	;--
	POP	ES
	POP	DI
	POP	SI
	RET
sizzleCharset ENDP
;----------------------------------------
_TEXT	ENDS
;########################################
END
