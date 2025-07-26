    .globl add_numbers
add_numbers:
    movl %edi, %eax
    addl %esi, %eax
    ret
    