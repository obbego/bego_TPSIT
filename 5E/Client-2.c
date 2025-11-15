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
    //CLIENT

    //FASE 1 CREAZIONE SOCKET
    struct sockaddr_in servizio;

    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr = htonl(INADDR_LOOPBACK); //127.0.0.1
    servizio.sin_port = htons(Serverport);

    char stringa[20];
    int socketfd;

    while(1){
        socketfd = socket(AF_INET, SOCK_STREAM, 0);

        //FASE 2 CONNECT
        connect(socketfd, (struct sockaddr*)&servizio, sizeof(servizio));

        printf("Inserisci stringa: ");
        scanf("%s", stringa);

        //FASE 3 WRITE
        write(socketfd, stringa, sizeof(stringa));

        //FASE 4 READ
        read(socketfd, stringa, sizeof(stringa));

        printf("Risposta del server: %s\n", stringa);

        //FASE 5 CLOSE
        close(socketfd);
    }

    return 0;
}