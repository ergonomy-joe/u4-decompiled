
DGROUP	GROUP CONST

CONST	SEGMENT PUBLIC WORD 'CONST'
	ASSUME DS:DGROUP

;====---- monster animation sequence ----====
PUBLIC D_3380
D_3380	db 01h,01h,01h,00h,00h,01h,01h,01h,00h,00h,01h,01h,02h,02h,03h,03h
	db 04h,04h,01h,02h,03h,04h,01h,02h,05h,06h,07h,08h,05h,06h,07h,08h
	db 05h,06h,07h,08h,05h,06h,07h,08h,05h,06h,07h,08h,05h,06h,07h,08h
	db 09h,0Ah,09h,0Ah,09h,0Ah,0Bh,0Bh,0Bh,0Bh,0Ch,0Ch,0Dh,0Dh,0Ch,0Dh
	db 0Ch,0Dh,0Ch,0Bh,0Bh,0Bh,00h,00h,01h,02h,03h,04h,01h,02h,05h,06h
	db 07h,08h,05h,06h,07h,08h,09h,0Ah,0Bh,0Bh,0Bh,00h,00h,0Eh,0Eh,0Eh
	db 0Fh,10h,10h,10h,11h,11h,11h,10h,10h,10h,11h,11h,11h,10h,10h,10h
	db 0Fh,0Eh,0Eh,00h,00h,0Bh,0Bh,0Bh

;====---- monster animation sequence ----====
PUBLIC D_33F8
D_33F8	db 01h,00h,01h,02h,03h,04h,03h,02h,01h,00h,01h,02h,03h,04h,05h,06h
	db 05h,06h,05h,06h,04h,07h,08h,09h,0Ah,09h,08h,07h,08h,09h,0Ah,0Bh
	db 0Ch,0Bh,0Ch,0Dh,0Bh,0Ch,0Dh,01h,0Dh,01h,0Eh,01h,0Fh,01h,0Eh,01h
	db 0Fh,0Ah,09h,08h,10h,11h,10h,11h,10h,11h,09h,08h,07h,04h,03h,02h

;====---- monsters anim src_y ----====
PUBLIC D_3438
D_3438	db 00h,20h,40h,60h,80h,0A0h
	db 00h,20h,40h,60h,80h,0A0h
	db 00h,20h,40h,60h,80h,0A0h

;====---- monster #1 anim src_x ----====
PUBLIC D_344A
D_344A	db 00h,00h,00h,00h,00h,00h
	db 07h,07h,07h,07h,07h,07h
	db 0Eh,0Eh,0Eh,0Eh,0Eh,0Eh

;====---- monster #2 anim src_x ----====
PUBLIC D_345C
D_345C	db 22h,22h,22h,22h,22h,22h
	db 1Ch,1Ch,1Ch,1Ch,1Ch,1Ch
	db 16h,16h,16h,16h,16h,16h


;====---- handwriting data? ----====
PUBLIC D_346E
D_346E	db 054h,0BDh,055h,0BCh,057h,0BCh,059h,0BCh,05Bh,0BCh,05Ch,0BDh,05Ch,0BEh,05Bh,0BFh
	db 059h,0BFh,058h,0BEh,058h,0BDh,057h,0BBh,056h,0BAh,056h,0B9h,055h,0B8h,055h,0B7h
	db 054h,0B6h,054h,0B5h,053h,0B4h,053h,0B3h,052h,0B2h,052h,0B1h,051h,0B0h,04Fh,0B0h
	db 04Eh,0B0h,04Dh,0B1h,04Dh,0B2h,04Eh,0B3h,050h,0B3h,051h,0B2h,054h,0B2h,055h,0B1h
	db 056h,0B1h,057h,0B0h,059h,0B0h,05Bh,0B0h,05Dh,0B0h,05Fh,0B0h,061h,0B0h,063h,0B0h
	db 065h,0B0h,067h,0B0h,069h,0B0h,06Bh,0B0h,06Dh,0B0h,06Fh,0B0h,071h,0B0h,073h,0B0h
	db 075h,0B0h,077h,0B0h,079h,0B0h,07Bh,0B0h,07Dh,0B0h,07Fh,0B0h,081h,0B0h,083h,0B0h
	db 085h,0B0h,087h,0B0h,089h,0B0h,08Bh,0B0h,08Dh,0B0h,08Fh,0B0h,091h,0B0h,093h,0B0h
	db 095h,0B0h,097h,0B0h,099h,0B0h,09Bh,0B0h,09Dh,0B0h,09Fh,0B0h,0A1h,0B0h,0A3h,0B0h
	db 0A5h,0B0h,0A7h,0B0h,0A9h,0B0h,0ABh,0B0h,0ADh,0B0h,0AFh,0B0h,0B1h,0B0h,0B3h,0B0h
	db 0B5h,0B0h,0B7h,0B0h,0B9h,0B0h,0BBh,0B0h,0BDh,0B0h,0BFh,0B0h,0C1h,0B0h,0C3h,0B0h
	db 0C5h,0B0h,0C7h,0B0h,0C9h,0B0h,0CAh,0B0h,0CBh,0B1h,0CCh,0B1h,0CDh,0B2h,05Eh,0B8h
	db 05Eh,0B7h,05Dh,0B6h,05Dh,0B5h,05Ch,0B4h,05Ch,0B3h,05Dh,0B2h,05Fh,0B2h,060h,0B2h
	db 061h,0B3h,061h,0B4h,062h,0B5h,062h,0B6h,063h,0B7h,063h,0B8h,062h,0B9h,060h,0B9h
	db 05Fh,0B9h,069h,0B9h,06Ah,0B8h,06Ah,0B7h,069h,0B6h,069h,0B5h,068h,0B4h,068h,0B3h
	db 067h,0B2h,06Bh,0B8h,06Ch,0B9h,06Eh,0B9h,077h,0B9h,075h,0B9h,074h,0B9h,073h,0B8h
	db 073h,0B7h,072h,0B6h,072h,0B5h,071h,0B4h,071h,0B3h,072h,0B2h,074h,0B2h,075h,0B3h
	db 076h,0B4h,077h,0B5h,077h,0B6h,078h,0B7h,078h,0B8h,079h,0B9h,079h,0BAh,07Ah,0BBh
	db 07Ah,0BCh,07Bh,0BDh,07Bh,0BEh,076h,0B3h,077h,0B2h,08Bh,0BEh,08Bh,0BDh,08Ah,0BCh
	db 08Ah,0BBh,089h,0BAh,089h,0B9h,088h,0B8h,088h,0B7h,087h,0B6h,087h,0B5h,086h,0B4h
	db 086h,0B3h,085h,0B2h,08Ch,0BFh,08Eh,0BFh,08Fh,0BFh,090h,0BEh,090h,0BDh,08Fh,0BCh
	db 08Fh,0BBh,08Eh,0BAh,08Eh,0B9h,08Ch,0B9h,08Fh,0B8h,08Fh,0B7h,08Eh,0B6h,08Eh,0B5h
	db 08Dh,0B4h,08Dh,0B3h,08Ch,0B2h,08Ah,0B2h,088h,0B2h,087h,0B3h,096h,0B9h,097h,0B8h
	db 097h,0B7h,096h,0B6h,096h,0B5h,095h,0B4h,095h,0B3h,094h,0B2h,098h,0B8h,099h,0B9h
	db 09Bh,0B9h,0A1h,0B9h,0A0h,0B8h,0A0h,0B7h,09Fh,0B6h,09Fh,0B5h,09Eh,0B4h,09Eh,0B3h
	db 09Dh,0B2h,0A2h,0BCh,0A2h,0BBh,0A9h,0BCh,0A9h,0BBh,0A8h,0BAh,0A8h,0B9h,0A7h,0B8h
	db 0A7h,0B7h,0A6h,0B6h,0A6h,0B5h,0A5h,0B4h,0A5h,0B3h,0A6h,0B2h,0A8h,0B2h,0A9h,0B2h
	db 0AAh,0B3h,0A5h,0B9h,0A6h,0B9h,0AAh,0B9h,0B2h,0B9h,0B1h,0B8h,0B1h,0B7h,0B0h,0B6h
	db 0B0h,0B5h,0AFh,0B4h,0AFh,0B3h,0AEh,0B2h,0B3h,0BCh,0B3h,0BBh,0BBh,0B8h,0BAh,0B9h
	db 0B8h,0B9h,0B7h,0B9h,0B6h,0B8h,0B6h,0B7h,0B7h,0B6h,0B8h,0B5h,0B9h,0B4h,0B9h,0B3h
	db 0B8h,0B2h,0B6h,0B2h,0B5h,0B2h,0B4h,0B3h,0C5h,0BEh,0C5h,0BDh,0C4h,0BCh,0C4h,0BBh
	db 0C3h,0BAh,0C3h,0B9h,0C2h,0B8h,0C2h,0B7h,0C1h,0B6h,0C1h,0B5h,0C0h,0B4h,0C0h,0B3h
	db 0BFh,0B2h,0C5h,0B9h,0C6h,0B9h,0C7h,0B8h,0C7h,0B7h,0C6h,0B6h,0C6h,0B5h,0C5h,0B4h
	db 0C5h,0B3h,0C6h,0B2h
	db 0

;====---- tile map data? ----====
PUBLIC D_3683
D_3683	db 06h,06h,06h,04h,04h,04h,01h,01h,00h,00h,00h,00h,01h,04h,04h,0Dh,0Eh,0Fh,04h
	db 06h,06h,04h,04h,04h,01h,01h,01h,01h,00h,00h,01h,01h,04h,04h,04h,04h,04h,04h
	db 06h,04h,04h,01h,01h,01h,02h,02h,01h,01h,01h,01h,01h,01h,0Ah,04h,04h,04h,06h
	db 06h,04h,04h,01h,01h,02h,02h,01h,01h,09h,08h,01h,01h,01h,01h,04h,06h,06h,06h
	db 04h,04h,04h,04h,01h,01h,01h,01h,04h,04h,08h,08h,01h,01h,01h,01h,01h,06h,06h

PUBLIC D_36E2
D_36E2	db 88h,20h,11h,80h,20h,31h,80h,20h,51h,80h,20h,71h,88h,27h
	db 11h,84h,27h,10h,84h,17h,10h,84h,07h,10h,84h,77h,88h,20h,51h,80h
	db 20h,31h,80h,20h,11h,80h,70h,88h,01h,66h,84h,11h,66h,84h,07h,10h
	db 84h,17h,10h,82h,11h,46h,82h,17h,0Fh,82h,11h,47h,82h,17h,0Eh,82h
	db 11h,48h,27h,0Eh,84h,11h,49h,77h,84h,11h,4Ah,88h,27h,0Eh,84h,17h
	db 0Eh,84h,17h,0Dh,84h,28h,0Eh,84h,18h,0Eh,84h,11h,2Ah,80h,1Ch,0Bh
	db 80h,1Ch,0Ch,80h,7Ch,1Dh,0Dh,81h,7Dh,84h,1Eh,0Dh,80h,1Eh,0Ch,80h
	db 1Eh,0Bh,80h,1Eh,0Ah,81h,7Eh,84h,11h,4Ah,84h,11h,4Bh,07h,0Dh,84h
	db 11h,4Ch,07h,0Eh,84h,15h,0Ch,84h,15h,0Dh,84h,05h,0Dh,16h,0Ch,84h
	db 16h,0Dh,84h,0Dh,0Eh,81h,7Dh,84h,1Dh,0Eh,81h,7Dh,84h,0Dh,0Dh,81h
	db 7Dh,84h,1Ch,0Dh,81h,7Ch,84h,0Dh,0Eh,81h,7Dh,84h,1Dh,0Eh,81h,7Dh
	db 84h,0Dh,0Dh,81h,7Dh,75h,03h,0Dh,84h,1Dh,0Dh,81h,7Dh,84h,1Ch,0Eh
	db 81h,7Ch,84h,1Dh,0Dh,81h,7Dh,76h,14h,0Dh,88h,18h,0Dh,84h,18h,0Ch
	db 17h,0Eh,84h,78h,17h,0Dh,84h,17h,0Ch,84h,77h,88h,71h,12h,4Ch,84h
	db 12h,6Ch,84h,12h,0Ch,84h,4Bh,00h,73h,82h,3Bh,01h,82h,2Bh,02h,12h
	db 0Bh,82h,2Bh,03h,82h,12h,0Ah,1Bh,04h,74h,82h,1Bh,05h,82h,1Bh,06h
	db 12h,6Ah,82h,1Bh,07h,82h,1Ch,09h,80h,1Ch,08h,80h,7Ch,1Dh,07h,81h
	db 7Dh,88h,1Bh,08h,82h,1Ch,09h,80h,7Ch,1Dh,08h,81h,7Dh,7Bh,84h,3Ah
	db 09h,84h,4Ah,09h,84h,4Ah,08h,12h,0Ah,84h,12h,09h,84h,12h,08h,84h
	db 2Ch,08h,80h,3Ch,08h,80h,7Ch,4Dh,08h,81h,7Dh,7Ah,88h,12h,68h,84h
	db 22h,68h,84h,32h,68h,84h,32h,08h,84h,32h,07h,84h,32h,67h,84h,42h
	db 67h,88h,47h,07h,84h,47h,08h,84h,47h,09h,48h,07h,84h,37h,09h,48h
	db 08h,84h,77h,48h,09h,84h,38h,09h,84h,78h,88h,37h,09h,84h,47h,09h
	db 84h,47h,08h,38h,09h,84h,47h,07h,48h,09h,84h,77h,48h,08h,84h,48h
	db 07h,84h,78h,88h,42h,07h,84h,42h,06h,84h,42h,05h,84h,42h,04h,84h
	db 42h,24h,84h,32h,24h,84h,32h,04h,84h,32h,03h,88h,37h,03h,84h,37h
	db 02h,84h,37h,01h,38h,03h,84h,47h,01h,38h,02h,82h,09h,09h,82h,47h
	db 00h,48h,02h,19h,08h,82h,29h,07h,82h,47h,01h,39h,06h,82h,3Eh,05h
	db 80h,3Eh,04h,80h,3Eh,03h,81h,7Eh,72h,82h,39h,05h,82h,39h,04h,48h
	db 03h,37h,01h,82h,39h,03h,82h,3Eh,03h,37h,02h,81h,7Eh,83h,4Dh,03h
	db 81h,7Dh,78h,44h,03h,84h,3Dh,03h,81h,7Dh,82h,3Dh,02h,81h,7Dh,82h
	db 3Dh,03h,81h,7Dh,79h,88h,47h,02h,84h,47h,03h,74h,88h,20h,01h,80h
	db 20h,21h,80h,20h,41h,80h,20h,61h,85h,47h,02h,84h,37h,02h,84h,27h
	db 02h,84h,27h,01h,84h,77h,88h,20h,61h,80h,20h,41h,80h,20h,21h,80h
	db 20h,01h,80h,70h,88h
	db 0FFh


CONST	ENDS
END
