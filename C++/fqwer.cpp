#include <bits/stdc++.h>

using namespace std;

struct info{
	int x,y,z;
};
int n,m,mp[10][10][4],res,x[4]={1,0,-1,0},y[4]={0,1,0,-1};
queue<info> q;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin >> mp[i][j][0];
			if(mp[i][j][0] == 2) q.push({i,j,0});
		} 
	}
	while(!q.empty()){
		info cur = q.front();q.pop();
		for(int i=0;i<4;i++){
			int nx = cur.first + x[i];
			int ny = cur.second + y[i];
			if(nx < 1 || ny < 1 || nx > n || ny > m || mp[nx][ny] != 0) continue;
			mp[nx][ny] = 2;
			q.push({nx,ny});
		}
	}	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) cout << mp[i][j] << ' ';//res += (mp[i][j] == 0);
		cout << "\n";
	}
	cout << res;
}