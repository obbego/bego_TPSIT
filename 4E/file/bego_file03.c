/*  Chiediamo in input il nome del file (testoDaLeggere.txt)
    di cui vogliamo conoscere il numero di righe e di caratteri
    Apriamo il file con la funzione fopen.

    Utilizziamo un ciclo while con la funzione fgets,
    che prende tre parametri...
*/

#include <stdio.h>

#define MAX_LEN 81  // dimensione massima di una riga

int main() {
    char nomeFile[260];
    FILE *fp;
    char buffer[MAX_LEN];
    int numRighe = 0;
    int numCaratteri = 0;

    // 1. Chiediamo il nome del file
    printf("Inserisci il nome del file da leggere: ");
    scanf("%s", nomeFile);

    // 2. Apriamo il file
    fp = fopen(nomeFile, "r");
    if (fp == NULL) {
        printf("Errore nell'apertura del file.\n");
        return -1;
    }

    // 3. Leggiamo il file riga per riga
    while (fgets(buffer, MAX_LEN, fp) != NULL) {
        numRighe++;

        // Contiamo i caratteri della riga
        for (int i = 0; buffer[i] != '\0'; i++) {
            numCaratteri++;
        }
    }

    fclose(fp);

    printf("Numero di righe: %d\n", numRighe);
    printf("Numero di caratteri: %d\n", numCaratteri);

    return 0;
}
