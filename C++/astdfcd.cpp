#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,m,c;
	scanf("%d %d",&m,&n);
	scanf("%d",&c);
	if(m+n >= c*2) printf("%d",m+n-c*2);
	else printf("%d",m+n);
}