#include <bits/stdc++.h>

using namespace std;

int n,m,k;
string res;
long long dp[205][205];
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m >> k;
	for(int i=0;i<=200;i++){
		dp[i][0] = 1;
		for(int j=1;j<=i;j++){
			dp[i][j] = min(1000000001LL,dp[i-1][j-1] + dp[i-1][j]);
		}
	}
	if (k > dp[n+m][n]) puts("-1");
    else {
    	int p = n+m;
        for (int i = 1; i <= p; i++) {
        	if (k > dp[n + m - 1][m]) {
                cout << "z";
                k -= dp[n + m - 1][m];
                m--;
            }
            else {
                cout << "a";
                n--;
            }
        }
    }
}