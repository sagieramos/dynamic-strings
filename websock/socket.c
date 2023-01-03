#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define BUFSIZE 1024

int main(int argc, char **argv)
{
    for(;;){
    int sockfd, newsockfd, n;
    socklen_t clilen;
    char buffer[BUFSIZE];
    struct sockaddr_in serv_addr, cli_addr;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Bind the socket to a local address
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(PORT);
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error binding socket");
        exit(1);
    }

    // Set the socket to listen for incoming connections
    listen(sockfd, 5);

    // Accept an incoming connection
    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    if (newsockfd < 0) {
        perror("Error accepting connection");
        exit(1);
    }

    // Communicate with the client
    while (1) {
        memset(buffer, 0, BUFSIZE);
        n = recv(newsockfd, buffer, BUFSIZE-1, 0);
        if (n < 0) {
            perror("Error reading from socket");
            exit(1);
        }
        if (n == 0) {
            break;
        }
        printf("Received message: %s", buffer);
        n = send(newsockfd, buffer, strlen(buffer), 0);
        if (n < 0) {
            perror("Error writing to socket");
            exit(1);
        }
    }

    // Close the socket
    close(newsockfd);
    close(sockfd);
}
    return 0;
}

