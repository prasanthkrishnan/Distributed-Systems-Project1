#ifndef constants
// (65,535  − 8 byte UDP header − 20 byte IP header)
// 65507 => 64 KB
// 32737 => 32 KB
// 16355 => 16 KB
// 995 => 1 KB
// asdasd
#define MSG_BUFFER_SIZE  995
#define ACK_BUFFER_SIZE  32
#define SERVER_PORT 10000
#define TIMEOUT_IN_SECONDS 3
#define SEQUENCE_NUMBER 1
#define SERVER_HOSTNAME "macaroni-07.cs.wisc.edu"
#define BILLION 1000000000L
#define DROP_PROBABILITY 10
#endif