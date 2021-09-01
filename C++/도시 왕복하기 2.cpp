#include <bits/stdc++.h>

using namespace std;

int n,p;
int c[805][805],f[805][805],par[805];
vector<int> edg[805];
int flow(int src,int snk){
	queue<int> q;
	memset(par,-1,sizeof(par));
	q.push(src);
	while(!q.empty() && par[snk] == -1){
		int now = q.front();q.pop();
		for(int next:edg[now]){
			if(c[now][next] > f[now][next] && par[next] == -1){
				par[next] = now;
				q.push(next);
			}
		}
	}
	if(par[snk] == -1) return 0;
	for(int v=snk;v!=src;v=par[v]) f[par[v]][v]++,f[v][par[v]]--;
	return 1;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> p;
	for(int i=1;i<=n;i++){
		c[i][i+400] = 1;
		edg[i].push_back(i+400);
		edg[i+400].push_back(i);	
	}
	for(int i=0;i<p;i++){
		int x,y;
		cin >> x >> y;
		c[y+400][x] = c[x+400][y] = 1;
		edg[x+400].push_back(y);
		edg[y].push_back(x+400);
		edg[y+400].push_back(x);
		edg[x].push_back(y+400);
	}
	int cnt = 0;
	while(flow(401,2)) cnt++;
	cout << cnt;
}