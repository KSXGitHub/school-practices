
.model small

.stack 0x100

.data

	ask db 10, 13, 'Nhap mot so nguyen (0 - 255): $'

    reply db 10, 13, 'Cac so ket thuc voi 5 hoac 7:$'

    limit dw ? ; Gioi han dem

	number dw ? ; Luu so nguyen vao day

	count db ? ; (Dung trong OutDec) Dem so chu so cua number

.code

	main proc

		mov AX, @data
		mov DS, AX

		call InDec
        mov AX, number
        mov limit, AX
        call OutSf57

		mov AH, 1
		int 0x21

		mov AH, 0x4C
		int 0x21

	main endp

    OutSf57 proc

        mov AH, 9
        lea DX, reply
        int 21h

        mov CX, 0
        mov BX, 10

        beginlist:

        mov AX, CX
        div BL

        cmp AH, 5
        je print57
        cmp AH, 7
        je print57
        jmp chkendlist

        print57:
        mov number, CX
        mov AH, 2
        mov DL, ' '
        int 0x21
        call OutDec

        chkendlist:
        cmp CX, limit
        je endlist
        inc CX
        jmp beginlist

        endlist:

        ret

    OutSf57 endp

	InDec proc

		push AX
		push BX
		push CX
		push DX

		reask:

		; Thong bao nhap
		mov AH, 9
		lea DX, ask
		int 0x21

		; Khoi tao
		mov number, 0
		mov BL, 10

		beginloop:

		; Nhap ki tu
		mov AH, 1
		int 0x21

		mov CH, 0 ; chu so vua nhap duoc luu vao CX

		; Neu nhan Enter, thoat vong lap
		cmp AL, 10
		je endloop
		cmp AL, 13
		je endloop

		; Neu nhap sai, nhap lai
		cmp AL, '0'
		jb reask
		cmp AL, '9'
		ja reask

		; number = 10 * number + CX
		mov CL, AL
		sub CL, '0'
		mov AX, number
		mul BL
		add AX, CX
		mov number, AX

		jmp beginloop

		endloop:

		pop DX
		pop CX
		pop BX
		pop AX
		ret

	InDec endp

	OutDec proc

		push AX
		push BX
		push CX
		push DX

		; Khoi tao cac bien
		mov BL, 10
		mov CX, number
		mov count, 0

		; Vong lap: Them cac chu so vao stack
		beginaddstack:
		cmp CX, 0
		je endaddstack
		inc count
		mov AX, CX
		div BL
		mov CX, AX
		mov CH, 0
		push AX
		jmp beginaddstack
		endaddstack:

		mov AH, 2

		; Vong lap: Hien thi cac chu so trong stack (theo thu tu nguoc lai)
		begindisplay:
		cmp count, 0
		je enddisplay
		dec count
		pop CX
		mov DL, CH
		add DL, '0'
		int 0x21
		jmp begindisplay
		enddisplay:

		pop DX
		pop CX
		pop BX
		pop AX
		ret

	OutDec endp
