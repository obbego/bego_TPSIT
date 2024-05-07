/******************************************************************************
3) Scrivere un programma in c che dopo aver inserito un vettore di N numeri controlli l’esistenza di
un numero richiesto successivamente all’utente. In caso affermativo visualizzare quante volte si
ripete il numero e che posizione/i occupa nel vettore utilizzato.
*******************************************************************************/

#include <stdio.h>

void
main ()
{
  //dichiarazione variabili
  int qtaNumeri = 0, nControllo = 0, contaPresente = 0;

  //ciclo per controllare la dimensione del vettore, che non puo essere <0
  do
	{
	  //chiedere in input la qta
	  printf ("Inserisci la dimensione del vettore: \n");
	  scanf ("%d", &qtaNumeri);

	  //comunicare l'errore nel caso di qta < 0
	  if (qtaNumeri < 0)
		printf
		  ("ERRORE: la quantita  dei numeri non puo essere < 0\nRINSERIRE: \n\n");
	}
  while (qtaNumeri < 0);

  //dichiarare i vettori in base alla qta di numeri che l'utente vuole inserire
  int vet[qtaNumeri];

  //popolare il il vettore originale + ciclo for per popolare tutte posizioni
  printf ("\nPOPOLAZIONE vettore: \n");
  for (int i = 0; i < qtaNumeri; i++)
	{
	  //comunicare la posizione che si sta popolando
	  printf ("Inserisci il %d numero: ", i + 1);
	  scanf ("%d", &vet[i]);
	}

    //chiedere in input il numero che si vuole controllare
     printf ("Inserisci la il numero da controllare nel vettore: \n");
	 scanf ("%d", &nControllo);
  
   //ciclo per controllare la presenza del numero
  for (int i = 0; i < qtaNumeri; i++)
	{
	  if(nControllo==vet[i])
	  {
	      contaPresente++;
	  }
	}
	
    //stampare a schermo quante volte compare
	if (contaPresente>0)
	{
	    printf("\n\nIl numero: %d \ncompare %d volte", nControllo, contaPresente);
	}
	else
	{
	 printf("\n\nIl numero: %d \nnon compare nel vettore");
	}
}