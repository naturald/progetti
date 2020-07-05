DATA SEGMENT PUBLIC
	primoNum DB "inserisci primo numero: ",'$'
	SecondoNum DB "inserisci primo secondo: ",'$'
	val1 DB 0
	val2 DB 0
	risposta DB "la somma e': ",'$'
	a_capo DB "",10,13,'$'
	dieci DB 10
	ris DB 0
	resto DB 0
	molt DB "la moltiplicazione e: ",'$'
	uguali DB "I NUMERI SONO UGUALI",'$'
	diversi DB "I NUMERI SONO DIVERSI",'$'
	cost EQU 5
	ciao DB "ciao",'$'
	arr DB 1,2,3,5,6
	
	
DATA ENDS

CODE SEGMENT 

	ASSUME CS:CODE,DS:DATA
	
PROGRAMMA:
	MOV AX,DATA
	MOV DS,AX
	
	MOV AH,09H
	LEA DX,primoNum
	;MOV DX, OFFSET PRIMA_STRINGA
	; SI PUO ANCHE METTERE QUESTO LEA DX,PRIMA_STRINGA
	INT 21H
	
	MOV AH,01H
	INT 21H
	MOV val1,AL
	SUB val1,48
	
	MOV AH,09H
	LEA DX,a_capo
	INT 21H
	
	MOV AH,09H
	LEA DX,SecondoNum
	INT 21H
	
	MOV AH,01H
	INT 21H
	MOV val2,AL
	SUB val2,48
	
	MOV AH,09H
	LEA DX,a_capo
	INT 21H
	
	MOV AL,val1
	ADD AL,val2

	MOV AH,09H
	LEA DX,risposta
	INT 21H
	
	MOV AH,00H
	DIV dieci
	MOV ris,AL
	MOV resto,AH
	
	MOV AH,02H
	ADD ris,48
	MOV DL,ris
	INT 21H
	
	MOV AH,02H
	ADD resto,48
	MOV DL,resto
	INT 21H
;--------------------------------------------------------------------
	MOV AH,09H
	LEA DX,a_capo
	INT 21H
	
	MOV AH,09H
	LEA DX,molt
	INT 21H
	
	MOV AH,00H
	MOV Al,val1
	MUL val2
	
	DIV dieci
	MOV ris,AL
	MOV resto,AH
	
	MOV AH,02H
	ADD ris,48
	MOV DL,ris
	INT 21H
	
	MOV AH,02H
	ADD resto,48
	MOV DL,resto
	INT 21H
;--------------------------------------------------------------------	
	MOV AH,09H
	LEA DX,a_capo
	INT 21H
	
	MOV AL,val1
	CMP AL,val2
	JNE diver
	
	MOV AH,09H
	LEA DX,uguali
	INT 21H
	
	JMP fine 
	
	diver:
		MOV AH,09H
		LEA DX,diversi
		INT 21H
		
	fine:
;--------------------------------------------------------------------	
	; XCHG puo scambiare il valore tra registro e variabile / registro e registro ma non tra variabile e variabile
;--------------------------------------------------------------------
	MOV AH,09H
	LEA DX,a_capo
	INT 21H	
	
	MOV CL,00H ; ricordarsi di inizializarlo non so perche ma inizia da -1 facendo fare un giro in piu di loop
	inizio:
		CMP CL,5
		JGE finel
		
		MOV AH,09H
		LEA DX,ciao
		INT 21H
		
		MOV AH,09H
		LEA DX,a_capo
		INT 21H
		
		INC CL
		JMP inizio
	
	finel:
	
;--------------------------------------------------------------------
	MOV AH,4CH 
	INT 21H
	

CODE ENDS
END PROGRAMMA