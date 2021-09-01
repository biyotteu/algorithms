//백준 2666번
//DP문제
//dp[a][b][c] a:문을 열어야하는 현재 차례, b,c: 이미 열려있는문
//b번 문을 닫고 현재 차례의 문을 열거나 
//c번 물을 닫고 현재 차례의 문을 열 때 중 최소값을 찾는다.

#include <bits/stdc++.h>

using namespace std;

int n,m,dp[25][25][25],turn[25];
int f(int a,int b,int c){
	if(a == m) return 0;
	int &ret = dp[a][b][c];
	if(ret != -1) return ret;
	return ret = min(f(a+1,turn[a+1],c) + abs(turn[a+1] - b),f(a+1,b,turn[a+1]) + abs(turn[a+1] - c));
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	memset(dp,-1,sizeof(dp));
	int x,y;
	cin >> x >> y;
	cin >> m;
	for(int i=1;i<=m;i++){
		int a;
		cin >> a;
		turn[i] = a;
	}
	cout << f(0,x,y);
}	