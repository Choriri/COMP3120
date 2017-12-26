//if you want lock version -> reduce '//(1)'!
//if you want thread one version -> reduce '//(1)' and, revise for(i=0;i<50000;i++)
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

//(1)pthread_mutex_t mutex_lock;

void *t_function(void *data);
int count = 0;

int main(void){
	pthread_t p_thread1, p_thread2;
	int status;
	struct timeval tv1;
        struct timeval tv2;
        long sec = 0, usec = 0;

	//(1)pthread_mutex_init(&mutex_lock, NULL);

        gettimeofday(&tv1, NULL);

	pthread_create(&p_thread1, NULL, t_function, (void *)"Thread1");
//(2)	pthread_create(&p_thread2, NULL, t_function, (void *)"Thread2");

	pthread_join(p_thread1, (void *)&status);
//(2)	pthread_join(p_thread2, (void *)&status);

	gettimeofday(&tv2, NULL);

	sec = tv2.tv_sec - tv1.tv_sec;
        usec = tv2.tv_usec - tv1.tv_usec;
	printf("time %ld:%ld\n", sec, usec);
//	printf("count : %d", count);
	return 0;
}
void *t_function(void *data){
	int i;
	char* thread_name = (char *)data;

//(1)	pthread_mutex_lock(&mutex_lock);

	for(i=0;i<1000000;i++){
		//printf("%s count %d\n", thread_name, count);
		count++;
		usleep(10);
	}

//(1)	pthread_mutex_unlock(&mutex_lock);
}
