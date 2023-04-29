section .data
	input db 'Enter number:'
	ilen equ $-input
	
	less db 'Num less than 5',10
	lesslen equ $-less
	equal db 'Num equal to 5',10
	equallen equ $-equal
	more db 'Num more than 5',10
	morelen equ $-more
	output db 'Largest number is:'
	olen equ $-output
	
section .bss
	num resb 4
	text resw 20

section .text
	global _start:

_start:
	;Input number 1
	mov eax,4
	mov ebx,1
	mov ecx,input
	mov edx,ilen
	int 0x80
	
	mov eax,3
	mov ebx,2
	mov ecx,num
	mov edx,4
	int 0x80
	
	;Compare with 5
	mov al,[num]
	sub al,'0'
	mov bl,'5'
	sub bl,'0'
	CMP al,bl
	
	JE L1
	JG L2
	JMP L3
	
	L1:
		mov eax,4
		mov ebx,1
		mov ecx,equal
		mov edx,equallen
		int 0x80
		JMP L4
	L2:
		mov eax,4
		mov ebx,1
		mov ecx,more
		mov edx,morelen
		int 0x80
		JMP L4
	L3:
		mov eax,4
		mov ebx,1
		mov ecx,less
		mov edx,lesslen
		int 0x80
L4:
mov eax,1
xor ebx,ebx
int 0x80
