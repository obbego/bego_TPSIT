#include <stdio.h>
#include <string.h> //libreria per le stringhe

int main() {
//dichiarazione variabile
    int numAzioni = 0;
    char input[50];
    int inserimento = 1; 
    float azioniPrezzo = 0; 
    float sommaPrezzi = 0;
    float valMax = 0;
    float valMin=0;
    int azioneMax=0;
    int azioneMin=0;
    float mediaPrezzi=0;
    float sommaParziale=0;
    int numAzioniParz=0;
    float mediaParziale=0; 

//inserimento dei valori
    while (inserimento==1) 
    {
        printf("Inserire la denominazione dell'azione (o 'terminato' per uscire): ");
        scanf("%s", input);

        //controllo valore inserito diverso da terminato
        if (strcmp(input, "terminato") == 0) //funzione per confrontare una stringa 
        {
            inserimento = 0; //condizione per far uscire dal ciclo
        }

        if (inserimento == 1) //condizione per far continuare il ciclo 
        {
            do { //inserimento e controllo prezzo azione
            printf("Inserire il prezzo dell'azione: ");
            scanf("%f", &azioniPrezzo);

            if (azioniPrezzo <= 0) 
            {
                printf("Il prezzo deve essere maggiore di zero. Rinserire.\n");
            }
        } while (azioniPrezzo <= 0);
                
        // calcola la somma dei prezzi delle azioni
        sommaPrezzi = sommaPrezzi + azioniPrezzo;
        
        //conteggio numero azioni per media + max/min
        numAzioni++;
        
        //conteggio per media azioni importo tra 2,50 e 3,50
        if ((azioniPrezzo>=2.50) && (azioniPrezzo<=3.50))
        {
            sommaParziale = sommaParziale + azioniPrezzo;
            numAzioniParz ++; 
        }
        //conteggio max/min 
        if (numAzioni==1)
        {
            valMin=azioniPrezzo; 
            valMax=azioniPrezzo;
            azioneMax=numAzioni;
            azioneMin=numAzioni;
        }
        else
        {
            if (valMin>azioniPrezzo)
            {
                valMin=azioniPrezzo;
                azioneMin=numAzioni;
            }
            
             if (valMax<azioniPrezzo)
            {
                valMax=azioniPrezzo;
                azioneMax=numAzioni;
            }
        }
        }
    }
    //calcolo medie
    mediaPrezzi = sommaPrezzi / numAzioni;
    mediaParziale = sommaParziale / numAzioniParz; 
        // Visualizza i risultati
    if(numAzioni>0)
    {
        printf("\nRisultati:\n");
        printf("1) Somma dei prezzi delle azioni: %.2f\n", sommaPrezzi);
        printf("2) Media dei prezzi delle azioni: %.2f\n", mediaPrezzi);
        printf("3) L'azione con il prezzo massimo è la: %d,con %.2f euro\n", azioneMax, valMax);
        printf("4) L'azione con il prezzo minimo è la: %d,con %.2f euro\n", azioneMin, valMin);
        printf("5) Media dei prezzi delle azioni con un importo compreso tra 2,50 e 3,50 euro: %.2f\n", mediaParziale);
    }
     else {
        printf("Nessuna azione inserita.\n");
    }

    return 0;
}