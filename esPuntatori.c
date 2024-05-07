/*Dopo aver letto un vettore di N elementi 
utilizzando i puntatori calcolare la media 
del vettore e determinare il massimo ed il minimo.*/
#include <stdio.h>

int esPuntatori(){
    //dichiarazioni variabili
    int nMax = 0, somma = 0, min = 0, max = 0;
    float media = 0;

    do {
        //chiedere la dimensione dell'array
        printf("Quanti numeri vuoi inserire? ");
        scanf ("%d", &nMax);
        //controllo la dimensione sia valida
        if (nMax < 0)
        printf("Un array non puo avere dimensione negativa\n");
    } while ((nMax < 0)); //chiedo fino a quando la dimensione non è valida
    
    //creo l'array
    int array[nMax];
    // creo un puntatore che punta all'array[0]
    int *p = array;
    
    //riempio l'array e controllo i dati
    for (int i = 0; i < nMax; i++)
    {
        //chiedo l'inserimento del numero
        printf("Inserisci il %d numero: ", (i+1));
        scanf("%d", p + i);
        //aggiungo alla somma il corrispondente valore appena inserito, attraverso il puntatore
        somma += *(p+i);
        
        //se è il primo numero inserito associo min e max a quel numero
        if (i == 0){
            min = *(p+i);
            max = *(p+i);
        }
        else{
        //controllo se il numero è minore del min attuale
        if (min > *(p+i))
        min = *(p+i);
        //controllo se il numero è maggiore del max attuale
        else if (max < *(p+i))
        max = *(p+i);
        }
    }

    //calcolo la media facendo il cast a float
    media = (float)somma/nMax;
    //stampo a schermo i risultati
    printf("La media dei numeri corrisponde a: %.2f\n", media);
    printf("Il minimo valore e': %d\n", min);
    printf("Il massimo valore e': %d\n", max);
    
    return 0;
    }