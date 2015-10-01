#include <UDP_lib.h>
#include <constants.h>
#include <assert.h>
#include <stdint.h> 
#include <time.h>
#include <inttypes.h>

void marshall_message(char msg[MSG_BUFFER_SIZE], int sequence_number) {
	int i;
	sprintf( msg, "%d", sequence_number );
	for (i = 32; i < MSG_BUFFER_SIZE - 1; ++i)
	{
		msg[i] = 'a';
	}
	// Adding a null at the end makes printf statement 
	msg[MSG_BUFFER_SIZE - 1] = '\0';
}

int main(int argc, char *argv[]) {
	// because we use 32 bytes sequence id which is returned in ack; msg size cant be less than that.
	int sequence_number = SEQUENCE_NUMBER;
	assert(MSG_BUFFER_SIZE > ACK_BUFFER_SIZE);
	assert(argc > 1);
	int number_of_packets = atoi(argv[1]);
	if(argc > 2)
		sequence_number =  atoi(argv[2]);
	printf("Number of packets: %d\n", number_of_packets);

	// //Port 0 - OS chooses port randomly
	int sd = UDP_Open(0);
	struct sockaddr_in addr, addr2;
	assert(UDP_FillSockAddr(&addr, SERVER_HOSTNAME, SERVER_PORT) > -1);
	int i;
	for (i = sequence_number; i < sequence_number + number_of_packets; ++i)
	{
		// i is used as sequence number
		char packet[MSG_BUFFER_SIZE];
		int wc;
		marshall_message(packet,i);
		timeout:
		printf("%s %d\n", "Sending packet sequence_number:", i);
		wc = UDP_Write(sd, &addr, packet, MSG_BUFFER_SIZE);
		if ( wc > 0) {
			char ack[ACK_BUFFER_SIZE];
			// wait for the ack
			int rc = UDP_Read(sd, &addr2, ack, ACK_BUFFER_SIZE);
			if(rc > 0) {
				printf("Ack received: \"%s\"\n", ack);
			}
			else {
				printf("%s %d\n", "timeout for packet sequence_number:", i);
				goto timeout;
			}
		}
		else {
			printf("%s %d\n", "Write failed for sequence_number:", i);
			goto timeout;
		}
	}
	return 0;
}