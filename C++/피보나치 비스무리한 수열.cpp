#include <bits/stdc++.h>

using namespace std;

int n;
long long dp[120];
int main(){
	dp[1] = dp[2] = dp[3] = 1;
	scanf("%d",&n);
	for(int i=4;i<=n;i++) dp[i] = dp[i-1] + dp[i-3];
	printf("%lld",dp[n]);
}