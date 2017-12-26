//In child, X = 100. (Eventhough in parent, x is changed.)
//Change of X is not affected other process.

#include <stdio.h>

int main(void){
	int x = 100;
	int pid = fork();

	if(pid==0){
		printf("Child!!\n");
		printf("x = %d ",x);
		x = x+x;
		printf("   => x+x, x = %d \n\n", x);
	}
	else{
		wait(0);
		printf("parent!!\n");
		printf("x = %d ",x);
		x = x+1;
		printf("    => x+1, X = %d \n\n", x);
		//wait(0);
	}
	return 0;
}
