/*Scrivere un programma in C che dopo aver inserito una stringa a piacere determini e o verifichi:
1) Il numero di consonanti e vocali contenute;
2) Che contenga solo lettere;
3) Il conteggio di una lettera (se presente) scelta dall’utente;
4) Crei 2 ulteriori stringhe che contengano 1 le lettere di posizione pari; la 2° le lettere di posizione dispari;
5) Verifichi se contiene doppie.

Inserita una 2° stringa determinare:
1) Quale delle 2 è più lunga e più corta;
2) Quale delle 2 stringhe contiene più vocali;
3) Quale delle 2 stringhe contiene più consonanti;
4) Quali sono le lettere contenute in ambedue le stringhe;*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void main() {
    int dim=0,vocali=0, consonanti=0, conteggioLettera=0;
    bool tutteLettere = true;
    char lettera;
    //chidere in input la dimesione della stringa
    printf("Inserisci la dimesione della 1 Stringa: ");
    scanf("%d", &dim);
    
    //dichiarare la stringa
    char stringa1 [dim];
    
    do
    {
    printf("Inserisci la 1 Stringa: ");
    scanf("%s", stringa1);
    //portare la stringa in minuscolo per semplificare il controllo
    for (int i = 0; i < strlen(stringa1); i++){
    stringa1[i] = tolower(stringa1[i]);
    }
    
    
    //controllo sia composta solo da lettere, se tutte lettere e' >0 non è composto solo da lettere
    for (int i = 0; i <strlen(stringa1); i++)
    {
        if ((stringa1[i]< 'a') && (stringa1[i]>'z'))
        {
            tutteLettere = false;
        }
    }
    if (tutteLettere == false)
    {
       printf("Non è composta solo da lettere, \n Rinserire");
    }
    } while (tutteLettere==false);

    //controllo quante vocali e quanti consonatni
    for(int i = 0; i <strlen(stringa1); i++){
        if (stringa1[i] == 'a' || stringa1[i] == 'e' || stringa1[i] == 'i' || stringa1[i] == 'o' || stringa1[i] == 'u')
        {
            vocali++;
        }
        else 
        {
            consonanti++;
        }
    }

    //chiedere in input la lettera da controllare + controllo che la lettera inserita sia una lettera
    do {
    printf("Inserisci la lettera da controllare: ");
    scanf("%c", &lettera);
    scanf("%c", &lettera);
    } 
    while (lettera<'a' && lettera > 'z');

    //portare la lettera in minuscolo per semplificare il controllo
    lettera = tolower(lettera);

    //controllo se la lettera e' presente in tutte le stringhe
    for (int i = 0; i < strlen(stringa1); i++)
    {
        if (stringa1[i] == lettera)
        {
            conteggioLettera++;
        }
    }


}

