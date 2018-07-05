.data

	prompt1: .asciiz "Enter the number of characters in the string \n"
	prompt2: .asciiz "\nEnter string\n"
	prompt3 : .asciiz "Reversed String Is :\n"
	prtspace: .byte ' '
	null : .byte '\0'
	string : .space 150
	string2 : .space 150
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
	la $t7,string2
	
	add $t1,$t1,$s0
	subi $t1,$t1,1
	
	loop:
		blez $t0,wb
		
		lb $a0,0($t1)
		
		sb $a0,0($t7)
		addi $t7,$t7,1
		subi $t1,$t1,1
		subi $t0,$t0,1
		j loop
		
	wb:
		la $t1,string
		la $t7,string2
		wbloop :
			blez $s0 finalexit
			lb $a0,0($t7)
			sb $a0,0($t1)
			addi $t7,$t7,1
			addi $t1,$t1,1
			subi $s0,$s0,1
			j wbloop
			
	finalexit:
		la $a0,null
		lb $a0,0($a0)
		sb $a0,0($t1)
		
		li $v0,4
		la $a0,string
		syscall
	
		li $v0,10
		syscall
