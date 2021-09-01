#include <bits/stdc++.h>

using namespace std;

int color[205],n,m;
vector<int> graph[205];
bool _find(int v,int t){
	color[v] = t;
	for(auto i:graph[v]){
		if((color[i] == 0 &&!_find(i,t^2)) || color[i]==t) return false;
	}
	return true;
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	if(_find(0,1)) printf("OK");
	else printf("IMPOSSIBLE");
}