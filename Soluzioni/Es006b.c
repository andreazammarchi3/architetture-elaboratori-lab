/********************************************************************************
 *                                                                              *
 *                   Architetture dei sistemi di Elaborazione                   *
 *                                                                              *
 ********************************************************************************

 Esercizio: 006
 Descrizione: Calcolare la parità di un vettore di byte

 ********************************************************************************/

#include <stdio.h>


void main()
{
// Variabili
	unsigned char Vettore[] = {3,7,3,7,5};
	unsigned int Lung = sizeof(Vettore)/sizeof(Vettore[0]);
	int Ris; // 0: parità pari, 1: parità dispari


// Blocco assembler
	__asm {
		MOV   ECX,Lung						; Lunghezza del vettore in ECX
		XOR   EDX,EDX						; Azzera EDX
		XOR   EAX,EAX						; Azzera EAX
Ciclo1:	MOV   AL,Vettore[ECX-1]				; Un byte per volta (partendo dalla fine)
Ciclo2:	TEST  AL,AL							; Per verificare se è 0
		JZ    FineC2						; Se è zero ho finito di contare i bit a 1
		MOV   EBX,EAX
		AND   EBX,1							; Azzera tutti i bit tranne il primo
		ADD   EDX,EBX						; EDX conta il numero di bit a uno
		SHR   AL,1							; Si prepara per il bit successivo
		JMP   Ciclo2						; Continua con il bit seguente
FineC2:	LOOP  Ciclo1						; Continua finchè ECX è 0
		AND   EDX,1							; Per controllare se EDX è pari o dispari
		MOV   Ris,EDX						; Ris è 1 se il numero di bit a uno è dispari, 0 altrimenti
	}


// Stampa su video
	printf("Ris=%d\n",Ris);
}
