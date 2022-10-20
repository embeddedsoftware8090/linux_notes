#include<stdio.h>
#include<sys/time.h>
int main()
{
	struct timeval time;
	gettimeofday(&time,NULL);
	printf("Time in seconds= %ld\n",time.tv_sec);
	printf("Time in micro seconds = %ld\n",time.tv_usec);
	return 0;
}
