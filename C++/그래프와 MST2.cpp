#include <bits/stdc++.h>
#define MX 200005

using namespace std;
using pp = pair<int,int>;

struct pos{
	int x,y,z,r;
	bool operator<(pos A) const{
		return z > A.z;
	}
};
int n,m,parent[MX],mstedge[MX],visit[MX],lvl[MX];
priority_queue<pos> Q;
vector<pp> tree[MX];
long long mst;
vector<pos> edge;
pp par[MX][20];

int _find(int v){
	if(v == parent[v]) return v;
	return parent[v] = _find(parent[v]);
}

void dfs(int v,int depth){
	visit[v] = 1;
	lvl[v] = depth;
	for(auto i:tree[v]){
		if(visit[i.first]) continue;
		par[i.first][0] = {v,i.second};
		dfs(i.first,depth+1);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++) parent[i] = i;
	for(int i=0;i<m;i++){
		int x,y,z;
		cin >> x >> y >> z;
		Q.push({x,y,z,i});
		edge.push_back({x,y,z,i});
	}
	while(Q.size()){
		pos cur = Q.top();
		Q.pop();
		int a = _find(cur.x);
		int b = _find(cur.y);
		if(a == b) continue;
		parent[a] = b;
		tree[cur.x].push_back({cur.y,cur.z});
		tree[cur.y].push_back({cur.x,cur.z});
		mst += cur.z;
		mstedge[cur.r] = 1;
	}
	dfs(1,0);
	for(int i=1;i<20;i++)
		for(int j=1;j<=n;j++){
			par[j][i].first = par[par[j][i-1].first][i-1].first;
			par[j][i].second = max(par[par[j][i-1].first][i-1].second,par[j][i-1].second);
		}
	for(int p=0;p<m;p++){
		if(mstedge[p]) cout << mst <<"\n";
		else{
			int a = edge[p].x;
			int b = edge[p].y;
			int cost = 0;
			if(lvl[a] > lvl[b]) swap(a,b);
			for(int i=19;i>=0;i--){
				if(lvl[b] - lvl[a] >= (1<<i)){
					cost = max(cost,par[b][i].second);
					b = par[b][i].first;
				}
			}
			if(a!=b){
				for(int i=19;i>=0;i--){
					if(par[a][i].first != par[b][i].first){
						cost = max(cost,max(par[a][i].second,par[b][i].second));
						a = par[a][i].first;
						b = par[b][i].first;
					}
				}
				cost = max(cost,par[a][0].second);
				cost = max(cost,par[b][0].second);
			}
			cout << mst - (long long)cost + (long long)edge[p].z <<"\n";
		}
	}
}