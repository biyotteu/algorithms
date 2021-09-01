#include <bits/stdc++.h>

using namespace std;

int n,m,start,dist[20005];
vector<pair<int,int>> gr[20005];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> Q;
int main(){
	scanf("%d %d %d",&n,&m,&start);
	while(m--){
		int x,y,z;
		scanf("%d %d %d",&x,&y,&z);
		gr[x].push_back({y,z});
	}
	memset(dist,-1,sizeof(dist));
	dist[start] = 0;
	Q.push({0,start});
	while(Q.size()){
		pair<int,int> cur = Q.top();
		Q.pop();
		if(cur.first > dist[cur.second]) continue;
		for(auto i:gr[cur.second]){
			if(dist[i.first] == -1 || dist[i.first] > dist[cur.second] + i.second){
				dist[i.first] = dist[cur.second] + i.second;
				Q.push({dist[i.first],i.first});
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(dist[i] == -1) puts("INF");
		else printf("%d\n",dist[i]);
	}
}