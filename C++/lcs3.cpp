#include <bits/stdc++.h>

using namespace std;

int dp[105][105][105],res;
int main(){
	ios::sync_with_stdio(false);
	string a,b,c;
	cin >> a >> b >> c;
	for(int i=1;i<=a.size();i++)
		for(int j=1;j<=b.size();j++)
			for(int k=1;k<=c.size();k++){
				if(a[i-1] == b[j-1] && b[j-1] == c[k-1]){
					dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
					res = max(res,dp[i][j][k]);
				}else dp[i][j][k] = max(dp[i-1][j][k],max(dp[i][j-1][k],dp[i][j][k-1]));
			}
	cout << res;
}