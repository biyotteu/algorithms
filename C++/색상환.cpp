#include <bits/stdc++.h>
#define MOD 1000000003
using namespace std;

int n,k;
long long dp[1005][1005],res;
long long f(int v,int cnt){
	if(cnt == 1) return v;
	if(v/2 < cnt || cnt <=0) return 0;
	long long &ret = dp[v][cnt];
	if(ret) return ret;
	ret += f(v-1,cnt);
	ret += f(v-2,cnt-1);
	ret %= MOD;
	return ret;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	cout << f(n,k);
}