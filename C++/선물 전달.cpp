#include <bits/stdc++.h>
#define MOD 1000000000

using namespace std;

long long int dp[1000005];
int n;
int main(){
	dp[0] = 1;
	cin >> n;
	for(int i=2;i<=n;i++)
		dp[i] = (i-1)*(dp[i-1]+dp[i-2])%MOD;
	cout << dp[n];
}
