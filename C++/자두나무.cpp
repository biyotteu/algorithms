#include <bits/stdc++.h>

using namespace std;

int dp[1000][31][2];
int res;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t,w,x;
	cin >> t >> w;
	cin >> x;
	if(x == 1){
		dp[1][0][0] = 1,res=1;
	}else{
		dp[1][1][1] = 1,res=1;
	}
	for(int i=2;i<=t;i++){
		cin >> x;
		dp[i][0][x-1] = dp[i-1][0][x-1] + 1;
		dp[i][0][!(x-1)] = dp[i-1][0][!(x-1)];
		res = max(res,max(dp[i][0][(x-1)],dp[i][0][!(x-1)]));
		for(int j=1;j<=w;j++){
			dp[i][j][x-1] = max(dp[i-1][j][x-1],dp[i-1][j-1][!(x-1)])+1;
			dp[i][j][!(x-1)] = max(dp[i-1][j][!(x-1)],dp[i-1][j-1][x-1]);
			res = max(dp[i][j][x-1],max(res,dp[i][j][!(x-1)]));
		}
	}
	cout << res;
}