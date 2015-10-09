#include <UDP_lib.h>
#include <constants.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

int isDuplicate(int *server_sequence_number, char ack[ACK_BUFFER_SIZE]) {
	int received_seq_number = atoi(ack);
	if(received_seq_number > *server_sequence_number) {
		*server_sequence_number = received_seq_number;
		return 0;
	}
	else
		return 1;
}

int should_send() {
	return (DROP_PROBABILITY > 0 ? (rand() % 100) > DROP_PROBABILITY : 1);
}

int main(int argc, char *argv[]) {
	
	srand((unsigned) time(NULL));

	int sd = UDP_Open(SERVER_PORT);
	assert(sd > -1);
	int server_sequence_number = SEQUENCE_NUMBER -1;
	while (1) {
		struct sockaddr_in s;
		char read_packet[MSG_BUFFER_SIZE];
		// Server waits till mesaage is recived
		int rc = UDP_Read_without_timeout(sd, &s, read_packet, MSG_BUFFER_SIZE);
		if (rc > 0) {
			// printf("received message sequence_number: %s \n", read_packet);
			char ack[ACK_BUFFER_SIZE];
			strncpy(ack, read_packet, ACK_BUFFER_SIZE);
			if(isDuplicate(&server_sequence_number,ack)){
				// printf("Duplicate Message received\n");
			}
			if(should_send()) {
				// printf("sending ack packet sequence_number : %s\n", ack);
				UDP_Write(sd, &s, ack, ACK_BUFFER_SIZE);
			}
		}
	}

	return 0;
}