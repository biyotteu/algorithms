#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		vector<pair<int,int>> n(4);
		vector<long long> dist(6);
		for(auto &i:n) cin >> i.first >> i.second;
		int cnt = 0;
		for(int i=0;i<4;i++)
			for(int j=i+1;j<4;j++)
				dist[cnt++] = (n[i].first - n[j].first)*(n[i].first - n[j].first) + (n[i].second - n[j].second)*(n[i].second - n[j].second);
		sort(dist.rbegin(),dist.rend());
		cout << (dist[0] == dist[1] && dist[2] == dist[3] && dist[3] == dist[4] && dist[4] == dist[5]) << "\n";
	}
}