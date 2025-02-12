#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{

    if (argc < 3)
    {
        printf("Numero argomenti sbagliato\n");
        exit(1);
    }

    int pid = fork();
    if (pid == 0)
    {
        execl("/usr/bin/cp", "cp", argv[1], argv[2], NULL);
        printf("File copiato");
        exit(0);
    }
    else
    {
        wait(&pid);
        execl("/usr/bin/cat", "cat", argv[2], NULL);
    }
}