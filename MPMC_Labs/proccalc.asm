section .data

	str1 db "Enter the numbers: "
	str1len equ $-str1

	sumstr db "Sum is: "
	sumlen equ $-sumstr

	diffstr db "Diff is: "
	difflen equ $-diffstr

	prodstr db "Prod is: "
	prodlen equ $-prodstr

	quostr db "Quotient is: "
	quolen equ $-quostr

	remstr db "Remainder is: "
	remlen equ $-remstr

	nl db "", 10
	nllen equ $-nl

section .bss
	num1 resb 4
	num2 resb 4
	prod resb 4
	quo resb 4
	rem resb 4
	sum resb 4
	diff resb 4

section .text
	global _start
_start:
	mov eax,4
    mov ebx,1
    mov ecx,str1
    mov edx,str1len
    int 0x80

    mov eax,3
    mov ebx,2
    mov ecx,num1
    mov edx,4
    int 0x80

    mov eax,3
    mov ebx,2
    mov ecx,num2
    mov edx,4
    int 0x80

	call SUM
	mov eax,4
    mov ebx,1
    mov ecx,sumstr
    mov edx,sumlen
    int 0x80
    
    mov eax,4
    mov ebx,1
    mov ecx,sum
    mov edx,4
    int 0x80
    call NEWLINE

	call DIFF
	mov eax,4
    mov ebx,1
    mov ecx,diffstr
    mov edx,difflen
    int 0x80
    
    mov eax,4
    mov ebx,1
    mov ecx,diff
    mov edx,4
    int 0x80
    call NEWLINE

	call PROD
	mov eax,4
    mov ebx,1
    mov ecx,prodstr
    mov edx,prodlen
    int 0x80
    
    mov eax,4
    mov ebx,1
    mov ecx,prod
    mov edx,4
    int 0x80
    call NEWLINE

	call DIV
	mov eax,4
    mov ebx,1
    mov ecx,quostr
    mov edx,quolen
    int 0x80
    
    mov eax,4
    mov ebx,1
    mov ecx,quo
    mov edx,4
    int 0x80
    call NEWLINE

    mov eax,4
    mov ebx,1
    mov ecx,remstr
    mov edx,remlen
    int 0x80
    
    mov eax,4
    mov ebx,1
    mov ecx,rem
    mov edx,4
    int 0x80
    call NEWLINE

mov eax,1
xor ebx,ebx
int 0x80

    SUM:
        mov eax, [num1]
        sub eax, '0'
        mov ebx, [num2]
        sub ebx, '0'
        add eax, ebx
        add eax, '0'
        mov [sum], eax
        ret
    
    DIFF:
        mov eax, [num1]
        sub eax, '0'
        mov ebx, [num2]
        sub ebx, '0'
        sub eax, ebx
        add eax, '0'
        mov [diff], eax
        ret
    
    PROD:
        mov al, [num1]
        sub al, '0'
        mov bl, [num2]
        sub bl, '0'
        mul bl
        add al, '0'
        mov [prod], al
        ret

    DIV:
        mov al, [num1]
        sub al, '0'
        mov bl, [num2]
        sub bl, '0'
        div bl
        add al, '0'
        mov [quo], al
        add ah, '0'
        mov [rem], ah
        ret
    
    NEWLINE:
        mov eax,4
        mov ebx,1
        mov ecx,nl
        mov edx,nllen
        int 0x80
        ret
