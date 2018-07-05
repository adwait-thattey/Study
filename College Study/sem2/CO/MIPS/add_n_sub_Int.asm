.data
	integer1: .word 23
	integer2: .word 25
	newLine: .byte '\n'
.text
	li $v0,1
	lw $t1,integer1
	lw $t2,integer2
	add $a0,$t1,$t2
	syscall
	
	li $v0,4
	la $a0,newLine
	syscall
	
	li $v0,1
	lw $t1,integer1
	lw $t2,integer2
	sub $a0,$t1,$t2
	syscall
	
	