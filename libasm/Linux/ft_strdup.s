global ft_strdup
extern ft_strlen
extern ft_strcpy
extern malloc

section .text
ft_strdup:
	call ft_strlen
	push rdi
	mov rdi , rax
	inc rdi
	;mov rdi,181798691840000 ;to fail malloc
	call malloc
	cmp rax,0
	je ret_error
	pop rcx
	mov rdi, rax
	mov rsi, rcx
	call ft_strcpy
	ret

ret_error:
	pop rdi
	ret
	


