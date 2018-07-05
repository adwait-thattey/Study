.data

	prompt1: .asciiz "Enter the number of characters in the string \n"
	prompt2: .asciiz "\nEnter string\n"
	prompt3 : .asciiz "Reversed String Is :\n"
	prtspace: .byte ' '
	string : .space 150
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
	
	li $v0,8
	la $a0,string
	li $a1,25
	syscall
	
	li $v0,4
	la $a0,prompt3
	syscall
	
	add $t0,$zero,$s0
	la $t1,string
	add $t1,$t1,$s0
	subi $t1,$t1,1
	loop:
		blez $t0,exit
		li $v0,11
		lb $a0,0($t1)
		syscall
		subi $t1,$t1,1
		subi $t0,$t0,1
		j loop
		
	exit:
	#li $v0,5
	#syscall
	#move $s0,$v0
	
	#li $v0,4
	#la $a0,prompt2
	#syscall
