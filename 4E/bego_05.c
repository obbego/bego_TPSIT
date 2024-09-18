/*Progettare un algoritmo che effettui le seguenti operazioni:
• continui a leggere da tastiera una serie di terne di valori interi A ,
B e C finchè non vengono inseriti dei valori tali per cui A + B < C
• conteggi il numero di volte in cui la differenza tra A e B è pari, dispari, e quando è nulla
• prima di terminare, visualizzi il valore dei valori conteggiati*/

#include <stdio.h>

int main() {
    //dichiarazione variabili
    int a=0, b=0, c=0, pari=0, dispari=0, null=0; 
    
	//inizio ciclo
    while (1) {
        printf("\nInserisci il valore di A: ");
        scanf("%d", &a);
        printf("Inserisci il valore di B: ");
        scanf("%d", &b);
        printf("Inserisci il valore di C: ");
        scanf("%d", &c);
		
		//controllare la condizione (A + B < C)
        if (a + b < c) {
            printf("\nchiusura del programma: A + B < C\n");
            break;
        }
        
		int differenza = a-b;
        
        if (differenza==0) {
            null++;
        } else if (differenza%2==0) {
            pari++;
        } else {
            dispari++;
        }
    }
    //stampa dei risultati
    printf("Differenze pari: %d\n", pari);
    printf("Differenze dispari: %d\n", dispari);
    printf("Differenze nulle: %d\n", null);

    return 0;
}


