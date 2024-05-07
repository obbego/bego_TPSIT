/* Scrivere un programma in C che, dopo aver letto N numeri (n scelto dall'utente) 
calcoli e visualizzi a video la somma dei numeri positivi, 
la somma dei numeri negativi in valore assoluto, 
il conteggio dei numeri negativi e positivi, 
la media dei numeri positivi e negativi.*/
#include <stdio.h>
void main()
{
    int qtaNumeri=0, num=0, i=0;
    int sommaPos=0, contaPos=0;
    int sommaNeg=0, contaNeg=0;
    int mediaNeg=0, mediaPos=0;
    printf("Quanti numeri vuole inserire? ");
    scanf("%d", &qtaNumeri);

    for (i = 0; i<qtaNumeri; i++)
     {
        printf("Inserisci il %d numero: ", i);
        scanf("%d", &num); 

        if(num>=0)
        {
            sommaPos = sommaPos+num;
            contaPos = contaPos + 1; 
        }
        else
        {
            sommaNeg = sommaNeg+num;
            contaNeg = contaNeg + 1; 
        }
     }
     sommaNeg = sommaNeg * (-1);
     if (contaNeg==0)
     {
        printf("\nNon sono stati inseriti numeri Negativi");
     }
     else
     {
        mediaNeg=sommaNeg/contaNeg; 
        printf("\nLa somma dei numeri Negativi in Val Ass: %d ", sommaNeg);
        printf("\nSono stati inseriti %d: numeri Negativi: ", contaNeg);
        printf("\nLa Media dei numeri Negativi: %d", mediaNeg);
     }
          if (contaPos==0)
     {
        printf("\nNon sono stati inseriti numeri Positivi");
     }
     else
     {
        mediaPos=sommaPos/contaPos; 
        printf("\nLa somma dei numeri Positivi: %d ", sommaPos);
        printf("\nSono stati inseriti %d: numeri Positivi: ", contaPos);
        printf("\nLa Media dei numeri Positivi: %d", mediaPos);
     }
}
