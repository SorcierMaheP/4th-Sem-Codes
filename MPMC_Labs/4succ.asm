section .data
    SYS_WRITE equ 4
    STDOUT equ 1
    SYS_READ equ 3
    STDIN equ 2
    SYS_EXIT equ 1
    RETURN_CODE_SUCCESS equ 0
    input db 'Enter a number:'
    input_len equ $-input

section .bss
    num resb 2

section .text
    global _start

_start:
    mov eax,SYS_WRITE
    mov ebx,STDOUT
    mov ecx,input
    mov edx,input_len
    int 0x80

    mov eax,SYS_READ
    mov ebx,STDIN
    mov ecx,num
    mov edx,2
    int 0x80

    inc byte [num]

    mov eax,SYS_WRITE
    mov ebx,STDOUT
    mov ecx,num
    mov edx,2
    int 0x80

    inc byte [num]

    mov eax,SYS_WRITE
    mov ebx,STDOUT
    mov ecx,num
    mov edx,2
    int 0x80

    inc byte [num]

    mov eax,SYS_WRITE
    mov ebx,STDOUT
    mov ecx,num
    mov edx,2
    int 0x80

    inc byte [num]

    mov eax,SYS_WRITE
    mov ebx,STDOUT
    mov ecx,num
    mov edx,2
    int 0x80

mov eax,SYS_EXIT
mov ebx,RETURN_CODE_SUCCESS
int 0x80

    