//백준 2616번
//DP문제
//dp[n][k] n:n번째 칸의 열차, k:k번째 소형기차
//각 칸에 승객의 누적합을 구한다.
//누적합을 통해 길이가 m인 열차의 구간합중 최대를 구한다.

#include <bits/stdc++.h>

using namespace std;

int n,m,dp[50005][3];
vector<int> train;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	train.resize(n+1);
	for(int i=1;i<=n;i++){
		cin >> train[i];
		train[i] += train[i-1];
	}
	cin >> m;
	for(int i=m;i<=n;i++){
		dp[i][0] = max(dp[i-1][0],train[i] - train[i-m]);
		if(dp[i-m][0]) dp[i][1] = max(train[i] - train[i-m] + dp[i-m][0],dp[i-1][1]);
		if(dp[i-m][1]) dp[i][2] = max(train[i] - train[i-m] + dp[i-m][1],dp[i-1][2]);
	}
	cout << dp[n][2];
}