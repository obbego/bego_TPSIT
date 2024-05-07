/*Scrivere un programma in C che dopo aver inserito
i cognomi e i voti di una classe di studenti
determini e/o verifichi: 
1) La media dei voti visualizzando, inoltre il numero di studenti inseriti;   
 2) Il voto massimo, il voto minimo ed I relativi cognomi degli studenti  
 3) Il numero degli studenti che hanno una valutazione sufficiente o superiore
 4) Il numero degli studenti che hanno una valutazione insufficiente o inferiore;   
 5) Il numero di studenti che hanno un voto compreso tra 7.50 e 10 estremi inclusi.
Il programma deve permettere il re-inserimento degli studenti e dei relativi voti.*/

#include <stdio.h>
#include <string.h>

void main()
{
    int nStudenti=0, contaInsufficenti=0, contaSufficenti=0, contaSecchioni=0, scelta=0;
    float votoMax=0, votoMin=0, votoMedia=0; 
    char nomeStudente[21], studenteMax[21], studenteMin[21];

    do
    {
        while(nStudenti<=0)
        {
        printf("Inserisci il numero di studenti della Classe");
        scanf("%d", &nStudenti);
        if (nStudenti<=0)
        printf("Numero di studenti non accettabile\n Rinserire");
        }

        float vettVoti[nStudenti]; 

            printf("Inserisci il nome del 1: studente\n(max 20 caratteri)");
            scanf("%s", &nomeStudente);
            strcpy(nomeStudente,studenteMax);
            strcpy(nomeStudente,studenteMin);
            do
            {
            printf("Inserisci il voto di %s: ", nomeStudente);
            scanf("%f", &vettVoti[0]);
            if (vettVoti[0]<0 || vettVoti[0]>10)
            {
                printf("Voto non accettabile\n Rinserire");
            }
            }
            while(vettVoti[0]<0 || vettVoti[0]>10);
            votoMax=vettVoti[0];
            votoMin=vettVoti[0];
            votoMedia=+vettVoti[0];


        for(int i=1; i < nStudenti; i++)
        {
            printf("Inserisci il nome del %d: studente\n(max 20 caratteri)", (i+1));
            scanf("%s", &nomeStudente);
            
            do
            {
            printf("Inserisci il voto di %s: ", nomeStudente);
            scanf("%f", &vettVoti[i]);
            if (vettVoti[i]<0 || vettVoti[i]>10)
            {
                printf("Voto non accettabile\n Rinserire");
            }
            }
            while(vettVoti[i]<0 || vettVoti[i]>10);
            votoMedia=+vettVoti[i];

            if (vettVoti[i] < votoMin)
            {
                votoMin=vettVoti[i];
                strcpy(nomeStudente,studenteMax);
            }
            
            if (vettVoti[i] > votoMax)
            {
                votoMin=vettVoti[i];
                strcpy(nomeStudente,studenteMin);
            }
            
            if (vettVoti[i]<6) 
            {
                contaInsufficenti++;
            }
            else
            {
                contaSufficenti++; 
                if(vettVoti[i]>=7.5)
                {
                    contaSecchioni++;
                }
            }          
        }
        votoMedia = votoMedia/nStudenti;
        printf("\nLa media dei voti corrisponde a: %.2f", votoMedia);
        printf("\nIl voto più alto è di %s: %.2f",studenteMax, votoMax);
        printf("\nIl voto più basso è di %s: %.2f",studenteMin, votoMin);
        printf("\nIl numero di insufficenti è %d", contaInsufficenti); 
        printf("\nIl numero di sufficenti è %d", contaSufficenti); 
        printf("\nIl numero di voti superiori a 7.5 è %d", contaSecchioni); 
        
        printf("\n\nVuole inserire un altra classe?\nInserisci 1 per ripetere");
        scanf("%d", &scelta);
    }
    while(scelta==1);
}