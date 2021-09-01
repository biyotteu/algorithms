#include <bits/stdc++.h>
#define INF (1<<29)
#define ND (cur.z+1)%4
using namespace std;

struct info{
	int x,y,z;
	info(){}
	info(int a,int b,int c){
		x = a,y =b,z = c;
	}
};
int n,m,X,Y,visit[305][305][4];
int dx[4]={1,0,-1,0},dy[4]={0,-1,0,1};
queue<info> Q;
int main(){
	scanf("%d %d %d %d",&n,&m,&X,&Y);
	n++,m++,X++,Y++;
	Q.push(info(1,1,0));
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) for(int k=0;k<4;k++) visit[i][j][k] = INF;
	visit[1][1][0] = 0;
	while(!Q.empty()){
		info cur = Q.front();
		Q.pop();
		if(cur.x < 1 || cur.y < 1 || cur.x > n || cur.y > m){ 
			continue;
		}
		int k = visit[cur.x][cur.y][cur.z];

		if(k+1 < visit[cur.x+dx[cur.z]][cur.y+dy[cur.z]][ND]){
			Q.push(info(cur.x+dx[cur.z],cur.y+dy[cur.z],ND));
			visit[cur.x+dx[cur.z]][cur.y+dy[cur.z]][ND] = k+1;
		}
		if(k+1 < visit[cur.x+dx[ND]][cur.y+dy[ND]][ND]){
			Q.push(info(cur.x+dx[ND],cur.y+dy[ND],ND));
			visit[cur.x+dx[ND]][cur.y+dy[ND]][ND] = k+1;
		}
		if(k+1 < visit[cur.x][cur.y][ND]){
			Q.push(info(cur.x,cur.y,ND));
			visit[cur.x][cur.y][ND] = k+1;
		}
	}
	int res = INF;
	for(int i=0;i<4;i++) res = min(res,visit[X][Y][i]);
	if(res == INF) printf("-1");
	else printf("%d",res);
}