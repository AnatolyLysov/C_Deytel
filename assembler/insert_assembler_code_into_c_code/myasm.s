 .global add_numbers  # Make the function globally accessible
add_numbers:
    movl 4(%esp), %eax  # Load the first argument into EAX
    addl 8(%esp), %eax  # Add the second argument to EAX
    ret                 # Return, result is in EAX
    