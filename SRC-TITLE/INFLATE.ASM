EXTRN _open:NEAR
EXTRN _close:NEAR
EXTRN _read:NEAR
EXTRN _lseek:NEAR
EXTRN _malloc:NEAR
EXTRN _free:NEAR

DGROUP	GROUP _BSS

_BSS	SEGMENT PUBLIC WORD 'BSS'
	ASSUME DS:DGROUP

D_3B20	dw ?	;deflated file size
D_3B22	dw ?	;deflated file buffer(pointer)
D_3B24	db ?	;12 bits flag
D_3B25	db ?	;temporary stores 4 bits
D_3B26	dw 0f00h dup(?)
D_5926	db 0f00h dup(?)
D_6826	db 100h dup(?)

_BSS	ENDS


_TEXT	SEGMENT PUBLIC BYTE 'CODE'
	ASSUME CS:_TEXT

C_21E5	PROC NEAR
	PUSH	BP
	MOV	BP,SP
	;-- AX := (bp06 << 4) ^ bp04
	MOV	CL,4
	MOV	AX,[BP+06]
	SHL	AX,CL
	XOR	AX,[BP+04]
	AND	AH,0Fh
	;--
	TEST	AH,0FFh
	JZ	C_221C
	MOV	BX,AX
	SHL	BX,1
	MOV	CX,D_3B26[BX - 2*100h]
	TEST	CX,0FFFFh
	JZ	C_224B
	AND	CX,NOT 2000h
	CMP	CX,[BP+04]
	JNZ	C_221C
	MOV	BX,AX
	MOV	CL,D_5926[BX - 100h]
	CMP	CL,[BP+06]
	JZ	C_228E
C_221C:
	MOV	AX,[BP+06]
	SUB	AH,AH
	SHL	AX,1
	ADD	AX,[BP+04]
	OR	AX,800h
	MUL	AX
	RCL	AX,1
	RCL	DX,1
	RCL	AX,1
	RCL	DX,1
	MOV	AL,AH
	MOV	AH,DL
	AND	AH,0Fh
	TEST	AH,0FFh
	JZ	C_2261
	MOV	BX,AX
	SHL	BX,1
	MOV	CX,D_3B26[BX - 2*100h]
	TEST	CX,0FFFFh
C_224B:
	JZ	C_228E
	AND	CX,NOT 2000h
	CMP	CX,[BP+04]
	JNZ	C_2261
	MOV	BX,AX
	MOV	CL,D_5926[BX - 100h]
	CMP	CL,[BP+06]
	JZ	C_228E
C_2261:
	ADD	AX,1FDh
	AND	AX,0FFFh
	TEST	AH,0FFh
	JZ	C_2261
	MOV	BX,AX
	SHL	BX,1
	MOV	CX,D_3B26[BX - 2*100h]
	TEST	CX,0FFFFh
	JZ	C_228E
	AND	CX,NOT 2000h
	CMP	CX,[BP+04]
	JNZ	C_2261
	MOV	BX,AX
	MOV	CL,D_5926[BX - 100h]
	CMP	CL,[BP+06]
	JNZ	C_2261
C_228E:	;--
	POP	BP
	RET	
C_21E5	ENDP

;AX := read 12 bits?
C_2290	PROC NEAR
	MOV	BX,D_3B22
	;-- AL := read one byte
	SUB	D_3B20,1
	JB	C_22C8	;end of buffer?
	MOV	AL,[BX]
	INC	BX
	;--
	TEST	D_3B24,0FFh
	JNZ	C_22BF
	;========================
	;== read a second byte ==
	;== stores 12 bits in  ==
	;== AX and the remai-  ==
	;== ning 4 in D_3B25   ==
	;========================
	;-- DL := read one byte
	SUB	D_3B20,1
	JB	C_22C8	;end of buffer?
	MOV	DL,[BX]
	INC	BX
	;--
	MOV	D_3B25,DL
	MOV	CL,4
	MOV	AH,0
	SHL	AX,CL
	SHR	DL,CL
	OR	AL,DL
	;--
	JMP	SHORT C_22CB
	;========================
C_22BF:	;== read only one byte ==
	;== use remaining 4    ==
	;== bits from D_3B25   ==
	;========================
	MOV	AH,D_3B25
	AND	AH,0Fh
	;--
	JMP	SHORT C_22CB
	;===================
C_22C8:	;== end of buffer ==
	;===================
	MOV	AX,0FFFFh
	;=======
C_22CB:	;==   ==
	;=======
	XOR	D_3B24,1
	MOV	D_3B22,BX
	;--
	RET
C_2290	ENDP

;LZW inflate?
;[Lempel-Ziv-Welch]
C_22D5	PROC NEAR
	PUSH	BP
	MOV	BP,SP
	SUB	SP,8
	PUSH	SI
	PUSH	DI
	PUSH	ES
	;--
	MOV	WORD PTR [BP-04],0
	MOV	D_3B24,0
	MOV	AX,DS
	MOV	ES,AX
	;--
	SUB	AX,AX
	LEA	DI,D_3B26
	MOV	CX,0F00h
	REPZ	STOSW
	;--
	CALL	C_2290	;AX := read 12 bits?
	MOV	[BP-06],AX
	MOV	[BP-08],AX
	;--
	CALL	[BP+04]	;callback(AL)
	;***************
C_2303:	;** main loop **
	;***************
	CALL	C_2290	;AX := read 12 bits?
	MOV	[BP-02],AX
	;%%
	CMP	AX,0FFFFh
	JNZ	C_2311
	JMP	C_23BC	;finished!
C_2311:	;--
	TEST	AH,0FFh
	JZ	C_235C
	;=======
	;==   ==
	;=======
	LEA	SI,D_6826
	MOV	BX,AX
	SHL	BX,1
	TEST	D_3B26[BX - 2*100h],0FFFFh
	JNZ	C_232F
	MOV	AX,[BP-08]
	MOV	[SI],AL
	INC	SI
	MOV	AX,[BP-06]
C_232F:
	MOV	BX,AX
	TEST	AH,0FFh
	JZ	C_2348
	MOV	AL,D_5926[BX - 100h]
	MOV	[SI],AL
	INC	SI
	SHL	BX,1
	MOV	AX,D_3B26[BX - 2*100h]
	AND	AX,NOT 2000h
	JMP	C_232F
C_2348:	;--
	MOV	[BP-08],AX
	CALL	[BP+04]	;callback(AL)
C_234E:	;--
	DEC	SI
	MOV	AL,[SI]
	CALL	[BP+04]	;callback(AL)
	;--
	CMP	SI,OFFSET DGROUP:D_6826
	JNZ	C_234E
	;--
	JMP	SHORT C_2362
	;=======
C_235C:	;==   ==
	;=======
	CALL	[BP+04]	;callback(AL)
	MOV	[BP-08],AL
	;=======
C_2362:	;==   ==
	;=======
	PUSH	[BP-08]
	PUSH	[BP-06]
	CALL	C_21E5
	ADD	SP,4
	MOV	BX,AX
	;--
	MOV	AX,[BP-08]
	MOV	D_5926[BX - 100h],AL
	SHL	BX,1
	MOV	AX,[BP-06]
	OR	AX,2000h
	MOV	D_3B26[BX - 2*100h],AX
	INC	WORD PTR [BP-04]
	MOV	AX,[BP-04]
	CMP	AX,0CCCh
	JBE	C_23B3
	MOV	AX,DS
	MOV	ES,AX
	MOV	WORD PTR [BP-04],0
	;--
	SUB	AX,AX
	LEA	DI,D_3B26
	MOV	CX,0F00h
	REPZ	STOSW
	;--
	CALL	C_2290	;AX := read 12 bits?
	MOV	[BP-02],AX
	MOV	[BP-08],AX
	CMP	AX,0FFFFh
	JZ	C_23BC	;finished!
	;--
	CALL	[BP+04]	;callback(AL)
C_23B3:	;--
	MOV	AX,[BP-02]
	MOV	[BP-06],AX
	;--
	JMP	C_2303	;main loop!
C_23BC:	;--
	POP	ES
	POP	DI
	POP	SI
	MOV	SP,BP
	POP	BP
	RET
C_22D5	ENDP

;load file + inflate(callback)?
;[bp+04] file name
;[bp+06] callback(AL)
PUBLIC _C_23C3
_C_23C3	PROC NEAR
	PUSH	BP
	MOV	BP,SP
	SUB	SP,4
	;--
	MOV	AX,8000h	;O_BINARY|O_RDONLY
	PUSH	AX
	PUSH	[BP+04]
	CALL	_open
	ADD	SP,4
	;%%
	MOV	[BP-02],AX
	CMP	AX,-1
	JZ	C_243A	;error
	;** compute file size **
	MOV	BX,2	;SEEK_END
	PUSH	BX
	MOV	BX,0
	PUSH	BX
	PUSH	BX
	PUSH	AX	;file handle
	CALL	_lseek
	ADD	SP,8
	MOV	D_3B20,AX
	;** **
	PUSH	AX	;file size
	CALL	_malloc
	ADD	SP,2
	MOV	D_3B22,AX
	MOV	[BP-04],AX
	TEST	AX,0FFFFh
	JZ	C_243A	;error
	;--
	MOV	AX,0
	PUSH	AX
	PUSH	AX
	PUSH	AX
	PUSH	[BP-02]
	CALL	_lseek
	ADD	SP,8
	;--
	PUSH	D_3B20
	PUSH	D_3B22
	PUSH	[BP-02]
	CALL	_read
	ADD	SP,6
	;--
	PUSH	[BP-02]
	CALL	_close
	ADD	SP,2
	;--
	PUSH	[BP+06]	;callback
	CALL	C_22D5	;inflate?
	ADD	SP,2
	;--
	MOV	AX,0
	JMP	SHORT C_243F	;sould be return but?
C_243A:	;-- error --
	MOV	AX,-1
	JMP	SHORT C_243F	;sould be return but?
C_243F:	;** **
	PUSH	[BP-04]
	CALL	_free
	ADD	SP,2
	;** **
	MOV	SP,BP
	POP	BP
	RET
_C_23C3	ENDP

_TEXT	ENDS

END
