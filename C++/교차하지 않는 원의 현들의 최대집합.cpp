#include <bits/stdc++.h>

using namespace std;

int cc[101][101],dp[101][101];
int main(){
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		int x,y;
		cin >> x >> y;
		if(x>y) swap(x,y);
		cc[x][y] = 1;
	}
	for(int k=0;k<100;k++){
		for(int i=1;i+k<=100;i++){
			int r = i+k;
			for(int p=i;p<=r;p++){
				dp[i][r] = max(dp[i][r],dp[i][p-1] + dp[p+1][r-1] + cc[p][r]);
			}
		}
	}
	cout << dp[1][100];
}