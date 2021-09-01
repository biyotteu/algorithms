#include <bits/stdc++.h>

using namespace std;

struct edg{
	int v,c,d;
	bool operator<(edg A)const{
		return d > A.d;
	}
};
int n,m,k,T,dist[105][10005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> T;
	while(T--){
		memset(dist,-1,sizeof(dist));
		cin >> n >> m >> k;
		vector<vector<edg>> ed(n+1);
		for(int i=0;i<k;i++){
			int u,v,c,d;
			cin >> u >> v >> c >> d;
			ed[u].push_back({v,c,d});
			// ed[v].push_back({u,c,d});
		}
		priority_queue<edg> q;
		dist[1][0] = 0;
		q.push({1,0,0});
		while(!q.empty()){
			edg now = q.top();q.pop();
			if(dist[now.v][now.c] < now.d) continue;
			for(edg next:ed[now.v]){
				int nxm = now.c + next.c;
				if(nxm <= m && (dist[next.v][nxm] == -1 || dist[next.v][nxm] > now.d + next.d)){
					dist[next.v][nxm] = now.d + next.d;
					q.push({next.v,nxm,now.d + next.d});
				}
			}
		}
		int res = INT_MAX;
		for(int i=0;i<=m;i++){
			if(dist[n][i] != -1) res = min(res,dist[n][i]);
		}
		if(res == INT_MAX) cout<< "Poor KCM\n";
		else cout << res << "\n";
	}
}