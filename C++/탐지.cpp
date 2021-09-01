#include <bits/stdc++.h>

using namespace std;

int dp[50][50],n,m;
int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<=n;i++) for(int j=0;j<=n;j++) dp[i][j] = 1e9;
	dp[0][0] = 0;
	for(int i=1;i<=n;i++){
		dp[i][i-1] = dp[i][i] = 0;
		dp[i-1][i] = 1;
	}
	for(int i=0;i<m;i++){
		int x,y,z;
		scanf("%d %d %d",&x,&y,&z);
		if(dp[x-1][y] > z) dp[x-1][y] = z;
		dp[y][x-1] = -z;
	}
	for(int k=0;k<=n;k++)
		for(int i=0;i<=n;i++)
			for(int j=0;j<=n;j++)
				if(dp[i][k] + dp[k][j] < dp[i][j])
					dp[i][j] = dp[i][k] + dp[k][j];
	for(int i=0;i<=n;i++) 
		if(dp[i][i] < 0){
		puts("NONE");
		return 0;
		}
	for(int i=0;i<n;i++) printf("%c",(dp[0][i+1] - dp[0][i]) ? '#' : '-');
}