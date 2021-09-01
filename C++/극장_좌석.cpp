#include <bits/stdc++.h>

using namespace std;

int n,m,idx,x;
long long int pibo[50],res = 1;
int main(){
	scanf("%d %d",&n,&m);
	pibo[0]=pibo[1]=1;
	for(int i=2;i<=n;i++) pibo[i] = pibo[i-1] + pibo[i-2];
	for(int i=0;i<m;i++){
		scanf("%d",&x);
		res *= pibo[x-idx-1];
		idx = x;
	}
	res *= pibo[n-x];
	printf("%lld",res);
}