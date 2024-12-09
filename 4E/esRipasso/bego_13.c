/*Dato N un numero intero positivo, generare e visualizzare 
in ordine crescente i numeri dispari minori o uguali a N.*/

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
	
	for (i = 0; i <= n; i++)
	{
		if (!(i%2==0))
		{
			printf ("N dispari: %d\n", i);
		}
	}
	
	
	return 0;
}
