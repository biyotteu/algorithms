#include <bits/stdc++.h>

using namespace std;
using pp = pair<int,int>;

vector<pp> graph[100005];
int par[100005][20];
int n,m,visit[100005],lvl[100005];
long long dist[100005];

void dfs(int v,int depth,long long sum){
	visit[v] = 1;
	lvl[v] = depth;
	dist[v] = sum;
	for(auto i:graph[v]){
		if(visit[i.first]) continue;
		par[i.first][0] = v;
		dfs(i.first,depth+1,sum + i.second);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i=0;i<n-1;i++){
		int x,y,z;
		cin >> x >> y >> z;
		graph[x].push_back({y,z});
		graph[y].push_back({x,z});
	}
	dfs(1,0,0);
	for(int i=1;i<20;i++)
		for(int j=1;j<=n;j++)
			par[j][i] = par[par[j][i-1]][i-1];
	cin >> m;
	while(m--){
		int x,a,b,st,en;
		cin >> x >> a >> b;
		st = a, en = b;
		if(lvl[a] > lvl[b]) swap(a,b);
		for(int i=19;i>=0;i--){
			if(lvl[b] - lvl[a] >= (1<<i))
				b = par[b][i]; 
		}
		if(a!=b){
			for(int i=19;i>=0;i--){
				if(par[a][i] != par[b][i]){
					a = par[a][i];
					b = par[b][i];
				}
			}
			a = par[a][0];
		}
		if(x == 1){
			cout << dist[st] + dist[en] - 2*dist[a] << "\n";
		}else{
			int k;
			cin >> k;
			if(lvl[st] - lvl[a] + 1 >= k){
				k-=1;
				for(int i=19;i>=0;i--){
					if((1<<i) <= k){
						k -= (1<<i);
						st = par[st][i];
					}
				}
				cout << st << "\n";
			}else{
				k = (lvl[st] + lvl[en] - 2*lvl[a] + 1) - k;
				for(int i=19;i>=0;i--){
					if((1<<i) <= k){
						k -= (1<<i);
						en = par[en][i];
					}
				}
				cout << en << "\n";
			}
		}
	}
}