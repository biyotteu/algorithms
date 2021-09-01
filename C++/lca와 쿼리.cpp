#include <bits/stdc++.h>
#define MX 100005

using namespace std;
using pp = pair<int,int>;

int n,m,visit[MX],par[MX][20],lvl[MX];
vector<int> tree[MX];
void dfs(int v,int depth){
	visit[v] = 1;
	lvl[v] = depth;
	for(auto i:tree[v]){
		if(visit[i]) continue;
		par[i][0] = v;
		dfs(i,depth+1);
	}
}
int lca(int a,int b){
	if(lvl[a] > lvl[b]) swap(a,b);
	for(int i=19;i>=0;i--)
		if(lvl[b] - lvl[a] >= (1<<i)) b = par[b][i];
	if(a!=b){
		for(int i=19;i>=0;i--){
			if(par[a][i] != par[b][i]){
				a = par[a][i];
				b = par[b][i];
			}
		}
		a = par[a][0];
	}
	return a;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i=0;i<n-1;i++){
		int x,y;
		cin >> x >> y;
		tree[x].push_back(y);
		tree[y].push_back(x);
	}
	dfs(1,0);
	for(int j=1;j<20;j++)
		for(int i=1;i<=n;i++) par[i][j] = par[par[i][j-1]][j-1];
	cin >> m;
	while(m--){
		int a,b,c;
		cin >> c >> a >> b;
		vector<pp> res;
		int x = lca(c,a), y = lca(c,b), z = lca(a,b);
		res.push_back({lvl[x],x});	
		res.push_back({lvl[y],y});	
		res.push_back({lvl[z],z});	
		sort(res.rbegin(),res.rend());
		cout << res[0].second << "\n";
	}
}