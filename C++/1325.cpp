#include <bits/stdc++.h>

using namespace std;

int n,m,cnt;
vector<vector<int>> edg;
vector<int> vst;
void dfs(int v){
	vst[v] = 1;
	cnt++;
	for(int next:edg[v]){
		if(vst[next]) continue;
		dfs(next);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	edg.resize(n+1);
	for(int i=0;i<m;i++){
		int x,y;
		cin >> x >> y;
		edg[y].push_back(x);
	}
	int res = 0;
	vector<int> res_arr;
	for(int i=1;i<=n;i++){
		vst.clear();
		vst.resize(n+1,0);
		cnt = 0;
		dfs(i);
		if(res < cnt){
			res_arr.clear();
			res_arr.push_back(i);
			res = cnt;
		}else if(res == cnt){
			res_arr.push_back(i);
		}
	}
	for(int i:res_arr) cout << i << ' ';
}