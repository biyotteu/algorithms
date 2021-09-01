#include <bits/stdc++.h>

using namespace std;

int n, ret, idx[2005][2005], parent[4000005], _map[2005][2005],visit[2005][2005];
int X[4] = {1, 0, -1, 0}, Y[4] = {0, 1, 0, -1},_count;
int _find(int v) {
	if (parent[v] == v) return v;
	return parent[v] = _find(parent[v]);
}
void _union(int a, int b) {
	int x = _find(a), y = _find(b);
	if (x == y) return;
	_count--;
	parent[x] = y;
}

void print(){
	for(int i = 1; i <= n*n; i++){
		printf("%d ", _find(i));
		if(i % n == 0) puts("");
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			printf("%d ", visit[i][j]);
		}
		puts("");
	}
}
queue<pair<int,int>> Q;
int main()
{
	scanf("%d %d", &n, &ret);
	int cnt = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			idx[i][j] = cnt++;
		}
	for (int i = 1; i <= n * n; i++) parent[i] = i;
	for (int i = 0; i < ret; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		Q.push({a,b});
	}
	for (int res = 0; ; res++) {
		int limit = Q.size();
		for(int i=0;i<limit;i++){
			pair<int,int> cur = Q.front();
			Q.pop();
			if(visit[cur.first][cur.second]) continue; 	
			visit[cur.first][cur.second] = 1;
			_count++;
			for(int j=0;j<4;j++){
				int x = cur.first + X[j], y = cur.second + Y[j];
				if(x > n || y > n || x < 1 || y < 1) continue;
				if(visit[x][y]) _union(idx[x][y],idx[cur.first][cur.second]);
				else Q.push({x,y});
			}
		}
		if(_count == 1){
			printf("%d",res);
			return 0;
		}
	}
}
