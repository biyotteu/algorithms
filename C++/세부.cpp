#include <bits/stdc++.h>

using namespace std;

int start,endd,n,m;
vector<pair<int,int>> graph[100005];
int spfa(int st,int en){
	int dist[100005],inQ[100005];
	queue<int> Q;
	for(int i=1;i<=n;i++){
		dist[i] = 0;
		inQ[i] = 0;
	}
	Q.push(st);
	dist[st] = (1<<29);
	inQ[st]=1;
	while(!Q.empty()){
		int cur = Q.front();
		Q.pop();
		inQ[cur] = 0;
		for(auto i:graph[cur]){
			int k = min(dist[cur],i.second);
			if(dist[i.first] < k){
				dist[i.first] = k;
				if(!inQ[i.first]){
					Q.push(i.first);
					inQ[i.first] = 1;
				}
			}
		}
	}
	return dist[en];
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	cin >> start >> endd;
	for(int i=0;i<m;i++){
		int x,y,z;
		cin >> x >> y >> z;
		graph[x].push_back({y,z});
		graph[y].push_back({x,z});
	}
	cout << spfa(start,endd);
}