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

section .data 
	str1 db "Enter your name: "
	len1 equ $-str1
	nl db "",10
	nllen equ $-nl
	spa db " "
	spalen equ $-spa

section .bss
	name resw 15
	count resb 4

section .text
	global _start
_start:
	write str1,len1
	read name,15

	mov byte[count],'1'

	L1:
		write count,4
		write spa,spalen
		write name,15

		inc byte[count]
		cmp byte[count],'9'
		JLE L1

mov eax,1
xor ebx,ebx
int 0x80