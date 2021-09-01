#include <bits/stdc++.h>
#define MOD 1000000000
using namespace std;

int n;
long long dp[1000005];
vector<int> num;
int main(){
	cin >> n;
	for(int k=1;k<=n;k*=2) num.push_back(k);
	dp[0] = 1;
	for(int j=0;j<num.size();j++){
		for(int i=num[j];i<=n;i++){
			dp[i] += dp[i-num[j]];
			dp[i] %= MOD;
		}
	}
	cout << dp[n];
}