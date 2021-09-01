#include <bits/stdc++.h>
#define MOD 1000000

using namespace std;


vector<int> code;
int n;
long long dp[5005];
int main(){
	string str;
	cin >> str;
	code.push_back(0);
	for(auto i:str) code.push_back(i-48);
	n = code.size();
	dp[0] = 1;
	for(int i=1;i<n;i++){
		int b = code[i-1]*10 + code[i];
		int a = code[i];
		if(a) dp[i] += dp[i-1];
		if(b >= 10 && b <= 26) dp[i] += dp[i-2];
		dp[i] %= MOD; 
	}
	printf("%d",dp[n-1]);
}