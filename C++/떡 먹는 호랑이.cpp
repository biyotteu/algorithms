#include <bits/stdc++.h>

using namespace std;

int dp[32][2];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int d,k;
	cin >> d >> k;
	dp[1][0] = dp[2][1] = 1;
	dp[2][0] = dp[1][1] = 0;
	for(int i=3;i<=d;i++){
		dp[i][0] = dp[i-1][0] + dp[i-2][0];
		dp[i][1] = dp[i-1][1] + dp[i-2][1];
	}
	for(int i=1;i*dp[d][0]<=k;i++){
		if((k - i*dp[d][0])%dp[d][1] == 0){
			cout << i << '\n' << (k - i*dp[d][0])/dp[d][1];
			break;
		}
	}
}