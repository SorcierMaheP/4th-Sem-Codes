section .data
	string db 'The number is: ', 10
	stringlen equ $-string
	newline db '',10
	newlinelen equ $-newline
    num equ 4

section .bss
    buffer resb 1

section .text
	global _start
	
	%macro write 2
		mov eax, 4
		mov ebx, 1
		mov ecx, %1
        mov edx, %2
		int 0x80
	%endmacro

    %macro stringconv 1
        mov eax, %1
        mov ebx, 10
        mov edx, 0
        div ebx
        add edx, '0'
        mov byte [buffer], dl
        mov esi, buffer
    %endmacro

_start:
	write string,stringlen
    stringconv num
    write buffer,1
	write newline,newlinelen
	
mov eax,1
xor ebx,ebx
int 0x80