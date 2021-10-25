global _ft_strcmp

section .text

_ft_strcmp:
	mov rcx , -1
label:
	inc rcx
	mov r8b, byte[rdi + rcx]
	cmp r8b, byte[rsi + rcx]
	je condition
	sub r8b, byte[rsi + rcx]
	movsx rax , r8b 
	ret

condition:
	cmp r8b , 0
	jne label
	mov rax , 0
	ret
