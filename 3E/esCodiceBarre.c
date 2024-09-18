/*I codici a barre dei prodotti sono composti da 13 cifre, 
di cui l'ultima e' una cifra di controllo che si determina a 
partire dalle prime 12 (il codice vero e proprio) applicando le seguenti regole:
1)moltiplicare per 3 tutte le cifre in posizione dispari;
2)moltiplicare per 1 tutte le cifre in posizione pari;
3)sommare tra loro tutti i 12 valori così ottenuti;
4)calcolare il resto della divisione per 10 della somma ottenuta;
Codificare in linguaggio C un programma che, a paqrtire da un vettore di 12 e
lementi corrispondenti alle cifre di un codice a barre restituisca la cifra di controllo.*/

//importazione libreria i/o
#include <stdio.h>
//inizio main
int main ()
{
    //dichiarazione variabili
    int lunghezzaCodice = 13, moltiplicDispari = 3, posDispari = 0, moltiplicPari = 1, posPari = 0, cifraFinal = 0;
    //ho messo i moltiplicatori e la lunghezza come variabile perchè in caso qualcuno voglia modificare quei valori puo farlo facilmente solo 1 volta
    
    //dichiarazione vettore per il codice a barre
    int codiceB [lunghezzaCodice];

    //ciclo per: popolare l'array e dividere in cifre pari/dispari (pov:utente)
    for (int i = 0; i < lunghezzaCodice-1; i++)
    {
        //ciclo per controllare che la cifra inserita sia una cifra e non un numero (negativo o > 9)
        do{
        //chiedere in input la cifra
        printf("Inserisci la %d/12 cifra del codice a barre: ", i+1);
        scanf("%d", &codiceB[i]); 
        //controllo della valdita della cifra
        if (codiceB[i] > 9 || codiceB[i] < 0)
            //comunicare l'errore
            printf("Il numero inserito non è una cifra (1 solo numero), RINSERISCI\n\n");
        } while (codiceB[i] > 9 || codiceB[i] < 0);
        //ripetere fino a quando il valore non è accettabile

        if (i % 2 ==0) //controllo se pari o dispari (punto di vista dell'utente)
        posDispari = (codiceB[i] * moltiplicDispari) + posDispari;
        else // nell'altro caso
        posPari = (codiceB[i] * moltiplicPari) + posPari;
    }

    //calcolo la cifra finale e poi l'aggiungo all'array
    cifraFinal = (posDispari + posPari) % 10;
    codiceB[lunghezzaCodice-1] = cifraFinal;
    //per semplificare potevo fare anche cosi: codiceB[lunghezzaCodice-1] = (posDispari + posPari) % 10;  UTILIZZANDO UNA VARIABILE IN MENO

    //stampare a schemo il codice completo
    printf("\n\nCODICE COMPLETO: ");
    for(int i = 0; i < lunghezzaCodice; i++)
    printf("%d", codiceB[i]);

    return 0;
}