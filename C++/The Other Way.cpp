#include <bits/stdc++.h>
#define MX 100005
#define MOD 1000000009

using namespace std;
using pp = pair<long long,int>;

priority_queue<pp> Q;
int n,m,s,e;
long long dist[MX],dp[MX];
vector<pp> gr[MX];
vector<int> dag[MX];
long long f(int v){
	long long &ret = dp[v];
	if(ret) return ret;
	for(auto i:dag[v]){
		ret += f(i);
		ret %= MOD;
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> s >> e;
	for(int i=0;i<m;i++){
		int x,y,z;
		cin >> x >> y >> z;
		gr[x].push_back({z,y});
		gr[y].push_back({z,x});
	}
	memset(dist,-1,sizeof(dist));
	dist[s] = 0;
	Q.push({0,s});
	dp[s] = 1;
	while(Q.size()){
		pp cur = Q.top();
		Q.pop();
		cur.first = -cur.first;
		if(cur.first > dist[cur.second]) continue;
		for(auto i:gr[cur.second]){
			if(dist[i.second] == -1 || dist[i.second] > dist[cur.second] + i.first){
				dist[i.second] = dist[cur.second] + i.first;
				Q.push({-dist[i.second],i.second});
				dag[i.second].clear();
				dag[i.second].push_back(cur.second);
			}
			else if(dist[i.second] == dist[cur.second] + i.first){
				dag[i.second].push_back(cur.second);
			}
		}
	}
	cout << f(e);
}