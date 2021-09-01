#include <bits/stdc++.h>

using namespace std;

struct info{
	int x,y,cnt;
	info(){}
	info(int a,int b,int c){
		x = a, y = b, cnt =c;
	}
	bool operator <(info A)const { return cnt > A.cnt; }
};
int n,m,miro[105][105],visit[105][105],res = (1<<30),X[4]={1,0,-1,0},Y[4]={0,1,0,-1};
priority_queue<info> Q;
int main()
{
	scanf("%d %d",&m,&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			char c;
			scanf(" %c",&c);
			miro[i][j] = c-48;
		}
	Q.push(info(1,1,0));
	while(!Q.empty()){
		info cur = Q.top();
		Q.pop();
		if(visit[cur.x][cur.y] || cur.x > n || cur.x < 1 || cur.y > m || cur.y <1) continue;
		visit[cur.x][cur.y] = 1;
		if(cur.x == n && cur.y == m){
		 	res = min(res,cur.cnt);
		  	continue;
		}
		for(int i=0;i<4;i++){
			int nx = cur.x + X[i];
			int ny = cur.y + Y[i];
			if(miro[nx][ny]) Q.push(info(nx,ny,cur.cnt+1));
			else Q.push(info(nx,ny,cur.cnt));
		}
	}
	printf("%d",res);
}
