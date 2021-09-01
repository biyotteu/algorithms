#include <bits/stdc++.h>

using namespace std;

int dp[35];
int main() {
	int n;
	scanf("%d", &n);
	dp[0] = 1;
	dp[2] = 3;
	for (int i = 4; i <= n; i++) {
		dp[i] = 3 * dp[i - 2];
		for (int j = 4; j <= i; j = j + 2) dp[i] += 2 * dp[i - j];
	}
	printf("%d", dp[n]);
}