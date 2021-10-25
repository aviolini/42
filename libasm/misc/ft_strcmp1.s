global _ft_strcmp

section .text

_ft_strcmp:
label:
	mov r8b, byte[rdi]
	cmp r8b, byte[rsi]
	je increment
	sub r8b, byte[rsi]
	;xor rax, rax
	mov byte[rax], r8b 

	;movsx rax, r8b
	ret

increment:
	cmp r8b , 0
	je equal
	inc rdi
	inc rsi
	jmp label

equal:
	mov rax, 0
	ret