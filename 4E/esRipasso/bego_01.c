/******************************************************************************
Esercizio 1
Progettare un algoritmo che effettui la lettura da tastiera di una serie di coppie di valori numerici.
L'algoritmo deve calcolare e stampare il rapporto tra il valore minore e quello maggiore dei due. Il
programma termina quando uno dei due valori o entrambi sono uguali a zero.
*******************************************************************************/
#include <stdio.h>
int main()
{
    //dichiarazione variabili
    int n1=0, n2=0;
    double ris;
    //inizio ciclo
    do{
    //chiedere in input i dati
    printf("Inserisci il primo numero: ");
    scanf("%d", &n1);
    printf("\nInserisci il secodno numero: ");
    scanf("%d", &n2);
    /*controllare che i numeri siano =! da 0 perche 
    in quel caso esce subito dal ciclo e termina il codice*/
    if (n1==0||n2==0){
    	printf("Hai inserito 0");
    	break;
	}
       
    else if (n1<n2){
        ris = (double)n1/(double)n2;
        printf("\nIl risultato dell'operazioe %d / %d equivale a: %f\n\n", n1, n2, ris);
    	}
    else {
        ris = (double)n2/(double)n1;
        printf("\nIl risultato dell'operazioe %d / %d equivale a: %f\n\n", n2, n1, ris);
    	}
    }
    while(n1!= 0 && n2!=0);
    return 0;
}
