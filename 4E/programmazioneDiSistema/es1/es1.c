#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{

    int p0p1[2], pid1, pid2;
    pipe(p0p1);
    
    pid1 = fork(); //creo un 1 figlio per eseguire il primo comando (cat)

    if (pid1 == 0) //figlio 1
    {
        close(p0p1[0]); //chiudo lettura perche devo scrivre nella pipe
        close(1); //chiudo il fd 1, che è lo stdout
        dup(p0p1[1]); /*duplico nel primo spazio disponibile 
        (fd 1 che ho cappena chiuso) l'fd di scrittura della nostra pipe*/
        close(p0p1[1]); //vado a chiudere il fd originale perchè ora quello che mi serve è sullo stdout
        execl("/bin/cat", "cat", argv[1], (char *)0); //eseguo il comando cat che mandera il suo output allo stdout, cioe il fd della pipe
        return -1; //se arrivo qua qualcosa è andato storto quindi ritorno -1
    }

    pid2 = fork(); //creo un 2 figlio per eseguire il more

    if (pid2 == 0) //figlio 2
    {
        close(p0p1[1]); //chiudo scrittura perche devo solo leggere dalla pipe
        close(0); //chiudo lo stdin (tastiera)
        dup(p0p1[0]); //duplico nello stdin l'fd di lettura della pipe
        close(p0p1[0]); //vado a chiudere il fd originale perchè ora quello che mi serve è sullo stdin
        execl("/bin/more", "more", (char *)0); //eseguo il comando more, che avra letto dalla pipe e lo mandera allo stdout, ovvero 1 (video)
        return -1; //se arrivo qua qualcosa è andato storto quindi ritorno -1
    }

    close(p0p1[1]); //chiudo i 2 fd della pipe
    close(p0p1[0]);
    wait(&pid1); //aspetto i 2 processi
    wait(&pid2);

    return 0; //fine del padre
}