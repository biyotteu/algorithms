#include <bits/stdc++.h>

using namespace std;

int f(int x,int y,int z){
	if(z%2) return x^y;
	else return x;
}
int main(){
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	int res = max(max(f(a,b,c),f(a,c,b)),max(f(b,a,c),f(b,c,a)));
	res = max(max(f(c,a,b),f(c,b,a)),res);
	printf("%d",res);
}