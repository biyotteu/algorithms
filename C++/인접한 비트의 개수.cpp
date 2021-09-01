#include <bits/stdc++.h>

using namespace std;

int t,dp[105][105][2];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	dp[1][0][1] = 1;
	dp[1][0][0] = 1;
	for(int i=2;i<=100;i++){
		for(int j=0;j<=100;j++){
			if(j == 0) dp[i][j][1] += dp[i-1][j][0];
			else dp[i][j][1] += (dp[i-1][j-1][1] + dp[i-1][j][0]);
			dp[i][j][0] += (dp[i-1][j][0] + dp[i-1][j][1]); 
		}
	}
	cin >> t;
	while(t--){
		int n,k;
		cin >> n >> k;
		cout << dp[n][k][0] + dp[n][k][1] << "\n";
	}
}