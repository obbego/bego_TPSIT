/*Dato N un numero intero positivo,
calcolare e visualizzare la somma dei primi N numeri pari*/

#include <stdio.h>
int main(int argv, char *argc[])
{
    int n = 0, somma = 0;
    do
    {
        printf("Inserisci un N positivo: ");
        scanf("%d", &n);
        if (n < 0)
        {
            printf("Il numero deve essere positivo");
        }
    } while (n < 0);

    printf("\nSOMME:\n");
    for (int i = 2; i <= n; i++)
    {
        if (i % 2 == 0)
        {
            printf("(somma nuova) %d = (somma precedente) %d + (numero attuale) %d\n", somma + i, somma, i);
            somma += i;
        }
    }
    printf("\nSomma finale = %d\n\n", somma);

    return 0;
}