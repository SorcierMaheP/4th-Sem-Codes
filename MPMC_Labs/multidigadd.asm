%macro write 2
    mov eax, 4
    mov ebx, 1
    mov ecx, %1
    mov edx, %2
    int 80h
%endmacro

%macro read 1
    mov eax, 3
    mov ebx, 2
    mov ecx, %1 
    mov edx, 9
    int 80h
%endmacro

section .data
    str1 db "Enter a number: "
    str1len equ $-str1

    str2 db "The sum is: "
    str2len equ $-str2
    
section .bss
    num1 resb 4
    num2 resb 4
    sum resb 4

section .text
    global _start

_start:
    write str1, str1len

    read num1
    read num2 

    mov esi, 2
    mov ecx, 3
    clc

add:

    mov al, [num1 + esi]
    adc al, [num2 + esi]  
    aaa			;ascii adjust after addition
    pushf
    or al, 30h
    popf

    mov [sum + esi], al
    dec esi
    loop add

    write str2, str2len
    write sum, 4

mov eax, 1
mov ebx, 0
int 80h
