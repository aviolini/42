global ft_read
extern __errno_location

section .text

ft_read:

	mov rax, 0
	syscall
	cmp rax,0
	jl exit_error
	ret

exit_error:
	mov rdi , rax
	imul rdi,-1
	call __errno_location
	mov [rax], rdi
	mov rax, -1
	ret
