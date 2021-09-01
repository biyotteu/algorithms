#include <bits/stdc++.h>
#define MOD 1000000009

using namespace std;

int n;
long long dp[50005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 2;
	dp[4] = 3;
	for(int i=5;i<=n;i++){
		dp[i] = dp[i-2] + dp[i-1] - dp[i-4];
		dp[i] %= MOD;
	}
	cout << dp[n];
}