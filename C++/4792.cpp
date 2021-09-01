#include <bits/stdc++.h>
#define max_n 1005

using namespace std;

int par[max_n];
int _find(int v){
	if(v == par[v]) return v;
	return par[v] = _find(par[v]);
}
int main(){
	while(1){
		int n,m,k;
		cin >> n >> m >> k;
		if(n == 0) break;
		for(int i=1;i<=n;i++) par[i]=i;
		vector<pair<int,int>> R,B;
		for(int i=0;i<m;i++){
			char color;
			int x,y;
			cin >> color >> x >> y;
			// cout << color << x << y << "~~~~\n";
			if(color == 'R') R.push_back({x,y});
			else B.push_back({x,y});
		}
		int Bmin = 0,Bmax = 0;
		for(auto i:B){
			int x = _find(i.first);
			int y = _find(i.second);
			if(x == y) continue;
			par[y] = x;
			Bmax++;
		}
		for(int i=1;i<=n;i++) par[i]=i;
		for(auto i:R){
			int x = _find(i.first);
			int y = _find(i.second);
			if(x == y) continue;
			par[y] = x;
		}
		for(auto i:B){
			int x = _find(i.first);
			int y = _find(i.second);
			if(x == y) continue;
			par[y] = x;
			Bmin++;
		}
		if(Bmin <= k && k <= Bmax) cout << "1\n";
		else cout << "0\n";
	}
}