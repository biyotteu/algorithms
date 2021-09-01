#include <bits/stdc++.h>

using namespace std;

long long dp[105][105];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m;
	cin >> n >> m;
	dp[1][0] = dp[1][1] = 1;
	for(int i=2;i<=n;i++){
		dp[i][0] = 1;
		for(int j=1;j<=i;j++) dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
	}
	cout << dp[n][m];
}