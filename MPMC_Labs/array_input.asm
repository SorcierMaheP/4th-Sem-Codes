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
    asksize db 'Enter size: '
    asksizelen equ $-asksize

    ask db 'Enter array: '
    asklen equ $-ask

    show db 'Array contents: '
    showlen equ $-show

    array times 20 dw 0
    len equ 20

    nl db '', 10
    nllen equ $-nl

    spa db ' '
    spalen equ $-spa

section .bss
    num resb 2
    i resb 2
    element resb 2

section .text
    global _start:
_start:
    write asksize, asksizelen
    read num, 2

    write ask, asklen
    write nl, nllen
    mov byte[i], 0

    mov esi, array

    input:
        read element, 2
        mov ebx, [element]
        mov [esi], ebx

        inc esi
        inc byte[i]

        mov al, [i]
        mov bl, [num]
        sub bl, '0'
        cmp al, bl
        JE exit_input
        JMP input

    exit_input:
        write show, showlen
        write nl, nllen
        mov byte[i], 0
        mov esi, array

    output:
        mov ebx, [esi]
        mov [element], ebx
        write element, 1
        write spa,spalen

        inc esi
        inc byte[i]

        mov al, [i]
        mov bl, [num]

        sub bl, '0'
        cmp al, bl
        JL output

    write nl,nllen
    
mov eax, 1
xor ebx,ebx
int 80h