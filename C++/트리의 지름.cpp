#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> gr[100005];
int n,visit[100005],node;
long long mmx;
long long dfs(int v){
	visit[v] = 1;
	long long mx = 0;
	for(auto i:gr[v]) 
		if(!visit[i.first]) mx = max(dfs(i.first) + i.second,mx);
	return mx;
}
void _find(int v,long long sum){
	visit[v] = 1;
	int cnt = 0;
	for(auto i:gr[v]){
		if(visit[i.first]) continue;
		cnt++;
		_find(i.first,sum + i.second);
	}
	if(!cnt){
		if(mmx < sum){
			mmx = sum;
			node = v;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i=1;i<n;i++){
		int x,y,z;
		cin >> x >> y >> z;
		gr[x].push_back({y,z});
		gr[y].push_back({x,z});
	}
	_find(1,0);
	memset(visit,0,sizeof(visit));
	cout << dfs(node);
}