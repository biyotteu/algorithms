#include <bits/stdc++.h>

using namespace std;

int res,dp[4005][4005];
int main(){
	string a,b;
	cin >> a >> b;
	for(int i=0;i<a.size();i++)
		for(int j=0;j<b.size();j++){
			if(a[i] == b[j]){
				if(i==0 || j==0) dp[i][j] = 1;
				else dp[i][j] = dp[i-1][j-1] + 1;
				res = max(res,dp[i][j]);
			}
		}
	cout << res;
}