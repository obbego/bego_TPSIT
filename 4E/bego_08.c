/*Progettare un algoritmo che risolve il seguente problema. Si desidera 
calcolare la somma delle radici quadrate di N valori numerici inseriti 
dall’utente, con N inserito in input. 
L’algoritmo deve stampare la somma calcolata. L’algoritmo deve terminare
con un messaggio di errore quando viene inserito un numero che non
permette di effettuare il calcolo (nel dominio dei numeri reali).*/

#include <stdio.h>
#include <math.h> //per la funzione sqrt()

int main(int argc, char *argv[]) {
    //dichiarazione variabili
	double n = 0, somma = 0;
	int nInseriti = 0, i;
    
	do{
    	printf("Quanti numeri vuoi inserire? (deve essere maggiore di 0)\n");
    	scanf("%d", &nInseriti);
	} while (nInseriti <= 0);
	
	//inizio ciclo
    for (i = 0; i < nInseriti; i++) {
        
		printf("Inserisci il %d numero: \n", i+1);
        scanf("%lf", &n); //uso lf perche con f non mi prende i numeri
		//controllare se il numero è <0
        if (n < 0)
		{
            printf("Errore: fare la radice di un numero negativo non possibile.\n");
            break;
        }
        else 
		{
			somma += sqrt(n);	
		}
    }
    printf("La somma equivale a: %f", somma);
    
	return 0;
}

