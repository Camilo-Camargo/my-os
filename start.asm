bits 32
global _start
extern main

section .text
_start:
	cli ; clear interrupts
	mov esp, stack
	call main
	hlt ;halt

section .bss
	resb 8192
stack:
