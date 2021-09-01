#include <bits/stdc++.h>

using namespace std;

int n,dp[55005][35],chu[35];
void f(int v,int sum){
	if(v > n) return;
	int &ret = dp[sum][v];
	if(ret != -1) return;
	ret = 1;
	f(v+1,sum+chu[v]);
	f(v+1,sum);
	f(v+1,abs(sum-chu[v]));
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i=0;i<n;i++) cin >> chu[i];
	memset(dp,-1,sizeof(dp));
	f(0,0);
	int m;
	cin >> m;
	for(int i=0;i<m;i++){
		int x;
		cin >> x;
		if(dp[x][n] == 1) cout <<"Y ";
		else cout << "N ";
	}
}