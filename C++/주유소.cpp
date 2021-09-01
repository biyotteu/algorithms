#include <bits/stdc++.h>

using namespace std;

struct info{
	long long int x,y,z;
	bool operator<(info A)const{
		return x > A.x;
	}
};
vector<info> graph[2505];
priority_queue<info> Q;
long long int n,m,cost[2505],dp[2505][2505];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		cin >> cost[i];
	for(int i=0;i<m;i++){
		int x,y,z;
		cin >> x >> y >> z;
		graph[x].push_back({y,z});
		graph[y].push_back({x,z});
	}
	memset(dp,-1,sizeof(dp));
	Q.push({0,1,cost[1]});
	while(!Q.empty()){
		info cur = Q.top();
		Q.pop();
		if(dp[cur.y][cur.z]!=-1) continue;
		dp[cur.y][cur.z] = cur.x;
		if(cur.y == n){
			cout << cur.x;
			return 0;
		}
		for(auto i:graph[cur.y]){
			if(dp[i.x][min(cur.z,cost[i.x])] != -1) continue;
			Q.push({cur.x+i.y*cur.z,i.x,min(cur.z,cost[i.x])});
		}
	}
}