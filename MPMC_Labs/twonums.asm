section .data
    num1 equ 2
    num2 equ 7
    msg db "The numbers are: ", 0
    buffer times 2 db 0

section .text
    global _start

_start:
    mov eax, 4
    mov ebx, 1
    mov ecx, msg
    mov edx, 17
    int 0x80

    ; convert number1 to string
    mov eax, num1
    mov ebx, 10
    mov edx, 0
    div ebx
    add edx, '0'
    mov byte [buffer], dl
    mov byte [buffer+1], ' '
    mov esi, buffer

    mov ecx, esi
    sub ecx, buffer
    add ecx, 2

    ; print number1 string
    mov eax, 4
    mov ebx, 1
    mov edx, ecx
    mov ecx, buffer
    int 0x80

    ; convert number2 to string
    mov eax, num2
    mov ebx, 10
    mov edx, 0
    div ebx
    add edx, '0'
    mov byte [buffer], dl
    mov esi, buffer

    mov ecx, esi
    sub ecx, buffer
    add ecx, 2

    ; print number2 string
    mov eax, 4
    mov ebx, 1
    mov edx, ecx
    mov ecx, buffer
    int 0x80

mov eax, 1
mov ebx, 0
int 0x80