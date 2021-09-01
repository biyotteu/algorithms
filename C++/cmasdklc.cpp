#include <bits/stdc++.h>
#define INF 1234567890

using namespace std;

int dp[100005][5][5],n,score[5][5];
vector<int> dnn(1,0);
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(int i=1;i<5;i++) score[0][i] = 2,score[i][i] = 1;
	for(int i=1;i<=2;i++) score[i][i+2] = score[i+2][i] = 4;
	score[1][4] = score[1][2] = score[4][1] = score[2][1] = 3;
	score[3][4] = score[3][2] = score[2][3] = score[4][3] = 3;
	while(1){
		int x;
		cin >> x;
		if(!x) break;
		dnn.push_back(x);
	}
	n = dnn.size()-1;
	for(int i=0;i<=n;i++)
		for(int j=0;j<5;j++) 
			for(int k=0;k<5;k++) dp[i][j][k] = INF;
	dp[0][0][0] = 0;
	for(int i=1;i<=n;i++){
		int v = dnn[i];
		for(int j=0;j<5;j++){
			for(int k=0;k<5;k++){
				if(dp[i-1][j][k] != INF){
					dp[i][v][k] = min(dp[i][v][k],dp[i-1][j][k] + score[j][v]);
					dp[i][j][v] = min(dp[i][j][v],dp[i-1][j][k] + score[k][v]);
				}
			}
		}
	}

	int res = INF;
	for(int i=0;i<5;i++)
		for(int j=0;j<5;j++) res = min(res,dp[n][i][j]);
	cout << res;
}