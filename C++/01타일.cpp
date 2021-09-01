#include <bits/stdc++.h>
#define mod 15746

using namespace std;

int n;
long long int dp[1000005];
int main(){
	scanf("%d",&n);
	dp[1] = 1;
	dp[2] = 2;
	for(int i=3;i<=n;i++) dp[i] = (dp[i-1] + dp[i-2])%mod;
	printf("%d",dp[n]);
}