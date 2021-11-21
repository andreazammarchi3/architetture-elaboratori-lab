/********************************************************************************
 *                                                                              *
 *                   Architetture dei sistemi di Elaborazione                   *
 *                                                                              *
 ********************************************************************************

 Esercizio: 001b
 Descrizione: Moltiplicazione di due numeri mediante somme ripetute (Seconda Versione)

 ********************************************************************************/

#include <stdio.h>


void main()
{
// Variabili
	unsigned short Num1 = 60000;
	unsigned short Num2 = 60000;
	unsigned int Prodotto;


// Blocco assembler
	__asm {
		SUB  EAX,EAX		; Azzera EAX
		SUB  EBX,EBX		; Azzera EBX
		SUB  ECX,ECX		; Azzera ECX
		MOV  CX,Num2		; Moltiplicatore in CX
		JCXZ Fine
Ciclo:	ADD  AX,Num1		; Somma il moltiplicando al risultato parziale
		ADC  EBX,0			; Aggiunge un eventuale riporto nel totale a 32 bit (EAX)
		DEC  CX
		JNZ  Ciclo			; Se CX non è 0, ripete
Fine:	SHL  EBX,16			; Somma tutti i riporti nella parte alta di EAX
		ADD  EAX,EBX
		MOV  Prodotto,EAX	; Risultato finale in Prodotto
	}


// Stampa su video
	printf("Prodotto=%u\n",Prodotto);
}
