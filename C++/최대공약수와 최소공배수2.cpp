#include <bits/stdc++.h>

using namespace std;

int f(int a,int b){
	if(b == 0) return a;
	return f(b,a%b);
}
int main(){
	int a,b;
	scanf("%d %d",&a,&b);
	if(a<b) swap(a,b);
	printf("%d\n%d",f(a,b),a*b/f(a,b));
}