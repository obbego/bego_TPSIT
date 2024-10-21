/*Dati due numeri interi e positivi N1 e N2 con N2>N1, generare e
visualizzare in ordine decrescente i numeri compresi tra N1 e N2.*/
#include <stdio.h>
int main(int argc, char *argv[])
{
    int n1 = 0, n2 = 0, i;
    do
    {
        printf("Inserisci il primo numero, deve essere positivo: \n");
        scanf("%d", &n1);

        if (n1 < 0)
        {
            printf("Il numero non rispetta i requisiti\n\n");
        }

        else
        {
            printf("Inserisci un secondo numero, deve essere > di N1+1(%d): \n", n1);
            scanf("%d", &n2);

            if (n1+1 >= n2)
            {
                printf("Il numero non rispetta i requisiti\n\n");
            }
        }
    } while ((n1 < 0) || (n1+1 >= n2));

    for (i = n2 - 1; i > n1; i--)
    {
        printf("N: %d\n", i);
    }

    return 0;
}
