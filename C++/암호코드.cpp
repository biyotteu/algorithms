#include <bits/stdc++.h>
#define mod 1000000

using namespace std;

string str;
long long int dp[5005];
long long int f(int idx)
{
	if(idx >= str.size()) return 1;
	if(dp[idx]) return dp[idx];
	if(str[idx]-48 <= 2 && str[idx+1]-48 <= 6){
		dp[idx] += f(idx+2);
		dp[idx] %= mod;
	}
	dp[idx] += f(idx+1);
	dp[idx] %= mod;
	return dp[idx];
}
int main()
{
	cin >> str;
	printf("%lld",f(0));
}