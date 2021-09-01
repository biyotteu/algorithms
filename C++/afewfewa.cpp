#include <bits/stdc++.h>

using namespace std;

int n,e;
vector<vector<int>> edg;
vector<int> vst;
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
	int cnt = 0;
	queue<int> q;
	q.push(1);
	vst[1] = 1;
	while(!q.empty()){
		int v = q.front();q.pop();
		cnt++;
		for(int i:edg[v]){
			if(vst[i]) continue;
			vst[i] = 1;
			q.push(i);
		}
	}
	cout << cnt - 1;
}