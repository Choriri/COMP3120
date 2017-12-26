#include <stdio.h>

int main(void){
	int pid = fork();

	if(pid == 0){
		printf("CH : I will call exec()~~\n");
		execl("/bin/sh", "sh", NULL);
		printf("Did I print?\n");
	}
	else{
		wait(0);
		printf("PT : my child did exec() with /bin/sh\n");
	}

	return 0;
}
