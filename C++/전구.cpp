#include <bits/stdc++.h>

using namespace std;

int n,k,dp[205][205];
int co[205];
int main(){
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&co[i]);
		for(int j=i-1;j>0;j--){
			dp[j][i] = 987654321;
			for(int k=j;k<i;k++)
				dp[j][i] = min(dp[j][i],dp[j][k] + dp[k+1][i] + (co[j] != co[k+1]));
		}
	}
	printf("%d",dp[1][n]);
}