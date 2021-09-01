#include <bits/stdc++.h>

using namespace std;

int n,s;
long long dp[300005];
vector<pair<int,int>> pic;
bool cmp(const pair<int,int> &A, const pair<int,int> &B){
	return A.first < B.first;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> s;
	pic.push_back({0,0});
	for(int i=0;i<n;i++){
		int x,y;
		cin >> x >> y;
		pic.push_back({x,y});
	}
	sort(pic.begin(),pic.end());
	for(int i=1;i<=n;i++){
		if(pic[i].first < s) continue;
		int k = upper_bound(pic.begin(),pic.end(),make_pair((pic[i].first - s),0),cmp) - pic.begin() - 1;
		dp[i] = max(dp[i-1],dp[k] + pic[i].second);
	}
	cout << dp[n];
}