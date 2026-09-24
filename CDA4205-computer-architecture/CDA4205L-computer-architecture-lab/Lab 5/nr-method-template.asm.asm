.data


.text
	
	li t0, 107800		# load a value
	jal prntFloat		# print it to be sure the conersion worke
	jal prntNewLine
	
	# complete 2a, 2b, and 2c
	fcvt.s.w fa0, t0
	jal prntFloat
	
	fsqrt.s fa0, fa0
	jal prntFloat
	
	fmul.s fa0, fa0, fa0
	jal prntFloat
	jal prntNewLine
	
	# complete 2d (repeating 2a, 2b, and 2c, except with double precision
	fcvt.d.w fa0, t0
	jal prntDouble
	
	fsqrt.d fa0, fa0
	jal prntDouble
	
	fmul.d fa0, fa0, fa0
	jal prntDouble
	jal prntNewLine
	
	# now test Newton-Raphson method

	li t0, 9		# number n iterations
	li t1, 107800		# number X you want sqrt
	li t2, 2		# load constant 2
	li t3, 10		# load constant 10
	li t4, 1		# load constant 1
	
	# perform conversions for t0, t1, t2 and store results in ft0, ft2, ft4
	fcvt.d.w ft0, t1	# ft0 = 107800.0
	fcvt.d.w ft2, t2	# ft2 = 2.0
	fcvt.d.w ft4, t3	# ft4 = 10.0
	fcvt.d.w fs0, t4	# fs0 = 1.0
	fmv.d	ft8, ft0	# ft8 = 107800.0
	
	fdiv.d	fs0, fs0, ft4	# fs0 (threshold value of 10^-1, or 0.1) = 1.0 / 10.0
	fdiv.d	fs0, fs0, ft4	# fs0 (threshold value of 10^-2, or 0.01) = 0.1 / 10.0
	fdiv.d	fs0, fs0, ft4	# fs0 (threshold value of 10^-3, or 0.001) = 0.01 / 10.0
	fdiv.d	fs0, fs0, ft4	# fs0 (threshold value of 10^-4, or 0.0001) = 0.001 / 10.0
	fdiv.d	fs0, fs0, ft4	# fs0 (threshold value of 10^-5, or 0.00001) = 0.0001 / 10.0
	fdiv.d	fs0, fs0, ft4	# fs0 (threshold value of 10^-6, or 0.000001) = 0.00001 / 10.0
	fdiv.d	fs0, fs0, ft4	# fs0 (threshold value of 10^-7, or 0.0000001) = 0.000001 / 10.0
	fdiv.d	fs0, fs0, ft4	# fs0 (threshold value of 10^-8, or 0.00000001) = 0.0000001 / 10.0

	jal NewtonRoots		# get sqrt(N) in n iterations

	fmv.d fa0, ft6		# move the function result to fa0, and print the result
	jal prntNewLine
	jal prntDouble
	
	jal exit
		
NewtonRoots:
	 	flt.d	t4, ft0, ft4 	# t4 = 0, since 107800 > 10
	 	beq	t4, x0, other	# 0 == 0, so go to other
	 	fdiv.d	ft0, ft0, ft2	# fs0 = 107800 / 2 (wont execute, since 4205 > 10)
	 	jal 	NewtonRootsLoop	# go to NewtonRootsLoop
	 	
	other:	fdiv.d 	ft0, ft0, ft4	# fs0 = 107800 / 10
		jal 	NewtonRootsLoop	# go to NewtonRootsLoop
		
		
NewtonRootsLoop:

	# perform the actual N-R method computation
	# ft0 = 10780.0, ft8 = 107800.0, ft2 = 2.0, ft4 = 10.0
	fmv.d	fs2, ft0		# (prev guess) fs2 =  10780.0
	
	fmul.d	ft4, ft0, ft0		# ft4 = (10780.0)^2	
	fsub.d	ft10, ft4, ft8		# ft10 = (10780.0)^2 - 107800.0
	fmul.d 	fa0, ft2, ft0		# fa0 = 2 * 10780.0
	fdiv.d	fa0, ft10, fa0		# fa0 = ft10 / fa0
	fsub.d 	ft0, ft0, fa0		# ft0 = ft0 - fa0
					
	fmv.d	fs4, ft0		# (curr guess)  fs4 = result of N-R method
	fsub.d	fs4, fs2, fs4		# fs4 = prev - curr (10780.0 - 215.25)
	flt.d	t4, fs4, fs0		# t4 = ???, (prev - curr) < threshold (10780.0 - 10033.21892 > threshold, so t4 = 0)
	beq	t4, x0, continue_loop	# if t4 = 0, go to continue_loop (continues the cycle)
	
	fmv.d	fa0, ft0		# otherwise, t4 = 1, meaning the diff. is less than threshold, so we must end the loop
	jal	prntDouble
	jal 	exit
	
continue_loop:
	fmv.d	fa0, ft0
	jal	prntDouble	
	jal	NewtonRootsLoop
					
	# fmv.d fa0, ft0
	# jal prntDouble
	
	# addi	t0, t0, -1		# decrement value of n (iterations)
	# bgt	t0, x0, loop		# if counter > 0, go back to NewtonRootsLoop
	# jal	exit
# loop:	jal	NewtonRootsLoop
	

# helper functions

# prints a float and newline, assuming float already moved to fa0
prntFloat:
	li a7, 2
	ecall
	li a0, '\n'
	li a7, 11
	ecall
	jr ra

# prints a double and newline, assuming double already moved to fa0
prntDouble:
	li a7, 3
	ecall
	li a0, '\n'
	li a7, 11
	ecall
	jr ra
	
prntNewLine:
	li a0, '\n'
	li a7, 11
	ecall
	jr ra

exit:
	li a7, 10
	ecall
