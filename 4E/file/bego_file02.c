#include <stdio.h>

int main()
{
    char car;

    printf("\nInserisci un carattere da tastiera  >>   ");
    // getc()legge un singolo carattere da file o dallo stdin
    car = getc(stdin);
    printf("\nHai inserito: %c\n", car); // carattere
    printf("\nHai inserito: %d\n", car); // ascii

    // putc() scrive un solo carattere su file o stdout
    putc(car, stdout);

    // scrivo carattere su file
    FILE *fp;
    fp = fopen("output.txt", "w");
    if (fp != NULL) // apertura con successo
    {
        printf("\n apertura con successo");
        putc(car, fp);
        fclose(fp);
    }
    else printf("\nErrore apertura file\n");

    putchar(car);
    printf("\n");

    return 0;    
}