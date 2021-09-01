#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

int main(){
	int r;
	scanf("%d",&r);
	printf("%6f\n%6f",r*r*M_PI,(double)r*r*2);
}