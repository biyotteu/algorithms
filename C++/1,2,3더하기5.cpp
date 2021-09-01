#include <bits/stdc++.h>
#define MOD 1000000009

using namespace std;

long long dp[100005][3];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin >> t;
	dp[1][0] = 1;
	dp[2][1] = 1;
	dp[3][2] = 1;
	dp[3][0] = 1;
	dp[3][1] = 1;
	for(int i=4;i<=100000;i++){
		if(i>=3){
			dp[i][2] += (dp[i-3][0]+dp[i-3][1]);
			dp[i][2] %= MOD;
		}
		if(i>=2){
			dp[i][1] += (dp[i-2][0]+dp[i-2][2]);
			dp[i][1] %= MOD;
		}
		if(i>=1){
			dp[i][0] += (dp[i-1][2]+dp[i-1][1]);
			dp[i][0] %= MOD;
		}
	}
	while(t--){
		int n;
		cin >> n;
		cout << (dp[n][0]+dp[n][1]+dp[n][2])%MOD << "\n";
	}
}