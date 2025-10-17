/*Scrivere un programma in C che dopo aver dichiarato una struttura denominata Persona con i
seguenti campi: Nome, Cognome, età, codice fiscale, reddito annuo, anno_nascita,residenza(città) ;
determini:
1) La persona con reddito annuo più alto e quella con reddito annuo più basso.Visualizzare
per entrambe: nome, cognome, città e reddito.
2) Ordinare la lista delle persone in base all’anno di nascita** (dal più anziano al più
giovane), e visualizzarla.
3) Consentire all’utente di cercare una persona inserendo il codice fiscale..
4) Visualizzare tutte le persone con reddito superiore o uguale a un valore scelto dall’utente.
5) Calcolare la media dei redditi delle persone registrate nel sistema.
6) Visualizzare tutte le persone nate in un anno specifico, scelto dall’utente;
7) Visualizzare l&#39;elenco delle persone raggruppate per città di residenza, indicando per
ciascuna città: Quante persone vi risiedono, L’età media dei residenti*/

#include<stdio.h>
#include<string.h>

typedef struct 
{
  char nome[20];
  char cognome[20];
  int eta;
  char codiceFiscale[20];
  double redditoAnnuo;
  int annoNascita;
  char residenza[20]; 
} Persona;

void infoPersona(Persona p) {
    printf("Nome: %s, Cognome: %s, Eta: %d, CodiceFiscale: %s, AnnoNascita: %d, Citta: %s, Reddito: %f\n", p.nome, p.cognome, p.eta, p.codiceFiscale, p.annoNascita, p.residenza, p.redditoAnnuo);
}

int presenzaCitta(char elenco[][20], int dimElenco, char citta[]) {
    for (int i = 0; i < dimElenco; i++) {
        if (strcmp(elenco[i], citta) == 0) {
            return 0; // già presente
        }
    }
    return 1; // non trovata
}

void elencoPerCitta(Persona persone[], int dim) {
    char elenco[20][dim];
    int k = 0;
    int nPersone = 0;
    double etaPersone = 0;

    for (int i = 0; i < dim; i++) {
        if (presenzaCitta(elenco, k, persone[i].residenza) == 1) {
            strcpy(elenco[k], persone[i].residenza);
            printf("\nCittà: %s\n", elenco[k]);

            for (int j = 0; j < dim; j++) {
                if (strcmp(persone[j].residenza, elenco[k]) == 0) {
                    infoPersona(persone[j]);
                    nPersone++;
                    etaPersone = etaPersone + persone[j].eta;
                }
            }
            
            printf("\nNella città: %s\n", elenco[k]);
            printf("Il numero di persone è: %d\n", nPersone);
            etaPersone = etaPersone / nPersone;
            printf("L'età media delle persone è: %.2f\n", etaPersone);
            
            k++;
            nPersone = 0;
            etaPersone = 0;
        }
    }
}

int trovaRedditoMin(Persona persone[], int dim){
    int indiceRedMin = 0;
    for(int i = 0; i < dim; i++){
        if(persone[indiceRedMin].redditoAnnuo > persone[i].redditoAnnuo){
            indiceRedMin = i;
        }
    }
    return indiceRedMin;
}

int trovaRedditoMax(Persona persone[], int dim){
    int indiceRedMax = 0;
    for(int i = 0; i < dim; i++){
        if(persone[indiceRedMax].redditoAnnuo < persone[i].redditoAnnuo){
            indiceRedMax = i;
        }
    }
    return indiceRedMax;
}

void ordinaAnno(Persona persone[], int dim){
    Persona temp;
    for (int i = 0; i < dim; i++){
        for (int j = 0; j < dim - i - 1; j++){
            if(persone[j].annoNascita > persone[j+1].annoNascita){
                temp = persone[j];
                persone[j] = persone[j+1];
                persone[j+1] = temp;
            }
        }
    }
}

void visualizzaPersone(Persona persone[], int dim){
    for(int i = 0; i < dim; i++){
        infoPersona(persone[i]);
    }
    printf("\n");
}

int cercaCF (Persona persone[], int dim, char cf[]){
    for(int i = 0; i < dim; i++){
        if(strcmp(cf, persone[i].codiceFiscale) == 0){
            return i;
        }
    }
    return -1;
}

void cercaReddito (Persona persone[], int dim, double redditoRicerca){
    int stampato = 0;
    for(int i = 0; i < dim; i++){
        if(persone[i].redditoAnnuo >= redditoRicerca){
            stampato = 1;
            infoPersona(persone[i]);
        }
    }
    if (stampato == 0){
        printf("Non è stata trovata nessuna persona con quei requisiti\n");
    }
    printf("\n");
}

void cercaAnno (Persona persone[], int dim, int annoRicerca){
    int stampato = 0;
    for(int i = 0; i < dim; i++){
        if(persone[i].annoNascita == annoRicerca){
            stampato = 1;
            infoPersona(persone[i]);
        }
    }
    if (stampato == 0){
        printf("Non è stata trovata nessuna persona con quei requisiti\n");
    }
    printf("\n");
}

double calcolaMediaRedditi(Persona persone[], int dim){
    double somma = 0;
    for(int i = 0; i < dim; i++){
        somma += persone[i].redditoAnnuo; 
    }
    return somma/(double)dim;
}

int main(){
    
    Persona persone[20] = {
        {"Daniele", "Chiarion", 17, "CHRDNL07H27H620J", 2000000, 2007, "Rovigo"},
        {"Francesca", "Bianchi", 22, "BNCFNC03A41H501U", 18000, 2003, "Padova"},
        {"Luca", "Verdi", 45, "VRDLCA78C12F205X", 35000, 1978, "Venezia"},
        {"Giulia", "Rossi", 30, "RSSGLI94E22H501Z", 27000, 1994, "Vicenza"},
        {"Marco", "Neri", 55, "NRIMRC69B15H501Y", 42000, 1969, "Treviso"},
        {"Sara", "Gallo", 19, "GLLSRA05D44H501V", 15000, 2005, "Grignano"},
        {"Alessandro", "Fontana", 28, "FNTLSS96H12H501T", 32000, 1996, "Rovigo"},
        {"Elena", "Ferrari", 33, "FRRLNE91C22H501S", 29000, 1991, "Venezia"},
        {"Matteo", "Costa", 40, "CSTMTT84A01H501R", 37000, 1984, "Vicenza"},
        {"Chiara", "Moretti", 27, "MRTCHR97B15H501Q", 31000, 1997, "Treviso"},
        {"Davide", "Ricci", 50, "RCCDVD74C12H501P", 41000, 1974, "Padova"},
        {"Martina", "Greco", 24, "GRCMRT00E22H501N", 21000, 2000, "Venezia"},
        {"Simone", "Conti", 36, "CNTSMN88A01H501M", 34000, 1988, "Rovigo"},
        {"Valentina", "Barbieri", 29, "BRBVLN95B15H501L", 33000, 1995, "Vicenza"},
        {"Federico", "Sartori", 42, "SRTFDR82C22H501K", 39000, 1982, "Treviso"},
        {"Laura", "Martini", 31, "MRTLRA93D44H501J", 28000, 1993, "Padova"},
        {"Andrea", "De Luca", 38, "DLCDRA86H12H501H", 36000, 1986, "Venezia"},
        {"Paolo", "Rinaldi", 47, "RNLPLO77A01H501G", 40000, 1977, "Rovigo"},
        {"Marta", "Pellegrini", 26, "PLLMRT98B15H501F", 30000, 1998, "Vicenza"},
        {"Giovanni", "Sanna", 34, "SNNGVN90C22H501E", 35000, 1990, "Treviso"}
    };

    int dim = sizeof(persone) / sizeof(persone[0]);

    printf("Persona con reddito Minore: \n");
    infoPersona(persone[trovaRedditoMin(persone, dim)]);
    printf("\nPersona con reddito Maggiore: \n");
    infoPersona(persone[trovaRedditoMax(persone, dim)]);
    printf("\n");

    ordinaAnno(persone, dim);
    visualizzaPersone(persone, dim);

    char CF_ricerca[20];
    printf("Inserisci C.F. per ricerca: \n");
    scanf("%s", CF_ricerca);
    int indiceCF = cercaCF(persone, dim, CF_ricerca);
    if (indiceCF == -1){
        printf("Non sono state trovate persone con quel CF\n");
    }
    else{
        infoPersona(persone[indiceCF]);
        printf("\n");
    }

    double reddito_ricerca;
    printf("Inserisci un reddito minimo per ricerca: \n");
    scanf("%lf", &reddito_ricerca);
    cercaReddito(persone, dim, reddito_ricerca);

    printf("La media di tutti i redditi equivale a:\n");
    printf("%.2f\n", calcolaMediaRedditi(persone, dim));

    int anno_ricerca;
    printf("Inserisci anno per ricerca: \n");
    scanf("%d", &anno_ricerca);
    cercaAnno(persone, dim, anno_ricerca);
    
    elencoPerCitta(persone, dim);

    return 0;
}
