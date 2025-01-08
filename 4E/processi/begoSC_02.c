/*Scrivere un programma in linguaggio C che scriva l'alfabeto su un file
il cui nome deve essere letto da argv[1] */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    char alfabeto[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    int fd;

    fd = open(argv[1], O_WRONLY | O_CREAT, 644);

    for (int i = 0; i < 26; i++)
    {
        write(fd, &alfabeto[i], 1);
    }

    close(fd);

    printf("aaaa\n\n");

    return 0;
}