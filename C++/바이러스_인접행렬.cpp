#include <bits/stdc++.h>

using namespace std;

int n,e,cnt;
vector<vector<int>> edg;
vector<int> vst;
void f(int v){
	if(vst[v]) return;
	cnt++;
	vst[v] = 1;
	for(int i:edg[v]) f(i);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> e;
	edg.resize(n+1);
	vst.resize(n+1);
	while(e--){
		int x,y;
		cin >> x >> y;
		edg[x].push_back(y);
		edg[y].push_back(x);
	}
	f(1);
	cout << cnt - 1;
}