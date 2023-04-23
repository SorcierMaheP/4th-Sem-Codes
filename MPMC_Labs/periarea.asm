section .data
	askuserrect db "Enter the length of a rectangle: ", 10
	askuserrectlen equ $-askuserrect
	askUserBreadth db "Enter the breadth of a rectangle: ", 10
	askBreadthLen equ $-askUserBreadth

	displayarearect db "The area is : ", 9
	displayarearectlen equ $-displayarearect
	displayperirect db "The perimeter is: ", 9
	displayperirectlen equ $-displayperirect

    askusertrig db "Enter the side of a triangle: ", 10
	askusertriglen equ $-askusertrig
	askUserHeight db "Enter the height of a triangle: ", 10
	askHeightLen equ $-askUserHeight

	displayareatrig db "The area is : ", 9
	displayareatriglen equ $-displayareatrig
	displayperitrig db "The perimeter is: ", 9
	displayperitriglen equ $-displayperitrig

	newLineMsg db 0xA, 0xD
	newLineLen equ $-newLineMsg

section .bss
    length resb 2
    breadth resb 2
    inter resb 2
    area resb 2
    perimeter resb 2
    side1 resb 2
	side2 resb 2
	side3 resb 2
	height resb 2

section .text
    global _start

_start:

;-----Rectangle Calculation
    mov eax, 4
	mov ebx, 1
	mov ecx, askuserrect
	mov edx, askuserrectlen
	int 0x80

    mov eax, 3
	mov ebx, 2
	mov ecx, length
	mov edx, 2
	int 0x80

    mov eax, 4
	mov ebx, 1
	mov ecx, askUserBreadth
	mov edx, askBreadthLen
	int 0x80

    mov eax, 3
	mov ebx, 2
	mov ecx, breadth
	mov edx, 2
	int 0x80

    mov al, [length]
    sub al, '0'
    mov bl, [breadth]
    sub bl, '0'
    mul bl
    add al, '0'
    mov [area], al

    mov eax, 4
	mov ebx, 1
	mov ecx, displayarearect
	mov edx, displayarearectlen
	int 0x80

	mov eax, 4
	mov ebx, 1
	mov ecx, area
	mov edx, 2
	int 0x80

	mov eax, 4
	mov ebx, 1
	mov ecx, newLineMsg
	mov edx, newLineLen
	int 0x80

    mov eax, [length]
    sub eax, '0'
    mov ebx, [breadth]
    sub ebx, '0'
    add eax, ebx
    add eax, '0'
    mov [inter], eax

    mov al, [inter]
    sub al, '0'
    mov bl, '2'
    sub bl, '0'
    mul bl
    add al, '0'
    mov [perimeter], al

    mov eax, 4
	mov ebx, 1
	mov ecx, displayperirect
	mov edx, displayperirectlen
	int 0x80

	mov eax, 4
	mov ebx, 1
	mov ecx, perimeter
	mov edx, 2
	int 0x80

    mov eax, 4
	mov ebx, 1
	mov ecx, newLineMsg
	mov edx, newLineLen
	int 0x80

;-----Triangle calculation
	mov eax, 4
	mov ebx, 1
	mov ecx, askusertrig
	mov edx, askusertriglen
	int 0x80
	
	mov eax, 3
	mov ebx, 2
	mov ecx, side1
	mov edx, 2
	int 0x80

	mov eax, 3
	mov ebx, 2
	mov ecx, side2
	mov edx, 2
	int 0x80

	mov eax, 3
	mov ebx, 2
	mov ecx, side3
	mov edx, 2
	int 0x80

	mov eax, 4
	mov ebx, 1
	mov ecx, askUserHeight
	mov edx, askHeightLen
	int 0x80

	mov eax, 3
	mov ebx, 2
	mov ecx, height
	mov edx, 2
	int 0x80

	mov al, [side1]
	sub al, '0'
	mov bl, [height]
	sub bl, '0'
	mul bl
	add al, '0'	
	mov [inter], al
	
	mov al, [inter]
	sub al, '0' 
	mov bl, '2'
	sub bl, '0'
	div bl
	add al, '0'
	mov [area], al

	mov eax, 4
	mov ebx, 1
	mov ecx, displayareatrig
	mov edx, displayareatriglen
	int 0x80

	mov eax, 4
	mov ebx, 1
	mov ecx, area
	mov edx, 2
	int 0x80

	mov eax, 4
	mov ebx, 1
	mov ecx, newLineMsg
	mov edx, newLineLen
	int 0x80

	mov eax, [side1]
	sub eax, '0'
	mov ebx, [side2]
	sub ebx, '0'
	add eax, ebx
	add eax, '0'
	mov [inter], eax

	mov eax, [side3]
	sub eax, '0'
	mov ebx, [inter]
	sub ebx, '0'
	add eax, ebx
	add eax, '0'
	mov [perimeter], eax

	mov eax, 4
	mov ebx, 1
	mov ecx, displayperitrig
	mov edx, displayperitriglen
	int 0x80

	mov eax, 4
	mov ebx, 1
	mov ecx, perimeter
	mov edx, 2
	int 0x80

	mov eax, 4
	mov ebx, 1
	mov ecx, newLineMsg
	mov edx, newLineLen
	int 0x80

mov eax, 1
xor ebx, ebx
int 0x80