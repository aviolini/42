global ft_strcpy

section .text

ft_strcpy:
	mov rcx, -1

label:
	inc rcx
	mov ah, byte[rsi + rcx]
	mov byte[rdi + rcx],ah
	cmp byte[rdi + rcx], 0
	jne label
	mov rax ,rdi
	ret