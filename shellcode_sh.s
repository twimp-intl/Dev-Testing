section .data
    filename db '/bin/sh', 0      ; Null-terminated string "/bin/sh"

section .text
    global _start

_start:
    ; Set up the arguments for execve
    mov rdi, filename             ; Set rdi to point to "/bin/sh"
    xor rsi, rsi                 ; Zero out rsi (argv[])
    xor rdx, rdx                 ; Zero out rdx (envp[])
    mov rax, 59                  ; syscall number for execve (59)
    syscall                      ; Call the kernel

    ; Exit if execve fails
    xor rdi, rdi                 ; Zero out rdi (exit code 0)
    mov rax, 60                  ; syscall number for exit (60)
    syscall                      ; Call the kernel
