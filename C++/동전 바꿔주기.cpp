//백준 2624번
//DP문제 
//dp[m][n] m:m번째 코인을 사용할 차례,n:현재의 누적 비용
//dp[m][n] = dp[m][n] + dp[m - 1][n - (v * c)] // v = 사용되는 동전의 금액, c = 동전 개수(1 ~ n)
// n원을 m개까지의 경우의 수 + n - v * c(사용되는 동전) 원을 이전 동전까지(m-1) 교환할 때까지의 경우의 수 

#include <bits/stdc++.h>

using namespace std;

int n,m,dp[105][10005];
vector<pair<int,int>> coin;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i=0;i<m;i++){
		int x,y;
		cin >> x >> y;
		coin.push_back({x,y});
	}
	sort(coin.begin(),coin.end());
	for(int i=0;i<=m;i++) dp[i][0] = 1;
	for(int i=1;i<=coin.size();i++){

		for(int j=1;j<=coin[i-1].second;j++){
			for(int k=j*coin[i-1].first;k<=n;k++){
				dp[i][k] += dp[i-1][k-coin[i-1].first*j];
			}
		}
		for(int j=1;j<=n;j++) dp[i][j] += dp[i-1][j];
	}
	cout << dp[m][n];
}