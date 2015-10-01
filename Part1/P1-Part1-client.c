#include <UDP_lib.h>
#include <constants.h>
#include <assert.h>
int main(int argc, char *argv[]) {
	//Port 0 - OS chooses port randomly
	int sd = UDP_Open(0);
	// 
	struct sockaddr_in addr, addr2;
	assert(UDP_FillSockAddr(&addr, SERVER_HOSTNAME, SERVER_PORT) > -1);
	char message[BUFFER_SIZE];
	sprintf(message, "helloworld");
	
	if (UDP_Write(sd, &addr, message, BUFFER_SIZE) > 0) {
		char buffer[BUFFER_SIZE];
		int rc = UDP_Read(sd, &addr2, buffer, BUFFER_SIZE);
		if(rc > 0) {
			buffer[BUFFER_SIZE] = 0;
			printf("received message: \"%s\"\n", buffer);
		}
	}
	return 0;
}