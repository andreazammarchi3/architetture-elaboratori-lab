/********************************************************************************
 *                                                                              *
 *                   Architetture dei sistemi di Elaborazione                   *
 *                                                                              *
 ********************************************************************************

 Esercizio: 004
 Descrizione: Dato un numero, dire se è una potenza di due

 ********************************************************************************/

#include <stdio.h>


void main()
{
// Variabili
	unsigned int Num = 0x80000001;
	unsigned int Ris;	// Risultato: 1 se è pot. di 2, 0 altrimenti


// Blocco assembler
	__asm {
			MOV   ECX,Num		; Copia il numero in ECX
			XOR   EDX,EDX		; Risultato in EDX: inizialmente suppone 0 (non potenza di 2)
			JECXZ Fine			; Se è zero, non è una pot. di 2
Ciclo:		TEST  ECX,1			; Controlla il bit meno significativo
			JZ    Continua		; Se è zero, passa al successivo
			CMP   ECX,1			; E' esattamente 1?
			JE    Pot			; E' una pot. di 2
			JMP   Fine			; Non è una pot. di 2
Continua: 	SHR   ECX,1			; Sposta i bit a destra in ECX
			JMP   Ciclo			; Prova con il bit seguente
Pot:		INC   EDX			; E' una potenza di due: imposta il risultato a 1
Fine:		MOV   Ris,EDX		; Risultato in Ris
	}


// Stampa su video
	printf("Ris=%d\n",Ris);
}
