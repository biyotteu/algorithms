#include <bits/stdc++.h>

using namespace std;

int n,m,visit[1005];
vector<int> rel[1005];
void dfs(int v){
	if(visit[v]) return;
	visit[v] = 1;
	for(auto i:rel[v]) dfs(i); 
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		rel[x].push_back(y);
		rel[y].push_back(x);
	}
	int cnt = 0;
	for(int i=1;i<=n;i++){
		if(!visit[i]){
			dfs(i);
			cnt++;
		}
	}
	printf("%d",cnt);
}