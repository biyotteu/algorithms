#include <bits/stdc++.h>
#define MOD 1000000009

using namespace std;

long long dp[1005];
int card[1005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++) cin >> card[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i < j) break;
			if(!dp[i]) dp[i] = dp[i-j] + card[j];
			else dp[i] = min(dp[i],dp[i-j] + card[j]);
		}
	}
	cout << dp[n];
}