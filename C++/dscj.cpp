#include <bits/stdc++.h>

using namespace std;

int dfn[20005],fin[20005];
int n,m,cnt,scnt;
vector<int> graph[20005]; // 홀수=not
stack<int> s;
int NOT(int v){
	return v>n ? v-n : v+n;
}
int dfs(int v){
	int ret = dfn[v] = ++cnt;
	s.push(v);
	for(auto i:graph[v]){
		if(!dfn[i]) ret = min(ret,dfs(i));
		else if(!fin[i]) ret = min(ret,dfn[i]);
	}
	if(ret == dfn[v]){
		scnt++;
		while(1){
			int cur = s.top();
			s.pop();
			fin[cur] = scnt;
			if(cur == v) break;
		}
	}
	return ret;
}
int main(){
	scanf("%d %d",&n,&m);
	while(m--){
		int x,y;
		scanf("%d %d",&x,&y);
		if(x<0) x = -x+n;
		if(y<0) y = -y+n;
		graph[NOT(x)].push_back(y);
		graph[NOT(y)].push_back(x);
	}
	for(int i=1;i<=2*n;i++) if(!dfn[i]) dfs(i);
	for(int i=1;i<=n;i++)
		if(fin[i] == fin[i+n]){
			puts("0");
			return 0;
		}
	puts("1");
	for(int i=1;i<=n;i++)
		printf("%d ",fin[i] < fin[n+i]);
}