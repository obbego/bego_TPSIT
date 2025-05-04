#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Numero di argomenti non valido\n");
        exit(1);
    }

    int input;

    FILE *file;
    file = fopen(argv[1], "wb");
    if (file == NULL)
    {
        printf("Errore nell'apertura file in modalita di scrittura");
        exit(1);
    }

    for (int i = 0; i < 5; i++)
    {
        printf("Inserisci il numero: ");
        scanf("%d", &input);
        fwrite(&input, sizeof(input), 1, file);
    }
    
    fclose(file);
    file = fopen(argv[1], "rb");
    if (file == NULL)
    {
        printf("Errore nell'apertura file in lettura\n");
        exit(1);
    }

    while (fread(&input, sizeof(input), 1, file) > 0)
    {
        printf("\nNumero letto: %d", input);
    }
    printf("\n");

    fclose(file);
    return 0;
}