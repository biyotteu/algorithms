#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n,r;
ll dp[1005][1005];
vector<vector<int>> tree;
vector<int> cost;
ll pr(int v,int cnt){
	ll &ret = dp[v][cnt];
	if(ret) return ret;
	for(auto i:tree[v]){
		if(!ret) ret = pr(i,cnt+1);
		else ret = min(ret,pr(i,cnt+1));
	}
	ret += cost[v]*cnt;
	return ret;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> r;
	tree.resize(n+1);
	cost.resize(n+1);
	for(int i=1;i<=n;i++) cin >> cost[i];
	for(int i=1;i<n;i++){
		int x,y;
		cin >> x >> y;
		tree[x].push_back(y);
	}
	cout << pr(r,1);
}