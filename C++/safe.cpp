#include <bits/stdc++.h>

using namespace std;

int n,area[105][105],start=1E9,limit,res=1,X[4]={1,0,-1,0},Y[4]={0,1,0,-1},visit[105][105];
void f(int x,int y){
	if(x<0 || y<0 || x>=n || y>=n||visit[x][y]) return;
	visit[x][y] = 1;
	for(int i=0;i<4;i++) f(x+X[i],y+Y[i]);
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) {
		scanf("%d",&area[i][j]);
		limit = max(area[i][j],limit);
		start = min(area[i][j],start);
	}
	for(int k=start;k<limit;k++){
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++){
				visit[i][j] = 0;
				if(area[i][j]<=k) visit[i][j] = 1;
			}
		int cnt = 0;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++){
				if(visit[i][j]) continue;
				f(i,j),cnt++;
			}
		res = max(res,cnt);
	}
	printf("%d",res);
}