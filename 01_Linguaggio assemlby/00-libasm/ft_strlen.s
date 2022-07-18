global _ft_strlen

section .text

_ft_strlen:
	push rbp
	cmp rdi,0
	je ret_error
    mov rdx , -1

label:
    inc rdx
    cmp byte [rdx + rdi] , 0
    jne label 
    mov rax , rdx
	pop rbp 
    ret

ret_error:
	mov rax,0
	ret
