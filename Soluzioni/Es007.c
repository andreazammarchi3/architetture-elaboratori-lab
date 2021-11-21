/********************************************************************************
 *                                                                              *
 *                   Architetture dei sistemi di Elaborazione                   *
 *                                                                              *
 ********************************************************************************

 Esercizio: 007
 Descrizione: Ordinamento "ingenuo" di un vettore

 ********************************************************************************/

#include <stdio.h>


void main()
{
// Variabili
	int Vettore[] = {3,7,3,7,5,1,4,-3,-7,-9,2,6};
	//int Vettore[] = {3};
	unsigned int Lung = sizeof(Vettore)/sizeof(Vettore[0]);


// Blocco assembler
	__asm {		
			MOV   ECX,Lung				; Lunghezza del vettore in ECX
			DEC   ECX					; ECX va da Lung-1 a zero
Ciclo:		MOV   EAX,Vettore[4*ECX]	; Inizializza il massimo (EAX) con l'elemento in posizione ECX
			MOV   ESI,ECX				; Inizializza la posizione del massimo (ESI) a ECX
			MOV   EDI,ECX				; EDI è l'indice del ciclo interno
CicloInt:	DEC   EDI					; Elemento precedente
			JS	  Prossimo				; Si ferma quando EDI è negativo (-1)
			MOV   EBX,Vettore[4*EDI]	; Copia l'elemento EDI-esimo in EBX
			CMP   EBX,EAX				; Confronta con il (presunto) massimo EAX
			JLE   CicloInt				; EAX è ancora il massimo
			MOV   EAX,EBX				; Ho trovato un nuovo massimo: lo copio in EAX
			MOV   ESI,EDI				; Salvo anche il suo indice in ESI
			JMP   CicloInt
Prossimo:	MOV   EBX,Vettore[4*ECX]	; Scambio gli elementi del vettore in posizione ECX e ESI
			MOV   Vettore[4*ECX],EAX	; EAX Conteneva già l'elemento in posizione ESI
			MOV   Vettore[4*ESI],EBX
			DEC   ECX
			JNS   Ciclo					; Finchè ECX maggiore uguale a zero
	}


// Stampa su video
	{
		unsigned int i;
		for (i=0;i<Lung;i++) {
			printf("Vettore[%2d] = %d\n",i,Vettore[i]);
		}
	}
}
