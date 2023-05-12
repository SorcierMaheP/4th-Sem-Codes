%macro write 2
    mov eax, 4
    mov ebx, 1
    mov ecx, %1
    mov edx, %2
    int 0x80
%endmacro

%macro read 2
    mov eax, 3
    mov ebx, 2
    mov ecx, %1
    mov edx, %2
    int 0x80
%endmacro

%macro newline 0
    mov eax, 4
    mov ebx, 1
    mov ecx, nl
    mov edx, nllen
    int 0x80
%endmacro

%macro form 3
	mov eax, [%1]
	sub eax, '0'
	mov ebx, [%2]
	sub ebx, '0'
	add eax, ebx
	add eax, '0'
	mov [%3], eax
	int 0x80
%endmacro

section .bss
	n resb 4
	a resb 4
	b resb 4
	c resb 4
	i resb 4
	
section .data
	str1 db 'Enter a number: '
	str1len equ $-str1
	
	str2 db 'Fibonacci series: '
	str2len equ $-str2
	
	nl db "", 10
	nllen equ $-nl

    spa db " "
    spalen equ $-spa
	
section .text
	global _start
_start:
	write str1, str1len
	read n, 4
	write str2, str2len
	
	mov byte[i], '0'
	mov byte[a], '0'
	mov byte[b], '1'
	
	cmp byte[n], '0'
	JE L4
	JMP L1
	
	L1:
	write a, 4
    write spa,spalen
	inc byte[i]
	mov al, [i]
	cmp al, byte[n]
	JE L4
	JMP L2
	
	L2:
	write b, 4
    write spa,spalen
	inc byte[i]
	
	mov al, [i]
	cmp al, byte[n]
	JE L4
	JMP L3
	
	L3:
	form a, b, c
	write c, 4
	write spa,spalen
	mov al, [b]
	mov [a], al
	
	mov al, [c]
	mov [b], al
	
	inc byte[i]
	mov al, [i]
	cmp al, byte[n]
	JE L4
	JMP L3
	
	L4:
	newline
	mov eax, 1
	int 80h