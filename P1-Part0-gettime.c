#include <stdio.h>	
#include <stdint.h>	
#include <time.h>

#define BILLION 1000000000L

int main(int argc, char **argv)
{
	int n;
	uint64_t diff;
	struct timespec start, end;
	
	while(true)
	{
		printf("%s\n", "ENter the number of loops:");
		scanf("%d",&n);
		int i=0;
		clock_gettime(CLOCK_MONOTONIC, &start);	/* mark start time */
		while(i<n){
			++i;
		}
		clock_gettime(CLOCK_MONOTONIC, &end);	/* mark the end time */

		diff = BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
		printf("Number of loops = %d\n", n);
		printf("elapsed time = %llu nanoseconds\n", (long long unsigned int) diff);
	}

	return 0;
}
