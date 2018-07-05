.data
	str: .asciiz "Enter an Integer\n"

.text

	li $v0,4
	la $a0,str
	syscall
	
	li $v0,5
	syscall
	move $t1,$v0
	
	
	move $a0,$t1
	li $v0,1
	syscall
	
	