#include <bits/stdc++.h>

using namespace std;

int pal[2005],dp[2005][2005],n,m;
int f(int x,int y){
	if(dp[x][y]) return dp[x][y];
	if(x >= y) return 1;
	if(pal[x] == pal[y]) return dp[x][y] = f(x+1,y-1);
	return -1;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&pal[i]);
	scanf("%d",&m);
	while(m--){
		int x,y;
		scanf("%d %d",&x,&y);
		if(f(x,y) == 1) printf("1\n");
		else printf("0\n");
	}
}