#include <sys/wait.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int p, status;

int main(int argc, char *argv[])
{
    int pid = fork();

    if (pid != 0)
    {
        printf("Sono il padre, il mio pid: %d\n", getpid());
    }

    if (pid == 0)
    {
        printf("Sono il figlio 1, il mio pid: %d\n", getpid());
        printf("Sono il figlio 1, il pid di mio papa: %d\n", getppid());

        int pid2N = fork();
        if (pid2N == 0)
        {
            printf("Sono il nipote 1, il mio pid: %d\n", getpid());
            printf("Sono il nipote 1, il pid di mio papa: %d\n", getppid());
            exit(0);
        }

        int pid3N = fork();
        if (pid3N == 0)
        {
            printf("Sono il nipote 2, il mio pid: %d\n", getpid());
            printf("Sono il nipote 2, il pid di mio papa: %d\n", getppid());
            exit(0);
        }
        wait(&pid2N);
        wait(&pid3N);
        exit(0);
    }
    
    int pid4 = fork();

    if(pid4 == 0) {
        printf("Sono il figlio 2, il mio pid: %d\n", getpid());
        printf("Sono il figlio 2, il pid di mio papa: %d\n", getppid());
    }
    wait(&pid);
    wait(&pid4);
}
