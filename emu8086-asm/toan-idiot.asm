
.model small

.stack 100h

.data

    stdnum dw ?

.code

    main proc
        mov AX, @data
        mov DS, AX
        call InDec
        call NewLine
        call OutDec
        call Finalize
    main endp

    InDec proc

        push AX
        push BX
        push CX
        push DX

        mov stdnum, 0
        mov BL, 10
        mov CH, 0

        beginenterdigits:

        mov AH, 1
        int 21h

        cmp AL, 13
        je endenterdigits

        cmp AL, 10
        je endenterdigits

        sub AL, '0'
        mov CL, AL
        mov AX, stdnum
        mov DX, 0
        mul BX
        add AX, CX
        mov stdnum, AX

        jmp beginenterdigits

        endenterdigits:

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

        mov AX, stdnum
        mov CX, 0 ; number of digits
        mov BX, 10

        begingendigits:
        cmp AX, 0
        je endgendigits
        mov DX, 0
        div BX
        push DX
        inc CX
        jmp begingendigits
        endgendigits:

        mov AH, 2
        beginprintdigits:
        jcxz endprintdigits
        dec CX
        pop DX
        add DL, '0'
        int 21h
        jmp beginprintdigits
        endprintdigits:

        pop DX
        pop CX
        pop BX
        pop AX
        ret

    OutDec endp

    NewLine proc

        push AX
        push DX

        mov AH, 2

        mov DL, 13
        int 21h

        mov DL, 10
        int 21h

        pop DX
        pop AX
        ret

    NewLine endp

    Finalize proc

        mov AH, 1
        int 21h

        mov AH, 4Ch
        int 21h

    Finalize endp

    end main
