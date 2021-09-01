#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n,m;
		long long dp[100005][25][4];
		cin >> n >> m;
		for(int i=1;i<=8;i++) dp[1][i][1] = 1;
		for(int i=1;i<=8;i++){
			for(int j=1;j<=8;j++)
				dp[2][i+j][2] += dp[1][j][1];
		}
		for(int i=3;i<=n;i++){
			for(int a=1;a<=8;a++){
				for(int b=1;b<=24;b++){
					dp[i][a][1] += dp[i-1][b][3];
					dp[i][a][1] %= MOD;
				}
			}
			for(int a=1;a<=8;a++){
				for(int b=1;b<=8;b++){
					dp[i][a+b][2] += dp[i-1][b][1]; 
					dp[i][a+b][2] %= MOD;
				}
			}
			for(int a=1;a<=8;a++){
				for(int b=1;b<=16;b++){
					dp[i][a+b][3] += dp[i-1][b][2];
					dp[i][a+b][3] %= MOD;
				}
			}
		}
		long long res = 0;
		for(int i=1;i<=24;i++){
			res += dp[n][i][3];
			res %= MOD;
		}
		cout << res << "\n";
	}
}