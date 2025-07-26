    .globl add_numbers
add_numbers:
    movl 4(%esp), %eax    # Load first argument (a) into eax
    addl 8(%esp), %eax    # Add second argument (b) to eax
    ret
 
