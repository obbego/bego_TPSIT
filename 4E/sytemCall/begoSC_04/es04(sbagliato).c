/* Si vuole realizzare in linguaggio C un software monoprocesso che implementi il seguente comando:
$ cat file1.txt file2.txt file3.txt | grep “c”

Dove file[N].txt con N maggiore uguale a 1 sono una serie di files e il carattere "c" è a scopo esemplificativo e potrebbe essere
qualsiasi carattere.

Si utilizzino le system call al fine di leggere tutti i file di testo e, per ogni file, ricercare il carattere.
Al termine dell’esecuzione il software dovrà mostrare a video il numero di occorrenze del carattere trovate nei files e
dovrà contemporaneamente scrivere l’output su un file di testo il cui path sarà letto da argv.

Esempio:
$ ./a.out file1.txt file2.txt file3.txt k occorrenze.txt
$ Il carattere k compare 10 volte nei files: file1.txt, file2.txt, file3.txt
$ cat occorrenze.txt
$ Il carattere k compare 10 volte nei files: file1.txt, file2.txt, file3.txt

Osservazioni:
essendo il software monoprocesso non è necessario usare le pipe
prestare attenzione all’uso corretto di argv
si ricorda che il software deve funzionare per un numero arbitrario di files.
i percorsi dei files possono essere sia assoluti che relativi


Suggerimento:
Per facilitare la ricerca è possibile leggere un singolo carattere per volta usando la funzione read. */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void ricerca(char carattere, int fd[])
{
}

void popolaFd(int fd[], int argc, char *argv[])
{
    int y = 0;
    for (int i = 1; i < (argc - 2); i++)
    {
        fd[y] = open(argv[i], O_WRONLY | O_CREAT | O_TRUNC, 0644);
        y++;
    }
}

int main(int argc, char *argv[])
{

    if (argc < 4)
    {
        printf("\nErrore nel caricamento dei file");
        exit(1);
    }

    int fd[argc - 2];
    popolaFd(fd, argc, argv);

    char carattere, output[100];
    int nCarattere = 0;

    for (int i = 0; i < argc - 3; i++)
    {
        while (read(fd[i], &carattere, sizeof(carattere) > 0))
        {
            if (carattere == argv[argc - 2][0])
            {
                nCarattere++;
            }
        }
    }

    sprintf(output, "\nIl carattere %s compare %d volte nei files esaminati:\n", argv[argc - 2], nCarattere);

    write(1, output, strlen(output));

    fd[argc - 3] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    write(fd[argc - 3], output, strlen(output));

    close(*fd);
}
