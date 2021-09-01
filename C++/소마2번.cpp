#include <bits/stdc++.h>

using namespace std;

vector<int> vst,edg;
int n,res;
vector<int> re;
void dfs(int v,int cnt,int st){
	if(!v) return;
	if(v == st){
		res = max(cnt,res);
		return;
	}
	dfs(v+edg[v],cnt+1,st);
}
void d(int v){
	vst[v] = 1;
	if(vst[v+edg[v]]){
		if(!(v+edg[v])) return;
		re.push_back(v+edg[v]);
		return;
	} 
	d(v+edg[v]);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n;
	int res = 0;
	vst.resize(n+1);
	edg.resize(n+1);
	for(int i=1;i<=n;i++) cin >> edg[i];
	for(int i=1;i<=n;i++){
		if(vst[i]) continue;
		d(i);
	}
	for(auto i:re) dfs(edg[i]+i,1,i);
	cout << res;
}