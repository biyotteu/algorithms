#include <bits/stdc++.h>
#define INF 123456789

using namespace std;

int n,dp[1005],score[1005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i=1;i<=n;i++) cin >> score[i];
	for(int i=1;i<=n;i++){
		int m = score[i],M = score[i];
		for(int j=i-1;j>=1;j--){
			m = min(m,score[j]), M = max(M,score[j]);
			dp[i] = max(dp[i],dp[j-1]+M-m);
		}
	}
	cout << dp[n];
}