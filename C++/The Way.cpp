#include <bits/stdc++.h>
#define MOD 1000000009

using namespace std;

int n,dp[1005][3][4]; //0 아래, 1 오른쪽 2 왼쪽 3 위
int X[4] = {1,0,0,-1}, Y[4] = {0,1,-1,0};
int p[4] = {3,2,1,0};
int f(int x,int y,int z){
	if(x < 0 || y < 0 || x > n-1 || y > 2) return 0;
	cout << x << y << z << "\n";
	int &ret = dp[x][y][z];
	if(ret) return ret;
	for(int i=0;i<4;i++){
		if(i == z) continue;
		ret += f(x-X[z],y-Y[z],p[i]);
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	dp[0][0][0] = dp[0][0][1] = dp[0][0][2] = dp[0][0][3] = 1;
	int res = (f(n-1,2,0) + f(n-1,2,1))%MOD; 
	cout << res;
}