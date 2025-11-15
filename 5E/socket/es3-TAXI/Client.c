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
    //CLIENT taxi
    /* BRAINSTORMING CON IL DANIEL
    - dire string: RIPRISTINO o RICHIESTA in base all'operazione che si desidera effettuare
    - RICHIESTA: 2 string separate dove metto partenza e destinazione*/

    //FASE 1 CREAZIONE SOCKET
    struct sockaddr_in servizio;

    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr = 0;
    servizio.sin_port = htons(Serverport);

    char tipoServizio[20], partenza[20], destinazione[20];
    int socketfd;

    while(1){
        socketfd = socket(AF_INET, SOCK_STREAM, 0);

        //FASE 2 CONNECT
        connect(socketfd, (struct sockaddr*)&servizio, sizeof(servizio));

        printf("Inserisci partenza: ");
        scanf("%s", partenza);

        //FASE 3 WRITE
        write(socketfd, partenza, sizeof(partenza));

        //FASE 4 READ
        read(socketfd, stringa, sizeof(stringa));

        printf("Risposta del server: %s\n", stringa);

        //FASE 5 CLOSE
        close(socketfd);
    }

    return 0;
}
}