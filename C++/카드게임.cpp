#include <bits/stdc++.h>

using namespace std;

int n,a[2005],b[2005],dp[2005][2005];
int f(int x,int y){	
	if(x == 0 || y == 0) return 0;
	int &ret = dp[x][y];
	if(ret != -1) return ret;
	ret = 0;
	if(a[x] > b[y]) ret = f(x,y-1)+b[y];
	ret = max(ret,max(f(x-1,y-1),f(x-1,y)));
	return ret;
}
int main(){
	ios::sync_with_stdio(false);
	memset(dp,-1,sizeof(dp));
	cin >> n;
	for(int i=0;i<n;i++) cin >> a[n-i];
	for(int i=0;i<n;i++) cin >> b[n-i];
	cout << f(n,n);
}