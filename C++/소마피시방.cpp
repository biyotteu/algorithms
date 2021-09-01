#include <bits/stdc++.h>

using namespace std;

int p,n,h,dp[1001][101][25],res[101];
vector<int> cu[101];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> p >> n >> h;
	for(int i=0;i<n;i++){
		int x,y;
		cin >> x >> y;
		cu[x].push_back(y);
	}
	for(int i=1;i<=p;i++){
		for(int j=0;j<cu[i].size();j++){
			if(cu[i][j] <= h) dp[i][j][cu[i][j]] = 1;
			if(!j) continue;
			for(int k=0;k<=h;k++){
				if(cu[i][j] <= k && dp[i][j][k-cu[i][j]] || dp[i][j-1][k]) dp[i][j][k] = 1;
			}
		}
	}
	for(int i=1;i<=p;i++){
		for(int j=0;j<=h;j++)
			if(dp[i][cu[i].size()-1][j]) res[i] = j;
	}
	for(int i=1;i<=p;i++) cout << i <<' ' << res[i]*1000 << "\n";
}