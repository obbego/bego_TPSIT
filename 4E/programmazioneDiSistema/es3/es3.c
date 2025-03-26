#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>

/*Si scriva un’applicazione concorrente che presenti la seguente interfaccia:

cercaStringhe FileIn

dove FileIn è un nome assoluto di file.

L’applicazione deve contare il numero di volte in cui un insieme di stringhe
che l’utente inserisce da terminale (una alla volta) compaiono all’interno
del file passato come parametro in argv[1].
Se in una riga del file una parola compare più volte, al fine del conteggio,
considerare solamente la prima occorrenza.
L’applicazione termina quando l’utente inserisce la stringa “fine”.
L’applicazione deve visualizzare il numero di volte in cui ogni stringa
compare nel file e anche, al termine dell’esecuzione, il numero totale di
stringhe trovate nel file.*/

int main(int argc, char *argv[])
{
    int nParoleTrovate = 0;
    int p1p2;
    char *stringa;

    pipe(p1p2);
    
    if (argc != 2)
    {
        printf("Numero parametri errato\n");
        exit(1);
    }

    while (1)
    {
        printf("cercaStringe %s\n", argv[1]);

        printf("Inserisci stringa da cercare\n 'fine' per terminare\n");
        scanf("%s", stringa);

        if (stringa == "fine") {
            printf("Programma terminato: %d parole trovate", &nParoleTrovate);
            return 0;
        } else {

        }
    }
}