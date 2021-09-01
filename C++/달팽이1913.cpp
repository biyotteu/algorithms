#include <bits/stdc++.h>\

using namespace std;

int arr[1000][1000];
int main(){
	int n,m,x=0,y=0;
	int X[4] = {1,0,-1,0}, Y[4] = {0,1,0,-1};
	cin >> n >> m;
	int cnt = n*n,d = 0,rx,ry;
	while(cnt>0){
		if(cnt == m){
			rx = x;
			ry = y;
		}
		//cout << x << ' ' << y << ' ' << cnt<<"\n";
		arr[x][y] = cnt--;
		int nx = x + X[d], ny = y + Y[d];

		if(nx >= n || nx < 0 || ny >= n || ny < 0 || arr[nx][ny] != 0) d = (d+1) % 4;

		x += X[d];
		y += Y[d];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++) cout << arr[i][j] << " ";
		cout << "\n";
	}
	cout << rx+1 << ' ' << ry+1;
}