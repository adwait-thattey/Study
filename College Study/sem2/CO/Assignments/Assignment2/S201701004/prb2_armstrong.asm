.data
	enterANumber : .asciiz "Enter A Number\n"
	arm : .asciiz "Armstrong Number\n"
	nArm : .asciiz "Not an Armstrong Number\n"

.text

	main:
		li $v0,4
		la $a0,enterANumber
		syscall
		
		li $v0,5
		syscall
		move $s0,$v0
		
		addi $a1,$s0,0
		
		jal retNumberLength
		
		move $s1,$v1
		addi $a2,$s1,0
		addi $s2,$zero,0
		addi $s7,$zero,10
		addi $s4,$s0,0
		digitLoop:
			blez $s0,digitExit
			div $s0,$s7
			mflo $s0
			mfhi $a1
			jal power
			add $s2,$s2,$v1
			j digitLoop
					
		
		digitExit:
		move $s0,$s4
		beq $s0,$s2,armstrong
		bne $s0,$s1,notArmstrong
		
		li $v0,1
		addi $a0,$s2,0
		syscall
		
		
		li $v0,10
		syscall
		
	retNumberLength:
		move $t0,$a1
		addi $t1,$zero,0
		lenLoop:
			ble $t0, $zero,lenExit
			div $t0,$t0,10
			addi $t1,$t1,1			
			j lenLoop
		lenExit:
		move $v1,$t1	
		jr $ra
	
	power:
		addi $t2,$zero,1
		move $t0,$a1
		move $t1,$a2
		powerLoop:
			blez $t1,powerExit
			mul $t2,$t2,$t0
			subi $t1,$t1,1
			j powerLoop
		powerExit:
		move $v1,$t2
		jr $ra	
	
	armstrong :
		li $v0,4
		la $a0,arm
		syscall
		
		li $v0,10
		syscall
	
	notArmstrong:
		li $v0,4
		la $a0,nArm
		syscall
		
		li $v0,10
		syscall						
		
			
			
	
		
