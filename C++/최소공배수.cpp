#include <bits/stdc++.h>

using namespace std;

int gcd(int a,int b){
	if(!b) return a; 
	return gcd(b,a%b);
}
int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		int x,y;
		scanf("%d %d",&x,&y);
		if(x > y) swap(x,y);
		printf("%d\n",x*y/gcd(x,y));
	}
}