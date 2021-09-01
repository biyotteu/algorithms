#include <bits/stdc++.h>

using namespace std;
using pp = pair<int,int>;
using ppp = pair<pair<int,int>,int>;

int n,q;
vector<ppp> fr;
vector<vector<int>> gr; 
int djk(int st,int en){
	vector<int> dist(n,-1);
	priority_queue<pp> Q;
	dist[st] = 0;
	Q.push({0,st});
	while(Q.size()){
		pp cur = Q.top();
		Q.pop();
		cur.first = -cur.first;
		if(cur.first > dist[cur.second]) continue;
		for(auto i:gr[cur.second]){
			if(dist[i] == -1 ||dist[cur.second] + 1 < dist[i]){
				dist[i] = dist[cur.second] + 1;
				Q.push({dist[i],i});
			}
		}
	}
	return dist[en];
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	gr.resize(n);
	for(int i=0;i<n;i++){
		int x,y;
		cin >> x >> y;
		if(x>y) swap(x,y);
		fr.push_back({{x,y},i});
	}
	sort(fr.begin(),fr.end());
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(fr[j].first.first > fr[i].first.second) break;
			gr[fr[i].second].push_back(fr[j].second);
			gr[fr[j].second].push_back(fr[i].second);
		}
	}
	cin >> q;
	while(q--){
		int x,y;
		cin >> x >> y;
		x--,y--;
		cout << djk(x,y) << "\n";
	}
}