//importazione librerie
#include <stdio.h> //input-output
#include <ctype.h> //funzione tolower
#include <string.h>//stringhe + funzioni stringhe

//pag 219 - 235 STUDIA VACANZE
// CONSEGNA ESERCIZIO:
// Scrivere un programma in C che dopo aver inserito una stringa a piacere permetta di:
// 1) Eliminare 1 carattere scelto dall’utente (o più di 1 se si ripetono);
// 2) Eliminare 1 carattere scelto dall’utente in base alla sua posizione;
// 3) Aggiungere 1 carattere scelto dall’utente alla fine della stringa;

//inizio main
int main()
{
    //dichiarazione variabili
    char stringa1[30];
    char stringa2[30];
    char carattereAggiunto[1];
    char carattereEliminato;
    int j = 0, lunghezzaMax = 0, posElim = 0;

    //chiedere in input la stringa
    printf("Inserisci la stringa: ");
    //attribuire il valore alla variabile
    scanf("%s", stringa1);

    //convertire la stringa in minuscolo per facilitare il controllo
    for (int i = 0; i < strlen(stringa1); i++) {
        stringa1[i] = tolower(stringa1[i]);
    }

    //chiedere in input il carattere da eliminare
    printf("Digita il carattere da eliminare: ");
    scanf(" %c", &carattereEliminato); //aggiungere spazio per evitare problemi di buffer
    //convertire il carattere in minuscolo per facilitare il controllo
    carattereEliminato = tolower(carattereEliminato);

    // Eliminazione del carattere scelto dall'utente
    for (int i = 0; i < strlen(stringa1); i++) {
        if (stringa1[i] != carattereEliminato) {
            stringa2[j] = stringa1[i];
            //contatore parallelo
            j++;
        }
    }
    //impostare il terminatore di stringa per evitare di stampare caratteri strani
    stringa2[j] = '\0'; // terminatore di stringa

    //dare in output la stringa modificata
    printf("Stringa dopo l'eliminazione: %s\n", stringa2);
    printf("\n");
    
    
    /*printf("Inserisci la posizione del carattere da eliminare:\nPosizione max: %d", strlen(stringa2)); 
    mi da warning cosi, quindi mi tocca utilizzare una variabile in più per evitare il warning*/
    
    //attribuire a lMax il valore di strlen(stringa2) per comunicare all'utente il numero massimo che puo inserire
    lunghezzaMax = strlen(stringa2);
    printf("Inserisci la posizione del carattere da eliminare:\nPosizione max: %d\nse non vuole cancellare nulla inserisca un valore > della posizione Max o < 0\n", lunghezzaMax);
    scanf("%d", &posElim);
    
    //eliminare il carattere partendo da quello che si desidera eliminare
    for (int i = posElim-1; i < strlen(stringa2); i++)
    {
        //quando si è giunti alla fine mettere il terminatore di Stringa
        if (i ==  strlen(stringa2)-1) {
            stringa2[i] = '\0';
        }
        else{
            stringa2[i] = stringa2[i+1]; 
        }
    }
    
    //dare in output la stringa modificata
    printf("Stringa dopo l'eliminazione: %s\n", stringa2);
    printf("\n");
    
    
    //chiedere in input il carattere
    printf("Inserisci il carattere da aggiungere in ultima posizione:");
    /*scanf("%c", &carattereAggiunto);  
    assegnandolo come char mi da problemi nell'uso della funzione strcat, per evitare warning leggere carattereAggiunto come string*/
    scanf("%s", carattereAggiunto);  
    
    //usare la funzione strcat per concatenare le 2 stringhe
    strcat(stringa2,carattereAggiunto);
    
    //dare in output la stringa modificata
    printf("Stringa dopo l'aggiunta: %s\n", stringa2);
    printf("\n");


    return 0;
}
