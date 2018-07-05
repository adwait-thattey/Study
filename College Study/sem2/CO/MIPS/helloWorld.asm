.data
	
	myMessege : .asciiz "Hello Assembly\n"

.text

	li $v0, 4
	la $a0, myMessege
	syscall