#include <unistd.h>
#include <string.h>
#include <stdio.h>

int main(void){
	int pp[2], p2[2];
	pid_t pid;

	pipe(pp);
	pipe(p2);

	pid = fork();
	if(pid == 0){
		char msc[] = "Hi, I'm child1~";
		char mrc[256];
		puts("I'm child1. you are child2.");
		write(p2[1], msc, strlen(msc) +1);
		read(pp[0], mrc, sizeof(mrc));
		printf("I am process1. my sister, process2 tell me -> %s\n", mrc);
	}
	else if(pid>0){
		pid = fork();
		if(pid == 0){
			char msp[] = "Hello, p1~. I'm process 2.";
			char mrp[256];
			puts("I'm child2. nice to meet you!!");
			write(pp[1], msp, strlen(msp)+1);
			read(p2[0], mrp, sizeof(mrp));
			printf("I'm procee2. my sister tell me -> %s\n", mrp);
		}
		else if(pid>0)
			wait(1);
		wait(1);
	}


	return 0;
}
