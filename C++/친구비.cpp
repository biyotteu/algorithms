#include <bits/stdc++.h>

using namespace std;

int n,m,k,va = 0;
vector<int> parent,cost,res;
int _find(int v){
	if(v == parent[v]) return v;
	return parent[v] = _find(parent[v]);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> m >> k;
	parent.resize(n+1);
	cost.resize(n+1);
	res.resize(n+1,INT_MAX);
	for(int i=1;i<=n;i++){
		cin >> cost[i];
		parent[i]=i;
	} 
	while(m--){
		int x,y;
		cin >> x >> y;
		parent[_find(x)] = _find(y);
	}
	for(int i=1;i<=n;i++){
		int ret = _find(i);
		res[ret] = min(res[ret],cost[i]);
	}
	for(int i=1;i<=n;i++)
		if(i == _find(i)){
			if(res[i] != INT_MAX) va += res[i];
			else va += cost[i];
		} 
	if(va > k) cout << "Oh no";
	else cout << va;

}