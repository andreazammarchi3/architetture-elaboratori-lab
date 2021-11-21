/********************************************************************************
 *                                                                              *
 *                   Architetture dei sistemi di Elaborazione                   *
 *                                                                              *
 ********************************************************************************

 Esercizio: 005
 Descrizione: Somma e media degli elementi in un vettore

 ********************************************************************************/

#include <stdio.h>


void main()
{
// Variabili
	int Vettore[] = {1,2,3,4,5,6,7,8,9,10,1,2,3,-1,-2,-3};
	unsigned int Lung = sizeof(Vettore)/sizeof(int);
	int Somma;
	int Media;


// Blocco assembler
	// N.B. non si considera la possibilità di overflow della somma
	__asm {
		MOV   ECX,Lung					; Numero di elementi
		XOR   EAX,EAX					; Azzera EAX (conterrà la somma)
Ciclo:	ADD   EAX,Vettore[4*ECX-4]		; Gli elementi del vettore sono DWORD (4 byte)
		LOOP  Ciclo						; Continua finchè ECX è zero
		MOV   Somma,EAX					; Copia la somma
		CDQ								; Converte l'intero a 32bit con segno EAX in un interno a 64bit con segno EDX:EAX
		IDIV  Lung						; Divide EDX:EAX per Lung: risultato in EAX
		MOV   Media,EAX					; Copia la media
	}


// Stampa su video
	printf("Somma=%d\n",Somma);
	printf("Media=%d\n",Media);
}
