EXTRN u4_puts:NEAR
EXTRN u4_putc:NEAR
EXTRN Gra_putchar:NEAR
EXTRN t_callback:NEAR

EXTRN MSG_DSKERR:BYTE
EXTRN MSG_SYSERR:BYTE

EXTRN speed_info:WORD

EXTRN Party:BYTE

EXTRN txt_X:WORD
EXTRN txt_Y:WORD

PUBLIC cursor_rate


DGROUP	GROUP _DATA,_BSS
;########################################
_DATA	SEGMENT PUBLIC WORD 'DATA'
	ASSUME DS:DGROUP
;----------------------------------------
cursor_rate	dw 0	;D_0672
D_0674	dw 0
D_0676	dw 0FFFFh	;display cursor flag
;----------------------------------------
_DATA	ENDS
;########################################
_BSS	SEGMENT PUBLIC WORD 'BSS'
;----------------------------------------
;random seeds
PUBLIC seed_0,seed_1,seed_2,seed_3
seed_0	dd ?	;D_8732
seed_1	dd ?	;D_8736
seed_2	dd ?	;D_873A
seed_3	dd ?	;D_873E
;-- struct t_500 --
PUBLIC D_8742
D_8742	db 500h dup(?)
;--
D_8C42	db ?	;cursor state {0, 1, 2, 3}
D_8C43	dw ?	;cursor update counter
	db ?	;padding?
;----------------------------------------
_BSS	ENDS
;########################################
_TEXT	SEGMENT PUBLIC BYTE 'CODE'
	ASSUME CS:_TEXT
;----------------------------------------C_16CD
;[bp+04] wait delay in seconds
;[bp+06] allow interruption/prompt
PUBLIC _u_delay
_u_delay	PROC NEAR
	PUSH	BP
	MOV	BP,SP
	PUSH	SI
	;--
	MOV	D_8C43,1
	;--
	MOV	AX,cursor_rate
	MOV	D_0674,AX
	;--
	MOV	AH,2Ch	;get time
	INT	21h
	MOV	DL,DH	;seconds
	MOV	DH,0
	MOV	SI,DX
	ADD	SI,[BP+04]
	CMP	SI,60
	JB	C_1701
	;-- --
	SUB	SI,60
	;--
	TEST	WORD PTR [BP+06],0FFFFh
	JZ	C_1710	;cannot interrupt
	CALL	_u_kbhit
	TEST	AX,0FFFFh
	JNZ	C_176C	;key has been pressed
C_1701:	;--
	TEST	WORD PTR [BP+06],0FFFFh
	JZ	C_1710	;cannot interrupt
	CALL	_u_kbhit
	TEST	AX,0FFFFh
	JNZ	C_175D	;key has been pressed
C_1710:	;--
	CALL	t_callback
	;============
	;== cursor ==
	;============
	MOV	AX,[BP+06]
	AND	AX,D_0676
	JZ	C_1751
	;-- update shape
	MOV	AX,D_0674
	CMP	AX,cursor_rate
	JNZ	C_173D
	DEC	D_8C43
	JNZ	C_1751
	DEC	D_8C42
	AND	D_8C42,3
	;-- display
	MOV	AL,D_8C42
	ADD	AL,1Ch
	PUSH	AX
	CALL	Gra_putchar
C_173D:	;-- reload cursor counter
	MOV	AX,1
	ADD	AX,cursor_rate
	MUL	speed_info
	MOV	D_8C43,AX
	;--
	MOV	AX,cursor_rate
	MOV	D_0674,AX
	;=======
C_1751:	;==   ==
	;=======
	MOV	AH,2Ch	;get time
	INT	21h
	MOV	BL,DH	;seconds
	MOV	BH,0
	CMP	SI,BX
	JNZ	C_1701
C_175D:	;--
	MOV	AX,[BP+06]
	AND	AX,D_0676
	JZ	C_176C
	;-- delete cursor --
	MOV	AL,' '
	PUSH	AX
	CALL	Gra_putchar
C_176C:	;--
	POP	SI
	MOV	SP,BP
	POP	BP
	RET
_u_delay	ENDP
;----------------------------------------C_1771
PUBLIC u_rand_a
u_rand_a	PROC NEAR
	PUSHF
	PUSH	CX
	PUSH	DI
	PUSH	ES
	;--
	MOV	AX,DS
	MOV	ES,AX
	STD
	;--
	MOV	CX,0Eh
	MOV	DI,OFFSET DGROUP:seed_3+2
	CLC
	MOV	AL,[DI+01]
C_1784:	ADC	AL,[DI]
	STOSB
	LOOP	C_1784
	ADC	[DI],AL
	;--
	MOV	CX,10h
	MOV	DI,OFFSET DGROUP:seed_3+4
C_1791:	DEC	DI
	INC	BYTE PTR [DI]
	LOOPZ	C_1791
	;--
	POP	ES
	POP	DI
	POP	CX
	POPF
	;--
	MOV	AL,BYTE PTR seed_0
	MOV	AH,0
	TEST	AL,0FFh
	;--
	RET
u_rand_a	ENDP
;----------------------------------------C_17A2
PUBLIC u_rand_b
u_rand_b	PROC NEAR
	MOV	AL,BYTE PTR seed_0[3]
	ADC	AL,BYTE PTR seed_0[2]
	MOV	BYTE PTR seed_0[2],AL
	XOR	BYTE PTR seed_0[1],AL
	MOV	AL,BYTE PTR seed_0[1]
	ADC	AL,BYTE PTR seed_0[0]
	ROR	AL,1
	MOV	BYTE PTR seed_0[0],AL
	MOV	BYTE PTR seed_0[3],AL
	MOV	AH,0
	TEST	AX,0FFFFh
	RET
u_rand_b	ENDP
;----------------------------------------C_17C5
;increment Party.f_000
;returns:
; 1 if key is pressed
; 0 if not
PUBLIC _u_kbhit
_u_kbhit	PROC NEAR
	CALL	u_rand_a
	;-- increment (unsigned long)Party.f_000
	INC	WORD PTR Party
	JNZ	C_17D2
	INC	WORD PTR Party+2
C_17D2:	;--
	MOV	AH,1	;get keyboard status
	INT	16h
	JZ	C_17EB	;-- no key pressed
	CMP	AX,2E03h	;<CTRL C> key code ?
	JZ	C_17E7	;remove <CTRL C>
	TEST	AX,0FFFFh
	JZ	C_17E7	;remove <CTRL C>
	;-- returns 1
	MOV	AX,1
	JMP	SHORT C_17F1
C_17E7:	;-- remove <CTRL C>
	MOV	AH,0	;wait for keypress and read character
	INT	16h
C_17EB:	;--
	CALL	t_callback
	;-- returns 0
	MOV	AX,0
C_17F1:	;-- --
	OR	AX,AX
	;--
	RET
_u_kbhit	ENDP
;----------------------------------------C_17F4
;get keyboard scancode
;wait if necessary
PUBLIC _u_kbread
_u_kbread	PROC NEAR
	;-- wait a very long time,
	;-- and allow key interrupt
	MOV	AX,8081h
	PUSH	AX
	PUSH	AX
	CALL	_u_delay
	ADD	SP,4
	;--
	MOV	AH,0
	INT	16h
	;--
	RET
_u_kbread	ENDP
;----------------------------------------C_1804
;wait while key pressed
PUBLIC _u_kbflush
_u_kbflush	PROC NEAR
	;-- allow interrupts
	STI
	NOP
	NOP
	NOP
	CLI
	;--
	CALL	_u_kbhit
	JZ	C_1813
	CALL	_u_kbread
	JMP	_u_kbflush
C_1813:	;--
	RET
_u_kbflush	ENDP
;----------------------------------------
;get current default drive
PUBLIC C_1814
C_1814	PROC NEAR
	MOV	AH,19h	;get current default drive
	INT	21h
	INC	AL
	MOV	AH,0
	;--
	RET
C_1814	ENDP
;----------------------------------------
;select disk
PUBLIC C_181D
C_181D	PROC NEAR
	PUSH	BP
	MOV	BP,SP
	;--
	MOV	DL,[BP+04]
	DEC	DL
	MOV	AH,0Eh	;select disk
	INT	21h
	MOV	AH,0
	;--
	POP	BP
	RET	2
C_181D	ENDP
;----------------------------------------
;test file
PUBLIC C_182F
C_182F	PROC NEAR
	PUSH	BP
	MOV	BP,SP
	;--
	MOV	DX,[BP+04]
	MOV	AL,0
	MOV	AH,3Dh	;open file
	INT	21h
	JNB	C_1842
	;--
	MOV	AX,0
	JMP	SHORT C_184B
C_1842:	;--
	MOV	BX,AX
	MOV	AH,3Eh	;close file
	INT	21h
	;--
	MOV	AX,1
C_184B:	;--
	POP	BP
	RET	2
C_182F	ENDP
;----------------------------------------
;piracy check function ?
;succes => 0
;failure => -1
PUBLIC C_184F
C_184F	PROC NEAR
	PUSHF
	PUSH	BX
	PUSH	AX
	PUSH	CX
	PUSH	DX
	PUSH	DS
	PUSH	ES
	;--
	PUSH	BP
	MOV	BP,SP
	PUSH	DI
	PUSH	SI
	;-- set drive
	MOV	AH,19h	;get current default drive
	INT	21h
	CMP	AL,1
	JBE	C_1865
	MOV	AL,0
C_1865:	MOV	DL,AL	;drive
	;--
	MOV	SI,4	;4 tries
	MOV	CL,10h	;from sector 10h
nextSector:	;--
	MOV	AX,(2 SHL 8) OR 1	;read 1 sector
	MOV	DH,0	;head 0
	MOV	CH,9	;track 9
	MOV	BX,0C000h
	MOV	ES,BX
	XOR	BX,BX	;to c000:0000
	INT	13h
	JB	C_1887
	;-- one track success
	DEC	CL
	JZ	C_1890	;finished
	MOV	SI,4	;4 tries
	JMP	nextSector
C_1887:	;-- failed this sector
	DEC	SI
	JNZ	nextSector
	;-- failure
	MOV	BX,0FFFFh
	JMP	C_1893	;(+nop)
C_1890:	;-- success
	MOV	BX,0
C_1893:	;--
	POP	SI
	POP	DI
	MOV	SP,BP
	POP	BP
	;--
	POP	ES
	POP	DS
	POP	DX
	POP	CX
	POP	AX
	MOV	AL,BL
	POP	BX
	POPF
	RET
C_184F	ENDP
;----------------------------------------
;set critical error handler
PUBLIC C_18A2
C_18A2	PROC NEAR
	PUSH	DS
	;--
	LEA	DX,INT_18B3
	MOV	AX,CS
	MOV	DS,AX
	MOV	AH,25h	;set new interrupt vector
	MOV	AL,24h	;Critical Error
	INT	21h
	;--
	POP	DS
	RET
C_18A2	ENDP
;----
INT_18B3:
	PUSH	BP
	MOV	BP,SP
	PUSH	BX
	PUSH	CX
	PUSH	DX
	PUSH	SI
	PUSH	DS
	PUSH	ES
	;--
	MOV	BX,SS
	MOV	DS,BX
	MOV	ES,BX
	TEST	AH,80h
	JNZ	C_190C
	;-- display disk error --
	PUSH	txt_Y
	PUSH	txt_X
	MOV	txt_Y,24	;18h
	MOV	txt_X,0
	;--
	LEA	AX,MSG_DSKERR
	PUSH	AX
	CALL	u4_puts
	;--
	MOV	AH,0
	INT	16h
	;--
	MOV	txt_X,0
	MOV	SI,39	;27h
C_18F0:	;--
	MOV	AX,' '
	PUSH	AX
	CALL	u4_putc
	;--
	DEC	SI
	JNZ	C_18F0
	;--
	POP	txt_X
	POP	txt_Y
	;-- --
	POP	ES
	POP	DS
	POP	SI
	POP	DX
	POP	CX
	POP	BX
	POP	BP
	MOV	AL,1
	IRET
C_190C:	;-- display fatal error
	LEA	AX,MSG_SYSERR
	PUSH	AX
	CALL	u4_puts
	;-- --
	POP	ES
	POP	DS
	POP	SI
	POP	DX
	POP	CX
	POP	BX
	POP	BP
	MOV	AL,2
	IRET
;----------------------------------------
_TEXT	ENDS
;########################################
END
