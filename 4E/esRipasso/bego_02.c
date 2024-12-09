/*Progettare un algoritmo che effettui le seguenti operazioni:
• continui a leggere da tastiera due valori numerici, fermandosi quando uno dei due numeri è
0 (zero)
• per ogni coppia di numeri letti:
? calcoli il prodotto dei due numeri e ne stampi il valore
? sommi il prodotto calcolato ad una variabile che memorizzi la somma di tutti i prodotti
• all’uscita del ciclo, stampi il valore della somma*/

#include <stdio.h>
int main()
{
	//dichiarazione variabili
    int n1=0, n2=0, prod=0, sommaTot=0;
    //inizio ciclo
    do{
    //chiedere in input i dati
    printf("\nInserisci il primo numero: ");
    scanf("%d", &n1);
    printf("\nInserisci il secodno numero: ");
    scanf("%d", &n2);
    /*controllare che i numeri siano =! da 0 perche 
    in quel caso esce subito dal ciclo e termina il codice*/
    if (n1==0||n2==0){
    	printf("Hai inserito 0\n");
    	break;
	}
    else{
    	prod = n1*n2;
    	sommaTot = sommaTot + prod;
	}
    }
    while(n1!= 0 && n2!=0);
    printf("\nLa somma totale equivale a: %d", sommaTot);
    return 0;
}
