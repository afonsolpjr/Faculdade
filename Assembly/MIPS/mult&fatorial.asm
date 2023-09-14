.data
	
.text
	j start
	#Tarefa: multiplicar n1 por n2, ambos inteiros positivos
	multiplica:
		
		#inicializando pilha para 3 valores
		subi $sp,$sp,12
		sw $s0,0($sp)
		sw $t0,4($sp)
		sw $t1,8($sp)
		
		#iniciando valor de retorno
		add $v0,$zero,$zero       
		
		#Testando se são 0
		beqz $a0,Exit
		beqz $a1,Exit
		
		#Vendo qual o maior e colocando em $s0
		slt $t0,$a0,$a1
		beqz $t0,else          
		#caso a1>a0
		add $s0,$a1,$zero
		add $t1,$a0,$zero
		j StartLoop
		
			else:
			add $s0,$a0,$zero
			add $t1,$a1,$zero
		
		#      s0 tem o maior valor, e t1 o menor (que será diminuido)
		StartLoop:
		beqz $t1,Exit
		add $v0,$v0,$s0
		subi $t1,$t1,1
		j StartLoop
	
		Exit:
		lw $s0,0($sp)
		lw $t0,4($sp)
		lw $t1,8($sp)
		addi $sp,$sp,12
		jr $ra
		
	
	fatorial_nao_recursivo:        #recebe num >=1
		#guardando registradores, inclusive ra
		subi $sp,$sp,24
		sw $t0,0($sp)
		sw $s0,4($sp)
		sw $s1,8($sp)
		sw $ra,12($sp)
		sw $a0,16($sp)
		sw $a1,20($sp)
		

		addi $s1,$zero,1
		addi $s0,$zero,1
		add $t0,$a0,$zero
		while:      #enquanto t0 > 1
		
		beq $t0,$s1,Exit2
		add $a0, $t0, $zero
		add $a1, $s0, $zero
		jal multiplica
		add $s0,$v0,$zero
		addi $t0,$t0,-1
		j while
		
		Exit2:
		add $v0,$s0,$zero
		lw $t0,0($sp)
		lw $s0,4($sp)
		lw $s1,8($sp)
		lw $ra,12($sp)
		lw $a0,16($sp)
		lw $a1,20($sp)
		addi $sp,$sp,24
		
		jr $ra
		
		
		
		
		
		
	start:
	
		addi $v0,$zero, 5
		syscall
		
		add $a0,$v0,$zero
		jal  fatorial_nao_recursivo