section .text
    global _ft_strlen

_ft_strlen:
    XOR RAX, RAX
    FT:
        CMP BYTE [RDI], 0
        JE return
        INC RAX
        INC RDI
        JMP FT
return:
    RET
