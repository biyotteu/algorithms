#include <bits/stdc++.h>
#define INF (1<<29)
using namespace std;

int n,a[150],idx,dp[300005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	int sum = 0,cnt;
	for(int i=1;;i++){
		sum += i;
		a[i] = a[i-1] + sum;
		if(a[i] > n) break; 
	}
	for(int i=1;i<=n;i++) dp[i] = INF;
	dp[0] = 0;
	for(int i=1;i<=n;i++){
		for(int j=1;a[j]<=i;j++){
			dp[i] = min(dp[i],dp[i-a[j]] + 1);
		}
	}
	cout << dp[n];
}