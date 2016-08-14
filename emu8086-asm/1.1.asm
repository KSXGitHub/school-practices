
.stack 0x100

.model small

.data

    ask db 'Nhap mot ki tu so trong khoang 0-8: $'
    reply db 10, 13, 'Ki tu so dung sau no la: '
    char db ?
    endl db 10, 13, 0x24

.code

    main proc

        ; init
        mov AX, @data
        mov DS, AX

        ; stdout.write(ask)
        jmp BeginAsk
        ReAsk:
        mov AH, 9
        lea DX, endl
        int 0x21
        BeginAsk:
        mov AH, 9
        lea DX, ask
        int 0x21

        ; char = getch() + 1
        mov AH, 1
        BeginInput:
        int 0x21
        cmp AL, '0'
        jb ReAsk
        cmp AL, '8'
        ja ReAsk
        inc AL
        mov char, AL

        ; stdout.write(reply)
        mov AH, 9
        lea DX, reply
        int 0x21

        ; getch()
        mov AH, 1
        int 0x21

        ; exit
        mov AH, 0x4C
        int 0x21

    main endp

    end main
