DGROUP	GROUP XOB,XO,XOE,c_common

XOB	SEGMENT PUBLIC WORD 'BSS'
XOB	ENDS
XO	SEGMENT PUBLIC WORD 'BSS'
XO	ENDS
XOE	SEGMENT PUBLIC WORD 'BSS'
XOE	ENDS

PUBLIC D_9140,D_9141,D_9142,Party
PUBLIC D_933A,D_943A,tile_forward,D_943E
PUBLIC D_9440,ship_x,ship_y,tile_cur
PUBLIC D_9445,D_9446,D_9448,D_944A
PUBLIC D_9452,pShapes,D_9458,CurMode
PUBLIC spell_cnt,D_946C,Combat,Fighters
PUBLIC File_DNG,activeChara,D_959C
PUBLIC tile_east,pCharset,spell_sta,D_95A5
PUBLIC txt_X,tile_north,activeCharaY
PUBLIC hit_tile,hit_x,hit_y
PUBLIC D_95B2
PUBLIC tile_west,tile_south,txt_Y,D_95C6
PUBLIC D_95C8,tile_back,D_95CC,D_95CE
PUBLIC D_96EE,File_MAP,WindDir,D_96F4
PUBLIC File_TLK,D_96F8,D_96F9,D_9772

;actually, the next segment should be
;generated as a COMDEF record

c_common	SEGMENT PUBLIC PARA 'BSS'
	ASSUME DS:DGROUP

D_9140	db ?
D_9141	db ?
D_9142	dw ?
Party	db 1F6h dup(?)	;D_9144
D_933A	dd 8*8 dup(?)	;tMap32x32 far *
D_943A	dw ?	;graphic adaptater type 
tile_forward	db ?	;D_943C
	db ?
D_943E	dw ?
D_9440	dw ?
ship_x	db ?	;D_9442
ship_y	db ?	;D_9443
tile_cur	db ?	;D_9444
D_9445	db ?
D_9446	dw ?
D_9448	db ?
	db ?
D_944A	db 8 dup (?)
D_9452	db ?
	db ?
pShapes	dd ?	;D_9454
D_9458	dw 9 dup(?)	;jmp_buf
CurMode	dw ?	;D_946A
D_946C	db ?
	db ?
spell_cnt	dw ?	;D_946E
Combat	db 0C0h dup(?)	;D_9470 struct tCombat
Fighters	db 68h dup(?)	;D_9530
File_DNG	dw ?	;D_9598
activeChara	dw ?	;D_959A
D_959C	db ?,?
tile_east	db ?	;D_959E
	db ?
pCharset	dd ?	;D_95A0
spell_sta	db ?	;D_95A4
D_95A5	db ?,?
	db ?
txt_X	dw ?
tile_north	db ?	;D_95AA
	db ?
activeCharaY	dw ?	;D_95AC
hit_tile	dw ?	;D_95AE
hit_x	db ?	;D_95B0
hit_y	db ?	;D_95B1
D_95B2	db 16 dup (?)
tile_west	db ?	;D_95C2
tile_south	db ?	;D_95C3
txt_Y	dw ?
D_95C6	dw ?
D_95C8	dw ?
tile_back	db ?	;D_95CA
	db ?
D_95CC	dw ?
D_95CE	db 120h dup (?)
D_96EE	db ?
	db ?
File_MAP	dw ?	;D_96F0
WindDir	dw ?	;D_96F2
D_96F4	db ?
	db ?
File_TLK	dw ?	;D_96F6
D_96F8	db ?
D_96F9	db 11*11 dup (?)
D_9772	db ?

c_common	ENDS

END
