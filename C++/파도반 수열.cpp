#include <bits/stdc++.h>

using namespace std;

long long int dp[105];
int main() {
	dp[1] = dp[2] = dp[3] = 1, dp[4] = dp[5] = 2;
	for (int i = 6; i <= 100; i++) dp[i] = dp[i - 1] + dp[i - 5];
	int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d", &n);
		printf("%lld\n", dp[n]);
	}
}