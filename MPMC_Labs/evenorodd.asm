section .data
	input db 'Enter number:'
	ilen equ $-input
	
	even db 'Number is even',10
	evenlen equ $-even
	
	odd db 'Number is odd',10
	oddlen equ $-odd
	
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
	mov bl,'2'
	sub bl,'0'
	div bl
	CMP al,bl
	
	JE L1
	JMP L2
	
	L1:
		mov eax,4
		mov ebx,1
		mov ecx,odd
		mov edx,oddlen
		int 0x80
		JMP L3
	L2:
		mov eax,4
		mov ebx,1
		mov ecx,even
		mov edx,evenlen
		int 0x80
L3:
mov eax,1
xor ebx,ebx
int 0x80
