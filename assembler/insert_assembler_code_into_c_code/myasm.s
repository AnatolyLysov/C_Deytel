.global add_numbers
add_numbers:
    movl 4(%esp), %eax
    addl 8(%esp), %eax
    ret
.section .note.GNU-stack,"",@progbits
    