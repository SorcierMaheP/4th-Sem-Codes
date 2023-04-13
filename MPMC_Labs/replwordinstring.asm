SECTION .data
    name db 'ABC DEF',10
    len equ $-name
    
    text1 db 'Original string:'
    len1 equ $-text1
    
    text2 db 'New string:'
    len2 equ $-text2
    
SECTION .text
    global _start

_start:
    mov eax,4
    mov ebx,1
    mov ecx,text1
    mov edx,len1
    int 0x80
    
    mov eax,4
    mov ebx,1
    mov edx,len
    mov ecx,name
    int 0x80
    
    mov [name], dword 'XYZ '
    
    mov eax,4
    mov ebx,1
    mov ecx,text2
    mov edx,len2
    int 0x80
    
    mov ebx,1
    mov eax,4
    mov ecx,name
    mov edx,len
    int 0x80
    
mov eax,1
mov ebx,0
int 0x80