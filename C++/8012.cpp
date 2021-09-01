#include <bits/stdc++.h>
#define max_n 30005

using namespace std;

int st[max_n][20],n,lvl[max_n],m,x,y,res,tmp;
vector<int> edg[max_n];
void dfs(int v,int par){
	for(int next:edg[v]){
		if(par == next) continue;
		lvl[next] = lvl[v] + 1;
		st[next][0] = v;
		dfs(next,v);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n;
	for(int i=1;i<n;i++){
		cin >> x >> y;
		edg[x].push_back(y);
		edg[y].push_back(x);
	}
	dfs(1,1);
	for(int j=1;j<20;j++){
		for(int i=1;i<=n;i++) st[i][j] = st[st[i][j-1]][j-1];
	}
	int last,cur;
	cin >> m >> last;
	m--;
	while(m--){
		tmp = 0;
		cin >> cur;
		x = cur;
		y = last;
		last = cur;
		if(lvl[y] < lvl[x]) swap(x,y);
		for(int j=19;j>=0;j--){
			if(lvl[y] - lvl[x] >= (1<<j)){
				y = st[y][j];
				tmp += (1<<j);
			}
		}
		if(x!=y){
			for(int j=19;j>=0;j--){
				if(st[x][j] != st[y][j]){
					tmp += 2*(1<<j);
					x = st[x][j];
					y = st[y][j];
				}
			}
			tmp += 2;
		}
		res += tmp;
	}
	cout << res;
}