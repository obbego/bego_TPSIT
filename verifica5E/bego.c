//FRANCESCO BEGO 5E 18/10/2025
#include<stdio.h>
#include<string.h>


//DEFINIZIONE STRUTTRA
typedef struct {
    char nome[20];
    char regione[20];
    int nAbitantiPrecedenti;
    int nAbitantiAttuali;
} Citta;

//Funzione per stampare tutte le info della citta
void infoCitta(Citta c) {
    printf("NOME: %s, REGIONE: %s, NUMERO ABITANTI PRECEDENTI: %d, NUMERO ABITANTI ATTUALI: %d\n", c.nome, c.regione, c.nAbitantiPrecedenti, c.nAbitantiAttuali);
}

//Funzione per inserire manualmente le info delle citta
void inserisciCitta(Citta array[], int dim){
    for (int i = 0; i < dim; i++){
        printf("Inserisci il nome della città: n.%d\n", i+1);
        scanf("%s", array[i].nome);
        
        printf("Inserisci la regione della città: n.%d\n", i+1);
        scanf("%s", array[i].regione);

        printf("Inserisci nAbitanti precedenti: n.%d\n", i+1);
        scanf("%d", &array[i].nAbitantiPrecedenti);

        printf("Inserisci nAbitanti attuali: n.%d\n", i+1);
        scanf("%d", &array[i].nAbitantiAttuali);

        printf("\n\n");
    }
}

//Funzione per calcolare la media degli abitanti precedenti
double mediaAbitantiPrecedenti(Citta array[], int dim){
    double sommaAbitanti = 0;
    for (int i = 0; i < dim; i++){
        sommaAbitanti += array[i].nAbitantiPrecedenti;
    }

    return sommaAbitanti / (double)dim;
}

//Funzione per cercare una citta dato un parametro contenente la regione
void cercaPerRegione(Citta array[], int dim, char regioneRicerca[20]) {
    int stampato = 0;
    for(int i = 0; i < dim; i++){
        if(strcmp(array[i].regione, regioneRicerca) == 0){
            infoCitta(array[i]);
            stampato = 1;
        }
    }
    //controllo sia stato stampato qualcosa
    if (stampato == 0){
        printf("Non è stata trovata nessuna citta con la regione: %s\n", regioneRicerca);
    }
}

//Funzione che calcola la variazione degli abitanti
void calcolaVariazione(Citta array[], int dim){
    int variazione = 0;
    for (int i = 0; i < dim; i++){
        variazione = array[i].nAbitantiAttuali - array[i].nAbitantiPrecedenti;

        //output personalizzato
        if(variazione > 0){
            printf("La popolazione è aumentata di: %d abitanti\n", variazione);
        }
        else if(variazione < 0){
            printf("La popolazione è diminuita di: %d abitanti\n", variazione);
        }
        else {
            printf("La popolazione è rimasta invariata\n");
        }

        //reset variazione
        variazione = 0;
    }
}

//funzione per eliminare la citta dall'elenco
void scalaArray(Citta array[], int pos, int dim){
    for (int i = pos; i < dim - 1; i++){
        array[i] = array[i+1];
    }
}

//Funzione che cancella la citta e ritorna la nuova dimensione dell'array
int cancellaCitta(Citta array[], int dim, char nomeRicerca[]){
    for (int i = 0; i < dim; i++){
        if (strcmp(array[i].nome, nomeRicerca)){
            scalaArray(array, i, dim);
            dim--;
        }
    }
    return dim;
}

//funzione che stampa tutte le citta nell'array
void visualizzaCitta(Citta array[], int dim){
    for(int i = 0; i < dim; i++){
        infoCitta(array[i]);
    }
}


int main(){
    int dim = 0;
    
    printf("Quante cità vuoi inserire: \n");
    scanf("%d", &dim);

    //dichiarazione array di struttura citta
    Citta array[dim];
    
    //PUNTO 1
    inserisciCitta(array, dim);

    //PUNTO 2
    printf("La media degli abitanti prededenti: \n");
    printf("%.2f\n", mediaAbitantiPrecedenti(array, dim));

    //PUNTO 3
    char regioneRicerca[20];
    printf("Inserisci regione per ricerca: \n");
    scanf("%s", regioneRicerca);
    cercaPerRegione(array, dim, regioneRicerca);

    //PUNTO 4
    calcolaVariazione(array, dim);

    //PUNTO 5
    char nomeRicerca[20];
    printf("Inserisci il nome della citta per cancellarla: \n");
    scanf("%s", nomeRicerca);
    int oldDim = dim;
    dim = cancellaCitta(array, dim, nomeRicerca);
    if (oldDim!= dim) {
        printf("Elenco città senza: %s\n", nomeRicerca);
        visualizzaCitta(array, dim);
    }
    else {
        printf("Errore nella cancellazione");
    }

    return 0;
}