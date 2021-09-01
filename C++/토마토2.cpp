#include <bits/stdc++.h>

using namespace std;

struct info{
	int x,y,z;
};
int tmm[105][105][105];
int cnt,X[6]={1,0,0,-1,0,0},Y[6]={0,1,0,0,-1,0},Z[6]={0,0,1,0,0,-1};
int n,m,h,ret,res;
queue<info> Q;
int main(){
	scanf("%d %d %d",&m,&n,&h);
	for(int k=1;k<=h;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				int x;
				scanf("%d",&tmm[i][j][k]);
				if(tmm[i][j][k] == 1){
					Q.push({i,j,k});
					cnt++;
				}
				if(tmm[i][j][k] != -1) ret++;
			}
		}
	}
	if(ret == cnt){ 
		printf("0");
		return 0;
	}
	while(Q.size()){
		int size = Q.size();
		for(int p=0;p<size;p++){
			info cur = Q.front();
			Q.pop();
			for(int i=0;i<6;i++){
				int nx = cur.x + X[i],ny = cur.y + Y[i],nz = cur.z + Z[i];
				if(nx < 1 || ny < 1 || nz < 1 || nx > n || ny > m || nz > h || tmm[nx][ny][nz] != 0) continue;
				cnt++;
				tmm[nx][ny][nz] = 1;
				Q.push({nx,ny,nz});
			}
		}
		res++;
	}
	if(ret == cnt) printf("%d",res-1);
	else printf("-1");
}