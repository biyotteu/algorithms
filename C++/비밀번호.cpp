#include <bits/stdc++.h>

using namespace std;

int n,m,dp[10][10];
vector<int> pass;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i=0;i<m;i++){
		int x;
		cin >> x;
		pass.push_back(x);
	}
	dp[0][0] = 1;
	for(int j=1;j<=n;j++){
		for(int i=0;i<=m;i++){
			if(i == 0) dp[j][i] += dp[j-1][i]*9; 
			else{
				dp[j][i] += dp[j-1][i] * 9;
				dp[j][i] += dp[j-1][i-1];
			}
			cout << dp[j][i] << ' ';
		}
		cout << endl;
	}

	cout << dp[n][m];
}