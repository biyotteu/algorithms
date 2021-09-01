#include <bits/stdc++.h>

using namespace std;

int n,root,d,res;
vector<int> gr[55];
set<int> s;
void dfs(int v){
	if(gr[v].empty() || gr[v].size() == 1 && gr[v][0] == d){
		res++;
		return;
	}
	for(auto i:gr[v]){
		if(i == d) continue;
		dfs(i);
	}
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		if(x == -1) root = i;
		else gr[x].push_back(i);
	}
	scanf("%d",&d);
	if(d == root){
		puts("0");
		return 0;
	}
	dfs(root);
	printf("%d",res);
}