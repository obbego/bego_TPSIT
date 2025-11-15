#include <stdio.h>       //std in-out
#include <stdlib.h>      //per utilizzo di certe funzioni:htonl,rand,....
#include <sys/socket.h>  //funz. accept+bind+listen
#include <sys/types.h>   //funz. accept
#include <netinet/in.h>  //definiscono la struttura degli indirizzi
#include <string.h>      //funz. stringhe
#include <errno.h>       //gestioni errori connessione
#include <ctype.h>       //bind
#include <unistd.h>      //API POSIX

#define Serverport 1450

int main(){
    //SERVER
    
    //FASE 1 CREAZIONE SOCKET
    struct sockaddr_in servizio;

    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr = htonl(INADDR_ANY); 
    servizio.sin_port = htons(Serverport);

    char stringa[40];
    int socketfd, soa, fromlen = sizeof(servizio);

    socketfd = socket(AF_INET, SOCK_STREAM, 0);

    //FASE 2 BIND
    bind(socketfd, (struct sockaddr*)&servizio, sizeof(servizio));

    //FASE 3 LISTEN
    listen(socketfd, 10);

    while(1){
        printf("Server in ascolto...\n");
        fflush(stdout);

        //FASE 4 ACCEPT
        soa = accept(socketfd, (struct sockaddr*)&servizio, &fromlen);

        //FASE 5 READ
        read(soa, stringa, sizeof(stringa));
        printf("Stringa ricevuta: %s\n", stringa);

        //CONTROLLO (semplice)
        if(strlen(stringa) > 0){
            strcpy(stringa, "Messaggio ricevuto");
        } else {
            strcpy(stringa, "Errore: messaggio vuoto");
        }

        //FASE 6 WRITE
        write(soa, stringa, sizeof(stringa));

        //FASE 7 CLOSE
        close(soa);
    }

    return 0;
}
