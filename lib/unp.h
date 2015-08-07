#ifndef __unp_h
#define __unp_h



#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>

#include <arpa/inet.h>

/* Miscellaneous constants */
#define MAXLINE     4096
#define BUFFSIZE    8192





/* Following shortens all the typecasts of pointer arguments: */
#define SA struct sockaddr







#endif
