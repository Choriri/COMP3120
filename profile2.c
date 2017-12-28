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
	pthread_t pt1, pt2, pt3;
	int status;

	pthread_create(&pt1, NULL, check, (void *)"Thread start");
	pthread_create(&pt2, NULL, check, (void *)"Thread start");
	pthread_create(&pt3, NULL, check, (void *)"Thread start");

	pthread_join(pt1, (void *)&status);
	pthread_join(pt2, (void *)&status);
	pthread_join(pt3, (void *)&status);

	printf("종료됩니다.\n");

	return 0;
}

void *check(void *data){
	FILE *p;
	int k=0;

	pthread_mutex_lock(&mutex_lock);
	while(i<5){
		printf("%d번째\n", i+1);
		//printf("CPU usage >> \n");

		printf("Memory usage >> \n");
		p = popen("cd /proc/1778;cat status", "r");
		if(p != NULL){
			while(k<17){
				fgets(memory, sizeof(memory), p);
				k++;
			}
			printf("%s",memory);
			fgets(memory, sizeof(memory), p);
                        printf("%s",memory);
			k++;
			while(k<25){
				fgets(memory, sizeof(memory), p);
				k++;
			}
			while(k<28){
				fgets(memory, sizeof(memory), p);
				k++;
				printf("%s", memory);
			}
		}
		sleep(1);
		i++;
		k=0;
		printf("\n");
	}
	pthread_mutex_unlock(&mutex_lock);
}
