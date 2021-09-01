#include <bits/stdc++.h>
#define INF 123456789
using namespace std;

int n,dp[55][500005],res,sum;
vector<int> block;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(dp,-1,sizeof(dp));
	cin >> n;
	block.resize(n+1);
	dp[0][0] = 0;
	for(int i=1;i<=n;i++) cin >> block[i];
	for(int i=1;i<=n;i++){
		for(int j=0;j<=sum;j++){
			if(dp[i-1][j] == -1) continue;
			dp[i][j] = max(dp[i][j],dp[i-1][j]);
			int a = dp[i-1][j];
			int b = a+j;
			dp[i][j+block[i]] = max(dp[i][j+block[i]],a);
			a += block[i];
			if(a>b) swap(a,b);
			dp[i][b-a] = max(dp[i][b-a],a);
			if(a == b) res = max(res,dp[i][b-a]);
		}
		sum += block[i];
	}
	if(res == 0) cout << -1;
	else cout << res;
} 