
global _ft_list_push_front

extern _malloc

section .text
_ft_list_push_front:
	push rbp
	push rdi
	push rsi
	mov rdi, 16
	call _malloc
	pop rsi
	pop rdi
	cmp rax, 0
	je exit_error
	mov r8, [rdi]
	mov [rdi], rax
	mov [rax], rsi
	mov [rax + 8], r8
	pop rbp
exit_error:
	ret


