/*Dato N un numero intero positivo, generare e visualizzare in ordine
decrescente i primi N numeri interi positivi.*/

int main(int argc, char *argv[])
{		
	int n = 0, i;
	
	do
	{
		printf("Inserisci un numero, deve essere positivo: \n");
		scanf("%d", &n);
		if (n < 0)
		{
			printf("Il numero non rispetta i requisiti\n\n");
		}
	} while (n < 0);
	
	for(int i = n; i >= 0; i--) 
    {
        printf("N: %d\n", i);
    }
	
	return 0;
}