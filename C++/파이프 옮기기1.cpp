#include <bits/stdc++.h>

using namespace std;

int n,pi[20][20],dp[20][20][3]; // 0 -> ㅡ , 1 -> \ , 2 -> ㅣ  
int f(int i,int j){
	return !(pi[i+1][j] | pi[i][j+1] | pi[i+1][j+1]);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++) cin >> pi[i][j];
	dp[1][2][0] = 1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(j+1 <= n && !pi[i][j+1]) dp[i][j+1][0] += dp[i][j][0];
			if(i+1 <= n && j+1 <= n && f(i,j)) dp[i+1][j+1][1] += dp[i][j][0];

			if(i+1 <= n && !pi[i+1][j]) dp[i+1][j][2] += dp[i][j][2];
			if(i+1 <= n && j+1 <= n && f(i,j)) dp[i+1][j+1][1] += dp[i][j][2];

			if(j+1 <= n && !pi[i][j+1]) dp[i][j+1][0] += dp[i][j][1];
			if(i+1 <= n && !pi[i+1][j]) dp[i+1][j][2] += dp[i][j][1];
			if(i+1 <= n && j+1 <= n && f(i,j)) dp[i+1][j+1][1] += dp[i][j][1];
		}
	}
	cout << dp[n][n][0] + dp[n][n][1] + dp[n][n][2];
}