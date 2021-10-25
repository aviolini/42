global _ft_read
extern ___error

section .text

_ft_read:
mov rax, 0x2000003
	syscall
	jc exit_error
	ret

exit_error:
	mov rdi , rax
	call ___error
	mov [rax], rdi
	mov rax, -1
	ret

