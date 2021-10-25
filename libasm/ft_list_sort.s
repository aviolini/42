global _ft_list_sort   
extern _printf

section .text

_ft_list_sort:
	push rbp
	mov r12, rsi
	mov r11, rdi
	mov rdx, 0

init:
	mov r13, r11
	mov rdi, [r13]
	mov rsi, [rdi + 8]
	mov rdi, [rdi]
	mov rsi, [rsi]
	call r12
	cmp rax, 0
	jl deref

swap1:

	mov r8,[r13]
	mov r9, [r8 + 8]		
	mov r10, [r9 + 8]	
;	cmp r14, 0
;	jne print	
	mov [r13], r9
	mov [r9 + 8], r8
	mov [r8 + 8], r10
	cmp rdx,0
	je init	;MODIFICARE CON JMP PERCHE
			;RDX POTREBBE CAMBIARE
			;DOPO LA CHIMATA DI R12

deref:
	mov r13,[r13]
	mov rdi, [r13 + 8]
	lea r13, [r13]
	mov rsi, [rdi + 8]
	mov rdi, [rdi]
	mov rsi, [rsi]
	call r12
	cmp rax, 0
	jl deref
swap2:
	mov r8,[r13 + 8]
	mov r9, [r8 + 8]
	mov r10, [r9 + 8]	
	mov [r13 + 8], r9
	mov [r9 + 8], r8
	mov [r8 + 8], r10

	cmp rdx,0
	je init
	
	jmp return
	jmp print
	jmp return

return:
	pop rbp
	ret

print:
	;mov rsi,r8
	mov rdi, format
	;mov rsi, r11
	call _printf
	jmp return

format: 
	db "printf: %p",10,0
formatd: 
	db "printf: %d",10,0
formats: 
	db "printf: %s",10,0

;METTERE LE PROTEZIONI PER LE USCITE
;FARE IL DEREF2 DOPO LO SWAP
;IL SECONDO E IL TERZO ELEMENTO LI SCAMBIA
	;ANCHE SE NON DEVE

;LINUX:
;clear && nasm -felf64 ft_list_push_front.s && nasm -felf64 ft_list_sort.s && gcc -no-pie ft_list_push_front.o ft_list_sort.o test_bonus.c && ./a.out