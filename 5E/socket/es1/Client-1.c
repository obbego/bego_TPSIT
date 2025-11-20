#include <stdio.h>       //std in-out
#include <stdlib.h>      //per utilizzo di certe funzioni:htonl,rand,....
#include <sys/socket.h>  //funz. accept+bind+listen
#include <sys/types.h>   //funz. accept
#include <netinet/in.h>  //definiscono la struttura degli indirizzi
#include <string.h>      //funz. stringhe
#include <errno.h>       //gestioni errori connessione
#include <ctype.h>       //bind
#include <unistd.h>     // file header che consente l'accesso alle API dello standard POSIX
#include <arpa/inet.h> 

#define Serverport 1450

int main(){
    //CLIENT
    
    //FASE 1 CREAZIONE SOCKET
    struct sockaddr_in servizio;

    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr=htonl(INADDR_ANY); //htnol converte indirizzo in bit
    servizio.sin_port = htons(Serverport);
    //servizio.sin_addr.s_addr = inet_addr("192.168.60.155"); //IP server

    char stringa[20];
    int socketfd; //socket file descriptor -> contiene dei valori/prametri
    socketfd = socket(AF_INET, SOCK_STREAM, 0); // AF_INET (?),SOCK_STREAM conectionful, con 0 si sceglie il protocollo in automatico

    //FASE 2 CONNESIONE
    connect(socketfd,(struct sockaddr*)&servizio,sizeof(servizio)); //socketfd per vedere se la socket ha avuto successo, (struct sockaddr*)&servizio per dare indirizzo e porte, sizeof(servizio) per dimensione
    printf("Inserisci la stringa: \n");
    scanf("%s", stringa);

    //FASE 3 WRITE
    write(socketfd, stringa, sizeof(stringa)); 
    close(socketfd);

    return 0;
}