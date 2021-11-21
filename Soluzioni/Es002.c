/********************************************************************************
 *                                                                              *
 *                   Architetture dei sistemi di Elaborazione                   *
 *                                                                              *
 ********************************************************************************

 Esercizio: 002
 Descrizione: Algoritmo per l'estrazione di radice

 ********************************************************************************/

#include <stdio.h>


void main()
{
// Variabili
	unsigned int Num = 10;
	unsigned int Radice;


// Blocco assembler
	__asm {
		XOR  EDX,EDX		; Azzera EDX
		MOV  ECX,01h		; Numero da sottrarre inizialmente
		MOV  EAX,Num		; Numero di cui calcolare la radice
Ciclo:	SUB  EAX,ECX		; Sottrae il numero dispari ECX
		JL   Fine			; Se minore di zero, esce
		INC  EDX			; Incrementa il risultato
		ADD  ECX,02h		; Il nuovo numero dispari da sottrarre
		JMP  Ciclo			; Ripete
Fine:	MOV  Radice,EDX		; Copia il risultato
	}


// Stampa su video
	printf("Radice=%d\n",Radice);
}
