#include <bits/stdc++.h>

using namespace std;

vector<int> dfn,fin,result;
int n,m,cnt;
vector<int> graph[20005]; // 홀수=not
stack<int> s;
vector<vector<int>> scc;
int idx(int v){
	if(v<0) return 2*(-v)-1;
	else return 2*v-2;
}
int NOT(int v){
	if(v%2) return v+1;
	else return v-1;
}
int dfs(int v){
	int ret = dfn[v] = cnt++;
	s.push(v);
	for(auto i:graph[v]){
		if(dfn[i] == -1) ret = min(ret,dfs(i));
		else if(!fin[i]) ret = min(ret,dfn[i]);
	}
	if(ret == dfn[v]){
		vector<int> tmp;
		int lvl = scc.size()+1;
		while(1){
			int cur = s.top();
			s.pop();
			tmp.push_back(cur);
			fin[cur] = lvl;
			if(cur == v) break;
		}
		scc.push_back(tmp);
	}
	return ret;
}
int main(){
	scanf("%d %d",&n,&m);
	dfn.resize(2*n+2,-1);
	fin.resize(2*n+2);
	for(int i=0;i<m;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		x = idx(x);
		y = idx(y);
		graph[NOT(x)].push_back(y);
		graph[NOT(y)].push_back(x);
	}
	for(int i=1;i<=2*n;i++)
		if(dfn[i] == -1) dfs(i);
	for(int i=1;i<=n;i++)
		if(fin[i*2] == fin[2*i-1]){
			printf("0");
			return 0;
		}
	puts("1");
	vector<int> res(n+1,-1);
	int l = scc.size();
	for(int i=l-1;i>=0;i--){
		for(auto j:scc[i]){
			if(res[j/2] == -1) res[j/2] = (j&1);
		}
	}
	for(int i=0;i<n;i++) printf("%d ",res[i]);
}