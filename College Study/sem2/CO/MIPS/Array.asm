.data

	myArray: .space 400
	prompt1: .asciiz "How many numbers do ou wanna enter \n"
	prompt2: .asciiz "\nStart Entering Numbers in Array\n"
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
	
	loop2:
		bge $t1,$t0,exit2
		li $v0,1
		lw $a0,myArray($t1)
		syscall
		addi $t1,$t1,4
		j loop2
		
	
	exit2:
	li $v0,10
	syscall
	