#include <bits/stdc++.h>

using namespace std;

int n,m,lvl[1005];
vector<int> gr[1005],res;
queue<int> Q;	
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	while(m--){
		int k;
		cin >> k;
		int last;
		cin >> last;
		for(int i=1;i<k;i++){
			int p;
			cin >> p;
			lvl[p]++;
			gr[last].push_back(p);
			last = p;
		}
	}
	for(int i=1;i<=n;i++)
		if(!lvl[i]) Q.push(i);
	while(Q.size()){
		int cur = Q.front();
		Q.pop();
		res.push_back(cur);
		for(auto i:gr[cur]){
			lvl[i]--;
			if(!lvl[i]) Q.push(i);
		}
	}
	if(res.size() != n) cout << 0;
	else{
		for(auto i:res) cout << i << "\n";
	}
}