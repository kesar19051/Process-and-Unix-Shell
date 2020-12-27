C:
	gcc -c a1.c

ASM:
	nasm -felf64 a.asm

combine: a1.o a.o
	gcc a1.o a.o -o combined
	
clear:
	rm a1.o 
	rm a.o


