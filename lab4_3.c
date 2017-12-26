//No. I use 'wiat()' function before "goodbye".
#include <stdio.h>

int main(void){
        int pid;

	pid = fork();
        if(pid == 0)
                printf("child says 'Hello'\n");
        else{
		wait(1);
                printf("parent says 'Goodbye'\n");
//		wait(1);
	}
        return 0;
}


