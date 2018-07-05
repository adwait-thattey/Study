.data
	myInt : .word 123
	myFloat : .float 12.365
	myDouble : .double 1963.157298246288382
	zeroDouble : .double 0.0
	space : .byte ' '
.text

	li $v0,1
	lw $a0,myInt
	syscall
	
	li $v0,4
	la $a0,space
	syscall
	
	li $v0,2
	lwc1 $f12,myFloat
	syscall
	
	li $v0,4
	la $a0,space
	syscall
	
	#ldc1 $f2,myDouble
	#ldc1 $f0,zeroDouble
	
	#add.d $f12,$f2,$f0
	
	li $v0,3
	ldc1 $f12,myDouble
	syscall
	