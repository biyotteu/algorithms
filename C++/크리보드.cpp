#include <bits/stdc++.h>

using namespace std;

long long dp[105],n;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(long long i=1;i<=n;i++){
		dp[i] = max(i,dp[i-1]+1);
		for(int j=3;j<=10;j++){
			if(j>i) break;
			dp[i] = max(dp[i],dp[i-j]*(j-1));
		}
	}
	cout << dp[n];
}