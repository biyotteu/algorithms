#include <bits/stdc++.h>

using namespace std;

int n,m,lvl[100005],MS,tree[100005][20];
vector<int> graph[100005];
int dfs(int v,int par){
	lvl[v] = lvl[par] + 1;
	tree[v][0] = par;
	for(int i = 1;i<=MS;i++)
		tree[v][i] = tree[tree[v][i-1]][i-1];
	for(auto i:graph[v]){
		if(i == par) continue;
		dfs(i,v);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	MS = (int)floor(log2(n));
	for(int i=0;i<n-1;i++){
		int x,y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	dfs(1,0);
	cin >> m;
	for(int i=0;i<m;i++){
		int x,y;
		cin >> x >> y;
		if(lvl[x] < lvl[y]) swap(x,y);
		for(int k=MS;k>=0;k--){
			if(lvl[tree[x][k]] >= lvl[y])
				x = tree[x][k];
		}
		if(x == y){
			cout << x << "\n";
			continue;
		}else{
			int res = x;
			for(int k = MS; k>=0; k--){
				if(tree[x][k] != tree[y][k]){
					x = tree[x][k];
					y = tree[y][k];
				}
			}
			cout <<tree[x][0] << '\n';
		}
	}

}