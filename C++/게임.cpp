#include <bits/stdc++.h>

using namespace std;

int n,m,start;
int game[55][55],dp[55][55];
int X[4] = {1,0,-1,0} , Y[4] = {0,1,0,-1};
int f(int a,int b){
	if(a < 1 || b < 1 || a > n || b > m || game[a][b] == -1) return 0;
	int &ret = dp[a][b];
	if(ret) return ret;
	for(int i=0;i<4;i++){
		int nx = a + game[a][b] * X[i];
		int ny = b + game[a][b] * Y[i];
		if(game[nx][ny] == game[a][b]){
			puts("-1");
			exit(0);
		}
		ret = max(ret,f(nx,ny)+1);
	}
	return ret;
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			char x;
			scanf(" %c",&x);
			if(x != 'H') game[i][j] = (x - 48);
			else game[i][j] = -1;
		}
	printf("%d",f(1,1));
}