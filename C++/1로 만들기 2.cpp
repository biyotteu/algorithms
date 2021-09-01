#include <bits/stdc++.h>

using namespace std;

int n,dp[1000005],p[1000005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i=1;i<=n;i++) dp[i] = 123456789;
	dp[1] = 0;
	for(int i=2;i<=n;i++){
		dp[i] = dp[i-1] + 1;
		p[i] = i-1;
		if(i%3 == 0){
			if(dp[i] > dp[i/3]+1){
				dp[i] = dp[i/3]+1;
				p[i] = i/3;
			}
		}
		if(i%2 == 0){
			if(dp[i] > dp[i/2]+1){
				dp[i] = dp[i/2]+1;
				p[i] = i/2;
			}
		}
	}
	cout << dp[n] << "\n";
	int k = n;
	while(1){
		cout << k << ' ';
		if(k == 1) break;
		k = p[k]; 
	}
}