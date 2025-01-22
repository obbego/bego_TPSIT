#include <sys/wait.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>

void numeriRandom(int arr[], int size, int min, int max)
{
    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        arr[i] = min + (rand() % (max - min + 1));
    }
}
int prodotto(int arr[], int n)
{
    int prodotto = 1;
    for (int i = 0; i < n; i++)
    {
        prodotto = prodotto * arr[i];
    }
    return prodotto;
}
int somma(int arr[], int n)
{
    int somma = 0;
    for (int i = 0; i < n; i++)
    {
        somma += arr[i];
    }
    return somma;
}
double media(int arr[], int n)
{
    return (float)somma(arr, n) / n;
}

void visualizzaComponenti(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d: componente: %d\n", i, arr[i]);
    }
    printf("\n\n");
}

int status;

int main(int argv, char *argc[])
{
    int n = 3;
    int arr[n];
    // generaArr(arr);
    numeriRandom(arr, n, 1, 5);
    visualizzaComponenti(arr, n);

    int pid2 = fork();
    if (pid2 < 0)
    {
        printf("Il fork non è stato generato correttamente\n");
        exit(-1);
    }
    else if (pid2 != 0)
    {
        printf("P1: mio PID = %d, mio figlio P2 ha PID = %d\n", getpid(), pid2);
    }
    else if (pid2 == 0) // figlio p2
    {
        printf("P2: mio PID = %d, mio padre P1 ha PID = %d\n", getpid(), getppid());
        int pid4 = fork();
        if (pid4 == 0)
        {
            printf("P4: mio PID = %d, mio padre P2 ha PID = %d\n", getpid(), getppid());
            printf("Il prodotto dei componenti del vettore: %d\n", prodotto(arr, n));
            exit(0);
        }
        wait(&pid4);
        int pid5 = fork();
        if (pid5 == 0)
        {
            printf("P5: mio PID = %d, mio padre P2 ha PID = %d\n", getpid(), getppid());
            printf("La media dei componenti del vettore: %.2f\n", media(arr, n));
            exit(0);
        }
        wait(&pid5);
        exit(0);
    }

    int pid3 = fork(); // figlio p3
    if (pid3 < 0)
    {
        printf("Il fork non è stato generato correttamente\n");
        exit(-1);
    }
    else if (pid3 != 0)
    {
        printf("P1: mio PID = %d, mio figlio P3 ha PID = %d\n", getpid(), pid3);
        wait(&status);
    }
    else
    {
        printf("P3: mio PID = %d, mio padre P1 ha PID = %d\n", getpid(), getppid());
        visualizzaComponenti(arr, n);
        int pid6 = fork();
        if (pid6 == 0) // figlio 6
        {
            printf("P6: mio PID = %d, mio padre P2 ha PID = %d\n", getpid(), getppid());
            int s = somma(arr, n);
            exit(s);
        }
        if (pid6 > 0)
        {
            int statusP6;
            wait(&statusP6);
            printf("La somma dei componenti dell arr: %d\n", WEXITSTATUS(statusP6));
            exit(0);
        }
    }
    exit(0);
}
