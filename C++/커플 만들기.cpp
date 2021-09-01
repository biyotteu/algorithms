#include <bits/stdc++.h>
#define MX 1005

using namespace std;

int n,m;
long long dp[MX][MX];
vector<long long> A,B;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	A.resize(n);
	B.resize(m);
	for(int i=0;i<n;i++) cin >> A[i];
	for(int i=0;i<m;i++) cin >> B[i];
	sort(A.begin(),A.end());
	sort(B.begin(),B.end());
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			if(i == j) dp[i][j] = dp[i-1][j-1] + abs(A[i-1] - B[j-1]);
			else if(i > j) dp[i][j] = min(dp[i-1][j-1] + abs(A[i-1]-B[j-1]),dp[i-1][j]);
			else dp[i][j] = min(dp[i-1][j-1] + abs(A[i-1]-B[j-1]),dp[i][j-1]);
		}
	cout << dp[n][m];
}