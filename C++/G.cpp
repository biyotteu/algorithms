#include <bits/stdc++.h>

using namespace std;

int n,m;
vector<vector<int>> node;
vector<int> dist,around,res;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> Q; 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	node.resize(n+1);
	for(int i=1;i<=n;i++){
		for(;;){
			int x;
			cin >> x;
			if(!x) break;
			node[i].push_back(x);
		}
	}
	dist.resize(n+1,-1);
	around.resize(n+1,0);
	res.resize(n+1,-1);
	cin >> m;
	for(int i=0;i<m;i++){
		int x;
		cin >> x;
		dist[x] = 0;
		Q.push({0,x});
	}
	while(Q.size()){
		int size = Q.size();
		for(int i=0;i<size;i++){
			pair<int,int> cur = Q.top();
			Q.pop();
			if(cur.first > dist[cur.second]) continue;
			for(auto i:node[cur.second]){
				if((dist[i] == -1 || dist[i] > dist[cur.second] + 1)){
					around[i] += 1;
					if(around[i]*2 >= node[i].size()){
						dist[i] = dist[cur.second] + 1;
						Q.push({dist[i],i});
					}	
				}
			}
		}
	}
	for(int i=1;i<=n;i++) cout << dist[i] << ' ';
	
}