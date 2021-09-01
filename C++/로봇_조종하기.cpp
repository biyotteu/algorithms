#include <bits/stdc++.h>
#define INF -(1<<29)

using namespace std;

int n,m,cost[1005][1005],dp[1005][1005],cur[1005][2];
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin >> cost[i][j];
	dp[1][1] = cost[1][1];
	for(int i=2;i<=m;i++) dp[1][i] = dp[1][i-1] + cost[1][i];
	for(int i=2;i<=n;i++){
		for(int j=1;j<=m;j++)
			cur[j][0] = cur[j][1] = (dp[i-1][j] + cost[i][j]);
		for(int j=2;j<=m;j++)
			cur[j][0] = max(cur[j][0],cur[j-1][0]+cost[i][j]);
		for(int j=m-1;j>=1;j--)
			cur[j][1] = max(cur[j][1],cur[j+1][1]+cost[i][j]);
		for(int j=1;j<=m;j++)
			dp[i][j] = max(cur[j][0],cur[j][1]);
	}
	cout << dp[n][m];
}