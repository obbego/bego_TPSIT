/******************************************************************************
1) Dopo aver caricato in memoria un 2 vettori di uguale 
dimensione composti da numeri interi
scrivere in output un terzo vettore dato 
dalla somma delle componenti fatta a una a una (Vettore somma).
*******************************************************************************/

#include <stdio.h>

void
main ()
{
  //dichiarazione variabili
  int qtaNumeri = 0;

  //ciclo per controllare la dimensione del vettore, che non puo essere <0
  do
	{
	  //chiedere in input la qta
	  printf ("Inserisci la dimensione dei vettori: \n");
	  scanf ("%d", &qtaNumeri);

	  //comunicare l'errore nel caso di qta < 0
	  if (qtaNumeri < 0)
		printf
		  ("ERRORE: la quantitC  dei numeri non puo essere < 0\nRINSERIRE: \n\n");
	}
  while (qtaNumeri < 0);

  //dichiarare i vettori in base alla qta di numeri che l'utente vuole inserire
  float vet1[qtaNumeri], vet2[qtaNumeri], vetSomma[qtaNumeri];

  //popolare il 1 vettore + ciclo for per popolare tutte posizioni
  printf ("\nPOPOLAZIONE 1 vettore: \n");
  for (int i = 0; i < qtaNumeri; i++)
	{
	  //comunicare la posizione che si sta popolando
	  printf ("Inserisci il %d numero: ", i + 1);
	  scanf ("%f", &vet1[i]);
	}

  //popolare il 2 vettore + ciclo for per popolare tutte posizioni
  printf ("\nPOPOLAZIONE 2 vettore: \n");
  for (int i = 0; i < qtaNumeri; i++)
	{
	  //comunicare la posizione che si sta popolando
	  printf ("Inserisci il %d numero: ", i + 1);
	  scanf ("%f", &vet2[i]);
	}

  //ciclo per sommare e stampare a schermo la somma dei 2 vettori
  for (int i = 0; i < qtaNumeri; i++)
	{
	  //nel vettore somma sommare gli altri 2 vet in posizione i  
	  vetSomma[i] = vet1[i] + vet2[i];
	  //stampare a schermo i risultati
	  printf ("La somma dei %d numeri = %.2f ", i + 1, vetSomma[i]);
	}
}
