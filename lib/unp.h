#ifndef __unp_h
#define __unp_h

#include "../config.h"


#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>

#include <arpa/inet.h>

/* Following could be derived from SOMAXCONN in <sys/socket.h>, but many
 * kernels still #define it as 5, while actually supporting many more */
#define LISTENQ     1024    // 2nd argument to listen()

/* Miscellaneous constants */
#define MAXLINE     4096
#define BUFFSIZE    8192





/* Following shortens all the typecasts of pointer arguments: */
#define SA struct sockaddr







#endif
