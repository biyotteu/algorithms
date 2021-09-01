#include <bits/stdc++.h>

using namespace std;

int parent[1005];
int _find(int v){
	if(parent[v] == v) return v;
	return parent[v] = _find(parent[v]);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n,m,cnt = 0;
		cin >> n >> m;
		for(int i=1;i<=n;i++) parent[i] = i;
		while(m--){
			int a,b;
			cin >> a >> b;
			a = _find(a);
			b = _find(b);
			if(a == b) continue;
			else{
				parent[a] = b;
				cnt++;
			}
		}
		cout << cnt << "\n";
	}
}