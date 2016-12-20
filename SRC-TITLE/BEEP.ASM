
EXTRN speed_info:WORD

_TEXT	SEGMENT PUBLIC BYTE 'CODE'
	ASSUME CS:_TEXT

;same as sound(1) for avatar.exe
PUBLIC sound_1	;C_21BF
sound_1	PROC NEAR
	MOV	AX,0CAh
	MUL	speed_info
	MOV	DX,AX
	;-- backup port 61h
	IN	AL,61h
	MOV	AH,AL
	;--
	AND	AL,NOT 3
	MOV	CX,10h
C_21D1:
	OUT	61h,AL
	XOR	AL,2
	MOV	BX,DX
C_21D7:
	DEC	BX
	PUSHF
	PUSH	AX
	POP	AX
	POPF
	JNZ	C_21D7
	LOOP	C_21D1
	;-- restore port 61h
	MOV	AL,AH
	OUT	61h,AL
	;--
	RET
sound_1	ENDP

_TEXT	ENDS

END
