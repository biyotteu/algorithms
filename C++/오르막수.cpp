#include <bits/stdc++.h>
#define mod 10009

using namespace std;

int n;
long long int dp[1005][10];
int main(){
	scanf("%d",&n);
	for(int i=0;i<=9;i++) dp[1][i] = 1;
	for(int i=2;i<=n;i++){
		for(int j=0;j<=9;j++)
			for(int k=0;k<=j;k++){
			 	dp[i][j] += dp[i-1][k];
			 	dp[i][j] %= mod;
			}
	}
	long long int res = 0;
	for(int i=0;i<=9;i++){
		res += dp[n][i];
		res %= mod;
	}
	printf("%d",res);
}