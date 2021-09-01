#include <bits/stdc++.h>

using namespace std;

vector<int> item[7];
int cost;
int dp[6000005][6];
long long int res;
int main()
{
	for(int i=1;i<7;i++)
	{
		int x;
		scanf("%d",&x);
		for(int j=0;j<x;j++)
		{
			int y;
			scanf("%d",&y);
			item[i].push_back(y);
		}
		sort(item[i].begin(),item[i].end());
	}
	scanf("%d",&cost);
	for(int j=1;j<=6;j++)
	for(int i=0;i<item[j].size();i++) dp[cost-item[j][i]][j]++;
	for(int j=1;j<=6;j++)
	for(int i=1;i<=cost;i++) dp[i][j] += dp[i-1][j];
	for(int i=1;i<=cost;i++)
		for(int j=1;j<=6;j++){
			dp[i][i] *= dp[j][i-1]; 
		}

	/*for(int i=2;i<=6;i++){
		for(int k=item[i][0];k<=cost;k++)
		for(int j=0;j<item[i].size();j++){
			if(k <= item[i][j]) break;
			dp[k][i] += dp[k-item[i][j]][i-1];	
		}
	}*/
	for(int i=1;i<=cost;i++) res += dp[i][6];
	printf("%d",res);
}