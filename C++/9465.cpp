#include <bits/stdc++.h>

using namespace std;

int dp[100005][2],in[100005][2];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		int n,res=0;
		cin >> n;
		dp[0][0] = dp[0][1] = 0;
		for(int i=1;i<=n;i++) cin >> in[i][0];
		for(int i=1;i<=n;i++) cin >> in[i][1];
		dp[1][0] = in[1][0];
		dp[1][1] = in[1][1];
		res = max(dp[1][0],dp[1][1]);
		for(int i=2;i<=n;i++){
			dp[i][0] = max(dp[i-2][1],dp[i-1][1]) + in[i][0];
			dp[i][1] = max(dp[i-2][0],dp[i-1][0]) + in[i][1];
			res = max(res,max(dp[i][0],dp[i][1]));
		}
		cout<< res << "\n";	
	}
}