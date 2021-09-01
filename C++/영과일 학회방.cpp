#include <bits/stdc++.h>

using namespace std;

int n,m,visit[55][55],idx[55][55],cnt,res;
vector<int> graph[50*50+10],llist,vs;
int X[4] = {1,0,-1,0};
int Y[4] = {0,1,0,-1};
void dfs(int x,int y,int ch){
	if(visit[x][y] || idx[x][y] == -1) return;
	visit[x][y] = 1;
	if(ch){
		for(int k=0;k<4;k++){
				int nx = X[k] + x;
				int ny = Y[k] + y;
				if(nx < 1 || ny < 1 || nx > n || ny > m || idx[nx][ny] == -1) continue;
				graph[idx[x][y]].push_back(idx[nx][ny]);
		}
		llist.push_back(idx[x][y]);
	}else{
		graph[idx[x][y]].push_back(cnt+1);
	}
	for(int k=0;k<4;k++){
		int nx = X[k] + x;
		int ny = Y[k] + y;
		if(nx < 1 || ny < 1 || nx > n || ny > m) continue;
		dfs(nx,ny,!ch);
	}
}
int f(int v){
	if(vs[v]) return 0;
	vs[v] = 1;
	for(int i=0;i<graph[v].size();i++){
		if(f(graph[v][i]) || graph[v][i] == cnt+1){
			graph[graph[v][i]].push_back(v);
			graph[v].erase(graph[v].begin()+i);
			return 1;
		}
	}
	return 0;
}
int main(){
	cin >> n >> m;1
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			char x;
			cin >> x;
			if(x == 'X') idx[i][j] = -1;
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			if(idx[i][j] == -1) continue;
			idx[i][j] = ++cnt;
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			if(visit[i][j] || idx[i][j] == -1) continue;
			dfs(i,j,1);
		}
	
	for(int i=0;i<llist.size();i++){
		vs.clear();
		vs.resize(cnt+2);
		if(f(llist[i])) res++;
	}
	cout << res+(cnt-res*2);
}