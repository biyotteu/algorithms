//백준 15966
//DP 문제 
//연속적으로 증가하는 최장 수열을 찾는다
//dp[i] = i번째까지 연속적으로 증가한 수열의 최대값
#include <bits/stdc++.h>

using namespace std;

int n,dp[1000005];
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=0;i<n;i++){
		int x;
		cin >> x;
		dp[x] = max(dp[x],dp[x-1]+1);
	}
	int res = 0;
	for(int i=1;i<=1000000;i++)
		res = max(res,dp[i]);
	cout << res;
}