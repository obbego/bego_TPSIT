#include <stdio.h>       //std in-out
#include <stdlib.h>      //per utilizzo di certe funzioni:htonl,rand,....
#include <sys/socket.h>  //funz. accept+bind+listen
#include <sys/types.h>   //funz. accept
#include <netinet/in.h>  //definiscono la struttura degli indirizzi
#include <string.h>      //funz. stringhe
#include <errno.h>       //gestioni errori connessione
#include <ctype.h>       //bind
#include <unistd.h>      //API POSIX
#include <arpa/inet.h>   //SERVE PER inet_addr()
#include <stdbool.h>     //Per variabili BOOL


#define SERVERPORT 1450

int main(){
    //CLIENT taxi

    /* BRAINSTORMING CON IL DANIEL
       - prima invio stringa: RIPRISTINO o RICHIESTA
       - se RICHIESTA devo chiedere partenza e destinazione
    */

    //STRUTTURA PER LA CONNESSIONE
    struct sockaddr_in servizio;
    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr = inet_addr("192.168.60.200"); //IP server
    servizio.sin_port = htons(SERVERPORT);

    //BUFFER
    char tipoServizio[20];
    char partenza[50];
    char destinazione[50];
    bool risultato;
    int socketfd;

    while(1){
        //FASE 1 CREAZIONE SOCKET
        socketfd = socket(AF_INET, SOCK_STREAM, 0);

        //FASE 2 CONNECT - Con controllo connessione
        if(connect(socketfd, (struct sockaddr*)&servizio, sizeof(servizio)) < 0){
            printf("ERRORE: impossibile connettersi al server! Server offline o non raggiungibile.\n");
            close(socketfd);
            return 1;   // TERMINA IL PROGRAMMA
        }

        //SCELTA OPERAZIONE
        int scelta;
        printf("\n1) Richiesta taxi\n2) Taxi rientrato\nScelta: ");
        scanf("%d", &scelta);

        if(scelta == 1){
            //RICHIESTA TAXI
            strcpy(tipoServizio, "RICHIESTA");

            //FASE 3 WRITE: tipo richiesta
            if(write(socketfd, tipoServizio, sizeof(tipoServizio)) < 0){
                printf("ERRORE: nessuna risposta dal server. Terminazione programma.\n");
                close(socketfd);
                return 1;
            }

            printf("Inserisci partenza: ");
            scanf(" %[^\n]", partenza);

            printf("Inserisci destinazione: ");
            scanf(" %[^\n]", destinazione);

            //INVIO dati
            write(socketfd, partenza, sizeof(partenza));
            write(socketfd, destinazione, sizeof(destinazione));

            //FASE 4 READ ESITO
            if(read(socketfd, &risultato, sizeof(risultato)) <= 0){
                printf("ERRORE: il server non ha risposto alla richiesta.\n");
                close(socketfd);
                return 1;
            }

            if(risultato == true)
                printf("Richiesta accettata! Taxi disponibile.\n");
            else
                printf("Richiesta rifiutata! Taxi terminati.\n");

        } else if(scelta == 2){
            //RIPRISTINO TAXI
            strcpy(tipoServizio, "RIPRISTINO");

            //invio codice
            if(write(socketfd, tipoServizio, sizeof(tipoServizio)) < 0){
                printf("ERRORE: impossibile inviare dati al server.\n");
                close(socketfd);
                return 1;
            }

            printf("Hai segnalato un taxi rientrato.\n");

        } else {
            printf("Scelta non valida.\n");
        }

        //FASE 5 CLOSE
        close(socketfd);
    }

    return 0;
}
