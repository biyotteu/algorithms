#include <bits/stdc++.h>
#define INF (1<<29)

using namespace std;

struct info{
    int x,y,z;
    info(){}
    info(int a,int b,int c){
        x = a,y = b,z = c;
    }
};
int visit[305][305][4];
int n,m,Y,X;
int dx[4]={1,0,-1,0},dy[4]={0,-1,0,1};
queue<info> Q;
int main() {
    scanf("%d %d %d %d",&n,&m,&X,&Y);
    X += 1,Y += 1,m+=1,n+=1;
    Q.push(info(1,1,0));
    for(int i=0;i<305;i++)
    	for(int j=0;j<305;j++)
    	for(int k=0;k<4;k++) visit[i][j][k] = (1<<29);
    visit[1][1][0] = 0;
    while(!Q.empty()){
        info cur = Q.front();
        Q.pop();
        if(cur.x < 1 || cur.x > n || cur.y < 1 || cur.y > m) continue;
        int k = visit[cur.x][cur.y][cur.z];
        if(k+1 < visit[cur.x+dx[cur.z]][cur.y+dy[cur.z]][(cur.z+1)%4]){
            visit[cur.x+dx[cur.z]][cur.y+dy[cur.z]][(cur.z+1)%4] = k+1;
            Q.push(info(cur.x+dx[cur.z],cur.y+dy[cur.z],(cur.z+1)%4));
        }
        if(k+1 < visit[cur.x+dx[(cur.z+1)%4]][cur.y+dy[(cur.z+1)%4]][(cur.z+1)%4]){
            visit[cur.x+dx[(cur.z+1)%4]][cur.y+dy[(cur.z+1)%4]][(cur.z+1)%4] = k+1;
            Q.push(info(cur.x+dx[(cur.z+1)%4],cur.y+dy[(cur.z+1)%4],cur.z+1));
        }
        if(k+1 < visit[cur.x][cur.y][(cur.z+1)%4]){
        	visit[cur.x][cur.y][(cur.z+1)%4] = k+1;
        	Q.push(info(cur.x,cur.y,(cur.z+1)%4));
        }
    }
    int res = INF;
    for(int i=0;i<4;i++) res = min(res,visit[X][Y][i]);
    if(res == INF) printf("-1");
    else printf("%d",res);
}