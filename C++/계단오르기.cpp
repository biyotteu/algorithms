#include <bits/stdc++.h>

using namespace std;

int dp[21],n;
int main(){
	scanf("%d",&n);
	dp[0] = dp[1] = 1;
	for(int i=2;i<=n;i++) dp[i] = dp[i-1] + dp[i-2];
	printf("%d",dp[n]);
}