#include <bits/stdc++.h>
#define INF 9876543210L
using namespace std;

struct info{
	int x,y;
};
int n,m,k;
vector<info> graph[100005];
vector<long long> spfa(int start){
	vector<long long> dist(2*n+5,INF);
	vector<int> inQ(2*n+5,0);
	queue<int> Q;
	dist[start] = 0;
	inQ[start] = 1;
	Q.push(start);
	while(!Q.empty()){
		int cur = Q.front();
		Q.pop();
		inQ[cur] = 0;
		for(auto i:graph[cur]){
			if(dist[cur] + i.y < dist[i.x]){
				dist[i.x] = dist[cur] + i.y;
				if(!inQ[i.x]){
					inQ[i.x] = 1;
					Q.push(i.x);
				}
			}
		}
	}
	return dist;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for(int i=0;i<m;i++){
		int x,y,z;
		cin >>  x >> y >> z;
		graph[x].push_back({y,z});
		graph[y].push_back({x,z});
		graph[x+n].push_back({y+n,z});
		graph[y+n].push_back({x+n,z});
	}
	vector<int> hay(n+1,0);
	for(int i=0;i<k;i++){
		int x,y;
		cin >> x >> y;
		hay[x] = max(hay[x],y);
	}
	for(int i=1;i<=n;i++){
		if(!hay[i]) continue;
		int x = i;
		int y = hay[i];
		graph[x+n].push_back({x,-y});
		for(auto i:graph[x]){
			graph[x+n].push_back({i.x,i.y-y});
		}
	}
	vector<long long> dist1 = spfa(n);
	vector<long long> dist2 = spfa(2*n); 
	for(int i=1;i<n;i++){
		if(dist1[i] >= dist2[i]) cout << "1\n";
		else cout << "0\n";
	}
}