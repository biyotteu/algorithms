#include <bits/stdc++.h>

using namespace std;
using ii = pair<int,long long>;
using ll = long long;

int n,m,k,s,t;
ll dist[100005][15];
vector<ii> edg[100005],back[100005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> m>> k >> s >> t;
	for(int i=0;i<m;i++){
		int a,b;
		long long c;
		cin >> a >> b >> c;
		edg[a].push_back({b,c});
		back[b].push_back({a,0l});
	}
	memset(dist,-1l,sizeof(dist));
	priority_queue<pair<ll,pair<int,int>>> q;
	dist[s][0] = 0l;
	q.push({0l,{s,0}});
	while(!q.empty()){
		pair<ll,pair<int,int>> cur = q.top();q.pop();
		if(dist[cur.second.first][cur.second.second] > cur.first) continue;
		
		for(auto i:edg[cur.second.first]){
			if(i.second == 0 && cur.second.second+1 <= k){
				ll &ret = dist[i.first][cur.second.second+1];
				if(ret == -1 || ret < cur.first){
					ret = cur.first;
					q.push({cur.first,{i.first,cur.second.second+1}});
				}
			}
			if(i.second != 0){
				ll &ret = dist[i.first][cur.second.second];
				if(ret == -1 || ret < cur.first + i.second){
					ret = cur.first + i.second;
					q.push({cur.first + i.second,{i.first,cur.second.second}});
				}
			}
		}
	}

	ll res = -1;
	for(int i=0;i<=k;i++){
		res = max(res,dist[t][i]);
	}
	cout << res;
}