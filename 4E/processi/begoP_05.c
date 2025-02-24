#include <sys/wait.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int somma = 0;

int main(int argc, char *argv[])
{
    int pid1 = fork();

    if (pid1 == 0) // Figlio p1
    {
        printf("\nPid1: Sono il Figlio: PID mio = %d, PID di mio padre = %d", getpid(), getppid());
        somma = 1 + 2;
        printf("\nPid1 %d: devo sommare 1 + 2 = %d", getpid(), somma);
        exit(somma);
    }
    else if (pid1 > 0) // Padre
    {
        int pid2 = fork();

        if (pid2 == 0) // Figlio p2
        {
            printf("\nPid2: Sono il Figlio: PID mio = %d, PID di mio padre = %d", getpid(), getppid());
            somma = 3 + 4;
            printf("\nPid2 %d: devo sommare 3 + 4 = %d", getpid(), somma);
            exit(somma);
        }
        else if (pid2 > 0) // Padre
        {
            int val1 = 0, val2 = 0;
            wait(&val1);
            wait(&val2);
            somma = WEXITSTATUS(val1) + WEXITSTATUS(val2);
            printf("\nPid0: Sono il Padre: PID mio = %d", getpid());
            printf("\nPid0 %d: visualizzare la somma dei valori ottenuti dai prosessi figli\n%d + %d = %d\n", getpid(), WEXITSTATUS(val1), WEXITSTATUS(val2), somma);
        }
        else
        {
            printf("\nERRORE NELLA GENERAZIONE DEL PROCESSO figlio p2");
        }
    }
    else
        printf("\nERRORE NELLA GENERAZIONE DEL PROCESSO figlio p1");
}