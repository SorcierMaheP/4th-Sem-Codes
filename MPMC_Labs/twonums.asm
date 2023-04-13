section .data
    input db 'Enter number:'
    i_len equ $-input

    output db 'The two numbers are:'
    o_len equ $-output

section .bss
    num1 resb 4
    num2 resb 4

section .text
    global _start

_start:
    mov eax,4
    mov ebx,1
    mov ecx,input
    mov edx,i_len
    int 0x80
    
    ;Input number 1

    mov eax,3
    mov ebx,2
    mov ecx,num1
    int 0x80
    
    mov eax,4
    mov ebx,1
    mov ecx,input
    mov edx,i_len
    int 0x80
    
    ;Input number 2

    mov eax,3
    mov ebx,2
    mov ecx,num2
    int 0x80
    
    mov eax,4
    mov ebx,1
    mov ecx,output
    mov edx,o_len
    int 0x80

    ;Print the 2 numbers

    mov eax,4
    mov ebx,1
    mov ecx,num1
    mov edx,num2
    int 0x80
    
mov eax,1
mov ebx,0
int 0x80