#include <bits/stdc++.h>
#define max_n 10005
using namespace std;

int T,n;
int st[max_n][20],lvl[max_n];
vector<vector<int>> edg;
void dfs(int v,int par){
	for(int next:edg[v]){
		lvl[next] = lvl[v] + 1;
		st[next][0] = v;
		dfs(next,v);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> T;
	while(T--){
		memset(st,0,sizeof(st));
		memset(lvl,0,sizeof(lvl));
		edg.clear();
		cin >> n;
		edg.resize(n+1);
		vector<int> root(n+1,1);
		int x,y;
		for(int i=1;i<n;i++){
			cin >> x >> y;
			edg[x].push_back(y);			
			root[y] = 0;
		}
		for(int i=1;i<=n;i++){
			if(root[i]){
				dfs(i,i);
				break;
			}
		}
		for(int j=1;j<20;j++){
			for(int i=1;i<=n;i++) st[i][j] = st[st[i][j-1]][j-1];
		}
		cin >> x >> y;
		if(lvl[x] > lvl[y]) swap(x,y);
		for(int j=19;j>=0;j--){
			if(lvl[y] - lvl[x] >= (1<<j)) y = st[y][j];
		}
		if(x!=y){
			for(int j=19;j>=0;j--){
				if(st[x][j] != st[y][j]){
					x = st[x][j];
					y = st[y][j];
				}
			}
			x = st[x][0];
		}
		cout << x << "\n";
	}
}