#include <bits/stdc++.h>

using namespace std;

int dp[10005][1005],cow[10005],mc[10005],n,k;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for(int i=1;i<=n;i++) cin >> cow[i];
	for(int i=1;i<=n;i++){
		int ret = 0;
		for(int j=0;j<k;j++){
			if(i==j) break;
			ret = max(ret,cow[i-j]);
			mc[i] = max(mc[i-j-1]+ret*(j+1),mc[i]);
		}
	}
	cout << mc[n];
	return 0;
}