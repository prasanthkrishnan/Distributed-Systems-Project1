#include <stdio.h>	
#include <stdint.h>	
#include <stdlib.h>	
#include <time.h>

#define BILLION 1000000000L

int main(int argc, char **argv)
{
	uint64_t diff;
	struct timespec start, end;
	int i;

	/* measure monotonic time */
	clock_gettime(CLOCK_MONOTONIC, &start);	/* mark start time */
	sleep(1);	/* do stuff */
	clock_gettime(CLOCK_MONOTONIC, &end);	/* mark the end time */

	diff = BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
	printf("elapsed time = %llu nanoseconds\n", (long long unsigned int) diff);

	/* now re-do this and measure CPU time */
	/* the time spent sleeping will not count (but there is a bit of overhead */
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);	/* mark start time */
	sleep(1);	/* do stuff */
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);		/* mark the end time */

	diff = BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
	printf("elapsed process CPU time = %llu nanoseconds\n", (long long unsigned int) diff);

	return 0;
}
