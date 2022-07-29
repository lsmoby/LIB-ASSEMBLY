section .text
    global _ft_write
extern  ___error
_ft_write:
    mov rax, 0x02000004
    syscall
    jc  _error
    ret
_error:
    push rax
    call ___error
    pop r8
    mov [rax], r8
    mov rax, -1
    ret