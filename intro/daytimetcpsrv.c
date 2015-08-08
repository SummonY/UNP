#include "unp.h"
#include <time.h>

// Socket wrapper function
int Socket(int family, int type, int protocol)
{
    int n;

    if ((n = socket(family, type, protocol)) < 0)
        err_sys("socket error");
    return (n);
}


// Bind wrapper function
int Bind(int fd, struct sockaddr *addr, int size)
{
    int n;
    if ( (n = bind(fd, addr, size)) < 0)
        err_sys("bind error");
    
    return n;
}

// Listen wrapper function
int Listen(int fd, int backlog)
{
    int n;

    if ((n = listen(fd, backlog)) < 0)
        err_sys("listen error");

    return n;
}

// Accept wrapper function
int Accept(int fd, struct sockaddr *addr, int size)
{
    int n;

    if ((n = accept(fd, addr, size)) < 0)
        err_sys("accept error");

    return n;
}

// Write wrapper function
int Write(int fd, char buff[], int size)
{
    int n;

    if ((n = write(fd, buff, size)) < 0)
        err_sys("write error");

    return n;
}

// Close wrapper function
int Close(int fd)
{
    int n;

    if ((n = close(fd)) < 0)
        err_sys("close error");

    return n;
}

int main(int argc, char **argv)
{
    int listenfd, connfd;
    struct sockaddr_in sockvaddr;
    char buff[MAXLINE];
    time_t ticks;

    listenfd = Socket(AF_INET, SOCK_STREAM, 0);
    
    bzero(&sockvaddr, sizeof(sockvaddr));
    sockvaddr.sin_family = AF_INET;
    sockvaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    sockvaddr.sin_port = htons(13);     // daytime server

    Bind(listenfd, (SA *) &sockvaddr, sizeof(sockvaddr));

    Listen(listenfd, LISTENQ);

    for (;;)
    {
        connfd = Accept(listenfd, (SA *)NULL, NULL);
        
        printf("Accept block.\n");
        ticks = time(NULL);
        snprintf(buff, sizeof(buff), "%.24s\r\n", ctime(&ticks));
        Write(connfd, buff, strlen(buff));

        Close(connfd);
    }
    exit(0);
}
