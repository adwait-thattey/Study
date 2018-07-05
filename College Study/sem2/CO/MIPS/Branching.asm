.data

	str1 : .asciiz "Enter an Integer\n"
	str2 : .asciiz "Enter another Integer\n"
	prtEqual : .asciiz "The numbers are Equal\n"
	isGtThan : .asciiz " Is Greater Than "
	space : .byte ' '
	newLine : .byte '\n'
.text

	main :	
		li $v0,4
		la $a0,str1
		syscall
		
		li $v0,5
		syscall
		move $t1,$v0
		
		li $v0,4
		la $a0,str2
		syscall
		
		li $v0,5
		syscall
		move $t2,$v0

		move $a1,$t1
		move $a2,$t2
			
		jal check	
	
		#End Process
		li $v0,10
		syscall
	
	check:
	
		beq $a1,$a2,equal
		bgt $a1,$a2,greater
		move $t1,$a1
		move $a1,$a2
		move $a2,$t1
		bgt $a1,$a2,greater
		
		
		jr $ra
		
	equal:
		li $v0,4
		la $a0,prtEqual
		syscall
		
		li $v0,10
		syscall
		
	greater :
		li $v0,1
		move $a0,$a1
		syscall
		
		li $v0,4
		la $a0,isGtThan
		syscall
		
		li $v0,1
		move $a0,$a2
		syscall
		
		li $v0,10
		syscall
	
	
	