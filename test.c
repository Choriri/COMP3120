#include <stdio.h>
#include <stdlib.h>

int main(){
FILE *fp;
int a =0;

fp = fopen("input.txt", "r");
fscanf(fp, "%d", &a);

printf("%d\n", a);

return 0;

}
