
.stack 0x100

.model small

.data

    ask db 'Nhap vao mot chu so hex: $'

    reply db 10, 13, 'Dang thap phan cua no la: $'

    number db 0

.code

    main proc
        call Initialize
        ;call InputHexChar
        mov number, 23
        call OutDecimal
        call Pause
        call Finalize
    main endp

    OutDecimal proc
        push AX
        push BX
        push CX
        push DX
        mov BL, 10
        mov BX, 10
        PrintDigit:
        cmp number, 0
        je Return
        mov AH, 0
        mov AL, number
        div BX
        mov number, AL
        mov AH, 2
        mov DL, AL
        add DL, '0'
        int 0x21
        jmp PrintDigit
        Return:
        pop DX
        pop CX
        pop BX
        pop AX
        ret
    OutDecimal endp

    InputHexChar proc
        push AX
        push DX
        mov AH, 9
        lea DX, ask
        int 0x21
        mov AH, 1
        ReInput:
        int 0x21
        cmp AL, 'a'
        jb ReInput
        cmp AL, 'f'
        ja ReInput
        sub AL, 'a'-10
        mov number, AL
        pop DX
        pop AX
        ret
    InputHexChar endp

    Initialize proc
        mov AX, @data
        mov DS, AX
        ret
    Initialize endp

    Pause proc
        push AX
        mov AH, 1
        int 0x21
        pop AX
        ret
    Pause endp

    Finalize proc
        mov AH, 0x4C
        int 0x21
        ret
    Finalize endp

    end main
