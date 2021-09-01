#include <bits/stdc++.h>
#define MX 10005

using namespace std;

int n,wt[MX][2],dp[MX][3],w;
void f(int v){
	for(int i=v;i<n;i++){
		dp[i+1][0] = min(dp[i][1],dp[i][2])+1;
		if(wt[i][0] + wt[i][1] <= w) dp[i+1][0] = min(dp[i+1][0],dp[i][0]+1);
		if(i>0 && wt[i-1][0] + wt[i][0] <= w && wt[i-1][1] + wt[i][1] <= w) dp[i+1][0] = min(dp[i+1][0],dp[i-1][0]+2);
		if(i<n-1){
			dp[i+1][1] = dp[i+1][0] + 1;
			if(wt[i][0] + wt[i+1][0] <= w) dp[i+1][1] = min(dp[i+1][1],dp[i][2]+1);
			dp[i+1][2] = dp[i+1][0] + 1;
			if(wt[i][1] + wt[i+1][1] <= w) dp[i+1][2] = min(dp[i+1][2],dp[i][1]+1);
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		cin >> n >> w;
		for(int i=0;i<2;i++) for(int j=0;j<n;j++) cin >> wt[j][i];
		dp[0][0] = 0;
		dp[0][1] = dp[0][2] = 1;
		int res = 2e9;
		f(0);
		res = min(res,dp[n][0]);
		if(n>1){
			if(wt[0][0] + wt[n-1][0] <= w){
				dp[1][0] = 1;
				dp[1][1] = 2;
				dp[1][2] = wt[0][1] + wt[1][1] <= w ? 1:2;
				f(1);
				res = min(res,dp[n-1][2]+1);
			}
			if(wt[0][1] + wt[n-1][1] <= w){
				dp[1][0] = 1;
				dp[1][2] = 2;
				dp[1][1] = wt[0][0] + wt[1][0] <= w ? 1:2;
				f(1);
				res = min(res,dp[n-1][1]+1);
			}
			if(wt[0][0] + wt[n-1][0] <= w && wt[0][1] + wt[n-1][1] <= w){
				dp[1][0] = 0;
				dp[1][1] = dp[1][2] = 1;
				f(1);
				res = min(res,dp[n-1][0]+2);
			}
		}
		cout << res << "\n";
	}
}