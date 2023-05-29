section .data
	arraymsg db 'Array contents are: 2,10,73,92,30,56',10
	arraymsglen equ $-arraymsg
    msg1 db 'Numbers above 50: ' 
    msg1len equ $-msg1
    msg2 db 'Numbers below 50: ' 
    msg2len equ $-msg2
    newline db '',10
    n1 equ $-newline

%macro write 2
	mov eax,4
	mov ebx,1
	mov ecx, %1
	mov edx, %2
	int 0x80
%endmacro
 
%macro read 2
	mov eax,3
	mov ebx,2
	mov ecx,%1
	mov edx,%2
	int 0x80
%endmacro

    global arr 
    arr: db 2,10,73,92,30,56

section .bss
    above resb 1
    below resb 1
    temp resb 5

section .text
    global _start
_start:
	write arraymsg,arraymsglen
	call count
	write msg1,msg1len
	write above, 1
	write newline,n1
	write msg2,msg2len
	write below, 1
	write newline,n1

mov eax ,1
xor ebx,ebx
int 0x80

count:
	mov eax, 0
	mov [above],eax
	mov [below], eax
	mov ecx, 6
	mov esi, 0
	L1:
        movzx edi, byte[arr+esi]
        mov [temp],edi 
        mov al,[temp]
        mov bl,50
        cmp al, bl
        jg L2

        inc byte[below]
        jmp end
	L2:
	    inc byte[above]
	end:
        inc esi
        loop L1
        mov eax, [below]
        add eax, '0'
        mov [below], eax
        mov eax, [above]
        add eax, '0'
        mov [above], eax
	ret
