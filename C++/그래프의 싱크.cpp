#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graph;
vector<vector<int>> scc;
vector<int> dfn,fin,sn;
stack<int> s;
int n,m,cnt,res;
int dfs(int v){
	int ret = dfn[v] = cnt++;
	s.push(v);
	for(auto i:graph[v]){
		if(dfn[i] == -1) ret = min(ret,dfs(i));
		else if(!fin[i]) ret = min(ret,dfn[i]);
	}
	if(ret == dfn[v]){
		vector<int> tmp;
		while(1){
			int cur = s.top();
			s.pop();
			fin[cur] = 1;
			sn[cur] = scc.size()+1;
			tmp.push_back(cur);
			if(cur == v) break;
		}
		sort(tmp.begin(),tmp.end());
		scc.push_back(tmp);
	}
	return ret;
}
int main(){
	while(1){
		cnt = 1;
		res = 0;
		while(!s.empty()) s.pop();
		sn.clear();
		graph.clear();
		dfn.clear();
		fin.clear();
		scc.clear();
		scanf("%d",&n);
		graph.resize(n+1);
		dfn.resize(n+1,-1);
		fin.resize(n+1,0);
		sn.resize(n+1,0);
		if(n == 0) return 0;
		scanf("%d",&m);
		while(m--){
			int x,y;
			scanf("%d %d",&x,&y);
			graph[x].push_back(y);
		}
		for(int i = 1; i <= n; i++){
			if(dfn[i] == -1) dfs(i);
		}
		vector<int> result;
		for(auto i:scc){
			int cmp = 0;
			for(auto j:i){
				for(auto next:graph[j]){
					if(sn[next] == sn[j]) continue;
					else{
						cmp = 1;
						break;
					}
				}
				if(cmp) break;
			}
			if(cmp) continue;
			for(auto j:i) result.push_back(j);
		}
		sort(result.begin(),result.end());
		for(auto i:result) printf("%d ",i);
		printf("\n");
	}
}