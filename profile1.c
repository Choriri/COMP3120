#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

void *check(void *data);

pthread_mutex_t mutex_lock;

char cpu[1024];
char memory[1024];
int i;

int main(void){
	pthread_t pt1;
	int status;

	pthread_create(&pt1, NULL, check, (void *)"Thread start");

	pthread_join(pt1, (void *)&status);

	printf("종료됩니다.\n");

	return 0;
}

void *check(void *data){
	FILE *p;
	pthread_mutex_lock(&mutex_lock);
	while(i<5){
		printf("%d번째 순서\n", i);
		printf("CPU usage >> \n");
		
		printf("Memory usage >> \n");
		p = popen("free", "r");
		if(p != NULL){
			fgets(memory, sizeof(memory), p);
			printf("%s\n",memory);
			fgets(memory, sizeof(memory), p);
                        printf("%s\n",memory);
		}
		sleep(1);
		i++;
	}
	pthread_mutex_unlock(&mutex_lock);
}
