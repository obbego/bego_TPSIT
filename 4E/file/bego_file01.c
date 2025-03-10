#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Tipo di dato, un'oggetto, una struttura definita in stdio.h
    FILE *nomi;     // definisco una variabile di tipo puntatore a FILE
    
    nomi = fopen("nomi.txt", "w"); // APRE UN FILE, restituisce un puntatore a FILE
    //"w" == scrittura (se non esiste viene creato o se esiste viene sovrascritto)
    //"a" == append (aggiunge)
    return 0;
}