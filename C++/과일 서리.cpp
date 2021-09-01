#include <bits/stdc++.h>

using namespace std;

int dp[50][50];
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	//m-1 c m-n
	dp[0][0] = 1;
	for(int i=1;i<=m-1;i++){
		dp[i][0] = 1;
		for(int j=1;j<=i;j++) dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
	}
	printf("%d",dp[m-1][m-n]);
}