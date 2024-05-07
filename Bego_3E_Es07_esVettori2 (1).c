/******************************************************************************
2) Scrivere un programma in c che dopo aver inserito un vettore di N numeri interi separi il vettore
inserito in 2 ulteriori vettori il primo contenente i numeri pari ed il secondo con i numeri dispari.
*******************************************************************************/

#include <stdio.h>

void
main ()
{
  //dichiarazione variabili
  int qtaNumeri = 0, j=0, k=0, contaPari=0, contaDispari=0;

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
  int vetOriginale[qtaNumeri];

  //popolare il il vettore originale + ciclo for per popolare tutte posizioni
  printf ("\nPOPOLAZIONE vettore: \n");
  for (int i = 0; i < qtaNumeri; i++)
	{
	  //comunicare la posizione che si sta popolando
	  printf ("Inserisci il %d numero: ", i + 1);
	  scanf ("%d", &vetOriginale[i]);
	}

   //ciclo per contare quanti pari e dispari
  for (int i = 0; i < qtaNumeri; i++)
	{
	  if(vetOriginale[i]%2==0)
	  {
	      contaPari++;
	  }
	  else 
	  {
	       contaDispari++;
	  }
	}
	
	//dichiarazione array pari dispari
    int vetPari[contaPari], vetDispari[contaDispari];
  
  //ciclo per dividere in pari e dispari
  for (int i = 0; i < qtaNumeri; i++)
	{
	  if(vetOriginale[i]%2==0)
	  {
	      vetPari[j]= vetOriginale[i];
	      j++;
	  }
	  else 
	  {
	       vetDispari[k]= vetOriginale[i];
	       k++;
	  }
	}
	
    //stampare a schermo i numeri pari
	printf("\n\nNUMERI pari");
	for (int f=0; f < contaPari; f++)
	{
	    printf("\n%d", vetPari[f]);
	}
	
	//stampare a schermo i numeri dispari
	printf("\n\nNUMERI dispari");
	for (int f=0; f < contaDispari; f++)
	{
	    printf("\n%d", vetDispari[f]);
	}
}