/*Una birreria a fine serata deve conteggiare l’incasso. La cassiera accende il software gestionale il quale le chiede di inserire una alla volta le consumazioni servite.
Le consumazioni si dividono in bevande e ristorazione. La cassiera per ogni consumazione deve inserire la tipologia di consumazione e il suo importo.

Quando la cassiera inserisce la stringa “esci” il software deve mostrare a video le seguenti informazioni:
1.	La media dell’incasso delle bevande 
2.	La media dell’incasso della ristorazione
3.	Deve indicare se sono state vendute più bevande o più ristorazioni*/

#include <string.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
	//dichiarazione variabili
	double import, sommaBevande = 0, sommaRistorazione = 0, mediaBevande = 0, mediaRistorazione = 0;
	char tipo[12];
    int contaRistorazione = 0, contaBevande = 0;

    do
    {
        do {
            printf("Scrivi: \n [] bevande \n [] ristorazione \n [] esci\n");
            scanf("%s", tipo);
            if ((strcmp("esci", tipo) != 0 && strcmp(tipo, "bevande") != 0 && strcmp(tipo, "ristorazione") != 0))
            	printf("La parola inserita non e' corretta.\nRinserire\n");
        } while (strcmp("esci", tipo) != 0 && strcmp(tipo, "bevande") != 0 && strcmp(tipo, "ristorazione") != 0);

        do
        {
            if (strcmp("esci", tipo)==0)
            	break;
			printf("Importo: \n");
            scanf("%lf", &import);
            if (import <= 0)
            	printf("Non puoi inserire importo negativo\nRinserire\n");
        } while (import <= 0);

        if (strcmp(tipo, "bevande") == 0)
        {
            contaBevande++;
            sommaBevande += import;
        }

        if (strcmp(tipo, "ristorazione") == 0)
        {
            contaRistorazione++;
            sommaRistorazione += import;
        }

    } while (strcmp(tipo, "esci") != 0);

    if (contaRistorazione > contaBevande)
    {
        printf("Sono state vendute piu' ristorazioni\n");
    }
    else if (contaRistorazione == contaBevande)
	{
    	printf("Sono state vendute lo stesso numero di ristorazioni e bevande\n");
	}
	else
    {
        printf("Sono state vendute piu' bevande\n");
    }

    mediaBevande = sommaBevande / contaBevande;
    mediaRistorazione = sommaRistorazione / contaRistorazione;

    if(contaBevande > 0)
		printf("Media delle bevande: %f\n", mediaBevande);
    if(contaRistorazione > 0)
		printf("Media delle ristorazioni: %f\n", mediaRistorazione);
    
	return 0;
}
