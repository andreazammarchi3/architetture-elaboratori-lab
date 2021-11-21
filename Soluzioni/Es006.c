/********************************************************************************
 *                                                                              *
 *                   Architetture dei sistemi di Elaborazione                   *
 *                                                                              *
 ********************************************************************************

 Esercizio: 006
 Descrizione: Calcolare la paritÃ  di un vettore di byte

 ********************************************************************************/

#include <stdio.h>


void main()
{
	// Variabili
	unsigned char Vettore[] = { 3,7,3,7,5 };
	unsigned int Lung = sizeof(Vettore) / sizeof(Vettore[0]);
	int Ris; // 0: paritÃ  pari, 1: paritÃ  dispari

// Blocco assembler
	__asm
	{
		XOR EAX, EAX				//Somma
		MOV ECX, Lung				//Lunghezza del vettore
Ciclo1:
		MOV BL, Vettore[ECX - 1]	//Un byte per volta (partendo dalla fine)
Ciclo2:
		CMP BL, 0					//Verifico se Ã¨ 0
		JE ProssimoByte				//Se Ã¨ zero ho finito di contare i bit a 1 per il byte corrente
		TEST BL, 1					//Azzera tutti i bit tranne il meno significativo aggiornando solo le flag
		JZ ProssimoBit				//Se il bit meno significativo Ã¨ 0 non devo incrementare Somma
		INC EAX						//Altrimenti incrementa il numero di bit a 1 trovati (Somma)
ProssimoBit:
		SHR BL, 1					//Sposta tutti i bit di una posizione verso destra
		JMP Ciclo2					//Riparte il ciclo di valutazione del bit meno significativo

ProssimoByte:
		LOOP Ciclo1					//Valuta tutti i byte di Vettore fino a quando ECX Ã¨ 0

		AND EAX, 1					//Per controllare se EAX Ã¨ pari o dispari
		MOV Ris, EAX				//Ris Ã¨ 1 se il numero di bit a uno Ã¨ dispari, 0 altrimenti
	}

	// Stampa su video
	printf("Ris=%d\n", Ris);
}
