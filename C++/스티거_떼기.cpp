#include <bits/stdc++.h>

using namespace std;

int n,dp[100005][2],A[100005],res=0;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&A[i]);
	dp[1][1] = A[1];
	dp[2][0] = A[2];
	for(int i=3;i<=n;i++){
		dp[i][0] = max(dp[i-2][0],dp[i-3][0]) + A[i];
		if(i!=n)dp[i][1] = max(dp[i-2][1],dp[i-3][1]) + A[i];
		res = max(res,max(dp[i][0],dp[i][1]));
	}
	printf("%d",res);
}