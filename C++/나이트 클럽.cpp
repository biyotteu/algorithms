#include <bits/stdc++.h>
#define INF -9876543212L
using namespace std;

int n,t,s;
long long int dp[3005][3005];
vector<pair<int,int>> A;
long long int f(int v,int m){
	if(v<0 || m<0) return INF;
	if(v == 0) return 0;
	long long int &ret = dp[v][m];
	if(ret != -1) return ret;
	if(m-A[v].second < s && s < m) return ret = max(f(v-1,m),f(v-1,s-A[v].second) + A[v].first);
	return ret = max(f(v-1,m),f(v-1,m-A[v].second) + A[v].first);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> t >> s;
	A.push_back({0,0});
	for(int i=0;i<n;i++){
		int x,y;
		cin >> x >> y;
		A.push_back({x,y});
	}
	memset(dp,-1,sizeof(dp));
	cout << f(n,t);
}