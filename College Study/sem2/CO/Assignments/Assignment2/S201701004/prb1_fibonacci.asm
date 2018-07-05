.data

	prompt1: .asciiz "Enter the number of terms\n"
	prompt2: .asciiz "The fibonacci sequence is : \n"
	spc: .byte ' '

.text

	li $v0,4
	la $a0,prompt1
	syscall
	
	li $v0,5
	syscall
	
	move $s0,$v0
	
	addi $t0,$zero,0
	addi $t1,$zero,1
	
	li $v0,1
	addi $a0,$t0,0
	syscall
	
	li $v0,4
	la $a0,spc
	syscall
		
	li $v0,1
	addi $a0,$t1,0
	syscall
	
	sub $s0,$s0,2
	
	loop :
		add $t1,$t1,$t0
		sub $t0,$t1,$t0
		blez $s0,end
		
		li $v0,4
		la $a0,spc
		syscall
		
		li $v0,1
		addi $a0,$t1,0
		syscall
		
		sub $s0,$s0,1
		j loop
	
	end :
		li $v0,10
		syscall			