#include <bits/stdc++.h>

using namespace std;

vector<int> gr[10005];
int n,root[10005],t_[10005],res,dp[10005];
int dfs(int v){
	if(dp[v]) return dp[v];
	int MM = 0;
	for(auto i:gr[v]){
		MM = max(MM,dfs(i));
	}
	return dp[v] = MM + t_[v];
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> t_[i];
		int cnt = 0;
		while(1){
			int x;
			cin >> x;
			if(x == -1) break;
			cnt ++;
			gr[x].push_back(i);
		}
		if(cnt == 0) root[i] = 1;
	}
	for(int i=1;i<=n;i++){
		if(root[i]) dfs(i);
	}
	for(int i=1;i<=n;i++) cout << dp[i] <<"\n";
}
