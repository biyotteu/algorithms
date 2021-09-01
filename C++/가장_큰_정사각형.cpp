#include <bits/stdc++.h>

using namespace std;

int dp[1005][1005];
int n,m,res=0;
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			int k;
			scanf("%1d",&k);
			if(k){ 
				dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
				res = max(dp[i][j],res);
			}
		}
	printf("%d",res*res);
}