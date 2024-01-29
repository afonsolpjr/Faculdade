.data
vetor: .word 1222,96,8,7,23,44,0,2,52,123,345,2345,456,234,11,223,59,9,7
tam: .word 19

.text


j start
	
quicksort:
	#usaremos 3 variaveis
	# a0  = vec
	# a1 = tamanho do vetor
subi $sp,$sp,16
sw $s0,0($sp) # i
sw $s1,4($sp) # j
sw $s2,8($sp) # endereço v[j]
sw $s3,12($sp) # endereço v[j+1]

addi $s0,$zero,1
for1:
	add $s1,$zero,$zero
	for2:
		#carregar v[j] em t0
		sll $s2,$s1,2
		add $s2,$s2,$a0
		lw $t0,0($s2)
		#carregar v[j+1] em t1
		addi $s3,$s2,4
		lw $t1,0($s3)
		
		slt $t2,$t0,$t1
		bne $t2,$zero,else
		beq $t0,$t1,else
	
		#substituir
		
		sw $t0, 0($s3)
		sw $t1, 0($s2)
		
		else:
	
		addi $s1,$s1,1
		#checa condicoes for2
		sub $t3,$a1,$s0
		slt $t0,$s1,$t3
		bne $t0,$zero,for2
		#fim do for2
	
	addi $s0,$s0,1
	#checa condicao for1
	slt $t0,$s0,$a1
	bne $t0,$zero,for1  
	# fim do for1
		
	
lw $s0,0($sp)
lw $s1,4($sp)
lw $s2,8($sp)
lw $s3,12($sp)
addi $sp,$sp,16

jr $ra

start:

	#carregar endereço base em a0 e tamanho em a1
la $a0,vetor
lw $a1,tam
	
jal quicksort
	