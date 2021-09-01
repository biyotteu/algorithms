#include <bits/stdc++.h>
#define mod 10007

using namespace std;

int n,k;
long long dp[1005][1005];
int main()
{
	scanf("%d %d",&n,&k);
	dp[0][0] = 1;
	for(int i=1;i<=n;i++){
		dp[i][0] = 1;
		dp[i][i] = 1;
		for(int j=1;j<i;j++){
			dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%mod;
		}
	}
	printf("%lld",dp[n][k]);
}