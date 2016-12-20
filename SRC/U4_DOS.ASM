EXTRN _exit:NEAR

_TEXT	SEGMENT PUBLIC BYTE 'CODE'
	ASSUME CS:_TEXT

;--C_1FF4
PUBLIC _dalloc
_dalloc PROC NEAR
	PUSH	BP
	MOV	BP,SP
	;-- convert to size in paragraphs
	MOV	BX,[BP+04]
	SHR	BX,1
	SHR	BX,1
	SHR	BX,1
	SHR	BX,1
	TEST	WORD PTR [BP+04],0Fh
	JZ	C_200A
	INC	BX
C_200A:	;--
	MOV	AH,48h
	INT	21h
	MOV	DX,AX
	MOV	AX,0
	JNB	C_201F
	;--
	MOV	AX,2Dh
	PUSH	AX
	CALL	_exit
	;--
	MOV	DX,0
C_201F:	;--
	MOV	SP,BP
	POP	BP
	RET
_dalloc ENDP

;--C_2023
PUBLIC _dfree
_dfree PROC NEAR
	PUSH	ES
	PUSH	BP
	MOV	BP,SP
	;--
	MOV	ES,[BP+08]
	MOV	AH,49h
	INT	21h
	;--
	MOV	SP,BP
	POP	BP
	POP	ES
	RET
_dfree ENDP

;--C_2033
PUBLIC _dopen
_dopen PROC NEAR
	PUSH	BP
	MOV	BP,SP
	;--
	MOV	DX,[BP+04]
	MOV	AL,[BP+06]
	MOV	AH,3Dh
	INT	21h
	JNB	C_2045
	MOV	AX,0FFFFh
C_2045:	;--
	MOV	SP,BP
	POP	BP
	RET
_dopen ENDP

;--C_2049
PUBLIC _dlseek
_dlseek PROC NEAR
	PUSH	BP
	MOV	BP,SP
	;--
	MOV	BX,[BP+04]
	MOV	CX,[BP+08]
	MOV	DX,[BP+06]
	MOV	AL,0
	MOV	AH,42h	; move file pointer using handler
	INT	21h
	JNB	C_2063
	MOV	AX,0FFFFh
	MOV	DX,0FFFFh
C_2063:	;--
	MOV	SP,BP
	POP	BP
	RET
_dlseek ENDP

;--C_2067
PUBLIC _dread
_dread PROC NEAR
	PUSH	BP
	MOV	BP,SP
	PUSH	DS
	PUSH	SI
	PUSH	DI
	;--
	MOV	BX,[BP+04]
	MOV	CX,[BP+0Ah]
	MOV	DX,[BP+06]
	MOV	AX,[BP+08]
	MOV	DS,AX
	MOV	AH,3Fh
	INT	21h
	JNB	C_2084
	MOV	AX,0FFFFh
C_2084:	;--
	POP	DI
	POP	SI
	POP	DS
	MOV	SP,BP
	POP	BP
	RET
_dread ENDP

;--C_208B
PUBLIC _dwrite
_dwrite PROC NEAR
	PUSH	BP
	MOV	BP,SP
	PUSH	DS
	;--
	MOV	BX,[BP+04]
	MOV	CX,[BP+0Ah]
	MOV	DX,[BP+06]
	MOV	AX,[BP+08]
	MOV	DS,AX
	MOV	AH,40h
	INT	21h
	JNB	C_20A6
	MOV	AX,0FFFFh
C_20A6:	;--
	POP	DS
	MOV	SP,BP
	POP	BP
	RET
_dwrite ENDP

;--C_20AB
PUBLIC _dclose
_dclose PROC NEAR
	PUSH	BP
	MOV	BP,SP
	;--
	MOV	BX,[BP+04]
	MOV	AH,3Eh
	INT	21h
	MOV	AX,0
	JNB	C_20BD
	MOV	AX,0FFFFh
C_20BD:	;--
	MOV	SP,BP
	POP	BP
	RET
_dclose ENDP


_TEXT	ENDS

END
