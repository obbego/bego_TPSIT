#include <sys/wait.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int t = 0;

int main(int argc, char *argv[])
{
    int pid1 = fork();

    if (pid1 == 0) // figlio
    {
        t = 2;
        printf("\nPid1: Sono il Figlio: PID mio = %d, PID di mio padre = %d devo dormire per %d secondi\n", getpid(), getppid(), t);
        sleep(t);
        printf("Pid1: %d, ho finito di dormire\n", getpid());
    }
    else if (pid1 > 0) // padre
    {
        int pid2 = fork();
        if (pid2 == 0) // figlio
        {
            t = 4;
            printf("\nPid2: Sono il Figlio: PID mio = %d, PID di mio padre = %d devo dormire per %d secondi\n", getpid(), getppid(), t);
            sleep(t);
            printf("Pid2: %d, ho finito di dormire\n", getpid());
            exit(t);
        }
        else if (pid2 > 0) // padre
        {
            int valT = 0;
            waitpid(pid2, &valT, 0);
            printf("Padre pid0 %d, mio figlio pid2 ha dormito per %d secondi\n", getpid(), WEXITSTATUS(valT));
        }
        else // errore
        {
            printf("\nERRORE NELLA GENERAZIONE DEL PROCESSO figlio p2");
        }
    }
    else // errore
    {
        printf("\nERRORE NELLA GENERAZIONE DEL PROCESSO figlio p1");
    }
}