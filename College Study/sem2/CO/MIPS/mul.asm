.data
	str1 : .asciiz "Enter an Integer\n"
	str2 : .asciiz "Enter another Integer\n"
	str3 : .asciiz "\nThe product is : " 
	
.text
	li $v0,4
	la $a0,str1
	syscall
	
	li $v0,5
	syscall
	move $s0,$v0
	
	li $v0,4
	la $a0,str2
	syscall
	
	li $v0,5
	syscall
	move $s1,$v0
	
	li $v0,4
	la $a0,str3
	syscall
	
	mul $t1,$s0,$s1
	
	li $v0,1
	move $a0,$t1
	syscall
	