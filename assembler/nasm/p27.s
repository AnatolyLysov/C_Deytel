%include "stud_io.inc"
globl p27

section .text
p27: mov eax, 0
again: PRINT "Hello"
    PUTCHAR 10
    inc eax
    cmp eax, 5
    jl again
    FINISH
