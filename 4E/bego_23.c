/*Dati due numeri interi positivi N1 ed N2 calcolare, mediante la somma
ripetuta, il prodotto dei due numeri e visualizzarli.*/

#include <stdio.h>
int main(int argv, char *argc[])
{
    int n1 = 0, n2 = 0, somma = 0;
    do
    {
        printf("Inserisci un primo N > 0: ");
        scanf("%d", &n1);
        if (n1 < 1)
        {
            printf("Il numero deve essere > 0");
        }
        else
        {
            printf("Inserisci un secondo N > 0");
            scanf("%d", &n2);
            if (n2 < 1)
            {
                printf("Il numero deve essere > 0");
            }
        }
    } while ((n1 < 1) || (n2 < 1));

    printf("\nPRODOTTO:\n");
    /*for (int i = 2; i <= n1; i++)
    {
        if (i % 2 == 0)
        {
            printf("(somma nuova) %d = (somma precedente) %d + (numero attuale) %d\n", somma + i, somma, i);
            somma += i;
        }
    }
    printf("\nSomma finale = %d\n\n", somma);*/

    return 0;
}