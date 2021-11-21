/********************************************************************************
 *                                                                              *
 *                   Architetture dei sistemi di Elaborazione                   *
 *                                                                              *
 ********************************************************************************

 Esercizio: 006b
 Descrizione: Calcolare la parità di un vettore di byte (Seconda Versione)

 ********************************************************************************/

#include <stdio.h>


void main()
{
// Variabili
	unsigned char Vettore[] = {3,7,3,7,5,1,4};
	unsigned int Lung = sizeof(Vettore)/sizeof(Vettore[0]);
	int Ris; // 0: parità pari, 1: parità dispari


// Blocco assembler
	__asm {
		MOV   ECX,Lung						; Lunghezza del vettore in ECX
		XOR   EDX,EDX						; Azzera EDX
Ciclo:	XOR   DL,Vettore[ECX-1]				; xor con un byte per volta (partendo dalla fine)
		LOOP  Ciclo							; Continua finchè ECX è 0
		TEST  DL,DL							; Il byte in DL ha la stessa parità dell'intera stringa
		LAHF								; Carica i flag in AH
		NOT   AH							; Il flag di parità è 1 se la parità è pari: lo inverto
		SHR   EAX,10						; Sposto il flag di parità sul primo bit di EAX
		AND   EAX,1							; Mantengo solo il primo bit
		MOV   Ris,EAX						; Ris è 1 se il numero di bit a uno è dispari, 0 altrimenti
	}


// Stampa su video
	printf("Ris=%d\n",Ris);
}
