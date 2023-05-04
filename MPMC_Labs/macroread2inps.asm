section .data
	string1 db 'Enter string 1:',10
	string1len equ $-string1
	string2 db 'Enter string 2:',10
	string2len equ $-string2
	output1 db 'String 1 is:',10
	output1len equ $-output1
	output2 db 'String 2 is:',10
	output2len equ $-output2
	newline db '',10
	newlinelen equ $-newline
section .bss
	str1 resb 10
	str2 resb 10
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
	read str1,10
	write newline,newlinelen

	write string2,string1len
	read str2,10
	write newline,newlinelen

	write output1,output1len
	write str1,10
	write newline,newlinelen

	write output2,output2len
	write str2,10
	write newline,newlinelen

mov eax,1
xor ebx,ebx
int 0x80
	
