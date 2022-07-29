section .text
    global _ft_strcpy

_ft_strcpy:
    mov rcx, 0
    loop:
        cmp byte [rsi + rcx], 0
        je return
        mov al, rsi[rcx]
        mov rdi[rcx], al
        inc rcx
        jmp loop
    return:
        mov rdi[rcx], byte 0
        mov rax, rdi
        ret