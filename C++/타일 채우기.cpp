#include <bits/stdc++.h>

using namespace std;

int dp[505][20];
int f(int v,int tp){
	if(!v) return tp == 0;
	if(v < 0) return 0;
	int &ret = dp[v][tp];
	if(ret != -1) return ret;
	ret = 0;
	if(tp == 0){
		ret += f(v-1,0);
		ret += f(v-1,3);
		ret += f(v-1,9);
		ret += f(v-1,12);
		ret += f(v-2,0);
	}
	if(tp == 3){
		ret += f(v-1,0);
		ret += f(v-1,12);
	}
	if(tp == 6){
		ret += f(v-1,9);
	}
	if(tp == 9){
		ret += f(v-1,0);
		ret += f(v-1,6);
	}
	if(tp == 12){
		ret += f(v-1,0);
		ret += f(v-1,3);
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(dp,-1,sizeof(dp));
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		cout << f(n,0) << "\n";
	}
}