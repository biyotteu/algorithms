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
int _find(int v){
	if(v == parent[v]) return v;
	return parent[v] = _find(parent[v]);
}
void _union(int a,int b){
	a = _find(a);
	b = _find(b);
	parent[a] = b;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin >> n >> m;
	parent.resize(n+1);
	for(int i=1;i<=n;i++) parent[i]=i;
	for(int i=0;i<m;i++){
		int x,y,z;
		cin >> x >> y >> z;
		peo.push_back({x,y,z});
	}
	sort(peo.begin(),peo.end());
	int be = 0;
	vector<int> save;
	for(auto i:peo){
		if(be != i.z){
			for(auto j:save){
				if(_find(j)!=_find(1)){
					parent[j] = j;
				}
			}
			save.clear();
			be = i.z;
		}
		_union(i.x,i.y);
		save.push_back(i.x);
		save.push_back(i.y);
	}
	for(int i=1;i<=n;i++){
		if(_find(1) == _find(i)) cout << i << ' ';
	}
}