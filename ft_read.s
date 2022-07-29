section .text
    global _ft_read
extern  ___error
_ft_read:
    mov rax, 0x02000003
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