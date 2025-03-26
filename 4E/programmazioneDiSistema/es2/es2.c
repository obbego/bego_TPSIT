#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>


int main(int argc, char *argv[])
{

    int p1p2[2],p2p0[2], pid1, pid2;
    int nread, fdFile;
    char buff;
    pipe(p1p2);
    
    pid1 = fork(); //creo un 1 figlio per eseguire il primo comando (cat)

    if (pid1 == 0) //figlio 1
    {
        close(p1p2[0]); //chiudo lettura perche devo scrivre nella pipe
        close(1); //chiudo il fd 1, che è lo stdout
        dup(p1p2[1]); /*duplico nel primo spazio disponibile 
        (fd 1 che ho cappena chiuso) l'fd di scrittura della nostra pipe*/
        close(p1p2[1]); //vado a chiudere il fd originale perchè ora quello che mi serve è sullo stdout
        execl("/bin/cat", "cat", argv[1], (char *)0); //eseguo il comando cat che mandera il suo output allo stdout, cioe il fd della pipe
        return -1; //se arrivo qua qualcosa è andato storto quindi ritorno -1
    }

    pipe(p2p0);
    pid2 = fork(); //creo un 2 figlio per eseguire il more

    if (pid2 == 0) //figlio 2
    {
        //lettura da pipe p1p2
        close(p1p2[1]); //chiudo scrittura perche devo solo leggere dalla pipe
        close(0); //chiudo lo stdin (tastiera)
        dup(p1p2[0]); //duplico nello stdin l'fd di lettura della pipe
        close(p1p2[0]); //vado a chiudere il fd originale perchè ora quello che mi serve è sullo stdin

        //scrittura su pipe p2p0
        close(p2p0[0]);
        close(1);
        dup(p2p0[1]);
        close(p2p0[1]);

        execl("/bin/wc", "wc", (char *)0); //eseguo il comando wc, che avra letto dalla pipe e lo mandera allo stdout, ovvero p2p0[1]
        return -1; //se arrivo qua qualcosa è andato storto quindi ritorno -1
    }

    close(p1p2[1]); //chiudo i 2 fd della pipe p1p2
    close(p1p2[0]);

    close(p2p0[1]); //chiudo i 2 fd della pipe p2p0
    
    //scrittura su file
    fdFile = open("wc.txt", O_WRONLY | O_CREAT, 0777);

    while ((nread = read(p2p0[0], &buff, 1)) > 0)
    {
        write(fdFile, &buff, nread);
    }

    wait(&pid1); //aspetto i 2 processi
    
    close(fdFile);
    close(p2p0[0]);
    
    
    return 0; //fine del padre
}