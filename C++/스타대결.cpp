#include <bits/stdc++.h>

using namespace std;

int n, m,src = 0, snk = 101;
int f[105][105],c[105][105];
vector<int> edg[105];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	int sum1 = 0, sum2 = 0;
	src = 0, snk = n+m+1;
	for(int i=1;i<=n;i++){
		edg[src].push_back(i);
		edg[i].push_back(src);
		cin >> c[src][i];
		sum1 += c[src][i];
	}
	for(int i=n+1;i<=n+m;i++){
		edg[i].push_back(snk);
		edg[snk].push_back(i);
		cin >> c[i][snk];
		sum2 += c[i][snk];
	}
	for(int i=1;i<=n;i++){
		for (int j=n+1;j<=n+m;j++){
			edg[i].push_back(j);
			edg[j].push_back(i);
			c[i][j] = 1;
		}
	}
	if(sum1 != sum2){
		cout << -1;
		return 0;
	}
	while(sum1--){
		vector<int> par(n+m+2, -1);
		queue<int> Q;
		Q.push(src);
		while(!Q.empty()){
			int cur = Q.front();
			Q.pop();
			for(int next : edg[cur]){
				if(c[cur][next] > f[cur][next] && par[next] == -1){
					Q.push(next);
					par[next] = cur;
					if(next == snk) break;
				}
			}
		}
		if(par[snk] == -1){
			cout << -1;
			return 0;
		}
		for(int i=snk;i!=src;i=par[i]){
			f[par[i]][i]++;
			f[i][par[i]]--;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=n+1; j<=n+m;j++){
			if (f[i][j] == 1){
				f[src][i]--;
				f[i][src]++;
				f[i][j]--;
				f[j][i]++;
				f[j][snk]--;
				f[snk][j]++; // 일단 잠시 경로를 없애놓음
				queue<int> Q;
				Q.push(i);
				vector<int> par(n+m+2, -1);
				par[i] = src;
				while(!Q.empty()){
					int cur = Q.front();
					Q.pop();
					for(int next : edg[cur]){
						if(cur == i && next <= j) continue;
						if(next <= i) continue;
						if(c[cur][next] > f[cur][next] && par[next] == -1){
							Q.push(next);
							par[next] = cur;
							if (next == snk)
								break;
						}
					}
				}
				if(par[snk] == -1){
					f[src][i]++;
					f[i][src]--;
					f[i][j]++;
					f[j][i]--;
					f[j][snk]++;
					f[snk][j]--;
				}
				else{
					for(int v=snk;v!=src;v=par[v]){
						f[par[v]][v]++;
						f[v][par[v]]--;
					}
				}
				
			}
			cout << f[i][j];
		}
		cout << "\n";
	}
}