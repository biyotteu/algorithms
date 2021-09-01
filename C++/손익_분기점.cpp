#include <bits/stdc++.h>

using namespace std;

int main(){
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	int k = a/(c-b)+1;
	if(b>=c) printf("-1");
	else printf("%d",k);
}