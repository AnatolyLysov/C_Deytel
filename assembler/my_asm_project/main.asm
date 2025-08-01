section .datab
    hello db 'Hello, World!', 0 ; Null-terminated string

section .text
    global _start

_start:
    ; Write the string to stdout
    mov rax, 1          ; syscall: sys_write
    mov rdi, 1          ; file descriptor: stdout
    mov rsi, hello      ; pointer to the string
    mov rdx, 13         ; length of the string
    syscall             ; invoke operating system to do the write

    ; Exit the program
    mov rax, 60         ; syscall: sys_exit
    xor rdi, rdi        ; exit code 0
    syscall             ; invoke operating system to exit


; file nasm_how_to_compile_for_debug
