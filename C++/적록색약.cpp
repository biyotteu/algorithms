#include <bits/stdc++.h>

using namespace std;

int n,visit[105][105],res1,res2,X[4]={1,0,-1,0},Y[4]={0,1,0,-1};
char rgb[105][105];
void f(int x,int y,char flag){
	if(visit[x][y] || x<1 || y<1 || x>n || y>n || flag != rgb[x][y]) return;
	visit[x][y] = 1;
	for(int i=0;i<4;i++) f(x+X[i],y+Y[i],flag);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++) scanf(" %c",&rgb[i][j]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			if(!visit[i][j]){
				f(i,j,rgb[i][j]);
				res1++;
			}
		}
	memset(visit,0,sizeof(visit));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++) if(rgb[i][j] == 'G') rgb[i][j] = 'R';
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			if(!visit[i][j]){
				f(i,j,rgb[i][j]);
				res2++;
			}
		}
	printf("%d %d",res1,res2);	
}