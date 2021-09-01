//백준 2306
//DP문제
//dp[j][j+i] j~j+i까지의 koi유전자의 최대 길이
#include <bits/stdc++.h>

using namespace std;

string str;
int dp[505][505];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> str;
	for(int i=1;i<str.size();i++){
		for(int j=0;j+i<str.size();j++){
			int &ret = dp[j][j+i];
			for(int k=j;k<=i+j-1;k++) ret = max(dp[j][k] + dp[k+1][j+i],ret);
			if((str[j] == 'a' && str[i+j] == 't') || (str[j] == 'g' && str[i+j] == 'c')) ret = max(ret,dp[j+1][i+j-1] + 2);
		}
	}
	cout << dp[0][str.size()-1];
}