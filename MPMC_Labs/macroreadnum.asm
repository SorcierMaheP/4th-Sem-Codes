section .data
	string1 db 'Enter a number:',10
	string1len equ $-string1
	string2 db 'The number is: ', 10
	string2len equ $-string2
	newline db '',10
	newlinelen equ $-newline

section .bss
	num resb 4

section .text
	global _start
	
	%macro write 2
		mov eax, 4
		mov ebx, 1
		mov ecx, %1
		mov edx, %2
		int 0x80
	%endmacro

	%macro read 2
		mov eax,3
		mov ebx,2
		mov ecx,%1
		mov edx,%2
		int 0x80
	%endmacro

_start:
	write string1,string1len
	read num,4
	write newline,newlinelen

	write string2,string2len
	write num,4
	write newline,newlinelen
	
mov eax,1
xor ebx,ebx
int 0x80
	
