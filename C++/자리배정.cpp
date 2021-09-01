#include <bits/stdc++.h>

using namespace std;

int X[4]={1,0,-1,0},Y[4]={0,1,0,-1},ch[1005][1005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m,k,d=0,x=0,y=1;
	cin >> n >> m >> k;
	for(int i=0;i<n*m;i++){
		x+=X[d],y+=Y[d];
		ch[x][y] = 1;
		int nx = x+X[d],ny = y+Y[d];
		if(ch[nx][ny] || nx < 1 || nx > m || ny < 1 || ny > n) d = (d+1)%4;
		if(i+1 == k){
			cout << y << ' ' << x;
			return 0;
		}
	}
	cout << '0';
}