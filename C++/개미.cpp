#include <bits/stdc++.h>
#define MX 100005

using namespace std;
using pp = pair<int,int>;

vector<pp> graph[MX];
int n,ant[MX],visit[MX],dist[MX],par[MX][20];
void dfs(int v,int sum){
	visit[v] = 1;
	dist[v] = sum;
	for(auto i:graph[v]){
		if(visit[i.first]) continue;
		par[i.first][0] = v;
		dfs(i.first,sum+i.second);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i=1;i<=n;i++) cin >> ant[i];
	for(int i=0;i<n-1;i++){
		int x,y,z;
		cin >> x >> y >> z;
		graph[x].push_back({y,z});
		graph[y].push_back({x,z});
	}
	dfs(1,0);
	for(int i=1;i<20;i++)
		for(int j=1;j<=n;j++)
			par[j][i] = par[par[j][i-1]][i-1];

	for(int i=1;i<=n;i++){
		int p = i, sum = ant[i];
		for(int j=19;j>=0;j--){
			if(dist[p] - dist[par[p][j]] <= sum){
				sum -= (dist[p] - dist[par[p][j]]);
				p = par[p][j];
			}
		}
		if(!p) p = 1;
		cout << p << "\n";
	}
}