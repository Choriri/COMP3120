#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void *check(void *data);

pthread_mutex_t mutex_lock;

char od1[1024] = "cat /proc/";
char od2[1024] = "cd /proc/";
char cpu[1024];
char memory[1024];
int i;

int main(void){
	pthread_t pt1, pt2, pt3;
	int status;
	char pid[16];

	puts("What process do you want to check? Write the PID.");
        fgets(pid, sizeof(pid), stdin);
        strtok(pid, "\n");
        strcat(od1, pid);
        strcat(od1, "/stat\n");

	strcat(od2, pid);
	strcat(od2, ";cat status\n");


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
	int k=0, num1=0, num2=0;
	char *ptr;
	char pid[16];

	pthread_mutex_lock(&mutex_lock);
	while(i<10){
		printf("%d번째\n", i+1);

		printf("CPU usage >>\t");
		p = popen(od1, "r");
		if(p==NULL) printf("ERRRR");

		fgets(cpu,sizeof(cpu), p);

		ptr = strtok(cpu, " ");	//first token
		while(k<13){	//14th token
			ptr = strtok(NULL, " ");
			k++;
		}
		printf("utime : %s\t", ptr);	//utime
		num1 = atoi(ptr);

		ptr = strtok(NULL, " ");
		printf("stime : %s\t", ptr);	//stime
		num2 = atoi(ptr);

		printf("total time : %d\n", num1+num2);

		k=0;

		printf("Memory usage >>\t");
		p = popen(od2, "r");
		if(p != NULL){
			while(k<17){
				fgets(memory, sizeof(memory), p);
				k++;
			}

			fgets(memory, sizeof(memory), p);
                        printf("%s",memory);
			k++;
		}
		sleep(1);
		i++;
		k=0;
		printf("\n");
	}
	pthread_mutex_unlock(&mutex_lock);
}
