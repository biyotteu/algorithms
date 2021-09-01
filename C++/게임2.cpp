#include <bits/stdc++.h>

using namespace std;

int res,n,m,mp[55][55],visit[55][55],dp[55][55];
int X[4] = {1,0,-1,0} , Y[4] = {0,1,0,-1};

int f(int x,int y){
	if(x < 1 || y < 1 || x > n || y > m || mp[x][y] == 'H'-48) return 0;
	if(visit[x][y]){
		puts("-1");
		exit(0);
	}
	int &ret = dp[x][y];
	if(ret != -1) return ret;
	visit[x][y] = 1;
	int v = mp[x][y];
	for(int i=0;i<4;i++){
		int nx = x + X[i]*v , ny = y + Y[i]*v;
		ret = max(ret,f(nx,ny)+1);
	} 
	visit[x][y] = 0;
	return ret;
}
int main(){
	memset(dp,-1,sizeof(dp));
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			char x;
			scanf(" %c",&x);
			mp[i][j] = x - 48;
		}
	}
	printf("%d",f(1,1));
}