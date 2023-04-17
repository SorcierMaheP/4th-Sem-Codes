section .data
	num db 'Enter a number',10
	nlen equ $-num
	result db 'The sum is:'
	rlen equ $-result
	SYS_WRITE equ 4
	SYS_READ equ 3
	STDOUT equ 1
	STDIN equ 2
	SYS_EXIT equ 1
	RETURN_CODE_SUCCESS equ 0
	
section .bss
	num1 resb 4
	num2 resb 4
	res resb 4

section .text
	global _start

_start:
	mov eax,SYS_WRITE
	mov ebx,STDOUT
	mov ecx,num
	mov edx,nlen
	int 0x80
	
	mov eax,SYS_READ
	mov ebx,STDIN
	mov ecx,num1
	mov edx,2
	int 0x80
	
	mov eax,SYS_WRITE
	mov ebx,STDOUT
	mov ecx,num
	mov edx,nlen
	int 0x80
	
	mov eax,SYS_READ
	mov ebx,STDIN
	mov ecx,num2
	mov edx,2
	int 0x80
	
	mov eax,[num1]
	sub eax,'0'
	mov ebx,[num2]
	sub ebx,'0'
	
	add eax,ebx
	add eax,'0'
	
	mov [res],eax
	
	mov eax,SYS_WRITE
	mov ebx,STDOUT
	mov ecx,result
	mov edx,rlen
	int 0x80
	
	mov eax,SYS_WRITE
	mov ebx,STDOUT
	mov ecx,res
	mov edx,1
	int 0x80
	
mov eax,SYS_EXIT
mov ebx,RETURN_CODE_SUCCESS
int 80h
