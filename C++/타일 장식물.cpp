#include <bits/stdc++.h>

using namespace std;

int n;
long long int dp[100] = {0,1,1,2,3,5,};
int main(){
	scanf("%d",&n);
	for(int i=5;i<=n;i++) dp[i] = dp[i-1] + dp[i-2];
	printf("%lld",4*dp[n]+dp[n-1]*2);
}