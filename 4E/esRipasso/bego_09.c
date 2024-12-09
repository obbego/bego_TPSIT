/*Progettare un algoritmo che risolva il seguente problema. Si richieda 
all’utente di inserire una serie di terne di dati numerici (A, B, C). 
Il programma deve terminare quando uno dei valori inseriti è minore di
zero. Si scartino le terne nelle quali i valori non sono in ordine
strettamente crescente, ovvero quelle terne per cui non valga A < B < C.
Su tutte le terne non scartate si calcoli il massimo e il minimo dei
valori inseriti. Si stampino a video tali valori massimi e minimi prima
di terminare il programma.*/

#include <stdio.h>

int main(int argc, char *argv[]) {
    //dichiarazione variabili
	int a = 0, b = 0, c = 0, min = 0, max = 0, primaVolta=0;
	do
	{
		printf("inserisci A\n");
		scanf("%d", &a);
	
		printf("inserisci B\n");
		scanf("%d", &b);
		
		printf("inserisci C\n");
		scanf("%d", &c);
		
		if (a < b && b < c)
		{
			if (primaVolta == 0){
				min = a;
				max = c;
			}
			
			else if (a < min)
				min = a;
			
			if (c > max)
				max = c;
			printf("La terna rispetta i requisiti\n");
		}
		else
		{
			printf("La terna NON rispetta i requisiti\n");
		}
		printf("\n");

	} while (a >= 0 && b >= 0 && c >= 0);

	printf("\nIl numero max inserito: %d\n", max);
	printf("\nIl numero min inserito: %d\n\n", min);
    
	return 0;
}

