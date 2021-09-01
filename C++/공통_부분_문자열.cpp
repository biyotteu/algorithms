#include <bits/stdc++.h>

using namespace std;

int n,cost[100005],visit[100005],dist[100005],res,k;
vector<int> graph[100005];
void dfs(int v,int cnt){
	if(visit[v]) return;
	if(res < cnt + cost[v]){
		res = cnt + cost[v];
		k = v;
	}
	visit[v] = 1;
	for(auto i:graph[v]){
		dfs(i,cnt + cost[v]);
	}
	visit[v] = 0;
	return;
}
int main(void) {
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&cost[i]);
	for(int i=0;i<n-1;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	dfs(1,0);
	printf("%d %d",k,res);
}