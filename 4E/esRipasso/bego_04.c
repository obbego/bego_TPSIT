/*Progettare un algoritmo che effettui la lettura da tastiera di una serie
di coppie di valori numerici reali (sia positivi che negativi che zero).
Per ciascuna coppia, l’algoritmo deve calcolare e stampare il valore
della radice quadrata del rapporto tra il valore maggiore e quello
minore dei due. Il programma termina quando vengono inseriti dei valori
che non permettono di svolgere il calcolo nel dominio dei numeri reali.
Prima di terminare si richiede di stampare un messaggio che indichi la
ragione per cui non è stato possibile svolgere il calcolo.*/

#include <stdio.h>
#include <math.h> //per la funzione sqrt()

int main() {
    //dichiarazione variabili
    int n1=0, n2=0;
	double rapporto=0, radice=0;
    //inizio ciclo
    while (1) {
        printf("\nInserisci il primo numero: ");
        scanf("%d", &n1);
        printf("Inserisci il secondo numero: ");
        scanf("%d", &n2);
        
		//controllare se il numeratore è zero
        if ((n1<n2 && n1==0) || (n2<n1 && n2==0) || (n1==0 && n2==0)){
            printf("Errore: dividere per zero non possibile.\n");
            break;
        }
        //determinare il maggiore e il minore
        if (n1>n2) {
            rapporto=(double)n1/(double)n2;
        } else {
            rapporto=(double)n2/(double)n1;
        }

        //controllare se il rapporto è negativo
        if (rapporto < 0) {
            printf("Errore: impossibile calcolare la radice quadrata di un numero negativo.\n");
            break;
        }

        //calcolare la radice quadrata del rapporto
        radice = sqrt(rapporto);
        printf("La radice quadrata del rapporto tra il maggiore e il minore è: %f\n", radice);
    }
    return 0;
}

