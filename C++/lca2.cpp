#include <bits/stdc++.h>
#define max_n 100005

using namespace std;

int n,m,lvl[max_n],st[max_n][20];
vector<int> edg[max_n];

void dfs(int v,int par){
	lvl[v] = lvl[par] + 1;
	st[v][0] = par;
	for(int next:edg[v]){
		if(next == par) continue;
		dfs(next,v);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n;
	for(int i=0;i<n-1;i++){
		int x,y;
		cin >> x >> y;
		edg[x].push_back(y);
		edg[y].push_back(x);
	}
	dfs(1,0);
	for(int j=1;j<20;j++){
		for(int i=1;i<=n;i++){
			st[i][j] = st[st[i][j-1]][j-1];
		}
	}
	cin >> m;
	while(m--){
		int x,y;
		cin >> x >> y;
		if(lvl[x] > lvl[y]) swap(x,y);
		for(int j=19;j>=0;j--){
			if(lvl[y] - lvl[x] >= (1<<j)) y = st[y][j];
		}
		if(x == y) cout << x << "\n";
		else{
			for(int j=19;j>=0;j--){
				if(st[x][j] != st[y][j]){
					x = st[x][j];
					y = st[y][j];
				}
			}
			cout << st[x][0] << "\n";
		}

	}
}