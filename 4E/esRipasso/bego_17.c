/*Dato N un numero intero positivo maggiore di 1, 
generare e visualizzare il numero precedente. */

int main(int argc, char *argv[])
{
				
	int n = 0, i;
	
	do
	{
		printf("Inserisci un numero, deve essere >1: \n");
		scanf("%d", &n);
		if (n < 1)
		{
			printf("Il numero non rispetta i requisiti\n\n");
		}
	} while (n < 1);
	
	printf("Il numero precedente: %d", n-1);
	
	return 0;
}