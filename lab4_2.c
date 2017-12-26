//child and parent cna access the file descriptor.
//When I open 'output.txt', child's printf() and parent's printf() are written.

#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE *fp, *ff;
	pid_t pid;
	int a=0, b=0;

	fp = fopen("input2.txt", "r");
	ff = fopen("output.txt", "w");
	pid = fork();

	if(pid == 0){
		printf("Hi, I'm child.^^\n");
		fscanf(fp, "%d", &a);
		fprintf(ff, "CD : %d * %d = %d\n", a, b, a*b);
	}
	else{
		wait(1);
		printf("Hi, I'm parent. :-)\n");
		fscanf(fp, "%d", &b);
		fprintf(ff, "PT : %d * %d = %d\n", a, b, a*b);
		//wait(1);
	}


	return 0;
}
