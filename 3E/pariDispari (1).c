// Programma che legge N numeri interi, con N scelto dall'utente (N max 20)
// e calcola la somma/media dei Numeri inseriti maggiori di 5
// visualizzando i risultati a video

#include <stdio.h>
#define nome 10 // dichiarazione costante fuori dal main (senza ;)
void main()
{
    int i, num, n, vett[30], sommapari = 0, contpari = 0, sommadispari = 0, contdispari = 0;	// int = dichiarazione numero intero
    float mediapari, mediadispari;                                  							// dichiarazione numero reale in quanro media (ovvero divisione)
    do
    {
        printf("Quanti numeri vuoi inserire?\n"); 												// messaggio a schermo
        scanf("%d", &n);
    } while (n <= 0 || n >30);

    for (i = 0; i < n; i++)
    {
        printf("Inserisci il numero\n"); 														// messaggio a schermo
        scanf("%d", &vett[i]);
       
	    if (vett[i] % 2 == 0) 																	//condizione parità
        {
            sommapari = sommapari + vett[i];
            contpari++;
        }
        else  //condizione disparità
		{
   			sommadispari = sommadispari + vett[i];
            contdispari++;
		}
    }
    printf("\n");
    
	if (contpari>0)   //condizione di scrittura
    {
    printf(" La somma dei numeri pari risulta: %d\n", sommapari);   // restituzione dati output
	mediapari = (float)sommapari / contpari;
    printf(" La media dei numeri pari risulta: %.2f\n", mediapari);
    }
    else   printf (" Non ci sono numeri pari");
    
    printf("\n");
    
    if (contdispari>0)
    {
    printf(" La somma dei numeri dispari risulta: %d\n", sommadispari);
	mediadispari = (float) sommadispari / contdispari;
    printf(" La media dei numeri dispari risulta: %.2f\n", mediadispari);
    }
    else   printf (" Non ci sono numeri dispari");

 
}
