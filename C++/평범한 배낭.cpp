#include <bits/stdc++.h>

using namespace std;

int dp[105][100005];
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	int n,k;
	cin >> n >> k;
	vector<pair<int,int>> ob(n);
	for(auto &i:ob) cin >> i.first >> i.second;
	for(int i=0;i<n;i++){
		for(int j=0;j<=k;j++){
			if(!i){
				if(ob[i].first <= j) dp[i][j] = ob[i].second;
				continue;
			}
			if(ob[i].first <= j) dp[i][j] = max(dp[i-1][j],dp[i-1][j-ob[i].first] + ob[i].second);
			else dp[i][j] = dp[i-1][j];
		}
	}
	cout << dp[n-1][k];
}