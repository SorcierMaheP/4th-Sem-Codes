section .text
    input db 'Enter a number:'
    i_len equ $-input
    
    output db 'Number entered is:'
    o_len equ $-output

section .bss
    num resb 4

section .text
    global _start
    
_start:
    mov eax,4
    mov ebx,1
    mov ecx,input
    mov edx,i_len
    int 0x80
    
    ;Input number

    mov eax,3
    mov ebx,2
    mov ecx,num
    mov edx,4
    int 0x80
    
    mov eax,4
    mov ebx,1
    mov ecx,output
    mov edx,o_len
    int 0x80
    
    ;Output number
    
    mov eax,4
    mov ebx,1
    mov ecx,num
    mov edx,4
    int 0x80
    
mov eax,1
mov ebx,0
int 0x80