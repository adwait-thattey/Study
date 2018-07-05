.data
	prompt1: .asciiz "Enter A Number\n"
	prompt2: .asciiz "\nEnter another Numner\n"
	prompt3: .asciiz "\nGCD is : "
	zeroAlert: .asciiz "PLZ DO NOT ENTER ZERO\n PROGRAM TERMINATED.\n"

.text

	main:
		li $v0,4
		la $a0,prompt1
		syscall
		
		li $v0,5
		syscall
		beqz $v0,zeroException
		move $s0,$v0
		
		#if input is negative, make positive
		negloop1:
			bgtz $s0,exitnegloop1
			addi $t6,$zero,1
			mul $s0,$s0,-1
			j negloop1
		
		exitnegloop1:
		
		li $v0,4
		la $a0,prompt2
		syscall
		
		li $v0,5
		syscall
		beqz $v0,zeroException
		move $s1,$v0
		
		#if input is negative, make positive
		negloop2:
			bgtz $s0,exitnegloop2
			addi $t6,$zero,1
			mul $s1,$s1,-1
			j negloop2
		
		exitnegloop2:
		
		gcdLoop :
			div $s0,$s1
			mfhi $t0
			blez $t0,done
			move $s0,$s1
			move $s1,$t0
			j gcdLoop
			
		done:	
			li $v0,4
			la $a0,prompt3
			syscall
			
			li $v0,1
			addi $a0,$s1,0
			syscall
			
			li $v0,10
			syscall		
		
	zeroException:	
	
		li $v0,4
		la $a0,zeroAlert
		syscall
		li $v0,10
		syscall
	