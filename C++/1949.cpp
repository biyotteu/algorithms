#include <bits/stdc++.h>

using namespace std;

int n,pp[10005],vst[10005],dp[10005][2];
vector<int> edg[10005];
void dfs(int v){
	for(int next:edg[v]){
		if(vst[next]) continue;
		vst[next] = 1;
		dfs(next);
		dp[v][1] += dp[next][0];
		dp[v][0] += max(dp[next][1],dp[next][0]);
	}
	dp[v][1] += pp[v];
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n;
	for(int i=1;i<=n;i++) cin >> pp[i];
	for(int i=1;i<n;i++){
		int x,y;
		cin >> x >> y;
		edg[x].push_back(y);
		edg[y].push_back(x);
	}
	vst[1] = 1;
	dfs(1);	
	cout << max(dp[1][0],dp[1][1]);
}