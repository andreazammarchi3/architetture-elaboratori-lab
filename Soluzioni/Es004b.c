/********************************************************************************
 *                                                                              *
 *                   Architetture dei sistemi di Elaborazione                   *
 *                                                                              *
 ********************************************************************************

 Esercizio: 004b
 Descrizione: Dato un numero, dire se è una potenza di due (Seconda versione)

 ********************************************************************************/

#include <stdio.h>


void main()
{
// Variabili
	unsigned int Num = 0x800F0000;
	unsigned int Ris;	// Risultato: 1 se è pot. di 2, 0 altrimenti


// Blocco assembler
	__asm {
		XOR   EDX,EDX		; Risultato in EDX: suppongo 0
		MOV   EAX,Num		; Copia il numero in EAX e in EBX
		MOV   EBX,EAX
		NEG   EAX			; Complemento a 2
		JZ    Fine			; Se è zero non è una potenza di 2
		AND   EAX,EBX		; Esegue l'and bit-a-bit
		CMP   EAX,EBX		; Confronta
		JNE   Fine
		INC   EDX			; EAX e EBX sono uguali: è una potenza di 2, imposta EDX a 1
Fine:	MOV   Ris,EDX
	}


// Stampa su video
	printf("Ris=%d\n",Ris);
}
