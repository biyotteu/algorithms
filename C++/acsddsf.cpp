#include <bits/stdc++.h>

using namespace std;
using ii = pair<int,long long>;
using ll = long long;

int n,m,k,s,t;
ll dist[100005];
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
	dist[s] = 0;
	q.push({0,{s,0}});
	while(!q.empty()){
		pair<ll,pair<int,int>> cur = q.top();q.pop();
		if(dist[cur.second.first] > cur.first) continue;
		for(auto i:edg[cur.second.first]){
			ll &ret = dist[i.first];
			if(ret == -1 || ret < cur.first + i.second){
				ret = cur.first + i.second;
				q.push({ret,{i.first,cur.second.second}});
			}
		}
		if(cur.second.second<k){
			for(auto i:back[cur.second.first]){
				dist[i.first] = cur.first;
				q.push({cur.first,{i.first,cur.second.second+1}});
			}	
		}
		
	}
	cout << dist[t];
}