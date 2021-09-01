#include <bits/stdc++.h>

using namespace std;

int dp[105][1005];
int main()
{
	int n,s,m;
	vector<int> mus;
	scanf("%d %d %d",&n,&s,&m);
	mus.push_back(0);
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		mus.push_back(x);
	}
	dp[0][s] = 1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(!dp[i-1][j]) continue;
			if(j+mus[i] <= m) dp[i][j+mus[i]] = 1;
			if(j-mus[i] >= 0) dp[i][j-mus[i]] = 1;
		}
	}
	for(int i=m;i>=0;i--)
		if(dp[n][i]){
			printf("%d",i);
			return 0;
		}
	printf("-1");
}
