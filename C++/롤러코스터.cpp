#include <bits/stdc++.h>
#define INF 1234567890

using namespace std;

struct info{
	int x,y;
};
vector<info> graph[10005];
int n,m;
int spfa(int st,int en){
	vector<int> inQ(n+1,0),dist(n+1,0);
	queue<int> Q;
	Q.push(st);
	inQ[st] = 1;
	dist[st] = INF;
	while(!Q.empty()){
		int cur = Q.front();
		Q.pop();
		inQ[cur] = 0;
		for(auto i:graph[cur]){
			if(dist[i.x] < min(dist[cur],i.y)){
				dist[i.x] = min(dist[cur],i.y);
				if(!inQ[i.x]){
					inQ[i.x] = 1;
					Q.push(i.x);
				}
			}
		}
	}
	return dist[en];
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n>> m;
	for(int i=0;i<m;i++){
		int x,y,z;
		cin >> x >> y >> z;
		graph[x].push_back({y,z});
		graph[y].push_back({x,z});
	}
	int a,b;
	cin >> a >> b;
	cout << spfa(a,b);
}