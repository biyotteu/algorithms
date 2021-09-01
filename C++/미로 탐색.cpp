#include <bits/stdc++.h>
#define INF (1<<29)

using namespace std;

int n,m,miro[105][105],X[4]={1,0,-1,0},Y[4]={0,1,0,-1};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int dp[105][105];
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			dp[i][j] = INF;
			char c;
			cin >> c;
			miro[i][j] = c-'0';
		}
	}
	queue<pair<int,int>> q;
	q.push({1,1});
	dp[1][1] = 1;
	while(!q.empty()){
		int size = q.size();
		while(size--){
			int x = q.front().first, y = q.front().second;
			q.pop();
			for(int k=0;k<4;k++){
				int nx = x + X[k], ny  = y + Y[k];
				if(nx <= 0 || ny <= 0 || nx > n || ny > m || miro[nx][ny] == 0) continue;
				if(dp[nx][ny] > dp[x][y] + 1){
					q.push({nx,ny});
					dp[nx][ny] = dp[x][y] + 1;
				}
			}
		}

	}
	cout << dp[n][m];
}