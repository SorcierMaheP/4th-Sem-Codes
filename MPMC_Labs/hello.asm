SECTION .data
	hello db 'HelloWorld',10
	hellolen equ $-hello
SECTION .text
	GLOBAL _start
_start:
	mov eax,4
	mov ebx,1
	mov ecx,hello
	mov edx,hellolen
	int 80h
mov eax,1
mov ebx,0
int 80h


