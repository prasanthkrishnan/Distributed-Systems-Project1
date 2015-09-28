#include <stdio.h>	
#include <stdint.h>	
#include <time.h>

#define BILLION 1000000000L

int main(int argc, char **argv)
{
	uint64_t n;
	struct timespec start, end;

	while(1)
	{
		uint64_t diff = 0;
		uint64_t min = BILLION;
		uint64_t max = 0;
		printf("%s\n", "Enter the number of loops:");
		scanf("%llu",&n);
		while(n--){
			clock_gettime(CLOCK_MONOTONIC, &start);	/* mark start time */
			clock_gettime(CLOCK_MONOTONIC, &end);	/* mark the end time */
			diff = BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
			min = min < diff ? min : diff;
			max = max > diff ? max : diff;
		}

		printf("Number of loops = %llu \n", n);
		printf("minimum elapsed time = %llu nanoseconds\n", min);
		printf("maximum elapsed time = %llu nanoseconds\n", max);
	}

	return 0;
}
