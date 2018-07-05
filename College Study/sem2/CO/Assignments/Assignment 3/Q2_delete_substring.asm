.data

	prompt1: .asciiz "Enter the number of characters in the string \n"
	prompt2: .asciiz "\nEnter string\n"
	prompt3 : .asciiz "Enter number of characters in substring :\n"
	prompt4 : .asciiz "Enter the substring \n"
	prompt5: .asciiz "Modified String is \n"
	prtspace: .byte ' '
	string : .space 150
	newline: .byte '\0'
	substring : .space 25
.text

	main :
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
		
		li $v0,5
		syscall
		move $s1,$v0
			
		li $v0,4
		la $a0,prompt4
		syscall
		
		li $v0,8
		la $a0,substring
		li $a1,10
		syscall
		
		la $s3,string
		la $s4,substring
		addi $t7,$s0,0 #size of main string
		addi $s7,$zero,0 #count
		mainloop :
			blez $t7,exit_mainloop
			lb $t5,0($s3)
			lb $t6,0($s4)
			addi $s3,$s3,1
			addi $s7,$s7,1
			subi $t7,$t7,1
			beq $t5,$t6,call_check_match
			j mainloop
			
			
			
		
		call_check_match :
			addi $a2,$s3,0
			subi $a2,$a2,1
			#now a2 holds the position of current character in main string
			jal check_match
			beq $v1,$zero,mainloop
			
			jal delete_from_string
			
			j mainloop
		
		
		
		exit_mainloop :
		
		li $v0,4
		la $a0,prompt5
		syscall
		
		la $s3,string
		add $t3,$s3,$s0
		lb $t4,newline
		sb $t4,0($t3)
		
		mul $t0,$s7,$s1
		addi $t3,$t3,1
		lb $t4,prtspace
		j eraseloop
			
		eraseloop:
			blez $t0,exit_eraseloop
			sb $t4,0($t3)
			addi $t3,$t3,1
			subi $t0,$t0,1
			j eraseloop
			
		exit_eraseloop:
		li $v0,4
		la $a0,string
		syscall
		
		li $v0,10
		syscall
		
	check_match :
		addi $v1,$zero,1
		addi $t0,$a2,0 #position of current character in main string
		addi $t4,$s1,0 # size of substring
		la $t1,substring
		checkloop :
			blez $t4 , exit_checkloop
			lb $t2,0($t0)
			lb $t3,0($t1)
			bne $t2,$t3,check_false
			addi $t0,$t0,1
			addi $t1,$t1,1
			subi $t4,$t4,1
			j checkloop
		check_false :
		addi $v1,$zero,0
		exit_checkloop :
		jr $ra
	
	delete_from_string :
		add $t3,$s3,$s0
		subi $t3,$t3,1
		add $t0,$s3,$s1
		subi $t0,$t0,1 # t0 is the position from where elements need to be taken
		subi $t8,$s3,1 #t8 is the position from where deletion must take place
		deleteloop:
			beq $t0,$t3,exit_from_delete_loop
			lb $t4,0($t0)
			sb $t4,0($t8)
			addi $t0,$t0,1
			addi $t8,$t8,1
			j deleteloop
		
		exit_from_delete_loop:	
		sub $t7,$t7,$s1
		sub $s0,$s0,$s1
		jr $ra				
		
	
