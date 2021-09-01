#include <bits/stdc++.h>
#define INF 123456789000L

using namespace std;

struct edge{
	int x;
	long long int y;
};
int n,m,res;
vector<edge> graph[4005];
vector<long long int> spfa(){
	vector<long long int> dist(n+1,INF);
	vector<int> inQ(n+1,0);
	queue<int> Q;
	Q.push(1);
	inQ[1] = 1;
	dist[1] = 0;
	while(!Q.empty()){
		int cur = Q.front();
		Q.pop();
		inQ[cur] = 0;
		for(auto i:graph[cur]){
			if(dist[i.x] > dist[cur] + i.y){
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
vector<vector<long long int>> spfa2(){
	vector<vector<long long int>> dist(n+1,vector<long long int>(2,INF));
	vector<vector<int>> inQ(n+1,vector<int>(2,0));
	queue<pair<int,int>> Q;
	Q.push({1,0});
	dist[1][0] = 0;
	inQ[1][0] = 1;
	while(!Q.empty()){
		pair<int,int> cur = Q.front();
		Q.pop();
		inQ[cur.first][cur.second] = 0;
		for(auto i:graph[cur.first]){
			if(cur.second == 0){
				if(dist[i.x][!cur.second] > dist[cur.first][cur.second] + i.y/2){
					dist[i.x][!cur.second] = dist[cur.first][cur.second] + i.y/2;
					if(!inQ[i.x][!cur.second]){
						inQ[i.x][!cur.second] = 1;
						Q.push({i.x,!cur.second});
					}
				}
			}else{
				if(dist[i.x][!cur.second] > dist[cur.first][cur.second] + i.y*2){
					dist[i.x][!cur.second] = dist[cur.first][cur.second] + i.y*2;
					if(!inQ[i.x][!cur.second]){
						inQ[i.x][!cur.second] = 1;
						Q.push({i.x,!cur.second});
					}
				}
			}
		}
	}
	return dist;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i=0;i<m;i++){
		int x,y;
		long long int z;
		cin >> x >> y >> z;
		z *= 2;
		graph[x].push_back({y,z});
		graph[y].push_back({x,z});
	}
	vector<long long int> fox = spfa();
	vector<vector<long long int>> wolf = spfa2();
	for(int i=1;i<=n;i++){
		if(fox[i] < min(wolf[i][0],wolf[i][1])) res++;
	}
	cout << res;
}