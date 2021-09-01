#include <bits/stdc++.h>

using namespace std;

int n,dp[105],res;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		dp[i] = dp[i-1] + x;
	}
	for(int i=0;i<n;i++)
		for(int j=i+1;j<=n;j++){
			res = max(res,dp[j] - dp[i]);
		}
	printf("%d",res);
}