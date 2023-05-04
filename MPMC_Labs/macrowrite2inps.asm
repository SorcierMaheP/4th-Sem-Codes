section .data
    string1 db 'Hello There',10
    string1len equ $-string1
    string2 db 'General Kenobi',10
    string2len equ $-string2
	output1 db 'String 1 is:',10
	output1len equ $-output1
	output2 db 'String 2 is:',10
	output2len equ $-output2
	newline db '',10
	newlinelen equ $-newline

section .text
	global _start
	
	%macro write 2
		mov eax, 4
		mov ebx, 1
		mov ecx, %1
		mov edx, %2
		int 0x80
	%endmacro

_start:
	write output1,output1len
	write string1,string1len
	write newline,newlinelen

	write output2,output2len
	write string2,string2len
	write newline,newlinelen

mov eax,1
xor ebx,ebx
int 0x80