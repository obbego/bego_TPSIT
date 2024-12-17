#include <sys/wait.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int maggiore(int arr[], int n)
{
    int maggiore = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (maggiore < arr[i])
        {
            maggiore = arr[i];
        }
    }
    return maggiore;
}

int minore(int arr[], int n)
{
    int minore = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (minore > arr[i])
        {
            minore = arr[i];
        }
    }
    return minore;
}

int main(int argc, char *argv[])
{

    if (argc < 3)
    {
        printf("Il numero di argomenti passato non è corretto\n\n");
        return -1;
    }

    // Numero di elementi nell'array (primo argomento passato)
    int n = atoi(argv[1]);

    // Verifica che il numero di argomenti corrisponda a n + 1 (1 per n e n numeri)
    if (argc != n + 2)
    {
        printf("Il numero di argomenti non corrisponde al numero di elementi dell'array\n");
        return -1;
    }
    
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = atoi(argv[i + 2]);
    }

    int pid = fork();
    if (pid == 0)
    {
        printf("Sono il figlio: %d, padre mio: %d\n", getpid(), getppid());
        printf("Il numero maggiore dell'array è: %d\n", maggiore(arr, n));

        int pid2F = fork();
        if (pid2F == 0)
        {
            printf("Sono il nipote: %d, padre mio: %d\n", getpid(), getppid());
            printf("Il numero minore dell'array è: %d\n", minore(arr, n));
            exit(0);
        }
        wait(&pid2F);
        exit(0);
    }
    wait(&pid);
}