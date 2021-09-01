#include <bits/stdc++.h>

using namespace std;

vector<int> node[100001];
int n;
long long int res;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i=0;i<n;i++){
		int x,y;
		cin >> x >> y;
		node[y].push_back(x);
	}
	for(int i=1;i<=n;i++){
		if(node[i].empty()) continue;
		sort(node[i].begin(),node[i].end());
	}
	for(int i=1;i<=n;i++){
		if(node[i].empty() || node[i].size() == 1) continue;
		res += node[i][1] - node[i][0];
		for(int j=1;j<node[i].size();j++){
			int p;
			if(j+1<node[i].size()) p = min(abs(node[i][j] - node[i][j-1]),abs(node[i][j] - node[i][j+1]));
			else p = abs(node[i][j] - node[i][j-1]);
			res += p;
		}
	}
	cout << res;
}