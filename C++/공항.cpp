#include <bits/stdc++.h>

using namespace std;

vector<int> parent;
int P,G,last,cnt=1,res;
int _find(int v){
	if(parent[v] == v) return v;
	return parent[v] = _find(parent[v]);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> G >> P;
	parent.resize(G+1);
	for(int i=1;i<=G;i++) parent[i] = i;
	for(int i=0;i<P;i++){
		int x;
		cin >> x;
		int xx = _find(x);
		if(!xx) break;
		else{
			int yy = _find(xx-1);
			res++;
			parent[xx] = yy;
		}
	}
	cout << res;
}