// Programma che legge N numeri interi, con N scelto dall'utente (N max 20)
// e calcola la somma/media dei Numeri inseriti maggiori di 5
// visualizzando i risultati a video

#include <stdio.h>
#define nome 10 // dichiarazione costante fuori dal main (senza ;)
void main()
{
    int i, num, n, vett[30], somma = 0, cont = 0; // int = dichiarazione numero intero
    float media;                                  // dichiarazione numero reale in quanro media (ovvero divisione)
    do
    {
        printf("Quanti numeri vuoi inserire?\n"); // messaggio a schermo
        scanf("%d", &n);
    } while (n <= 0 || n > 20);

    for (i = 0; i < n; i++)
    {
        printf("Inserisci il numero\n"); // messaggio a schermo
        scanf("%d", &vett[i]);
        if (vett[i] > 5)
        {
            somma = somma + vett[i];
            cont++;
        }
    }
    printf("\n");
    printf(" La somma dei numeri >5 risulta: %d\n", somma);
    if (cont>0)
    {
    media = (float)somma / cont;
    printf(" La media dei numeri >5 risulta: %.2f\n", media);
    }
    else   printf ("Non ci sono numeri >5\n");
    
    printf("\n");

 
}
