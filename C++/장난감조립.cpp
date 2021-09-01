//백준 2637
//koi 2000
//dfs탐색 문제로
//리프노드만을 탐색하여
//자식노드부터 부모노드로 타고들어가
//코스트를 구한다

#include <bits/stdc++.h>

using namespace std;

int n,m,level[101];
vector<pair<int,int>> toy[101];
int dfs(int v){
	if(v == n) return 1;
	int ret = 0;
	for(auto i:toy[v]){
		ret += dfs(i.first) * i.second;
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	cin >> m;
	while(m--){
		int x,y,z;
		cin >> x >> y >> z;
		toy[y].push_back({x,z});
		level[x]++;
	}
	for(int i=1;i<n;i++){
		if(level[i]) continue;
		cout << i << ' ' << dfs(i)<< '\n';
	}
}