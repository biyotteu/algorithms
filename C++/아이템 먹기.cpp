#include <bits/stdc++.h>

using namespace std;

int n,m,A,B,wall[105][105],dp[105][105];
vector<pair<int,int>> item;
int main(){
	scanf("%d %d %d %d",&n,&m,&A,&B);
	while(A--){
		int x,y;
		scanf("%d %d",&x,&y);
		item.push_back({x,y});
	}
	sort(item.begin(),item.end());
	item.push_back({n,m});
	while(B--){
		int x,y;
		scanf("%d %d",&x,&y);
		wall[x][y] = 1;
	}
	pair<int,int> start = {1,1};
	long long res = 1;
	for(auto i:item){
		dp[start.first][start.second] = 1;
		for(int j=start.first;j<=i.first;j++){
			for(int k=start.second;k<=i.second;k++){
				if(wall[j][k]) continue;
				if(!wall[j-1][k] && j!=start.first) dp[j][k] += dp[j-1][k];
				if(!wall[j][k-1] && k!=start.second) dp[j][k] += dp[j][k-1];
			}
		}
		res *= dp[i.first][i.second];
		start = i;
	}
	printf("%lld",res);
}