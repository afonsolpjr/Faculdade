.data

 mensagem : .asciiz "Ola Mundo"
 
.text

	addi $v0,$zero,4
	la $a0,mensagem
	syscall
	