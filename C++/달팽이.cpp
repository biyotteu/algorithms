#include <bits/stdc++.h>

using namespace std;

int n,k,X[4]={1,0,-1,0},Y[4]={0,1,0,-1};	
int dal[1000][1000];
pair<int,int> res;
void f(int x,int y,int v,int s){
	dal[x][y] = v;
	if(v == 1) return;
	if(v == k) res = make_pair(x,y);
	int nx = x+X[s],ny = y+Y[s];
	if(nx < 1 || ny < 1 || nx > n || ny > n || dal[nx][ny]){
		s++;
		s%=4;
		f(x+X[s],y+Y[s],v-1,s);
	}else
		f(nx,ny,v-1,s);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	f(1,1,n*n,0);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) cout << dal[i][j] << ' ';
		cout << "\n";
	}
	cout << res.first << ' ' << res.second;
}