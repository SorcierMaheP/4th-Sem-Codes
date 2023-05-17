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

%macro newline 0
	mov eax, 4
	mov ebx, 1
	mov ecx, nl
	mov edx, nllen
	int 0x80
%endmacro

%macro SUM 3
	mov al, [%1]
	sub al, '0'
	mov bl, [%2]
	sub bl, '0'
	add al, bl
	add al, '0'
	mov [%3], al
	int 0x80
%endmacro

%macro DIFF 3
	mov eax, [%1]
	sub eax, '0'
	mov ebx, [%2]
	sub ebx, '0'
	sub eax, ebx
	add eax, '0'
	mov [%3], eax
%endmacro

%macro PROD 3
	mov al, [%1]
	sub al, '0'
	mov bl, [%2]
	sub bl, '0'
	mul bl
	add al, '0'
	mov [%3], al
%endmacro

%macro DIV 4
	mov al, [%1]
	sub al, '0'
	mov bl, [%2]
	sub bl, '0'
	div bl
	add al, '0'
	mov [%3], al
	add ah, '0'
	mov [%4], ah
%endmacro

section .data

	str1 db "Enter the numbers: "
	str1len equ $-str1

	read num1, num2

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
	write str1, str1len
	read num1, 4
	read num2, 4

	SUM num1, num2, sum
	write sumstr, sumlen
	write sum, 4
	newline

	DIFF num1, num2, diff
	write diffstr, difflen
	write diff, 4
	newline

	PROD num1, num2, prod
	write prodstr, prodlen
	write prod, 4
	newline

	DIV num1, num2, quo, rem
	write quostr, quolen
	write quo, 4
	newline
	write remstr, remlen
	write rem, 4
	newline

mov eax,1
xor ebx,ebx
int 0x80