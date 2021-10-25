global ft_strlen

section .text

ft_strlen:
	cmp rdi,0
	je ret_error
    mov rdx , -1

label:
    inc rdx
    cmp byte [rdx + rdi] , 0
    jne label 
    mov rax , rdx 
    ret

ret_error:
	mov rax,0
