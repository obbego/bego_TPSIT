/*Progettare un algoritmo che effettui le seguenti operazioni:
• legga da tastiera una coppia di valori interi A e B con A<B;
• continui a leggere da tastiera una serie di valori interi, terminando 
quando il valore letto è al di fuori dell’intervallo [A, B];
• conteggi la media dei valori letti;
• prima di terminare, stampi il valore calcolato.*/

#include <stdio.h>

int main() {
    //dichiarazione variabili
    int a=0, b=0, n=0, somma=0, i=0; 
    double media=0;
    
    printf("\nInserisci il valore di A: ");
    scanf("%d", &a);
    
	do{
	printf("Inserisci il valore di B (deve essre > di A): ");
    scanf("%d", &b);
	if(a>=b)
		printf("Il numero inserito non rispetta i requisiti\n");
    } while (a>=b);
    
	do{
	printf("Inserisci il %d numero: ", i+1);
    scanf("%d", &n);
    if (n<a || n>b){
       	break;
	}
	else {
		somma= somma+n;
		i++;
	}
	}while (n>=a && n<=b);

	media=(double)somma/i;
    printf("La media: %f\n", media);


    return 0;
}


