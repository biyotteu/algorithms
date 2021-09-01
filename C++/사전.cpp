#include <bits/stdc++.h>

using namespace std;

int n,m,k,dp[105][105];
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m >> k;
	dp[0][0] = 1;
	for(int i=0;i<=m;i++){
		for(int j=0;j<=n;j++){
			if(i == j && i == 0) continue;
			dp[j][i] += dp[j-1][i];
		}
	}
}
