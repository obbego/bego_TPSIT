/* Su una somma di denaro (relativa all'acquito di un prodotto) si vuole 
applicare uno sconto in base all'importo inserito seguendo il seguente schema:
            da 0 a 500€ sconto del 10%;
            da 501 a 1000 sconto del 20%;
            oltre i 1001 sconto 30%;
 Il programma dopo aver calcolato e visualizzato a video 
 lo sconto ed il prezzo netto deve permettere di re-inserire
 ulteriori somme di denaro.*/
#include <stdio.h>
void main()
{
    float prezzo;
    int scelta; 

    do
    {
    
    printf("Inserire l'importo dovuto: ");
    scanf("%f", &prezzo);

        if (prezzo<=0)
    {
        printf("Valore Errato");
    }
    else if (prezzo<=500)
    {
        prezzo = prezzo - ((prezzo/100)*10);
        printf("\nIl prezzo scontato del 10/100 corrisponde a: %.2f", prezzo); 
    }
    else if ((prezzo>500) && (prezzo<=1000))
    {
        prezzo = prezzo - ((prezzo/100)*20);
        printf("\nIl prezzo scontato 20/100 corrisponde a: %.2f", prezzo); 
    }
    else
    {
        prezzo = prezzo - ((prezzo/100)*30);
        printf("\nIl prezzo scontato 30/100 corrisponde a: %.2f", prezzo);   
    }

    printf("\nDesidera inserire altre somme di denaro?\n Digiti 1 per continuare \n qualsiasi altro valore per terminare ");
    scanf("%d", &scelta);     
    }
    
    while (scelta==1);

}