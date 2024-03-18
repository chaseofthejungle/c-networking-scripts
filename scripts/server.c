#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h> 
#include <unistd.h>
#define PORTNUM 2300
 
int main(int argc, char *argv[])
{
    char* msg = "Greetings from the Server! !\n";
  
    int newsocket;            // listener for new connections
    struct sockaddr_in dest; // client machine socket info
    struct sockaddr_in serv; // server socket info
    socklen_t socketsize = sizeof(struct sockaddr_in);

    memset(&serv, 0, sizeof(serv));           // server socket info initialized to 0
    serv.sin_family = AF_INET;                // connection set to TCP/IP protocol suite
    serv.sin_addr.s_addr = htonl(INADDR_ANY); // set server address
    serv.sin_port = htons(PORTNUM);           // set server port #    
    newsocket = socket(AF_INET, SOCK_STREAM, 0);
  
    bind(newsocket, (struct sockaddr *)&serv, sizeof(struct sockaddr)); // binds server info to listener
    listen(newsocket, 1); // listener initialized to maximum of one connection
    int connsocket = accept(newsocket, (struct sockaddr *)&dest, &socketsize);
  
    while(connsocket)
    {
        printf("New Connection from %s - Sending Welcome Message!\n", inet_ntoa(dest.sin_addr));
        send(connsocket, msg, strlen(msg), 0); 
        close(connsocket);
        connsocket = accept(newsocket, (struct sockaddr *)&dest, &socketsize);
    }

    close(newsocket);
    return EXIT_SUCCESS;
}
