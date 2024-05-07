#include <stdio.h>
#include <string.h>

int main() {
    //dichiarazione variabile
    int nStudenti = 0, contaInsufficenti = 0, contaSufficenti = 0, contaSecchioni = 0, scelta = 0;
    float votoMax = 0, votoMin = 0, votoMedia = 0;
    char nomeStudente[21], studenteMax[21], studenteMin[21];

    //inizio ciclo per permettere la ripetizione del codice
    do {
        //controllo numero inserito
        while (nStudenti <= 0) {
            printf("\nInserisci il numero di studenti della Classe: ");
            scanf("%d", &nStudenti);
            if (nStudenti <= 0) // comunicare l'errore
                printf("Numero di studenti non accettabile. Riprova.\n");
        }

        float vettVoti[nStudenti]; //dichiarazione vettore in base al numero di studenti

        //ciclo per inserire tutti i voti per tutti gli studenti
        for (int i = 0; i < nStudenti; i++) {
            printf("\nInserisci il nome del %d° studente (max 20 caratteri): ", i + 1);
            scanf("%s", nomeStudente);

            printf("Inserisci il voto di %s: ", nomeStudente);
            scanf("%f", &vettVoti[i]);
            //controllare la validità del voto
            while (vettVoti[i] < 0 || vettVoti[i] > 10) {
                printf("Voto non accettabile. Riprova: ");
                scanf("%f", &vettVoti[i]);
            }

            //aggiungere il voto ad una variabile per calcolare la media
            votoMedia += vettVoti[i];

            //controllo se è il 1° numero inserito per impostare il numero max e min e il nome
            if (i == 0) {
                strcpy(studenteMax, nomeStudente);
                strcpy(studenteMin, nomeStudente);
                votoMax = vettVoti[i];
                votoMin = vettVoti[i];
            } 
            //dopo il 1° inserimento
            else {
                //controllo per verificare se cè un nuovo numero max
                if (vettVoti[i] > votoMax) {
                    votoMax = vettVoti[i];
                    strcpy(studenteMax, nomeStudente);
                }
                //controllo per verificare se cè un nuovo numero min
                if (vettVoti[i] < votoMin) {
                    votoMin = vettVoti[i];
                    strcpy(studenteMin, nomeStudente);
                }
            }
            //controllo per aumentare il rispettivo contatore
            if (vettVoti[i] < 6)
                contaInsufficenti++;
            else {
                contaSufficenti++;
                if (vettVoti[i] >= 7.5)
                    contaSecchioni++;
            }
        }
        
        //calcolo media
        votoMedia = votoMedia / nStudenti;
        
        //stampare a schermo i risultati
        printf("\nLa media dei voti corrisponde a: %.2f", votoMedia);
        printf("\nIl voto più alto è di %s: %.2f", studenteMax, votoMax);
        printf("\nIl voto più basso è di %s: %.2f", studenteMin, votoMin);
        printf("\nIl numero di insufficenti è: %d", contaInsufficenti);
        printf("\nIl numero di sufficenti è: %d", contaSufficenti);
        printf("\nIl numero di voti superiori a 7.5 è %d", contaSecchioni);

        //chiedere al'utente se vuole ripetere il codice
        printf("\n\nVuoi inserire un'altra classe?\nInserisci 1 per ripetere: ");
        scanf("%d", &scelta);
        
        //rinizializzazione delle variabili
        nStudenti = 0;
        contaInsufficenti = 0;
        contaSufficenti = 0;
        contaSecchioni = 0;
        votoMax = 0;
        votoMin = 0;
        votoMedia = 0;
        
    } while (scelta == 1); //condizione per ripetere il codice

    return 0;
}
