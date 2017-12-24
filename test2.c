#include <sys/syscall.h>
#define SYS_NUM 332

int main(void){
	syscall(SYS_NUM);
	return 0;
}
