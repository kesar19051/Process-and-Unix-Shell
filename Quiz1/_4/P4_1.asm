global long_add

section .text

long_add:
	push ebp
	mov ebp, esp
	mov eax, [ebp+20]
	mov ecx, [ebp+16]
	mov edx, [ebp+12]
	mov ebx, [ebp+8]
	add eax, ecx
	add eax, edx
	add eax, ebx
	pop ebp
	ret
