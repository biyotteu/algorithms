#include <bits/stdc++.h>

using namespace std;

int n,w;
int dp[105][10005];
vector<pair<int,int>> item;
int f(int v,int sum){
	if(v == n) return 0;
	int &ret = dp[v][sum];
	if(ret) return ret;
	if(sum+item[v].first<=w) ret = max(f(v+1,sum),f(v+1,sum+item[v].first)+item[v].second);
	else ret = f(v+1,sum);
	return ret;
}
int main(){
	scanf("%d %d",&n,&w);
	for(int i=0;i<n;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		item.push_back({x,y});
	}
	printf("%d",f(0,0));
}