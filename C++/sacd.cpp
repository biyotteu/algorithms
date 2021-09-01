#include <bits/stdc++.h>
#define MOD 1000000007LL
using namespace std;

long long dp[100005][25][4];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n,m;
		memset(dp,0,sizeof(dp));
		cin >> n >> m;
		for(int i=1;i<=8;i++){
			dp[1][i][1] = dp[1][i][2] =dp[1][i][3] = 1;
		}
		for(int i=1;i<=8;i++){
			for(int j=1;j<=24;j++) dp[2][i][1] += dp[1][j][3];
		}
		for(int i=1;i<=16;i++){
			for(int j=1;j<=8;j++){
				if(i-j>=1 && i-j <= 8){
					dp[2][i][2] += dp[1][i-j][1];
				}
			}
		}
		for(int i=1;i<=24;i++){
			for(int j=1;j<=8;j++) dp[2][i][3] += dp[1][i-j][2];
		}
		for(int i=3;i<=n;i++){
			for(int a=1;a<=8;a++){
				for(int b=1;b<=24;b++){
					dp[i][a][1] += dp[i-1][b][3];
					dp[i][a][1] %= MOD;
				}
			}
			for(int a=1;a<=16;a++){
				for(int b=1;b<=8;b++){
					if(a-b>=1 && a-b<=8){
						dp[i][a][2] += dp[i-1][a-b][1]; 
						dp[i][a][2] %= MOD;
					}
				}
			}
			for(int a=m;a<=24;a++){
				for(int b=1;b<=8;b++){
					if(a>b){
						dp[i][a][3] += dp[i-1][a-b][2];
						dp[i][a][3] %= MOD;
					}
				}
			}
		}
		long long res = 0;
		/*for(int i=1;i<=10;i++){
			cout << i << "@@@@";
			for(int j=1;j<=24;j++) cout << dp[i][j][3] << ' ';
				cout << endl;
		}*/
		for(int i=1;i<=24;i++){
			res += dp[n][i][3];
			res %= MOD;
		}
		cout << res << "\n";
	}
}