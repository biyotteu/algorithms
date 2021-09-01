#include <bits/stdc++.h>

using namespace std;

int dp[35],DP[35];
int n;
int main(){
	dp[1] = DP[1] = 1;
	dp[2] = DP[2] = 3;
	cin >> n;
	for(int i=3;i<=n;i++) dp[i] = dp[i-1] + 2*dp[i-2];
	for(int i=3;i<=n;i++){
		if(i%2) DP[i] = (dp[i]+dp[i/2])/2;
		else DP[i] = (dp[i] + dp[i/2] + (2*dp[i/2-1]))/2;
	}
	cout << DP[n];
}