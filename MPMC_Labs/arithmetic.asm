
section .data

input db 10,'enter a number : '
ilen equ $-input

output_s db  10,'the sum is : '
olens equ $-output_s

output_d db 10,'the dif is : '
olend equ $-output_d

output_p db 10,'the mul is : '
olenp equ $-output_p

output_q db 10,'the quo is : '
olenq equ $-output_q

output_r db 10,'the rem is : '
olenr equ $-output_r

section .bss
 num1 resb 4
 num2 resb 4
 sum resb 4
 diff resb 4
 prod resb 4
 quo resb 4
 rem resb 4
 
section .text

global _start

_start:

  mov eax, 4
  mov ebx, 1
  mov ecx, input
  mov edx , ilen
  int 80h
  
  mov eax,3
  mov ebx,2
  mov ecx,num1
  mov edx,2
  int 80h
  
  mov eax, 4
  mov ebx, 1
  mov ecx, input
  mov edx , ilen
  int 80h
  
  mov eax,3
  mov ebx,2
  mov ecx,num2
  mov edx,2
  int 80h
  
  mov eax,[num1]
  sub eax,'0'
  mov ebx,[num2]
  sub ebx,'0'
  
  add eax,ebx
  add eax,'0'
  
  mov [sum],eax
  
  mov eax,4
  mov ebx,1
  mov ecx,output_s
  mov edx,olens
  int 80h
  
  mov eax,4
  mov ebx,1
  mov ecx,sum
  mov edx,2
  int 80h
  
   mov eax,[num1]
  sub eax,'0'
  mov ebx,[num2]
  sub ebx,'0'
  
  sub eax,ebx
  add eax,'0'
  
  mov [diff],eax
  
  mov eax,4
  mov ebx,1
  mov ecx,output_d
  mov edx,olend
  int 80h
  
  mov eax,4
  mov ebx,1
  mov ecx,diff
  mov edx,2
  int 80h
  
  mov al,[num1]
  sub al,'0'
  mov bl,[num2]
  sub bl,'0'
  
  mul bl
  add al,'0'
  
  mov [prod],al
  
  mov eax,4
  mov ebx,1
  mov ecx,output_p
  mov edx,olenp
  int 80h
  
  mov eax,4
  mov ebx,1
  mov ecx,prod
  mov edx,2
  int 80h
  
  mov al,[num1]
  sub al,'0'
  mov bl,[num2]
  sub bl,'0'
  
  div bl
  add al,'0'
  add ah,'0'
  mov [quo],al
  mov [rem],ah
  
  mov eax,4
  mov ebx,1
  mov ecx,output_q
  mov edx,olenq
  int 80h
  
  mov eax,4
  mov ebx,1
  mov ecx,quo
  mov edx,2
  int 80h
  
  mov eax,4
  mov ebx,1
  mov ecx,output_r
  mov edx,olenr
  int 80h
  
  mov eax,4
  mov ebx,1
  mov ecx,rem
  mov edx,2
  int 80h
  
mov eax, 1
mov ebx, 0
int 80h

