#include <bits/stdc++.h>

using namespace std;

int n,T,dp[10005][3];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	for(int i=1;i<=10000;i++){
		for(int j=0;j<3;j++){
			if(i > j){
				if(i == j+1){
					dp[i][j] = 1;
					continue;
				}
				for(int k=0;k<=j;k++){
					dp[i][j] += dp[i-j-1][k];
				}
			}
		}
	}
	cin >> T;
	while(T--){
		cin >> n;
		cout << dp[n][0] + dp[n][1] + dp[n][2] << "\n";
	}
}