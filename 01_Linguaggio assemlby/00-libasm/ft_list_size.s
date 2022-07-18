global _ft_list_size

section .text
_ft_list_size:

	mov rax, 0

	cmp rdi,0
	je exit_error

label:
	inc rax
	mov rdi, [rdi + 8]
	cmp rdi, 0
	jne label

end:
	ret
exit_error:
	ret
