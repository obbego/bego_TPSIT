#include <sys/wait.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>

int quadrato(int n)
{
    return n * n;
}
void contoRovescia(int n)
{
    printf("\nInizio conto alla rovescia\n\n");
    for (int i = n; i >= 0; i--)
    {
        printf("%d\n", i);
        sleep(1);
    }
    printf("\nFine conto alla rovescia\n");
}
void contoProgressivo(int n)
{
    printf("\nInizio conto progressivo\n\n");
    for (int i = 0; i <= n; i++)
    {
        printf("%d\n", i);
        sleep(1);
    }
    printf("\nFine conto progressivo\n");
}

int main(int argc, char *argv[])
{

    int numero = 0;
    printf("Inserire un numero da 0 a 10: ");
    scanf("%d", &numero);

    int pid2 = fork();

    if (pid2 > 0) // Processo padre
    {
        printf("\nP1: mio PID = %d, mio figlio P2 ha PID = %d", getpid(), pid2);
        wait(NULL);
        int pid3 = fork();
        if (pid3 > 0) // Processo p1
        {
            printf("\nP1: mio PID = %d, mio figlio P3 ha PID = %d\n", getpid(), pid3);
        }
        else if (pid3 == 0) // Processo p3
        {
            printf("\nP3: mio PID = %d, mio padre P1 ha PID = %d\n\n", getpid(), getppid());
            printf("\nIl numero inserito dall'utente: %d", numero);
            int pid6 = fork();
            if (pid6 > 0) // Processo p3
            {
                printf("\nP3: mio PID = %d, mio figlio P6 ha PID = %d", getpid(), pid6);
                int statusP6 = 0;
                wait(&statusP6);
                printf("\nP3: P6 ha restituito: %d", WEXITSTATUS(statusP6));
                exit(0);
            }
            else if (pid6 == 0) // Processo p6
            {
                printf("\nP6: mio PID = %d, mio padre P3 ha PID = %d", getpid(), getppid());
                exit(quadrato(numero));
            }
            else // p6 < 0
            {
                printf("\nErrore nella generazione del figlio P3\n");
            }
        }
        else // p3 < 0
        {
            printf("\nErrore nella generazione del figlio P3\n");
        }
    }

    else if (pid2 == 0) // Inizio processo 2
    {
        printf("\nP2: mio PID = %d, mio padre P1 ha PID = %d\n", getpid(), getppid());
        int pid4 = fork();
        if (pid4 > 0) // Processo p2
        {
            printf("\nP2: mio PID = %d, mio figlio P4 ha PID = %d", getpid(), pid4);
            wait(&pid4);
            int pid5 = fork();
            if (pid5 > 0) // Processo p2
            {
                printf("\nP2: mio PID = %d, mio figlio P5 ha PID = %d", getpid(), pid5);
                wait(&pid5);
                exit(0);
            }
            else if (pid5 == 0) // Processo p5
            {
                printf("\nP5: mio PID = %d, mio padre P2 ha PID = %d", getpid(), getppid());
                contoProgressivo(numero);
                exit(0);
            }
            else // p5 < 0
            {
                printf("\nErrore nella generazione del figlio P5\n");
            }
        }
        else if (pid4 == 0) // Processo p4
        {
            printf("\nP4: mio PID = %d, mio padre P2 ha PID = %d", getpid(), getppid());
            contoRovescia(numero);
            exit(0);
        }
        else // p4 < 0
        {
            printf("\nErrore nella generazione del figlio P4\n");
        }
    }
    else // p2 < 0
        printf("\nErrore nella generazione del figlio P2\n");

    return 0;
}