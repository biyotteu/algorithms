#include <bits/stdc++.h>

using namespace std;

long long int dp[100];
int main(){
	int t;
	scanf("%d",&t);
	dp[1]=dp[0]=1;
	dp[2]=2;
	dp[3]=4;
	for(int i=4;i<=67;i++) dp[i] = dp[i-1] + dp[i-2] + dp[i-3] + dp[i-4];
	while(t--){
		int n;
		scanf("%d",&n);
		printf("%lld\n",dp[n]);
	}
}