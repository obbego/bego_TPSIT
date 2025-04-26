/*Copia, carattere per carattere, il contenuto di un file
già esistente in un secondo file, da creare.
I nomi dei file devono essere inseriti in input dall'utente.*/

#include <stdio.h>

int main()
{
    char file1[260], file2[260];
    char c;
    FILE *fp1, *fp2;

    // 1. Chiediamo il nome del file da cui leggere
    printf("Inserisci il nome del file da cui leggere: ");
    scanf("%s", file1);

    // Su cui scrivere
    printf("Inserisci il nome del file su cui scrivere: ");
    scanf("%s", file2);

    // 2. Apriamo il file
    fp1 = fopen(file1, "r");
    if (fp1 == NULL)
    {
        printf("Errore nell'apertura del file da leggere.\n");
        return -1;
    }

    fp2 = fopen(file2, "w");
    if (fp2 == NULL)
    {
        printf("Errore nell'apertura del file su cui scrivere.\n");
        return -1;
    }


    // 3. Leggiamo e scriviamo
    while ((c = fgetc(fp1)) != '\0') {
        fputc(c, fp2);
    }

    printf("Scrittura avvenuta con successo sul file %s", file2);

    fclose(fp1);
    fclose(fp2);

    return 0;
}