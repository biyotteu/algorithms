#include <bits/stdc++.h>

using namespace std;

int wt[2005][2005],n,m,cnt,pp;
int parent[100005],X[4]={1,0,-1,0},Y[4]={0,1,0,-1};
queue<pair<pair<int,int>,int>> Q;
int _find(int v){
	if(v == parent[v]) return v;
	return parent[v] = _find(parent[v]);
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++) parent[i] = i;
	pp = m;
	for(int i=1;i<=pp;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		wt[x][y] = i;
		Q.push({{x,y},i});
		for(int k=0;k<4;k++){
				int nx = x + X[k], ny = y + Y[k];
				if(nx < 1 || nx > n || ny < 1 || ny > n || wt[nx][ny]==0) continue;
				int a = _find(wt[nx][ny]);
				int b = _find(wt[x][y]);
				if(a == b) continue;
				parent[a] = b;
				m--;
		}
	}
	while(1){
		if(m <= 1) break;
		cnt++;
		int size = Q.size();
		for(int i=0;i<size;i++){
			pair<pair<int,int>,int> cur = Q.front();
			Q.pop();
			for(int k=0;k<4;k++){
				int nx = cur.first.first + X[k], ny = cur.first.second + Y[k];
				if(nx < 1 || nx > n || ny < 1 || ny > n) continue;
				if(wt[nx][ny] == 0){
					wt[nx][ny] = cur.second;
					Q.push({{nx,ny},cur.second});
					for(int q = 0;q<4;q++){
						int nnx = nx + X[q], nny = ny + Y[q];
						if(nnx < 1 || nnx > n || nny < 1 || nny > n || wt[nnx][nny] == 0) continue;
						int a = _find(wt[nnx][nny]);
						int b = _find(wt[nx][ny]);
						if(a == b) continue;
						parent[a] = b;
						m--;
					}
				}
			}
		}
	}
	printf("%d",cnt);
}