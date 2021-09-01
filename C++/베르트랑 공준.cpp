#include <bits/stdc++.h>
#define lim 250000
using namespace std;

int dp[lim];
int main(){
	for(int i=2;i<sqrt(lim);i++){
		if(dp[i]) continue;
		for(int j=(i<<1);j<=lim;j+=i) dp[j] = 1;
	}
	while(1){
		int v;
		scanf("%d",&v);
		if(!v) return 0;
		int ret = 0;
		for(int i=v+1;i<=2*v;i++) ret += !dp[i];
		printf("%d\n",ret);
	}
}