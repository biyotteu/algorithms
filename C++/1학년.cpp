#include <bits/stdc++.h>

using namespace std;

int n, res;
long long int dp[105][25];
vector<int> num;
int main()
{
	scanf("%d", &n);
	num.push_back(0);
	for (int i = 0; i < n - 1; i++) {
		int x;
		scanf("%d", &x);
		num.push_back(x);
	}
	scanf("%d", &res);
	dp[1][num[1]]=1;
	for (int i = 2; i <= n - 1; i++)
		for (int j = 0; j <= 20; j++) {
			if (j + num[i] <= 20) dp[i][j] += dp[i-1][j + num[i]];
			if (j - num[i] >= 0) dp[i][j] += dp[i-1][j - num[i]];
		}
	printf("%lld", dp[n - 1][res]);
}