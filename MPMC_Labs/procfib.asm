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
	mov eax,4
    mov ebx,1
    mov ecx,str1
    mov edx,str1len
    int 0x80

    mov eax,3
    mov ebx,2
    mov ecx,n
    mov edx,4
    int 0x80

    mov eax,4
    mov ebx,1
    mov ecx,str2
    mov edx,str2len
    int 0x80

    call FIBO

mov eax,1
xor ebx,ebx
int 0x80

    FIBO:
	
        mov byte[i], '0'
        mov byte[a], '0'
        mov byte[b], '1'
        
        mov al,byte[i]
        cmp al,byte[n]
        JL L1
        JMP L4
        
        L1:
            mov eax,4
            mov ebx,1
            mov ecx,a
            mov edx,4
            int 0x80

            mov eax,4
            mov ebx,1
            mov ecx,spa
            mov edx,spalen
            int 0x80


            inc byte[i]
            mov al, [i]

            cmp al, byte[n]
            JL L2
            JMP L4
        
        L2:
            mov eax,4
            mov ebx,1
            mov ecx,b
            mov edx,4
            int 0x80

            mov eax,4
            mov ebx,1
            mov ecx,spa
            mov edx,spalen
            int 0x80

            inc byte[i]
            
            mov al, [i]
            cmp al, byte[n]
            JL L3
            JMP L4
        
        L3:
            call formula

            mov eax,4
            mov ebx,1
            mov ecx,c
            mov edx,4
            int 0x80

            mov eax,4
            mov ebx,1
            mov ecx,spa
            mov edx,spalen
            int 0x80


            mov al, [b]
            mov [a], al
            
            mov al, [c]
            mov [b], al
            
            inc byte[i]
            mov al, [i]
            cmp al, byte[n]
            JL L3
            JMP L4
        
        L4:
            ret
            
    formula:
        mov eax,[a]
        sub eax,'0'
        mov ebx,[b]
        sub ebx,'0'

        add eax,ebx
        add eax,'0'
        mov [c],eax
        ret