/********************************************************************************
 *                                                                              *
 *                   Architetture dei sistemi di Elaborazione                   *
 *                                                                              *
 ********************************************************************************

 Esercizio: 008
 Descrizione: Conversione di un numero in esadecimale (stringa)

 ********************************************************************************/

#include <stdio.h>


void main()
{
// Variabili
	unsigned int Num = 1254154;
	char Ris[8];


// Blocco assembler
	__asm {
			MOV   EAX,Num			; Copia il numero in EAX
			MOV   ECX,8				; Parte dalla fine della stringa
Ciclo:		MOV   EBX,EAX
			AND   EBX,0000000Fh		; Considera solo i 4 bit meno significativi
			CMP   EBX,10			; I numeri 10..15 diventano lettere 'A'..'F'
			JGE   Lettera
			MOV   EDX,48			; Il codice ascii del carattere '0'
			JMP   Continua
Lettera:	MOV   EDX,55			; Il codice ascii del carattere 'A' è 65
Continua:	ADD   EBX,EDX			; Ora EBX contiene il codice ascii della cifra esadecimale
			MOV   Ris[ECX-1],BL		; Copia il carattere nella stringa
			SHR   EAX,4				; I prossimi 4 bit
			LOOP  Ciclo
	}


// Stampa su video
	{
		unsigned int i;
		for (i=0;i<8;i++) {
			printf("%c",Ris[i]);
		}
		printf("\n");
	}
}