.data

	myArray: .space 400
	prompt1: .asciiz "How many numbers do ou wanna enter (max: 100) \n"
	prompt2: .asciiz "\nStart Entering Numbers in Array\n"
	prompt3: .asciiz "The Primes in the given array are : "
	prompt4: .asciiz "DO NOT ENTER NEGATIVE VALUES\nPROGRAM TERMINATED\n"
	prtSpace: .byte ' '
.text
	main:
		# print Prompt 1
		li $v0,4
		la $a0,prompt1
		syscall
		
		#Take size as input
		li $v0,5
		syscall
		blt $v0,0,negativeValueException #Exit program if entered value is negative
		move $s0,$v0
		
		#print prompt 2
		li $v0,4
		la $a0,prompt2
		syscall
		
		# Enter all elements in Array
		addi $t0,$s0,0 # t0 is the count
		addi $t1,$zero,0 #t1 starts from 0
		loop:
			blez $t0,exit # The count keeps decrementing in each iteration. Loop breaks when count = 0
			li $v0,5
			syscall
			
			blt $v0,0,negativeValueException #Exit program if entered value is negative
			sw $v0,myArray($t1) #take input from user and store in Array
			addi $t1,$t1,4
			subi $t0,$t0,1 #decrement count
			j loop
			
		exit:	
		
		mul $t0,$s0,4 #This is the total size of the array entered by USER
		addi $t1,$zero,0 #t1 starts from 0
		
		# Print prompt 3
		li $v0,4
		la $a0,prompt3
		syscall
		
		#This Loop iterates over each element of the array. It willsend each element to the function checkNPrintPrime.
		# The function checkNPrintPrime prints the number if it is a prime
		printPrimes:
			bge $t1,$t0,exitPrimes 
			lw $t3,myArray($t1)
			addi $a1,$t3,0 #cpy the number in argument register
			jal checkNPrintPrime #call function
			addi $t1,$t1,4
			j printPrimes
			
		
		exitPrimes:
		
		
		li $v0,10
		syscall
		
		
	checkNPrintPrime :
		addi $t5,$zero,2 #each number to be checked with
		addi $t6,$zero,2 #flag to check if broken from loop.This flag will contain reminder. 2 is just a dummy value for starting
		beq $a1,1,exitFromFunction # Exit from function without printing if input is 1. Handling special case of 1
		beq $a1,0,exitFromFunction # Exit from function without printing if input is 1. Handling special case of 0
		#This loop divides the number by t5 everytime. The loop breakes if reminder is 0 or if t5 becomes equal to the number
		#t5 is incremented everytime
		chkPrimeLoop:
			bge $t5,$a1,exitChkPrime
			addi $t7,$a1,0
			div $t7,$t5
			mfhi $t6
			beqz $t6,exitChkPrime
			addi $t5,$t5,1 #increment t5 everytime
			j chkPrimeLoop
		
		exitChkPrime:
			 # if remider=0, then exit. Else print the number, then make reminder 0 so that it exits in next iteration
			beqz $t6,exitFromFunction
			li $v0,1
			addi $a0,$a1,0
			syscall
			
			li $v0,4
			la $a0,prtSpace
			syscall
			
			addi $t6,$zero,0 #Make reminder 0 to exit in next iteration
			j exitChkPrime
		
		exitFromFunction:
		jr $ra	
	
	negativeValueException:
		li $v0,4
		la $a0,prompt4
		syscall
		
		li $v0,10
		syscall
				

			