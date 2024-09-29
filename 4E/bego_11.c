/*Dato N un numero intero positivo, generare e 
visualizzare il numero successivo.*/

#include <stdio.h>

int main(int argc, char *argv[])
{
	
	int n = 0;
	
	do
	{
		printf("Inserisci un numero, deve essere positivo: \n");
		scanf("%d", &n);
		if (n < 0)
		{
			printf("Il numero non rispetta i requisiti\n\n");
		}
	} while (n < 0);
	
	printf ("Il numero successivo corrisponde a %d", n+1);
	
	return 0;
}
