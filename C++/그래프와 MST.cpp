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

int n,m,mstedge[MX],visit[MX],lvl[MX],parent[MX];
long long mst;
pp par[MX][20];
priority_queue<pos> Q;
vector<pp> tree[MX];
vector<pos> qr;


int _find(int v){
	if(parent[v] == v) return v;
	return parent[v] = _find(parent[v]);
}

void dfs(int v,int depth){
	visit[v] = 1;
	lvl[v] = depth;
	for(auto i:tree[v]){
		if(visit[i.first]) continue;
		par[i.first][0] = {i.first,i.second};
		dfs(i.first,depth+1);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++) parent[i]=i;
	for(int i=0;i<m;i++){
		int u,v,w;
		cin >> u >> v >> w;
		//cout << u <<  ' ' << v << ' ' << w << "*****\n";
		Q.push({u,v,w,i});
		qr.push_back({u,v,w,i});
	}
	while(Q.size()){
		pos cur = Q.top();
		Q.pop();
		int a = _find(cur.x);
		int b = _find(cur.y);
		if(a == b) continue;
		//cout << cur.x << ' ' << cur.y << ' ' <<cur.z << "#!#!#!##!\n";
		mstedge[cur.r] = 1;
		mst += cur.z;
		parent[a] = b;
		tree[cur.x].push_back({cur.y,cur.z});
		tree[cur.y].push_back({cur.x,cur.z});
	}
	dfs(1,0);
	cout << "###" << par[4][2].second << ' ' << par[4][0].first<<"###\n";
	for(int i=1;i<20;i++)
		for(int j=1;j<=n;j++){
			par[j][i].first = par[par[j][i-1].first][i-1].first;
			par[j][i].second = max(par[j][i-1].second,par[par[j][i-1].first][i-1].second);
		}
	//cout << mst << "######\n";
	for(int pp=0;pp<m;pp++){
		if(mstedge[pp]) cout << mst << "&&&\n";
		else{
			int a = qr[pp].x;
			int b = qr[pp].y;
			int mmm = 0;
			if(lvl[a] > lvl[b]) swap(a,b);
			for(int i=19;i>=0;i--)
				if(lvl[b] - lvl[a] >= (1<<i)){
					mmm = max(mmm,par[b][i].second);
					b = par[b][i].first;
				}
			if(a!=b){
				for(int i=19;i>=0;i--){
					if(par[a][i].first != par[b][i].first){
						mmm = max(mmm,max(par[a][i].second,par[b][i].second));
						a = par[a][i].first;
						b = par[b][i].first;
					}
				}
				mmm = max(mmm,par[a][0].second);
				a = par[a][0].first;
			}
			cout << mst - mmm + qr[pp].r<<"\n"; //<< ' ' << mmm << ' ' << pp<< "\n";
		}
	}
}