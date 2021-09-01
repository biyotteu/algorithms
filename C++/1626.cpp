#include <bits/stdc++.h>
#define max_n 50005

using namespace std;
using iii = pair<int,pair<int,int>>;
using ii = pair<int,int>;

int n,m,lvl[max_n],par[max_n];
long long res;
int ret = 2e9,cnt;
ii st[max_n][20];
vector<ii> edg[max_n];

int _find(int v){
	if(v == par[v]) return v;
	return par[v] = _find(par[v]);
}
void dfs(int v,int par){
	for(ii next:edg[v]){
		if(next.first == par) continue;
		lvl[next.first] = lvl[v] + 1;
		st[next.first][0].first = v;
		st[next.first][0].second = next.second;
		dfs(next.first,v);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++) par[i] = i;
	priority_queue<iii> pq;
	queue<iii> q;
	for(int i=0;i<m;i++){
		int x,y,z;
		cin >> x>> y >> z;
		pq.push({-z,{x,y}});
	}
	while(!pq.empty()){
		iii cur = pq.top();pq.pop();
		cur.first = -cur.first;
		int x = _find(cur.second.first);
		int y = _find(cur.second.second);
		if(x == y) q.push(cur);
		else{
			cnt++;
			res += cur.first;
			par[y] = x;
			edg[cur.second.first].push_back({cur.second.second,cur.first});
			edg[cur.second.second].push_back({cur.second.first,cur.first});
		}
	}
	if(cnt != n-1 || m <= n-1){
		cout << -1;
		return 0;
	}
	dfs(1,1);
	for(int j=1;j<20;j++){
		for(int i=1;i<=n;i++){
			st[i][j].second = max(st[st[i][j-1].first][j-1].second,st[i][j-1].second);
			st[i][j].first = st[st[i][j-1].first][j-1].first;
		}
	}
	
	while(!q.empty()){
		iii cur = q.front();q.pop();
		int x = cur.second.first, y = cur.second.second;
		if(lvl[x] > lvl[y]) swap(x,y);
		int tmp = -1;
		for(int j=19;j>=0;j--){
			if(lvl[y]-lvl[x] >= (1<<j)){
				tmp = max(tmp,st[y][j].second);
				y = st[y][j].first;
			}
		}
		if(x != y){
			for(int j=19;j>=0;j--){
				if(st[x][j].first != st[y][j].first){
					tmp = max(tmp,max(st[x][j].second,st[y][j].second));
					x = st[x][j].first;
					y = st[y][j].first;
				}
			}
			tmp = max(tmp,max(st[x][0].second,st[y][0].second));
		}else{
			if(cur.first == tmp){
				x = cur.second.first, y = cur.second.second;
				if(lvl[x] > lvl[y]) swap(x,y);
				tmp = -1;
				for(int v = y;v!=x;v=st[v][0].first){
					if(cur.first != st[v][0].second) tmp = max(tmp,st[v][0].second);
				}
				// for(int j=19;j>=0;j--){
				// 	if(lvl[y]-lvl[x] >= (1<<j)){
				// 		tmp = max(tmp,st[y][j].second);
				// 		y = st[y][j].first;
				// 	}
				// }
			}
		}
		if(cur.first == tmp || tmp == -1) continue;
		ret = min(ret,cur.first-tmp);
	}
	if(ret == 2e9){
		cout << -1;
		return 0;
	}
	cout << res + ret;
}