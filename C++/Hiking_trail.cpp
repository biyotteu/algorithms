#include <bits/stdc++.h>

using namespace std;

int n,k,mt[10][10],MV,res,DP[10][10][2],X[4]={1,0,-1,0},Y[4]={0,1,0,-1};
int f(int x,int y,int ch,int cost){
	if(DP[x][y][ch]) return DP[x][y][ch];
	int ret = 0;
	for(int i=0;i<4;i++){
		int nx = x+X[i];
		int ny = y+Y[i];
		if(mt[nx][ny]>=cost && !ch){
			DP[x][y][1] = f(nx,ny,1,mt[nx][ny] - k) + 1;
		}
		else{
			if(mt[nx][ny]<cost)
				DP[x][y][ch] = f(nx,ny,ch,mt[nx][ny]) + 1;
		}
		ret = max(ret,max(DP[x][y][1],DP[x][y][0]));
	}
	return ret;
}
int main(){
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++){
		scanf("%d %d",&n,&k);
		MV = res = 0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++){
				scanf("%d",&mt[i][j]);
				MV = max(MV,mt[i][j]);
			}
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(MV == mt[i][j])
					res = max(res,f(i,j,0,MV));
	}
}