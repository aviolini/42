global ft_write
extern __errno_location

section .text

ft_write:

	mov rax, 1
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
