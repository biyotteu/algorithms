#include <bits/stdc++.h>

using namespace std;

struct info{
	int x,y,z;
};
int n,m,X[4] = {1,0,-1,0},Y[4] = {0,1,0,-1};
int tmt[1005][1005],res;
queue<info> Q;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> m >> n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int x;
			cin >> x;
			if(x == 1){

			 Q.push({i,j,0});
			 continue;
			}
			tmt[i][j] = x;
		}
	}
	while(!Q.empty()){
		info cur = Q.front();
		Q.pop();
 		if(tmt[cur.x][cur.y] || cur.x < 1 || cur.y < 1 || cur.x > n || cur.y > m) continue;
		tmt[cur.x][cur.y] = 1;
		res = max(res,cur.z);
		for(int i=0;i<4;i++){
			int nx = cur.x + X[i];
			int ny = cur.y + Y[i];
			if(tmt[nx][ny] == -1) continue;
			Q.push({nx,ny,cur.z+1});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(!tmt[i][j]){
				cout << -1;
				return 0;
			}
		}
	}
	cout << res;
}