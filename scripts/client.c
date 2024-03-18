#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h> 
#define MAXRCVLEN 500
#define PORTNUM 2300
 
int main(int argc, char *argv[])
{
   char buffer[MAXRCVLEN + 1];
   int length, newsocket; // need listener for new connections
   struct sockaddr_in dest; // client machine socket info
  
   newsocket = socket(AF_INET, SOCK_STREAM, 0);
  
   memset(&dest, 0, sizeof(dest));                // client socket info initialized to 0
   dest.sin_family = AF_INET;                     // connection set to TCP/IP protocol suite
   dest.sin_addr.s_addr = htonl(INADDR_LOOPBACK); // destination IP address set to 127.0.0.1 for localhost 
   dest.sin_port = htons(PORTNUM);                // set client port #
 
   connect(newsocket, (struct sockaddr *)&dest, sizeof(struct sockaddr_in));
  
   length = recv(newsocket, buffer, MAXRCVLEN, 0); 
   buffer[length] = '\0'; // manually null received data
   printf("Received %s (%d bytes of data).\n", buffer, length);

   close(newsocket);
   return EXIT_SUCCESS;
}
