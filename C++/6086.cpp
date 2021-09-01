#include <bits/stdc++.h>

using namespace std;

int n,par[100],c[100][100],f[100][100];
vector<int> edg[100];
int main(){
	cin >> n;
	for(int i=0;i<n;i++){
		char x,y;
		int z;
		cin >> x >> y;
		cin >> z;
		c[x-65][y-65] += z;
		c[y-65][x-65] += z;
		edg[x-65].push_back(y-65);
		edg[y-65].push_back(x-65);
	}
	int res = 0;
	while(1){
		memset(par,-1,sizeof(par));
		queue<int> q;
		q.push(0);
		while(!q.empty() && par[25] == -1){
			int now = q.front();q.pop();
			for(int next:edg[now]){
				if(c[now][next] > f[now][next] && par[next] == -1){
					par[next] = now;
					q.push(next);
				}
			}
		}
		if(par[25] == -1) break;
		int flow = 2e9;
		for(int v = 25;v!=0;v=par[v]) flow = min(flow,c[par[v]][v] - f[par[v]][v]);
		res += flow;
		for(int v = 25;v!=0;v=par[v]) f[par[v]][v] += flow, f[v][par[v]] -= flow;
	}
	cout << res;
}