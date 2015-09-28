#include <stdio.h>	
#include <stdint.h>	
#include <time.h>

#define BILLION 1000000000L

int main(int argc, char **argv)
{
	int n;
	uint64_t diff = 0;
	uint64_t ans = BILLION;
	struct timespec start, end;
	
		printf("minimum elapsed time = %llu nanoseconds\n", (long long unsigned int) diff);
		printf("minimum elapsed time = %llu nanoseconds\n", diff);
		printf("minimum elapsed time = %llu nanoseconds\n", (long long unsigned int) ans);
		printf("minimum elapsed time = %llu nanoseconds\n",  ans);
	while(1)
	{
		printf("%s\n", "ENter the number of loops:");
		scanf("%d",&n);
		int i=0;
		while(i<n){
			clock_gettime(CLOCK_MONOTONIC, &start);	/* mark start time */
			clock_gettime(CLOCK_MONOTONIC, &end);	/* mark the end time */
			++i;
			diff = BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
			ans = ans < diff ? ans : diff;
		}

		printf("Number of loops = %d\n", n);
		printf("minimum elapsed time = %llu nanoseconds\n", (long long unsigned int) diff);
	}

	return 0;
}
