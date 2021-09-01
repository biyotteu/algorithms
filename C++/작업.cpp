#include <bits/stdc++.h>

using namespace std;

vector<int> gr[10005];
int n,root[10005],ttime[10005],res,dp[10005];
queue<int> q;
int dfs(int v){
	if(dp[v]) return dp[v];
	int MM = 0;
	for(auto i:gr[v]){
		MM = max(MM,dfs(i));
	}
	return dp[v] = MM + ttime[v];
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> ttime[i];
		int t;
		cin >> t;
		if(t == 0) root[i] = 1;
		while(t--){
			int x;
			cin >> x;
			gr[x].push_back(i);
		}
	}
	for(int i=1;i<=n;i++){
		if(root[i]) res = max(res,dfs(i));
	}
	cout << res;
}