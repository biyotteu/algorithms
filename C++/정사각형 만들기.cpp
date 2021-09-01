#include <bits/stdc++.h>

using namespace std;

int dp[10005][105];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m,cnt=0;
	cin >> n >> m;
	while(n>=3*m){
		cnt++;
		n-=m;
	}
	for(int i=1;i<=n;i++) dp[i][1] = i;
	for(int i=1;i<=m;i++) dp[1][i] = i;

	for(int i=2;i<=n;i++){
		for(int j=2;j<=m;j++){
			int &ret = dp[i][j];
			if(i == j){
				ret = 1;
				continue;
			}
			ret = i*j;
			for(int k=1; k<=i/2; k++) ret=min(ret,dp[k][j]+dp[i-k][j]);
        	for(int k=1; k<=j/2; k++) ret=min(ret,dp[i][k]+dp[i][j-k]);
		}
	}
	cout << dp[n][m] + cnt;
}
