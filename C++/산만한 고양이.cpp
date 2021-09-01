#include <bits/stdc++.h>

using namespace std;
using pp = pair<int,int>;

int cnt,n,m,lvl[300005],finish[300005],res;
vector<int> gr[300005];
pp dfs(int v){
	int ret = lvl[v] = cnt++;
	int down = 0, up = 0;
	for(auto i:gr[v]){
		if(lvl[i] == -1){
			pp tmp = dfs(i);
			down += tmp.first;
			up += tmp.second;
		}
		else{
			if(finish[i]){
				down++,up--;
			}else{
				up++;
			}
		}
	}
	finish[v] = 1;
	return {down,up};
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
 	dfs(1);
}