section .text
	global _ft_strdup
	extern _ft_strlen
	extern _malloc
	extern _ft_strcpy
	extern ___error
_ft_strdup:
	xor		rax, rax
	push	rdi
	call	_ft_strlen
	mov		rdi, rax
	inc		rdi
	call	_malloc
	cmp		rax, 0
	je		_error
	mov		rdi, rax
	pop		rsi
	call	_ft_strcpy
	ret
_error:
    call ___error
    mov [rax], byte 12
    mov rax, 0
    ret
