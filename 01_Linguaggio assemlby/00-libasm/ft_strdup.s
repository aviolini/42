global _ft_strdup
extern _ft_strlen
extern _ft_strcpy
extern _malloc

section .text
_ft_strdup:
	call _ft_strlen
	push rdi
	mov rdi , rax
	inc rdi
	;mov rdi,181798691840000 ;to fail malloc
	call _malloc
	cmp rax,0
	je ret_error
	pop rcx
	mov rdi, rax
	mov rsi, rcx
	call _ft_strcpy
	ret

ret_error:
	pop rdi
	ret
	


