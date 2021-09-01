#include <bits/stdc++.h>
#define INF 123456789

using namespace std;

vector<pair<int,int>> graph[20005];
int n,m,s;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> Q;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> s;
	for(int i=0;i<m;i++){
		int x,y,z;
		cin >> x >> y >> z;
		graph[x].push_back({y,z});
	}
    vector<int> dist(n+1,INF);
    Q.push({0,s});
    dist[s]=0;
    while(!Q.empty())
    {
        pair<int,int> cur = Q.top();
        Q.pop();
        if(cur.first > dist[cur.second]) continue;
        for(auto i:graph[cur.second])
        {
            if(dist[i.first]>dist[cur.second]+i.second)
            {
                dist[i.first]=dist[cur.second]+i.second;
                Q.push({dist[i.first],i.first});
            }
        }
    }
    for(int i=1;i<=n;i++){
    	if(dist[i] == INF) cout << "INF\n";
    	else cout << dist[i] << "\n";
    }
}