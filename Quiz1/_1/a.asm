global _start

section .text

_start:
	mov rdi, 1
	mov rsi, 3
	call _checkGreater

_checkGreater:
	mov rax, rdi
	cmp rax, rsi
	jg _abc
	mov rax, 1
	mov rdi, 1
	mov rsi, msg
	mov rdx, 2
	syscall

	mov rax, 60
	mov rdi, 0
	syscall

_abc:
	mov rax, 1
	mov rdi, 1
	mov rsi, msg1
	mov rdx, 2
	syscall

	mov rax, 60
	mov rdi, 0
	syscall
	

section .rodata
	msg1: db "1", 10
	msg: db "0", 10
	


