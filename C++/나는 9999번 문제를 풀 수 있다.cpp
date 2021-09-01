#include <bits/stdc++.h>

using namespace std;

int n,m,a[305];
int _find(int v){
	if(v == parent[v]) return v;
	return parent[v] = _find(parent[v]);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(1){
		cin >> n >> m;
		if(n+m == 0) return 0;
		for(int i=1;i<=n;i++){
			int x;
			cin >> x;
			if(x) a[i] = 1;
			else a[i] = -1;
		}
	}
}