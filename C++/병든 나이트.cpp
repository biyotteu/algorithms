#include <bits/stdc++.h>

using namespace std;

int n,m,res;
int main(){
	scanf("%d %d",&n,&m);
	if(n == 1) puts("1");
	else if(n == 2) printf("%d",min(4,(m+1)>>1));
	else if(m < 7) printf("%d",min(4,m));
	else printf("%d",m-2);
}