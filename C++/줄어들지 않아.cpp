#include <bits/stdc++.h>

using namespace std;

long long dp[65][10];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		memset(dp,0,sizeof(dp));
		int n;
		cin >> n;
		for(int i=0;i<10;i++) dp[1][i] = 1;
		for(int i=2;i<=n;i++){
			for(int j=0;j<10;j++){
				for(int k=0;k<=j;k++){
					dp[i][j] += dp[i-1][k];
					//dp[i][j] %= MOD; 
				}
			}
		}
		long long res = 0;
		for(int i=0;i<10;i++){
			res += dp[n][i];
			//res %= MOD;
		}
		cout << res << endl;

	}
}