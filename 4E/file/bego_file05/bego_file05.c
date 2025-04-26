/*Leggi il file numeri.txt composto da una
sequenza di numeri separati da uno spazio.
Scrivi due file, pari.txt e dispari .txt,
nei quali inserisci i numeri letti a seconda del
loro valore pari o dispari.*/

#include <stdio.h>

int main()
{
    char file[260];
    FILE *fp, *fpP, *fpD;

    // 1. Chiediamo il nome del file da cui leggere
    printf("Inserisci il nome del file da cui leggere: ");
    scanf("%s", file);

    // 2. Apriamo il file
    fp = fopen(file, "r");
    if (fp == NULL)
    {
        printf("Errore nell'apertura del file da leggere.\n");
        return -1;
    }

    fpP = fopen("pari.txt", "w");
    if (fpP == NULL)
    {
        printf("Errore nell'apertura del file su cui scrivere i pari.\n");
        return -1;
    }

    fpD = fopen("dispari.txt", "w");
    if (fpD == NULL)
    {
        printf("Errore nell'apertura del file su cui scrivere i dispari.\n");
        return -1;
    }

    // 3. Leggiamo e scriviamo
    char c;
    while ((c = fgetc(fp)) != EOF)
    {
        if (!(c == ' '))
        {
            if ((c - '0') % 2 == 0)
            {
                fputc(c, fpP);
                fputc(' ', fpP);
            }
            else
            {
                fputc(c, fpD);
                fputc(' ', fpD);
            }
        }
    }

    printf("Scrittura avvenuta con successo\n");

    fclose(fp);
    fclose(fpP);
    fclose(fpD);

    return 0;
}