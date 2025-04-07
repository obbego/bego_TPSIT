#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>

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
    int p1p0[2];
    int pid;
    char buff[10000], stringa[1000000];

    pipe(p1p0);

    if (argc != 2)
    {
        printf("Numero parametri errato\n");
        exit(1);
    }

    while (1)
    {
        printf("cercaStringe %s\n", argv[1]);

        printf("Inserisci stringa da cercare\n'fine' per terminare\n");
        scanf("%s", stringa);

        if (strcmp(stringa, "fine") == 0)
        {
            close(p1p0[0]);
            close(p1p0[1]);

            printf("\n\nProgramma terminato: %d parole trovate\n", nParoleTrovate);
            return 0;
        }
        else
        {
            pid = fork();

            if (pid == 0) // figlio
            {
                close(p1p0[0]);
                close(1);
                dup(p1p0[1]);
                close(p1p0[1]);

                execl("/usr/bin/grep", "grep", "-c", stringa, argv[1], (char *)0);
                return -1;
            }

            read(p1p0[0], &buff, sizeof(buff));
            printf("Il file ha %d '%s' \n\n", atoi(buff), stringa);
            nParoleTrovate += atoi(buff);
        }
    }
}