#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>

/*Un’applicazione multiprocesso in C deve presentare la seguente interfaccia:
controlloFatture nomeFileFatture
dove nomeFileFatture è un nome assoluto di file.

A questo fine, l’addetto dell’azienda deve verificare, sul file passato
come parametro, se un cliente ha ancora delle fatture in sospeso oppure se
le ha pagate tutte.

Nel file passato come parametro sono memorizzate tutte le fatture, una per
ogni riga. Ogni riga è composta dal nome del cliente (un codice di 5 caratteri
alfanumerico che identifica univocamente ogni cliente), da un campo che
contiene la stringa “pagato” per le fatture saldate oppure “insoluto”
per quelle ancora insolute, più altri campi con altre informazioni.

L’addetto dell’azienda inserisce a terminale il codice dei clienti (uno alla
volta) di cui vuole controllare lo stato dei pagamenti. Per ogni cliente
inserito, l’applicazione deve visualizzare il nome del cliente stesso e il
numero di fatture di tale cliente che risultano ancora da pagare.

Quando l’applicazione termina,a causa dell’inserimento della stringa “esci”,
il programma deve visualizzare il numero totale di richieste di servizio
eseguite fino a quel momento.*/

int main(int argc, char *argv[])
{
    int p1p0[2], nRichieste = 0;
    char stringa[200], buff[100];

    pipe(p1p0);

    if (argc != 2)
    {
        printf("Argomenti errati. Inserire come primo argomento il nome di un file\n");
        exit(0);
    }

    while (1)
    {
        printf("Inserire codice cliente: \n'esci' per terminare\n\n");
        scanf("%s", stringa);

        if (strcmp("esci", stringa) == 0)
        {
            close(p1p0[0]);
            close(p1p0[1]);
            printf("Numero totale di richieste del servizio = %d\n", nRichieste);
            return 0;
        }
        else
        {
            int pid = fork();

            if (pid == 0) // figlio
            {
                close(p1p0[0]); // chiusura canale lettura
                close(1);       // sostituzione stdout
                dup(p1p0[1]);
                close(p1p0[1]);

                char ricerca[200];

                strcpy(ricerca, stringa);
                strcat(ricerca, " insoluto");

                execl("/usr/bin/grep", "grep", "-c", ricerca, argv[1], (char *)0);
                return -1;
            }

            wait(NULL);
            close(p1p0[1]);
            
            read(p1p0[0], &buff, sizeof(buff));
            printf("Il cliente %s ha %d fatture da pagare\n\n", stringa, atoi(buff));
            nRichieste += atoi(buff);
        }
    }
}