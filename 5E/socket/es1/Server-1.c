#include <stdio.h>       //std in-out
#include <stdlib.h>      //per utilizzo di certe funzioni:htonl,rand,....
#include <sys/socket.h>  //funz. accept+bind+listen
#include <sys/types.h>   //funz. accept
#include <netinet/in.h>  //definiscono la struttura degli indirizzi
#include <string.h>      //funz. stringhe
#include <errno.h>       //gestioni errori connessione
#include <ctype.h>       //bind
#include <unistd.h>     // file header che consente l'accesso alle API dello standard POSIX

#define Serverport 1450

int main(){
    //SERVER
    
    //FASE 1 CREAZIONE SOCKET
    struct sockaddr_in servizio;

    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr=htonl(INADDR_ANY); //htnol converte indirizzo in bit
    servizio.sin_port = htons(Serverport);

    char stringa[20];
    int socketfd, soa, fromlen = sizeof(servizio); //socket file descriptor -> contiene dei valori/prametri, soa -> risultato per la sycall accept
    socketfd = socket(AF_INET, SOCK_STREAM, 0); // AF_INET (?),SOCK_STREAM conectionful, con 0 si sceglie il protocollo in automatico

    //FASE 2 BIND -> indirizzo host con indirizzo socket
    bind(socketfd,(struct sockaddr*)&servizio,sizeof(servizio)); //socketfd per vedere se la socket ha avuto successo, (struct sockaddr*)&servizio per dare indirizzo e porte, sizeof(servizio) per dimensione
    
    //FASE 3 LISTEN
    listen(socketfd,10);
    while(1){
        printf("Server in ascolto\n");
        fflush(stdout);
        //FASE 4 ACCEPT
        soa = accept(socketfd,(struct sockaddr*)&servizio, &fromlen);
        //FASE 5 READ
        read(soa, stringa, sizeof(stringa));
        //FASE 6 WRITE
        printf("Stringa ricevuta: %s\n", stringa);
        //FASE 7 CLOSE
        close(soa);
    }
    return 0;
}