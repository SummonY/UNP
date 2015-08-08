#include "unp.h"


int main(int argc, char **argv)
{
    int sockfd, n;
    char recvline[MAXLINE + 1];
    struct sockaddr_in6 sockvaddr;
    
    

    if (argc != 2)
        err_quit("Usage: a.out <IPaddress>");

    if ((sockfd = socket(AF_INET6, SOCK_STREAM, 0)) < 0)
        err_sys("socket error");

    bzero(&sockvaddr, sizeof(sockvaddr));
    sockvaddr.sin6_family = AF_INET6;
    sockvaddr.sin6_port = htons(13);        // daytime server
    if (inet_pton(AF_INET6, argv[1], &sockvaddr.sin6_addr) <= 0)
        err_quit("inet_pton error for %s", argv[1]);

    if (connect(sockfd, (SA *) &sockvaddr, sizeof(sockvaddr)) < 0)
        err_sys("connect error");

    while ((n = read(sockfd, recvline, MAXLINE)) > 0) {
        recvline[n] = 0;                        // NULL terminate
        if (fputs(recvline, stdout) == EOF) {
            err_sys("fputs error");
        }
    }

    if (n < 0) {
        err_sys("read error");
    }
    exit(0);
}
