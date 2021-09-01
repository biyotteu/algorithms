#include <bits/stdc++.h>

using namespace std;

int n,cost[1005],dp[1005];
int main(){
	std::ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1;i<=n;i++) cin >> cost[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(j>=i)
				dp[j] = max(dp[j],dp[j-i]+cost[i]);
		}
	}
	cout << dp[n];
}