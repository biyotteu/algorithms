#include <bits/stdc++.h>
#define INF 123456789
using namespace std;

struct info{
	int x,y,z;
	bool operator<(info A)const{
		return z < A.z;
	}
};
int n,m,q,parent[200005],lvl[200005],MAX_SIZE;
pair<int,int> tree[200005][20];
priority_queue<info> pq;
vector<info> graph[200005];
int _find(int v){
	if(v == parent[v]) return v;
	return parent[v] = _find(parent[v]);
}
bool _union(info v){
	int a = _find(v.x);
	int b = _find(v.y);
	if(a == b) return false;
	parent[a] = b;
	return true;
}
void dfs(int v,int par,int cost){
	lvl[v] = lvl[par] + 1;
	tree[v][0].first = par;
	tree[v][0].second = cost;
	for(int i=1;i<=MAX_SIZE;i++){
		tree[v][i].first = tree[tree[v][i-1].first][i-1].first;
		tree[v][i].second = min(tree[v][i-1].second,tree[tree[v][i-1].first][i-1].second);
	}
	for(auto i:graph[v]){
		if(i.x == par) continue;
		dfs(i.x,v,i.y);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> q;
	MAX_SIZE = (int)floor(log2(n));
	for(int i=1;i<=n;i++) parent[i] = i;
	for(int i=0;i<m;i++){
		int x,y,z;
		cin >> x >>y >> z;
		pq.push({x,y,z});
	}
	for(int i=0;i<n;i++){
		info cur = pq.top();
		pq.pop();
		if(_union(cur)){
			graph[cur.x].push_back({cur.y,cur.z});
			graph[cur.y].push_back({cur.x,cur.z});
		}
	}
	dfs(1,0,0);
	for(int i=0;i<q;i++){
		int x,y;
		int res = 1234567890;
		cin >> x >> y;
		if(lvl[x] != lvl[y]){
			if(lvl[x] < lvl[y]) swap(x,y);
			for(int k = MAX_SIZE;k>=0;k--){
				if(lvl[tree[x][k].first] >= lvl[y]){
					if(tree[x][k].second!=0) res = min(res,tree[x][k].second);
					x = tree[x][k].first;
				}
			}
		}
		if(x == y){
			cout << res << '\n';
			continue;
		}else{
			for(int i=MAX_SIZE;i>=0;i--){
				if(tree[x][i] != tree[y][i]){
					if(tree[x][i].second) res = min(res,tree[x][i].second);
					if(tree[y][i].second) res = min(res,tree[y][i].second);
					x = tree[x][i].first;
					y = tree[y][i].first;
				}
					
			}
			cout << res << '\n';
		}
	}
}	