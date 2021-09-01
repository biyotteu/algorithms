#include <bits/stdc++.h>
#define ML  20
#define MN 100005
#define INF 123456789

using namespace std;

struct info{
	int x,y;
};
vector<info> graph[MN];
int n,m,depth[MN],visit[MN],parent[MN][ML],br[MN][ML],sr[MN][ML];
int dfs(int v){
	visit[v] = 1;
	for(auto i:graph[v]){
		if(visit[i.x]) continue;
		parent[i.x][0] = v;
		br[i.x][0] = i.y;
		sr[i.x][0] = i.y;
		depth[i.x] = depth[v] + 1;
		dfs(i.x);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	fill_n(&sr[0][0],MN*ML,INF);
	for(int i=0;i<n-1;i++){
		int x,y,z;
		cin >> x >> y >> z;
		graph[x].push_back({y,z});
		graph[y].push_back({x,z});
	}
	dfs(1);
	for(int j=0;j<ML;j++)
		for(int i=1;i<=n;i++){
			if(parent[i][j]){
				parent[i][j+1] = parent[parent[i][j]][j];
				br[i][j+1] = max(br[parent[i][j]][j],br[i][j]);
				sr[i][j+1] = min(sr[parent[i][j]][j],sr[i][j]);
			}
		}
	cin >> m;
	for(int i=0;i<m;i++){
		int x,y,minres = INF, maxres = 0;
		cin >> x >> y;
		if(depth[x] < depth[y]) swap(x,y);
		int diff = depth[x] - depth[y];
		for(int j=0;diff;j++){
			if(diff%2){
				minres = min(minres,sr[x][j]);
				maxres = max(maxres,br[x][j]);
				x = parent[x][j];
			}
			diff/=2;
		}
		if(x!=y){
			for(int j=ML-1;j>=0;j--){
				if(parent[x][j] != parent[y][j]){
					minres = min(minres,min(sr[x][j],sr[y][j]));
					maxres = max(maxres,max(br[x][j],br[y][j]));
					x = parent[x][j];
					y = parent[y][j];
				}
			}
			minres = min(minres,min(sr[x][0],sr[y][0]));
			maxres = max(maxres,max(br[x][0],br[y][0]));
			x = parent[x][0];
		}
		cout << minres << ' ' << maxres << "\n";
	}
}