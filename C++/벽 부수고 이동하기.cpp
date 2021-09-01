#include <bits/stdc++.h>

using namespace std;

long long n,m,mi[1005][1005],dist[1005][1005][2],X[4] = {1,0,-1,0},Y[4] = {0,1,0,-1};
struct XYZ{
	int x,y,z;
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin >> mi[i][j];
			dist[i][j][0] = dist[i][j][1] = INT_MAX;
		} 
	}
	queue<XYZ> q;
	q.push({1,1,0});
	dist[1][1][0] = 1;
	while(!q.empty()){
		int size = q.size();
		while(size--){
			XYZ cur = q.front();q.pop();
			for(int i=0;i<4;i++){
				int nx = cur.x + X[i], ny = cur.y + Y[i];
				if(nx < 1 || ny < 1  || nx > n || ny > m) continue;
				if(cur.z && !mi[nx][ny] && dist[nx][ny][1] > dist[cur.x][cur.y][1] + 1){
					dist[nx][ny][1] = dist[cur.x][cur.y][1] + 1;
					q.push({nx,ny,1});
				}
				if(!cur.z){
					if(mi[nx][ny]){
						if(dist[nx][ny][1] > dist[cur.x][cur.y][0] + 1){
							dist[nx][ny][1] = dist[cur.x][cur.y][0] + 1;
							q.push({nx,ny,1});	
						}
					}else{
						if(dist[nx][ny][1] > dist[cur.x][cur.y][1] + 1){
							dist[nx][ny][1] = dist[cur.x][cur.y][1] + 1;
							q.push({nx,ny,1});	
						}
						if(dist[nx][ny][0] > dist[cur.x][cur.y][0] + 1){
							dist[nx][ny][0] = dist[cur.x][cur.y][0] + 1;
							q.push({nx,ny,0});	
						}
					}
				}
				
			}
		}
	}
	if(dist[n][m][0] == dist[n][m][1] == INT_MAX) cout << -1;
	else cout << dist[n][m][0] << ' '<< dist[n][m][1];
}	