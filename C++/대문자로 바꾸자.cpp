#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

string str;
long long dp[1005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> str;
	dp[str.size()] = 1;
	for(int i=str.size()-1;i>=0;i--){
		vector<int> alph;
		alph.resize(26);
		dp[i] = 1;
		for(int j=i;j<str.size();j++){
			int cur = str[j]-97;
			alph[cur]++;
			if(alph[cur] == 3)
				dp[i] += dp[j+1];
		}
		dp[i] %= mod;
	}
	cout << (dp[0]+mod-1)%mod;
}