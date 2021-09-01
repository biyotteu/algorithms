#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pp;
int n,m,mp[10][10],res,x[4]={1,0,-1,0},y[4]={0,1,0,-1};
queue<pp> q;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin >> mp[i][j];
			if(mp[i][j] == 2) q.push({i,j});
		} 
	}
	while(!q.empty()){
		pp cur = q.front();q.pop();
		for(int i=0;i<4;i++){
			int nx = cur.first + x[i];
			int ny = cur.second + y[i];
			if(nx < 1 || ny < 1 || nx > n || ny > m || !mp[nx][ny]) continue;
			mp[nx][ny] = 2;
			q.push({nx,ny});
		}
	}	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) res += !mp[i][j];
	}
	cout << res;
}