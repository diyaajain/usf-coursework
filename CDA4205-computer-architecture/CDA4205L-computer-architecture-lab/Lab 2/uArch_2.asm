.globl __main

.data

.text 

	__main:
		li a7, 1
		
		li a0, 550
		li a1, 21
		li a2, 0
		jal _multiply
		
		ecall
		
		li a7, 10
		ecall
		
	_multiply:
	
		beqz a1, _done
		add a2,a2,a0
		addi a1,a1,-1
		j _multiply
	
	_done:
		addi a0,a2,0
		
		jr ra