/*Dati due numeri interi positivi N1 e N2 con N2>N1, generare e
visualizzare in ordine crescente i numeri interi compresi
nell'intervallo chiuso [N1,N2].*/

int main(int argc, char *argv[])
{
			
	int n1 = 0, n2 = 0, i;
	
	do
	{
		printf("Inserisci il primo numero, deve essere positivo: \n");
		scanf("%d", &n1);
		
		if (n1 < 0)
		{
			printf("Il numero non rispetta i requisiti\n\n");
		}
		
		else 
		{
			printf("Inserisci un secondo numero, deve essere > di N1: \n");
			scanf("%d", &n2);
		
			if (n1 > n2)
			{
				printf("Il numero non rispetta i requisiti\n\n");
			}
		}
	} while ((n1 < 0) && (n1 > n2));
	

	for (i = n1; i <= n2; i++)
	{
			printf ("N: %d\n", i);
	}
	
	return 0;
}
