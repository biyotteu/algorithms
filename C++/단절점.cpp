#include <bits/stdc++.h>

using namespace std;

int n,m,lvl[10005],able[10005],cnt,res;
vector<int> gr[10005];
int dfs(int v,int root){
	int ret = lvl[v] = cnt++;
	int node = 0;
	for(auto i:gr[v]){
		if(lvl[i] == -1){
			node++;
			int cur = dfs(i,0);
			if(!root && cur >= lvl[v])	able[v] = 1;
			ret = min(ret,cur);
		}else{
			ret = min(ret,lvl[i]);
		}
	}
	if(root && node > 1) able[v] = 1;
	return ret;
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		gr[x].push_back(y); 
		gr[y].push_back(x); 
	}
	memset(lvl,-1,sizeof(lvl));
	for(int i=1;i<=n;i++)
		if(lvl[i] == -1) dfs(i,1);
	for(int i=1;i<=n;i++) if(able[i]) res++;
	printf("%d\n",res);
	for(int i=1;i<=n;i++) if(able[i]) printf("%d ",i);
}