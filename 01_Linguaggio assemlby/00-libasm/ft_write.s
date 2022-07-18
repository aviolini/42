global _ft_write
extern ___error

section .text

_ft_write:
	mov rax, 0x2000004
	syscall
	jc exit_error
	ret

exit_error:
	mov rdi , rax
	call ___error
	mov [rax], rdi
	mov rax, -1
	ret

exit_1:
	mov rax, -1
	ret



;	global _ft_list_push_front
;
;extern _malloc

;section .text
;_ft_list_push_front:
;
;	push rbp
;	push rdi
;;	push rsi
;
;	mov rdi, 16
;	call _malloc
;	pop rsi
;	pop rdi
;
;	mov r8, [rdi]
;
;	mov [rax], rsi
;	cmp r8, 0
;	je next_null
;;	mov byte[rax + 8], 0
;	mov [rax + 8], r8
;		mov [rdi], rax		
;exit_error:
;	pop rbp
;	ret
;
;next_null:
;	mov qword[rax + 8], 0
;		mov [rdi], rax
;	pop rbp
;	ret
;
;;
;	mov r8b, [rdi]
;	cmp r8b, 0
;	je exit_error