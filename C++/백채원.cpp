#include <bits/stdc++.h>

using namespace std;

struct info{
	int x,y;
};
int n,m,k;
vector<info> graph[200005];
vector<long long int> spfa(vector<int> start){
	vector<int> inQ(n+1);
	vector<long long int> dist(n+1);
	queue<int> Q;
	for(int i=1;i<=n;i++){
		inQ[i] = 0;
		dist[i] = -1;
	}
	for(auto i:start){
		dist[i] = 0;
		inQ[i] = 1;
		Q.push(i);
	}
	while(!Q.empty()){
		int cur = Q.front();
		Q.pop();
		inQ[cur] = 0;
		for(auto i:graph[cur]){
			if(dist[i.x] == -1 ||dist[i.x] > dist[cur] + i.y){
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
		cin >> x >> y >> z;
		graph[x].push_back({y,z});
		graph[y].push_back({x,z});
	}
	vector<int> pe,be;
	for(int i=0;i<k;i++){
		int x;
		cin >> x;
		pe.push_back(x);
	}
	be.push_back(1);
	vector<long long int> bedist = spfa(be);
	vector<long long int> pedist = spfa(pe);
	int res = 0;
	for(int i=2;i<=n;i++){
		if(bedist[i] < pedist[i]){
			cout << i << ' ';
			res = 1;
		}
	}
	if(!res) cout << res;
}	