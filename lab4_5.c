//wait() is returned child process's ID when it is succeesed, and
// wait() is returned -1 when it is failed.
//If wait() is in the child process, finishing is strange and wait() return -1.
//IF you wnat to check this, remove '//(1)' and
// add '//' to the wait(0) in the parent process.

#include <stdio.h>

int main(void){

	int pid;
	int w=0;

	pid = fork();

	if(pid == 0){
		//(1)w = wait(1);
		//(1)printf("parent is finished.\n");
		printf("w = %d\n", w);
	}
	else if(pid > 0){
		w = wait(0);
		printf(":-) w is %d. \n", w);
	}
	return 0;
}
