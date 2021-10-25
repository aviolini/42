

global _ft_strcpy


;include <stdio.h>
extern _ft_strlen
extern _printf

section .text

_ft_strcpy:
	push rsi
	push rdi
	mov rdi , rsi
call _ft_strlen
	mov rcx , rax
	push rcx
	mov rdi , format
	mov rsi, rcx
call _printf
	pop rcx
	pop rdi
	pop rsi
	mov rdx , rcx
	;sub rdx , 1
	mov rcx , -1
label:
	inc rcx
	mov ah, byte[rsi + rcx]
	mov byte[rdi + rcx], ah
	cmp rcx, rdx
	jne label
	mov rax, rdi
	ret
format: 
	dq "|STRLEN_on printf: %s"