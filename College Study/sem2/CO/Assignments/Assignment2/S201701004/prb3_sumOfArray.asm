.data

	myArray: .space 400
	prompt1: .asciiz "How many numbers do ou wanna enter (max: 100) \n"
	prompt2: .asciiz "\nStart Entering Numbers in Array\n"
	prompt3: .ascii "The Sum is "
	prtspace: .byte ' '
.text
	li $v0,4
	la $a0,prompt1
	syscall
	
	li $v0,5
	syscall
	move $s0,$v0
	
	li $v0,4
	la $a0,prompt2
	syscall
	
	addi $t0,$s0,0
	addi $t1,$zero,0
	loop:
		blez $t0,exit
		li $v0,5
		syscall
		sw $v0,myArray($t1)
		addi $t1,$t1,4
		subi $t0,$t0,1
		j loop
		
	exit:	
	
	mul $t0,$s0,4
	addi $t1,$zero,0
	addi $s1,$zero,0
	calcSum:
		bge $t1,$t0,exitSum
		lw $t3,myArray($t1)
		add $s1,$s1,$t3
		addi $t1,$t1,4
		j calcSum
		
	
	exitSum:
	
	li $v0,4
	la $a0,prompt3
	syscall
	
	li $v0,1
	addi $a0,$s1,0
	syscall
	
	li $v0,10
	syscall