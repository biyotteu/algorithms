#include <bits/stdc++.h>

using namespace std;
using pp = pair<long long,long long>;

int n;
int dp[500005][2]; // 0 = left , 1 = right
int lef[500005],rig[500005];
priority_queue<pp> Q,Q1;
vector<pp> domi;
int fl(int v){

}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		long long x,y;
		scanf("%lld %lld",&x,&y);
		domi.push_back({x,y});
	}
	sort(domi.begin(),domi.end());
	int last = 0,last1=0;
	for(int i=1;i<n;i++){
		if(domi[i-1].first >= domi[i].first - domi[i].second) lef[i] = last;
		else{
			lef[i] = i;
			last = i;
		}
		if(domi[i-1].first+domi[i-1].second >= domi[i].first) rig[i] = last1;
		else{
			rig[i] = i;
			last1 = i;
		}
	}
	dp[0][0] = dp[0][1] = 1;
	Q.push({-1,0});
	Q1.push({-1,0});
	for(int i=1;i<n;i++){
		while(Q.size() && Q.top().second < lef[i]) Q.pop();
		while(Q1.size() && Q1.top().second < rig[i]) Q1.pop();
		if(domi[i-1].first + domi[i-1].second >= domi[i].first){
			dp[i][1] = -(int)Q1.top().first + 1;
			if(rig[i] == 0) dp[i][1] = 1;
			else dp[i][1] = min(dp[i][1],min(dp[rig[i]-1][0],dp[rig[i]-1][1]) + 1);
		}else dp[i][1] = min(dp[i-1][0] + 1, dp[i-1][1] + 1);
		if(domi[i-1].first >= domi[i].first - domi[i].second){
			dp[i][0] = -(int)Q.top().first + 1;
			if(lef[i] == 0) dp[i][0] = 1;
			else dp[i][0] = min(dp[i][0],min(dp[lef[i]-1][0],dp[lef[i]-1][1]) + 1);
		}else{
			dp[i][0] = min(dp[i-1][0] + 1, dp[i-1][1] + 1);
		}
		Q.push({-dp[i][1],i});
		Q1.push({-dp[i][0],i});
	}
	printf("%d",min(dp[n-1][0],dp[n-1][1]));
}