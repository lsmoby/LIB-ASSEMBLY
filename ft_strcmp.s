section .text
    global _ft_strcmp

_ft_strcmp:
    mov rcx, 0
    loop:
        mov dl, byte rdi[rcx]
        mov bl, byte rsi[rcx]
        cmp dl, 0
        je  less
        cmp bl, 0
        je  great
        cmp bl, dl
        jne notequal
        inc rcx
        jmp loop
    less:
        mov rax, -1
        cmp bl, 0
        je equal
        ret
    equal:
        mov rax, 0
        ret
    notequal:
        mov rax, 0
        cmp dl, bl
        jg  great
        mov rax, -1
        ret
    great:
        mov rax, 1
        ret