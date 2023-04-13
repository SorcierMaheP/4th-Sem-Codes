section .text
    input db 'Enter the name:'
    i_len equ $-input
    
    output db 'Name entered is:'
    o_len equ $-output

section .bss
    len resw 20

section .text
    global _start
    
_start:
    mov eax,4
    mov ebx,1
    mov ecx,input
    mov edx,i_len
    int 0x80
    
    ;Input name

    mov eax,3
    mov ebx,2
    mov ecx,len
    int 0x80
    
    mov eax,4
    mov ebx,1
    mov ecx,output
    mov edx,o_len
    int 0x80
    
    ;Output name
    mov eax,4
    mov ebx,1
    mov ecx,len
    int 0x80
    
mov eax,1
mov ebx,0
int 0x80