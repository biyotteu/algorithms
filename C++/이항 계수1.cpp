#include <bits/stdc++.h>

using namespace std;

int n,k,dp[15][15];
int main(){
	scanf("%d %d",&n,&k);
	dp[0][0] = 1;
	for(int i=1;i<=n;i++){
		dp[i][0] = 1;
		for(int j=1;j<=i;j++) dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
	}
	printf("%d",dp[n][k]);
}