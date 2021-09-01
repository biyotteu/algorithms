#include <bits/stdc++.h>

using namespace std;

struct info{
	int x,y,z;
	bool operator<(info A){
		return z < A.z;
	}
};
vector<info> peo;
vector<int> parent;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin >> n >> m;
	parent.resize(n+1);
	for(int i=0;i<m;i++){
		int x,y,z;
		cin >> x >> y >> z;
		peo.push_back({x,y,z});
	}
	sort(peo.begin(),peo.end());
	parent[1]=1;
	vector<pair<int,int>> save;
	int be = 0;
	for(auto i:peo){
		if(parent[i.x] || parent[i.y]) save.push_back({i.x,i.y});
		if(be != i.z){
			for(auto j:save) parent[j] = 1;
			save.clear();
		}
		be = i.z;
	}
	for(int i=1;i<=n;i++){
		if(parent[i]) cout << i << ' ';
	}
}