%macro write 2
    mov eax, 4
    mov ebx, 1
    mov ecx, %1
    mov edx, %2
    int 0x80
%endmacro

%macro read 2
    mov eax, 3
    mov ebx, 2
    mov ecx, %1 
    mov edx, %2
    int 0x80
%endmacro

section .data
    str1 db "Enter first number: "
    str1len equ $-str1

    str2 db "Enter second number: "
    str2len equ $-str2

    show db "The difference: "
    showlen equ $-show

    nl db '', 10
    nllen equ $-nl
    
section .bss
    num1 resb 4
    num2 resb 4
    diff resb 4

section .text
    global _start

_start:
    write str1, str1len
    read num1, 4
    write str2, str2len
    read num2, 4

    mov esi, 2
    mov ecx, 3
    clc

    sub_loop:

    mov al, [num1 + esi]
    sbb al, [num2 + esi]
    aas 			; ascii adjust after subtraction
    pushf
    or al, 30h
    popf

    mov [diff + esi], al
    
    dec esi
    loop sub_loop

    write show, showlen
    write diff, 4

    write nl, nllen

mov eax, 1
xor ebx,ebx
int 0x80
