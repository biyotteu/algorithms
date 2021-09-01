#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,k,m;
	scanf("%d %d %d",&n,&k,&m);
	int a = n*k-m;
	if(a>0) printf("%d",a);
	else printf("0");
}