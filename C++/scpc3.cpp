#include <bits/stdc++.h>

using namespace std;

int n,m,k;
vector<int> lvl,vst,st,par;
vector<vector<int>> edg;
int _find(int v){
	if(par[v] == v) return v;
	return par[v] = _find(par[v]);
}
void dfs(int v,int c,int dp){
	lvl[v] = dp;
	vst[v] = c;
	par[v] = c;
	for(auto i:edg[v]) dfs(i,c,dp+1);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	int T;
	cin >> T;
	for(int t=1;t<=T;t++){
		cout << "Case #" << t <<"\n";
		cin >> n >> m >> k;
		lvl.clear();
		lvl.resize(n+1);
		edg.clear();
		edg.resize(n+1);
		vst.clear();
		vst.resize(n+1);
		st.clear();
		st.resize(n+1);
		par.clear();
		par.resize(n+1);
		for(int i=0;i<m;i++){
			int x,y;
			cin >> x >> y;
			edg[x].push_back(y);
		}
		for(int i=1;i<=n;i++){
			if(vst[i]) continue;
			dfs(i,i,1);
		}
		for(int i=0;i<k;i++){
			int x,y;
			cin >> x >> y;
			if(_find(x) == _find(y)){
				if(lvl[x] + st[vst[x]] < lvl[y] + st[vst[y]]) cout << 0;
				else cout << 1;
			}else{
				cout << 0;
				par[_find(y)] = par[_find(x)];
				st[vst[y]] += st[vst[x]];
			}
		}
		cout << "\n";
	}
}