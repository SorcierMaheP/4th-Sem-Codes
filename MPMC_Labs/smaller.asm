section .data
	input db 'Enter number:'
	ilen equ $-input
	
	output db 'Smallest number is:'
	olen equ $-output
	
section .bss
	num1 resb 4
	num2 resb 4
	small resb 4

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
	mov ecx,num1
	mov edx,4
	int 0x80
	
	;Input number 2
	mov eax,4
	mov ebx,1
	mov ecx,input
	mov edx,ilen
	int 0x80
	
	mov eax,3
	mov ebx,2
	mov ecx,num2
	mov edx,4
	int 0x80
	
	;Print output
	mov eax,4
	mov ebx,1
	mov ecx,output
	mov edx,olen
	int 0x80
	
	;Find smaller number
	mov eax,[num1]
	mov ebx,[num2]
	CMP eax,ebx
	
	JG L1
	JMP L2
	
	L1:
	mov [small],ebx
	JMP Print
	
	L2:
	mov [small],eax
	JMP Print
	
	;Print smaller number
	Print:
	mov eax,4
	mov ebx,1
	mov ecx,small
	mov edx,4
	int 0x80

mov eax,1
xor ebx,ebx
int 0x80
