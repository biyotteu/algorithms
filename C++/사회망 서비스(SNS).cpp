#include <bits/stdc++.h>

using namespace std;

int n,dp[1000005][2],in[1000005];
vector<int> gr[1000005],gh[1000005];
void dfs(int v){
	in[v] = 1;
	for(auto i:gr[v]){
		if(!in[i]){
			gh[v].push_back(i);
			dfs(i);
		}
	}
}
int f(int v,int ear){
	int &ret = dp[v][ear];
	if(ret != -1) return ret;
	if(ear){
		ret = 1;
		for(auto i:gh[v])
			ret += min(f(i,0),f(i,1));
	}else{
		ret = 0;
		for(auto i:gh[v])
			ret += f(i,1);
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(dp,-1,sizeof(dp));
	cin >> n;
	for(int i=0;i<n-1;i++){
		int x,y;
		cin >> x >> y;
		gr[x].push_back(y);
		gr[y].push_back(x);
	}
	dfs(1);
	cout << min(f(1,0),f(1,1));

}