/*Si vuole realizzare un software concorrente in linguaggio C che
legga un file di testo da argv[1] e conteggi il numero di parole
presenti nel file.
Una volta effettuato il conteggio il programma principale
deve mostrarlo a video.

Note operative:
P0 genera P1 il quale legge il contenuto del file usando il comando cat.
P2 legge da pipe il flusso di caratteri e
capisce quando finisce una parola e ne inizia un'altra,
in modo da poter aggiornare il contatore.
P2 invia a P0 il totale
P0 stampa a video il totale.

Esempio:
$ ./a.out file.txt
Nel file sono presenti 10 parole*/

int main(int argc, char *argv[])
{
    int p1p2[2], p2p0[2];
    int nParole = 1, nLetti = 0;
    char buff;

    if (argc != 2)
    {
        printf("errore nel numero di argomenti");
        return -1;
    }

    pipe(p1p2);
    pipe(p2p0);

    if (pipe(p1p2) == -1 || pipe(p2p0) == -1) {
        perror("Errore creazione pipe");
        exit(1);
    }
    
    int p1 = fork();

    if (p1 < 0)
    {
        printf("errore generazione figlio p1");
        return -1;
    }
    // figlio
    else if (p1 == 0)
    {

        close(p1p2[0]);
        close(1);
        dup(p1p2[1]);
        close(p1p2[1]);

        execl("/bin/cat", "cat", argv[1]);
        return -1;
    }
    // padre
    else
    {
        int p2 = fork();
        if (p2 < 0)
        {
            printf("errore generazione figlio p2\n");
            return -1;
        }
        else if (p2 == 0)
        {
            close(p1p2[1]);
            close(p2p0[0]);

            while ((nLetti = read(p1p2[0], &buff, sizeof(buff))) > 0)
            {
                if (buff == ' ')
                {
                    nParole++;
                }
            }

            write(p2p0[1], &nParole, sizeof(nParole));
            exit(0);
        }
        else
        {
            wait();
            wait();
            close(p1p2[0]);
            close(p1p2[1]);
            close(p2p0[1]);
            read(p2p0[0], &nParole, sizeof(nParole));
            close(p2p0[0]);
            printf("Il numero di parole corrisponde a %d\n", nParole);
            return 0;
        }
    }
}
