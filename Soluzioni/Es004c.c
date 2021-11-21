/********************************************************************************
 *                                                                              *
 *                   Architetture dei sistemi di Elaborazione                   *
 *                                                                              *
 ********************************************************************************

 Esercizio: 004
 Descrizione: Dato un numero, dire se Ã¨ una potenza di due

 ********************************************************************************/

#include <stdio.h>


void main()
{
// Variabili
	unsigned int Num = 0x80000001;
	unsigned int Ris;	// Risultato: 1 se Ã¨ pot. di 2, 0 altrimenti


// Blocco assembler
	__asm
	{
		XOR		EBX,EBX			; Azzero Ris
		POPCNT 	EAX,Num			; Memorizzo in EAX il numero di bit uguali a 1 in Num
		CMP 	EAX,1			; Ce nÃ© solo 1?
		JE 		Pot				; E' una pot. di 2
		JMP 	Fine			; Non Ã¨ una pot. di 2
Pot:
		INC   	EDX				; E' una potenza di due: imposta il risultato a 1
Fine:
		Mov 	Ris,EBX			; Risultato in Ris
	}


// Stampa su video
	printf("Ris=%d\n",Ris);
}
