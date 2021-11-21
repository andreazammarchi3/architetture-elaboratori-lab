/********************************************************************************
 *                                                                              *
 *                   Architetture dei sistemi di Elaborazione                   *
 *                                                                              *
 ********************************************************************************

 Esercizio: 003b
 Descrizione: Ricerca di un carattere in una stringa (Seconda versione)

 ********************************************************************************/

#include <stdio.h>


void main()
{
// Variabili
	char Stringa[] = "Questa è una stringa";
	int Lunghezza = sizeof(Stringa)-1;
	char Carattere = 'è';
	int Posizione;


// Blocco assembler
	__asm {
		CLD								; Direzione ricerca: da sinistra a destra
		LEA   EDI,Stringa				; Indirizzo del primo byte di stringa in EDI
		MOV   EDX,EDI					; Copia l'indirizzo anche in EDX
		MOV   AL,Carattere				; Carattere da cercare in AL
		MOV   ECX,Lunghezza				; Numero di caratteri
		REPNE SCASB						; Istruzione di ricerca in una stringa
		JNZ   NonTr						; Se il flag di zero è settato, ho trovato il carattere
		SUB   EDI,EDX					; Per calcolare la posizione, sottrare l'indirizzo di partenza (EDX) a quello raggiunto (EDI)
		DEC   EDI						; La numerazione dei caratteri parte da 0
		JMP   Fine
NonTr:	MOV   EDI,-1			        ; Carattere non trovato
Fine:   MOV   Posizione,EDI				; Trovato in posizione EDX (-1 se non trovato)
	}


// Stampa su video
	printf("Posizione=%d\n",Posizione);
}
