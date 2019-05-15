.text

main:
	jal getc
	move $a0, $v0
	jal putc
getc:
	lui $t0, 0xffff 	#Direc. del registro de control del teclado
	#li $t1, 0 		#Inicia un contador de espera
	b_espera:
		lw $t2, ($t0) 		#Lee registro control del teclado
			      		#SINCRONIZACIÓN:
		andi $t2, $t2, 1 	#Extrae el bit de ready 
		#addiu $t1, $t1, 1  	#Incrementa el contador 
					#(cuenta las iteraciones)
		beqz $t2, b_espera 	#Si cero no hay carácter
					#continuamos esperando
		lw $v0, 4($t0)		#Lee registro de datos del teclado
					#Codigo de tecla guardado en $v0
		jr $ra
		
putc:
	#Carácter de salida en $a0
	lui $t3,0xffff	#ffff0000; SELECCIÓN
	b_espera2:
		lw $t3, 8($t4)		#registre control 
		andi $t3, $t3, 0x0001 	#bit de ready SINCRONIZACIÓN
		beq $t3, $0, b_espera2
		sw $a0, 12($t4)



end: 
	li $v0, 10
	syscall
