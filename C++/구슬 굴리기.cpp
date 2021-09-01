#include <bits/stdc++.h>
#define MX 300005

using namespace std;
using pp = pair<int,int>;

int n,_next[MX],parent[MX],t,check[MX],cyc[MX];
vector<pp> Q;
vector<int> res;
int _find(int v){
	if(v == parent[v]) return v;
	return parent[v] = _find(parent[v]);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> _next[i];
		parent[i] = i;
	}
	cin >> t;
	for(int i=0;i<t;i++){
		int x,y;
		cin >> x >> y;
		Q.push_back({x,y});
		if(x == 2) check[y] = 1;
	}
	for(int i=1;i<=n;i++){
		if(check[i] || _next[i] == 0) continue;
		if(_find(_next[i]) == i) cyc[i] = 1;
		else parent[i] = _find(_next[i]);
	}
	for(int i=Q.size()-1;i>=0;i--){
		int x = Q[i].first;
		int y = Q[i].second;
		if(x == 2){
			if(y == _find(_next[y])) cyc[y] = 1;
			else parent[y] = _find(_next[y]);
		}else{
			if(cyc[_find(y)]) res.push_back(-1);
			else res.push_back(_find(y));
		}
	}
	for(int i=res.size()-1;i>=0;i--){
		if(res[i] == -1) cout << "Infinity\n";
		else cout << res[i] << "\n";
	}
}