#include <stdio.h>

int main(){
	int *p;
	int a = 10;
	p = &a;
	printf("%u",p);
	p++;
	printf("%u\n",p);
}