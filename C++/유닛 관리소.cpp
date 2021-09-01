#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<int,int>> graph[100005];
int dfs(int v){
	
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n-1;i++){
		int x,y,z;
		scanf("%d %d %d",&x,&y,&z);
		graph[x].push_back({y,z});
		graph[y].push_back({x,z});
	}
 	dfs(1);
}