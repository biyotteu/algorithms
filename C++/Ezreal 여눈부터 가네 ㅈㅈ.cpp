#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

long long dp[1600][1600],res,sum;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	dp[0][0] = 1;
	for(int i=1;i<1600;i++){
		dp[i][0] = 1;
		for(int j=1;j<=i;j++)
			dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%MOD;
	}
	int n;
	cin >> n;
	sum = n*5;
	for(int i=0;i<n;i++){
		int cur = sum - i*4;
		if(cur%3) continue;
		res += dp[n-1][i];
		res %= MOD;
	}
	cout << res;
}