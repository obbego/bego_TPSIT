#include <sys/wait.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int ricerca(int arr[], int n, int num) {
    for (int i = 0; i < n; i++){
        if (arr[i] == num)
            return i;
    }
    return -1;
}

int main (int argc, char *argv[]) {
    int arr[] = {1, 2 ,3};
    
    int pid = fork();

    if (pid == 0) {
        int num = atoi(argv[1]);
        int pos = ricerca(arr, 3, num);

        if (pos != -1) 
            printf("\n\nIl numero %d si trova in %d posizione nell array\n\n", num, pos);
        else
            printf("Non è stato trovato il numero inserito");
        
        exit(1);
    }

    wait(&pid);

    return 0;
}