#include <bits/stdc++.h>

using namespace std;

struct info{
	int x,y;
};
int n,m,inQ[805][805],dist[805][805],X[4]={1,0,-1,0},Y[4]={0,1,0,-1};
int inQ1[805][805],dist1[805][805],res = -987654321;
char gr[805][805];
queue<info> Q,Q1;
void f(pair<int,int> v,int s){
	if(v.first < 1 || v.first > n || v.second < 1 || v.second > n || inQ[v.first][v.second] || gr[v.first][v.second] == 'T') return;
	if(gr[v.first][v.second] == 'D'){
		res = max(res,s);
		return;
	} 
	inQ[v.first][v.second] = 1;
	for(int i=0;i<4;i++){
		int nx = v.first + X[i], ny = v.second + Y[i];
		f(make_pair(nx,ny),min(s,dist[nx][ny]));
	}
	inQ[v.first][v.second] = 0;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(dist,-1,sizeof(dist));
	memset(dist1,-1,sizeof(dist1));
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			cin >> gr[i][j];
			if(gr[i][j] == 'H'){
				Q.push({i,j});
				dist[i][j] = 0;
				inQ[i][j] = 1;
			}
			if(gr[i][j] == 'M'){
				Q1.push({i,j});
				dist1[i][j] = 0;
				inQ1[i][j] = 1;
			}
		}
	while(!Q.empty()){
		info cur = Q.front();
		Q.pop();	
		inQ[cur.x][cur.y] = 0;
		for(int i=0;i<4;i++){
			int nx = cur.x + X[i], ny = cur.y + Y[i];
			if(nx < 1 || nx > n || ny < 1 || ny > n || gr[nx][ny] == 'T' || gr[nx][ny] == 'D') continue;
			if(dist[nx][ny] == -1 || dist[nx][ny] > dist[cur.x][cur.y] + 1){
				dist[nx][ny] = dist[cur.x][cur.y] + 1;
				if(!inQ[nx][ny]){
					inQ[nx][ny] = 1;
					Q.push({nx,ny});
				}
			}
		}
	}

	while(!Q1.empty()){
		info cur = Q1.front();
		Q1.pop();	
		inQ1[cur.x][cur.y] = 0;
		for(int i=0;i<4;i++){
			int nx = cur.x + X[i], ny = cur.y + Y[i];
			if(nx < 1 || nx > n || ny < 1 || ny > n || gr[nx][ny] == 'T' || gr[nx][ny] == 'D') continue;
			if(dist1[nx][ny] == -1 || dist1[nx][ny] > dist1[cur.x][cur.y] + 1){
				dist1[nx][ny] = dist1[cur.x][cur.y] + 1;
				if(!inQ1[nx][ny]){
					inQ1[nx][ny] = 1;
					Q1.push({nx,ny});
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout << dist[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout << dist1[i][j] << ' ';
		}
		cout << endl;
	}
}