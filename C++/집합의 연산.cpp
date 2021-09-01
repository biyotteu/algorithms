#include <bits/stdc++.h>

using namespace std;

int n,m;
int parent[1000005];
int _find(int v){
	if(parent[v] == v) return v;
	return parent[v] = _find(parent[v]);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++) parent[i] = i;
	for(int i=0;i<m;i++){
		int a,b,c;
		cin >> a >> b >> c;
		int bb = _find(b);
		int cc = _find(c);
		if(!a) parent[bb] = cc;
		else{
			if(bb == cc) cout << "YES" << "\n";
			else cout << "NO" << "\n";
		} 
	}
}