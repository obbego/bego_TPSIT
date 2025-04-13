/*Il file.txt rappresenta le fatture dell’ultimo mese della ditta ProgrammatoriHero srl
e contiene 3 campi: codice, “pagato” o “insoluto”, l’importo

Si vuole realizzare un programma concorrente in linguaggio C che mostri a video l'importo totale delle fatture emesse.

Si usi la seguente procedura:
Si generi un processo figlio P1 che legge il file e lo manda al processo P2 il quale
estrapola la terza colonna del file, e la manda al processo P0.
Il processo P0 riceve quindi tutti gli importi, ne calcola il totale e lo mostra a video.

Note operative
Il processo P1 usi il comando cat per mostrare il contenuto del file e inviarlo a P2
Il processo P2 usi il comando: awk '{print $3}' per estrapolare la terza colonna
Il processo P2 deve inviare al processo P0 la terza colonna
Il processo P0 deve leggere in input tutti i valori e per ogni lettura deve incrementare la variabile accumulatore “totale”

Osservazione:
strncat(strimporto, &buffer[0], sizeof(buffer[0]))
Aggiunge in coda alla stringa strimporto il carattere buffer[0] la cui dimensione è sizeof(buffer[0])

Osservazione:
char *ptr;
double x = strtod(strimporto, &ptr);
strtod converte la stringa strimporto in double.

Osservazione:
strimporto[0] = '\0';
Pone in posizione 0 di una stringa il carattere terminatore, in questo modo si resetta a livello logico una stringa*/

int main(int argv, char *argc[])
{
    int p1p2
}