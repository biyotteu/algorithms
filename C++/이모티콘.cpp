#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pp;
int dp[2005][2005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;
	cin >> n;
	queue<pp> q;
	q.push({1,0});
	int cnt = 1;
	while(!q.empty()){
		int size = q.size();
		while(size--){
			pp cur = q.front();q.pop();
			if(cur.first == n){
				cout << cnt-1;
				return 0;
			}
			if(dp[cur.first][cur.second]) continue;
			dp[cur.first][cur.second] = cnt;
			if(!dp[cur.first][cur.first]) q.push({cur.first,cur.first});
			if(cur.first+cur.second < 2005 && !dp[cur.first+cur.second][cur.second]) q.push({cur.first+cur.second,cur.second});
			if(cur.first > 1 && !dp[cur.first-1][cur.second]) q.push({cur.first - 1,cur.second});
		}
		cnt++;
	}

}