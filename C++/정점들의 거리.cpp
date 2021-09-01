#include <bits/stdc++.h>
#define ML 20
using namespace std;

struct info{
	int x,y;
};
vector<info> graph[40005];
int n,m,visit[40005],parent[40005][ML],depth[40005];
long long int dist[40005];
void dfs(int v){
	visit[v] = 1;
	for(auto i:graph[v]){
		if(visit[i.x]) continue;
		parent[i.x][0] = v;
		depth[i.x] = depth[v] + 1;
		dist[i.x] = dist[v] + i.y;
		dfs(i.x);
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
	dfs(1);
	for(int j=0;j<ML;j++){
		for(int i=1;i<=n;i++){
			if(parent[i][j]){
				parent[i][j+1] = parent[parent[i][j]][j];
			}
		}
	}
	cin >> m;
	for(int i=0;i<m;i++){
		int x,y,a,b;
		cin >> x >> y;
		a = x, b = y;
		if(depth[x] < depth[y]) swap(x,y);
		int diff = depth[x] - depth[y];
		for(int j=0;diff;j++){
			if(diff%2) x = parent[x][j];
			diff/=2;
		}
		if(x!=y){
			for(int j=ML-1;j>=0;j--){
				if(parent[x][j] != parent[y][j]){
					x = parent[x][j];
					y = parent[y][j];
				}
			}
			x = parent[x][0];
		}
		cout << dist[a] + dist[b] - 2*dist[x] << "\n";
	}
}