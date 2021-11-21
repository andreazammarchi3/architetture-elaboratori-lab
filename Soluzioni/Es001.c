/********************************************************************************
 *                                                                              *
 *                   Architetture dei sistemi di Elaborazione                   *
 *                                                                              *
 ********************************************************************************

 Esercizio: 001
 Descrizione: Moltiplicazione di due numeri mediante somme ripetute

 ********************************************************************************/

#include <stdio.h>


void main()
{
// Variabili
	unsigned short Num1 = 3;
	unsigned short Num2 = 5;
	unsigned int Prodotto;


// Blocco assembler
	__asm {
		SUB  EAX,EAX		; Azzera EAX
		SUB  EBX,EBX		; Azzera EBX
		SUB  ECX,ECX		; Azzera ECX
		MOV  BX,Num1		; Moltiplicando in BX (EBX)
		MOV  CX,Num2		; Moltiplicatore in CX
		JCXZ Fine			; Se CX è zero, non devo fare nulla
Ciclo:	ADD  EAX,EBX		; Somma il moltiplicando al risultato parziale
		LOOP Ciclo			; Decrementa CX e ripete se non è zero
Fine:	MOV  Prodotto,EAX	; Risultato finale in Prodotto
	}


// Stampa su video
	printf("Prodotto=%u\n",Prodotto);
}
