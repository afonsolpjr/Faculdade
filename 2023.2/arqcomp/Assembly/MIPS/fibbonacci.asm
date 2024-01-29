.text

j start

fib:
	bne $a0,$zero,else1 #caso arg = 0
	add $v0,$zero,$zero
	jr $ra
	else1:
		addi $t0,$zero,1 #caso arg = 1
		bne $a0,$t0,else2
		add $v0,$zero,$t0
		jr $ra
	else2:
		subi $sp,$sp,12  #alocando espaço pra salvar registradores
		sw $s0,0($sp)
		sw $a0,4($sp)
		sw $ra,8($sp)
		
		subi $a0,$a0,1 #fib de n-1
		jal fib
		add $s0,$v0,$zero #guardando fib(n-1)
		subi $a0,$a0,1 # fib (n-2)
		jal fib
		add $v0,$v0,$s0 #retorno = fib(n-1) + fib(n-2)
		
		lw $s0,0($sp) #recuperando registradores
		lw $a0,4($sp)
		lw $ra,8($sp)
		addi $sp,$sp,12
		
		jr $ra
		
		
start:

	addi $v0,$zero, 5
	syscall
		
	add $a0,$zero, $v0
	jal fib

		