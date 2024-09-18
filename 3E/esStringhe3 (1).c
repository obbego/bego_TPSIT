//importazione librerie
#include <stdio.h> //input-output
#include <ctype.h> //funzione tolower
#include <string.h>//stringhe + funzioni stringhe

// CONSEGNA ESERCIZIO:
/*
Scrivere
un programma in C che dopo aver inserito una stringa a piacere
permetta di:

1)Inserire un carattere, scelto dall’utente in una posizione sempre
scelta dall’utente;

2)Sostituisca un carattere, scelto dall’utente, con il seguente: X.
*/

//inizio main
int main()
{
    //dichiarazione variabili
    char stringa1[30];
    char carattereAggiunto;
    int posAgg = 0, posAggX = 0;

    //chiedere in input la stringa
    printf("Inserisci la stringa: ");
    //attribuire il valore alla variabile
    scanf("%s", stringa1);

    //convertire la stringa in minuscolo per facilitare il controllo
    for (int i = 0; i < strlen(stringa1); i++) {
        stringa1[i] = tolower(stringa1[i]);
    }

    //chiedere in input il carattere da aggiungere
    printf("Digita il carattere da aggiungere: ");
    scanf(" %c", &carattereAggiunto); //aggiungere spazio per evitare problemi di buffer
    //convertire il carattere in minuscolo per facilitare il controllo
    carattereAggiunto = tolower(carattereAggiunto);
    //chiedere in input la posizione dove aggiungerlo
    printf("Digita la posizione del carattere da aggiungere:\nPosizione min: 1 Posizione max: %ld\nSe superiore o minore non verrà inserito: ", strlen(stringa1));
    scanf(" %d", &posAgg);
    if(posAgg>=1 && posAgg <= strlen(stringa1)){
    // Aggiunta del carattere scelto dall'utente
    for (int i = strlen(stringa1); i >= posAgg; i--) 
    {
        stringa1[i] = stringa1[i - 1];
    }
    stringa1[posAgg-1] = carattereAggiunto;
    
    //impostare il terminatore di stringa per evitare di stampare caratteri strani
    stringa1[strlen(stringa1)] = '\0'; // terminatore di stringa
    }
    //dare in output la stringa modificata
    printf("Stringa dopo l'aggiunta: %s\n", stringa1);
    printf("\n");
    
    //chiedere in input la posizione dove aggiungerlo
    printf("Digita la posizione del carattere da aggiungere:\nPosizione min: 1 Posizione max: %ld\nSe superiore o minore non verrà inserito: ", strlen(stringa1));
    scanf(" %d", &posAggX);
    if(posAggX>=1 && posAggX <= strlen(stringa1)){
    for (int i = strlen(stringa1)-1; i >= posAggX-1; i--) 
    {
       if (i == posAggX-1)
        stringa1[i] = 'X';
       else
        stringa1[i]=stringa1[i];
    }
    }
    //dare in output la stringa modificata
    printf("Stringa dopo la sostituzione: %s\n", stringa1);
    printf("\n");

    return 0;
}