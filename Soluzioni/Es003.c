/********************************************************************************
 *                                                                              *
 *                   Architetture dei sistemi di Elaborazione                   *
 *                                                                              *
 ********************************************************************************

 Esercizio: 003
 Descrizione: Ricerca di un carattere in una stringa

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
		MOV  DL,Carattere				; Carattere da cercare in DL
		MOV  ECX,Lunghezza				; Numero di caratteri
		XOR  EBX,EBX					; Azzera EBX
Ciclo:	CMP  EBX,ECX					; Ho superato la lunghezza ?
		JGE  NonTr
		MOV  AL,Stringa[EBX]			; Copia in AL il carattere EBX-esimo
		CMP  AL,DL						; Confronta i caratteri
		JE   Fine						; Trovato!
		INC  EBX						; Passa al carattere successivo
		JMP  Ciclo
NonTr:	MOV  EBX,-1				        ; Carattere non trovato
Fine:	MOV  Posizione,EBX				; Trovato in posizione EBX (-1 se non trovato)
	}


// Stampa su video
	printf("Posizione=%d\n",Posizione);
}
