.data
vetor: .word 1222,0,96,8,7,23,44,,2,52,123,345,2345,456,234,11,223,59
tam: .word 17

.text


j start


troca:
	#t0 terá endereço A[j]
	#t1 terá A[j]
	# t2 tera endereço a[j+1]
	# t3 tera a[j+1]
	sll $t0,$a1,2
	add $t0,$a0,$t0
	lw $t1,0($t0)
	
	sll $t2,$a2,2
	add $t2,$a0,$t2
	lw $t3,0($t2)
	
	sw $t3,0($t0)
	sw $t1,0($t2)
	
	jr $ra




bubblesort:
subi $sp,$sp,24
sw $s0,0($sp) # i
sw $s1,4($sp) # trocado
sw $s2,8($sp) # tam
sw $a1,12($sp)
sw $a2,16($sp)
sw $ra,20($sp) # guardando ra

add $s2,$zero,$a1
do:

	add $s1,$zero,$zero #trocado = false
	#i = o
	add $s0,$zero,$zero	
	# calculando tam-1
	subi $s2,$s2,1 
	for:
		slt $t0,$s0,$s2
		beqz $t0,ForExit
		
		#carregar a[i] em t0
		#carregar a[i+1] em t1
		
		sll $t0,$s0,2
		add $t0,$a0,$t0
		
		lw $t1,4($t0)
		lw $t0,0($t0)
		
		slt $t3,$t1,$t0  # i+1 < i ?
		beqz $t3,else
		
 		add $a1,$zero,$s0
		addi $a2,$s0,1
		jal troca
		addi $s1,$s1,1
		
		else:
		
		addi $s0,$s0,1
		j for
		
	ForExit:
	beqz $s1, whileExit
	j do
whileExit:
		
lw $s0,0($sp)
lw $s1,4($sp)
lw $s2,8($sp)
lw $a1,12($sp)
lw $a2,16($sp)
lw $ra,20($sp)
addi $sp,$sp,24

jr $ra



start:

	#carregar endereço base em a0 e tamanho em a1
la $a0,vetor
lw $a1,tam
	
jal bubblesort
	
