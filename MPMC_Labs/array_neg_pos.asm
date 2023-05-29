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
    arraymsg db "Array contents are 1, 2, -7, 11, -10, 4, 8, 2, 5",10
    arraymsgstr equ $-arraymsg
    str1 db "Array is: ",10
    str1len equ $-str1
    pos_msg db "Positive count:"
    pos_len equ $-pos_msg
    neg_msg db "Negative count:"
    neg_len equ $-neg_msg
    nl db '', 10
    nllen equ $-nl

    array dw 1, 2, -7, 11, -10, 4, 8, 2, 5
    arrcnt equ 9
    poscnt dw 0
    negcnt dw 0

section .bss
        dis_buffer resb 2
    
section .text
    global _start

_start:
    write arraymsg,arraymsgstr
    mov esi, array
    mov ecx, arrcnt
    UP: 
        BT word[esi], 15
    JC NEG
    inc byte[poscnt]
    JMP POS

    NEG: inc byte[negcnt]
    POS:
        inc esi
        inc esi
        loop UP
    
    write pos_msg, pos_len
    mov bl, [poscnt]
    CALL HEX_ASCII

    write nl, nllen

    write neg_msg, neg_len
    mov bl, [negcnt]
    CALL HEX_ASCII

    write nl, nllen

mov eax, 1
xor ebx,ebx
int 0x80

HEX_ASCII:
    mov ecx, 2
    mov edi, dis_buffer
    DUP: 
        rol bl, 04
        mov al, bl
        and al, 0fh
        cmp al, 09h
        jbe NEXT
        add al, 07h

    NEXT:
        add al, 30h
        mov [edi], al
        inc edi
        loop DUP

        write dis_buffer, 2
    ret



        
