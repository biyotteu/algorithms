#include <bits/stdc++.h>
#define MOD 1000000009

using namespace std;

long long dp[1000005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	dp[0] = 1;
	for(int i=1;i<=1000000;i++){
		dp[i] = dp[i-1];
		if(i>=2) dp[i] += dp[i-2];
		if(i>=3) dp[i] += dp[i-3];
		dp[i] %= MOD;
	}
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		cout << dp[n] << "\n";
	}
}