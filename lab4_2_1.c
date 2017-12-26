//gettimeofday() can measure micro second!
//and I use sleep(5), but the reulst is more than 2 second.
//every rime, the result is change. so it is unaccurate.
#include <stdio.h>
#include <sys/time.h>
#include <time.h>

int main(void){
	struct timeval tv1;
	struct timeval tv2;
	int count = 0;
	long sec = 0, usec = 0;

	gettimeofday(&tv1, NULL);
	sleep(2);
	gettimeofday(&tv2, NULL);


	sec = tv2.tv_sec - tv1.tv_sec;
        usec = tv2.tv_usec - tv1.tv_usec;
        printf("sleep time- %ld:%ld\n", sec, usec);

	return 0;
}

