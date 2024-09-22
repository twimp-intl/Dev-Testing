section .data
    message db 'Secret message executed!', 0
    message_len equ $ - message

section .text
    global _start

; Entry point
_start:
    ; Prepare for self-modification: Make the .text section writable
    ; Syscall: mprotect (SYS_mprotect = 10)
    mov rax, 10            ; syscall: mprotect
    lea rdi, [rel _start]   ; addr: start of text section
    mov rsi, 4096          ; size: 4096 bytes (page size)
    mov rdx, 7             ; prot: PROT_READ | PROT_WRITE | PROT_EXEC
    syscall

    ; Call the obfuscate code (modifies part of the program)
    call obfuscate

    ; De-obfuscate and execute secret function
    call deobfuscate
    call secret_function

    ; Exit the program
    mov rax, 60            ; syscall: exit
    xor rdi, rdi           ; status: 0
    syscall

; Secret function to be obfuscated/deobfuscated
secret_function:
    mov rax, 1             ; syscall: write
    mov rdi, 1             ; file descriptor: stdout
    lea rsi, [rel message] ; pointer to message
    mov rdx, message_len   ; length of message
    syscall
    ret

; Simple XOR-based obfuscation of secret_function
obfuscate:
    mov rsi, secret_function
    mov rcx, secret_function_end - secret_function

xor_loop_obfuscate:
    xor byte [rsi], 0xAA   ; XOR with a fixed key (0xAA)
    inc rsi
    loop xor_loop_obfuscate
    ret

deobfuscate:
    mov rsi, secret_function
    mov rcx, secret_function_end - secret_function

xor_loop_deobfuscate:
    xor byte [rsi], 0xAA   ; Reapply XOR to deobfuscate (same key)
    inc rsi
    loop xor_loop_deobfuscate
    ret

; Mark the end of the function for obfuscation range
secret_function_end:
