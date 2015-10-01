#ifndef UDP_lib

#include <stdlib.h>
#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <strings.h>

int UDP_Open(int port);
int UDP_FillSockAddr(struct sockaddr_in *addr, char *hostName, int port);
int UDP_Write(int sd, struct sockaddr_in *addr, char *buffer, int n);
int UDP_Read(int sd, struct sockaddr_in *addr, char *buffer, int n);
#endif