PUBLIC far_psp
PUBLIC speed_info,equip_flags,patch_tandy

EXTRN seed_0:DWORD
EXTRN seed_1:DWORD
EXTRN seed_2:DWORD
EXTRN seed_3:DWORD

EXTRN __psp:WORD

DGROUP	GROUP _DATA,_BSS
;########################################
_DATA	SEGMENT PUBLIC WORD 'DATA'
	ASSUME DS:DGROUP
;----------------------------------------
far_psp	dw 0,0	;D_041C
D_0420	db "andy"
;----------------------------------------
_DATA	ENDS
;########################################
_BSS	SEGMENT PUBLIC WORD 'BSS'
;----------------------------------------
D_6926	dw ?,?	;original vector int 0x1c
D_692A	dw ?,?	;original vector int 0x24
speed_info	dw ?	;D_692E
D_6930	db ?	;original graphic mode
equip_flags	dw ?	;D_6931
patch_tandy	dw ?,?	;D_6933
	db ?	;padding?
;----------------------------------------
_BSS	ENDS
;########################################
_TEXT	SEGMENT PUBLIC BYTE 'CODE'
	ASSUME CS:_TEXT
;----------------------------------------
C_244C	dw 0
PUBLIC low_init	;C_244E
low_init	PROC NEAR
	PUSH	BP
	MOV	BP,SP
	SUB	SP,4
	;--
	PUSH	ES
	;-------------------------
	;-- Get equipment flags --
	;-------------------------
	INT	11h	;bios equipment flag
	MOV	CX,AX
	MOV	equip_flags,AX
	;-----------------------
	;-- Save graphic mode --
	;-----------------------
	MOV	AH,0Fh
	PUSH	BP
	INT	10h
	POP	BP
	MOV	D_6930,AL
	;--------------------------
	;-- Create PSP variable  --
	;--------------------------
	MOV	AX,__psp
	MOV	far_psp+2,AX	;transform psp into a far ptr
	;-----
	;-- --
	;-----
	MOV	AH,48h	;allocate memory
	MOV	BX,0FFFFh
	INT	21h
	SUB	BX,400h + 1
	MOV	[BP-04],BX
	;%%
	MOV	AH,48h	;allocate memory
	INT	21h
	MOV	[BP-02],AX
	;--
	MOV	AH,48h	;allocate memory
	MOV	BX,400h
	INT	21h
	MOV	patch_tandy+2,AX
	MOV	BX,50h
	MOV	ES,BX
	MOV	BX,10h
	MOV	ES:[BX],AX	;0050:0010
	;--
	MOV	ES,[BP-02]
	MOV	AH,49h	;free allocated memory
	INT	21h
	;------------------
	;-- Save int 24h --
	;------------------
	MOV	AH,35h
	MOV	AL,24h
	INT	21h
	MOV	D_692A,BX
	MOV	D_692A+2,ES
	;----------------------------
	;-- Reset random generator --
	;----------------------------
	MOV	AH,2Ch
	INT	21h
	MOV	WORD PTR seed_0,DX
	MOV	WORD PTR seed_0+2,CX
	MOV	WORD PTR seed_2,DX
	MOV	WORD PTR seed_2+2,CX
	;--
	MOV	AH,2Ah
	INT	21h
	MOV	WORD PTR seed_1,DX
	MOV	WORD PTR seed_1+2,CX
	MOV	WORD PTR seed_3,DX
	MOV	WORD PTR seed_3+2,CX
	;--------------------------
	;-- Check computer speed --
	;--------------------------
	MOV	CS:C_244C,0
	;--
	MOV	speed_info,0
	;-- save int 1ch
	MOV	AH,35h
	MOV	AL,1Ch
	INT	21h
	MOV	D_6926,BX
	MOV	D_6926+2,ES
	;-- set new int 1ch
	PUSH	DS
	LEA	DX,INT_257D
	MOV	AX,CS
	MOV	DS,AX
	MOV	AH,25h
	MOV	AL,1Ch
	INT	21h
	POP	DS
	;-- wait for C_0010 to reset
	MOV	AX,0
C_2500:	CMP	CS:C_244C,AX
	JZ	C_2500
	;--
	MOV	AX,CS:C_244C
C_250B:	INC	speed_info
	JS	C_252A
	MOV	DX,[BX+1F40h]
	MOV	DX,ES:[BX+SI+1F40h]
	MOV	DX,[BP+SI]
	MOV	DX,0
	MOV	CL,14h
	RCR	DX,CL
	CMP	CS:C_244C,AX
	JZ	C_250B
C_252A:	;-- restore int 1ch
	PUSH	DS
	MOV	AH,25h
	MOV	AL,1Ch
	LDS	DX,DWORD PTR D_6926
	INT	21h
	POP	DS
	;--
	MOV	DX,0
	MOV	AX,speed_info
	MOV	CX,1000
	DIV	CX
	TEST	AX,0FFFFh
	JNZ	C_2549
	MOV	AX,1
C_2549:	MOV	speed_info,AX
	;--
	POP	ES
	;--
	MOV	SP,BP
	POP	BP
	RET	
low_init	ENDP
;----
PUBLIC low_clean	;C_2551
low_clean	PROC NEAR
	PUSH	BP
	MOV	BP,SP
	PUSH	ES
	;--------------------------
	;-- Restore graphic mode --
	;--------------------------
	MOV	AH,0
	MOV	AL,D_6930
	INT	10h
	;-----
	;-- --
	;-----
	TEST	patch_tandy+2,0FFFFh
	JZ	C_256E
	;--
	MOV	ES,patch_tandy+2
	MOV	AH,49h	;free allocated memory
	INT	21h
	JNB	C_257A
C_256E:	;---------------------
	;-- restore int 24h --
	;---------------------
	PUSH	DS
	MOV	AH,25h
	MOV	AL,24h
	LDS	DX,DWORD PTR D_692A
	INT	21h
	POP	DS
C_257A:	;--
	POP	ES
	POP	BP
	RET
low_clean	ENDP
;----
INT_257D:
	INC	CS:C_244C
	IRET
;----------------------------------------
;determine graphic adapter type
PUBLIC low_gra	;C_2583
low_gra	PROC NEAR
	PUSH	SI
	PUSH	DI
	PUSH	ES
	;-- check f000:fffe
	MOV	AX,0F000h
	MOV	ES,AX
	MOV	DI,0FFFEh
	CMP	BYTE PTR ES:[DI],0FDh
	MOV	AX,1
	JZ	C_25C2	;is 0xfd?
	CMP	BYTE PTR ES:[DI],0FFh
	JNZ	C_25F9
	;-- is 0xff - look for 'Tandy'
	MOV	DI,0A000h
	MOV	CX,5FFFh
C_25A3:	MOV	AL,'T'
	REPNZ	SCASB
	JNZ	C_25F9
	PUSH	DI
	PUSH	CX
	MOV	CX,4
	LEA	SI,D_0420	;"andy"
	REPZ	CMPSB
	POP	CX
	POP	DI
	JNZ	C_25A3	;try next
	;-- return 3 - Tandy?
	MOV	AX,3
	JMP	SHORT C_2619
C_25BD:	;-- returns -1
	MOV	AX,-1
	JMP	SHORT C_2619
C_25C2:	;-- check b800:0000
	MOV	AX,0B800h
	MOV	ES,AX
	MOV	BX,0
	MOV	AX,ES:[BX]
	MOV	WORD PTR ES:[BX],5555h
	CMP	WORD PTR ES:[BX],5555h
	JNZ	C_25BD	;returns -1
	MOV	WORD PTR ES:[BX],0AAAAh
	CMP	WORD PTR ES:[BX],0AAAAh
	JNZ	C_25BD	;returns -1
	MOV	WORD PTR ES:[BX],0D221h
	CMP	WORD PTR ES:[BX],0D221h
	JNZ	C_25BD	;returns -1
	MOV	ES:[BX],AX
	;-- return 1 - cga?
	MOV	AX,1
	JMP	SHORT C_2619
C_25F9:	;--
	MOV	AH,12h
	MOV	BL,10h
	MOV	CX,0FFFFh
	INT	10h
	CMP	CX,-1
	JZ	C_25C2
	MOV	AL,BH
	AND	AX,1
	XOR	AL,1
	CMP	AL,0
	JZ	C_25BD	;returns -1
	CMP	AL,1
	JNZ	C_25C2
	;-- return 2 - ega?
	MOV	AX,2
C_2619:	;--
	POP	ES
	POP	DI
	POP	SI
	RET	
low_gra	ENDP
;----------------------------------------
_TEXT	ENDS
;########################################
END
