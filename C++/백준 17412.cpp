#include <bits/stdc++.h>

using namespace std;

int n,p,src=1,snk=2;
int c[405][405],f[405][405];
vector<int> edg[405];
int mcmf(){
	queue<int> q;
	vector<int> par(n+1,-1);
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
	if(par[snk] == -1) return false;
	for(int v = snk; v != src; v = par[v]){
		f[par[v]][v]++;
		f[v][par[v]]--;
	}
	return true; 
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> p;
	for(int i=0;i<p;i++){
		int x,y;
		cin >> x >> y;
		c[x][y] = 1;
		edg[x].push_back(y);
		edg[y].push_back(x);
	}
	int cnt = 0;
	while(mcmf()) cnt++;
	cout << cnt;
}