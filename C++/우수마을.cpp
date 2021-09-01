#include <bits/stdc++.h>

using namespace std;

int n,vil[10005],visit[10005];
vector<int> ma[10005];
int dfs(int v,int p){
	int ret = (p ? vil[v] : 0);
	visit[v] = 1;
	for(auto i:ma[v]){
		if(visit[i]) continue;
		if(p) ret += dfs(i,0);
		else ret += max(dfs(i,1),dfs(i,0));
	}
	visit[v] = 0;
	return ret;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&vil[i]);
	for(int i=1;i<=n-1;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		ma[x].push_back(y);
		ma[y].push_back(x);
	}
	printf("%d",max(dfs(1,1),dfs(1,0)));
}