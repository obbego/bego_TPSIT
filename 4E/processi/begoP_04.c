#include <sys/wait.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int p;
int status;

int main(int argc, char *argv[])
{
    p = fork();

    if (p==0) // se p = 0 è il figlio
    {
        printf("1_Sono il Figlio: PID mio = %d\n", getpid());
        printf("2_Sono il Figlio: PID di mio padre = %d\n", getppid());
        
        exit(21); // deve essere un numero <=255 perchè senno supera gli 8 bit
    }
    else
    {
        printf("3_Sono il Padre: PID mio = %d\n", getpid());
        printf("4_Sono il Padre: PID di mio figlio = %d\n", p);

        printf("Attendo che mio Figlio: termini\n", wait(&status));
        printf("Il codice di terminazione di mio figlio: WEXITSTATUS(status) = %d", WEXITSTATUS(status));
        //restituisce il codice di uscita del figlio

        printf("Attendo che mio Figlio(gia terminato): termini\n", wait(&status));
        //ritorna -1 perche non ci sono figli

        printf("\nSono il Padre: %d e il PID di mio figlio(gia terminato): %d", getpid(), p);
        printf("\nVedo ancora il suo codice d'uscita: %d\n\n", WEXITSTATUS(status));
        
    }

    return 0;
}