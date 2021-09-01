#include <bits/stdc++.h>

using namespace std;

int n,m,road[505][505],dp[505][505];
int X[4] = {1,0,-1,0}, Y[4] = {0,1,0,-1};
int f(int x,int y){
	if(x == n && y == m) return 1;
	if(dp[x][y] != -1) return dp[x][y];
	dp[x][y] = 0;
	for(int i=0;i<4;i++){
		int nx = x + X[i];
		int ny = y + Y[i];
		if(road[x][y] > road[nx][ny] && x>0 && y>0 && x<=n && y<=m) dp[x][y] += f(nx,ny);
	}
	return dp[x][y];
}
int main(){ 	
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			dp[i][j] = -1;
			scanf("%d",&road[i][j]);
		} 
	printf("%d",f(1,1));
}