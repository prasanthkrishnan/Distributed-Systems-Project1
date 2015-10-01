#include <UDP_lib.h>
#include <constants.h>
#include <assert.h>
int main(int argc, char *argv[]) {
	int sd = UDP_Open(SERVER_PORT);
	assert(sd > -1);
	while (1) {
		struct sockaddr_in s;
		char buffer[BUFFER_SIZE];
		int rc = UDP_Read(sd, &s, buffer, BUFFER_SIZE);
		if (rc > 0) {
			buffer[BUFFER_SIZE] = 0;
			printf("received message: \"%s\"\n", buffer);
			char reply[BUFFER_SIZE];
			sprintf(reply, "0123456789");
			UDP_Write(sd, &s, reply, BUFFER_SIZE);
		}
	}
	return 0;
}