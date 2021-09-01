#include <bits/stdc++.h>

using namespace std;

vector<int> gr[100005];
int n,parent[100005];
void dfs(int v,int p){
	parent[v] = p;
	for(auto i:gr[v]) if(!parent[i]) dfs(i,v);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i=0;i<n;i++){
		int x,y;
		cin >> x >> y;
		gr[x].push_back(y);
		gr[y].push_back(x);
	}
	dfs(1,1);
	for(int i=2;i<=n;i++) cout << parent[i] <<"\n";
}