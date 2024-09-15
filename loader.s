section .data
    file_mode db "rb", 0
    filename db "code.bin", 0
    fopen_err db "fopen failed", 0
    mmap_err db "mmap failed", 0

section .bss
    file_ptr resd 1    ; Use 32-bit (4-byte) reserved space
    file_size resd 1   ; Use 32-bit (4-byte) reserved space
    mem_ptr resd 1     ; Use 32-bit (4-byte) reserved space

section .text
    global _start

_start:
    ; Open the file
    mov eax, 5         ; sys_open (system call number)
    lea ebx, [filename] ; Filename to open
    mov ecx, 0         ; Read mode
    int 0x80           ; Call kernel
    mov [file_ptr], eax ; Save file descriptor

    ; Check if open failed
    cmp eax, -1        ; Check if file descriptor is -1 (error)
    je fopen_fail      ; Jump if error

    ; File operations
    mov eax, 19        ; sys_lseek (system call number)
    xor edx, edx       ; Offset (0)
    xor esi, esi       ; Whence (SEEK_SET)
    mov ebx, [file_ptr] ; File descriptor
    int 0x80           ; Call kernel

    mov eax, 30        ; sys_fstat (system call number)
    mov ebx, [file_ptr] ; File descriptor
    lea ecx, [file_size] ; Pointer to struct stat
    int 0x80           ; Call kernel

    ; Allocate memory
    mov eax, 9         ; sys_mmap (system call number)
    xor ebx, ebx       ; Address (NULL)
    mov edx, [file_size] ; Length
    mov esi, 3         ; PROT_READ | PROT_WRITE
    mov edi, 0x22      ; MAP_PRIVATE | MAP_ANONYMOUS
    int 0x80           ; Call kernel
    mov [mem_ptr], eax ; Save memory address

    ; Check if memory allocation failed
    cmp eax, -1        ; Check if mmap failed
    je mmap_fail       ; Jump if error

    ; Read shellcode from file
    mov eax, 3         ; sys_read (system call number)
    mov ebx, [file_ptr] ; File descriptor
    lea ecx, [mem_ptr] ; Buffer
    mov edx, [file_size] ; Number of bytes to read
    int 0x80           ; Call kernel

    ; Execute shellcode
    mov eax, [mem_ptr] ; Load address of shellcode
    jmp eax            ; Jump to shellcode

    ; Clean up and exit
    mov eax, 11        ; sys_munmap (system call number)
    mov ebx, [mem_ptr] ; Address
    mov ecx, [file_size] ; Length
    int 0x80           ; Call kernel

    ; Exit the program
    mov eax, 1         ; sys_exit (system call number)
    xor ebx, ebx       ; Exit code: 0
    int 0x80           ; Call kernel

fopen_fail:
    ; Print error message
    mov eax, 4         ; sys_write (system call number)
    mov ebx, 1         ; File descriptor: stdout
    lea ecx, [fopen_err] ; Message
    mov edx, 15        ; Message length
    int 0x80           ; Call kernel
    jmp $

mmap_fail:
    ; Print error message
    mov eax, 4         ; sys_write (system call number)
    mov ebx, 1         ; File descriptor: stdout
    lea ecx, [mmap_err] ; Message
    mov edx, 13        ; Message length
    int 0x80           ; Call kernel
    jmp $
