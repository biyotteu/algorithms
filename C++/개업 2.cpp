#include <bits/stdc++.h>

using namespace std;

int n,k;
vector<int> wik,dp,ch;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	dp.resize(n+1,(1<<29));
	ch.resize(n+1);
	for(int i=0;i<k;i++){
		int x;
		cin >> x;
		ch[x] = 1;
		wik.push_back(x);
	}
	for(int i=0;i<k;i++){
		for(int j=i+1;j<k;j++){
			if(wik[i]+wik[j] > n || ch[wik[i]+wik[j]]) continue;
			wik.push_back(wik[i]+wik[j]);
			ch[wik[i]+wik[j]] = 1;
		}
	}
	dp[0] = 0;
	for(int j=0;j<wik.size();j++){
		dp[wik[j]] = 1;
		for(int i=wik[j]+1;i<=n;i++)
			dp[i] = min(dp[i],dp[i-wik[j]]+1);
		}
	if(dp[n] != (1<<29))	cout << dp[n];
	else	cout << -1;
}