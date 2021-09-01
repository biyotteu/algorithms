#include <bits/stdc++.h>

using namespace std;

int parent[1005],n,m,c,v,MM = 1000;
int _find(int v){
	if(v == parent[v]) return v;
	return parent[v] = _find(parent[v]);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> m >> c >> v;
	for(int i=1;i<=n;i++) parent[i] = i;
	priority_queue<pair<int,pair<int,int>>> q;
	for(int i=0;i<m;i++){
		int x,y,z;
		cin >> x >> y >> z;
		q.push({z,{x,y}});
	}
	while(!q.empty()){
		int cost = q.top().first, x = q.top().second.first, y = q.top().second.second;q.pop();
		MM = min(MM,cost);
		parent[_find(x)] = _find(y);
		if(_find(c) == _find(v)){
			cout << MM;
			return 0;
		}
	}
}