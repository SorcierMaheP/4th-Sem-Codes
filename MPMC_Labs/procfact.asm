section .data
	input db "Enter number: "
	len1 equ $-input
	
	output db "Factorial is: "
	len2 equ $-output
	
section .bss

	num resb 4
	i resb 4
	fact resb 4
	
section .text
	global _start
_start:
	mov eax,4
	mov ebx,1
	mov ecx,input
	mov edx,len1
	int 0x80
	
	mov eax,3
	mov ebx,2
	mov ecx,num
	mov edx,4
	int 0x80
	
	mov eax,4
	mov ebx,1
	mov ecx,output
	mov edx,len2
	int 0x80
	
	call FACTORIAL
	
	mov eax,4
	mov ebx,1
	mov ecx,fact
	mov edx,4
	int 0x80

mov eax,1
xor ebx,ebx
int 0x80
	
	FACTORIAL:
		mov byte[i],'1'
		mov byte[fact],'1'
		
		L1:
		
			mov eax,[fact]
			sub eax,'0'
			mov ebx,[i]
			sub ebx,'0'
			mul ebx
			add eax,'0'
			mov [fact],eax

			inc byte[i]
			mov al, [i]
			CMP al, byte[num]
			JLE L1
			
		ret
			
	 
