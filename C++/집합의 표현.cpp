#include <bits/stdc++.h>

using namespace std;

int n,m,parent[205];
int _find(int v){
	if(v == parent[v]) return v;
	return parent[v] = _find(parent[v]);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++) parent[i] = i;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int x;
			cin >> x;
			if(!x) continue;
			parent[_find(i)] = _find(j);
		}
	}
	int k = -1;
	while(m--){
		int x;
		cin >> x;
		if(k == -1) k = _find(x);
		else{
			if(_find(k) != _find(x)){
				cout << "NO";
				return 0;
			}
		}
	}
	cout << "YES";
}