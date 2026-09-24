.globl __main

.data

.text 

	__main:
		li a7, 1
		
		li a0, 550
		li a1, 21
		jal _multiply
		
		ecall
		
		li a7, 10
		ecall
		
	_multiply:
	
		mul a0,a0,a1
		
		jr ra