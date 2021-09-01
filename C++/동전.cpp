#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m;
		vector<int> num,dp;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			int x;
			scanf("%d",&x);
			num.push_back(x);
		}
		scanf("%d",&m);
		dp.resize(m+1,0);
		dp[0] = 1;
		for(int i=0;i<n;i++){
			for(int j=1;j<=m;j++)
				if(j>=num[i])	dp[j] += dp[j-num[i]];
		}
		printf("%d\n",dp[m]);
	}
}