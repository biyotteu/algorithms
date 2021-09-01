#include <bits/stdc++.h>

using namespace std;

int gr[505][505],n,m,res;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i=0;i<m;i++){
		int x,y;
		cin >> x >> y;
		gr[x][y] = 1;
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i == j || k == i || k == j) continue;
				if(gr[i][k]&&gr[k][j]) gr[i][j] = 1;
			}
		}
	}
	for(int i=1;i<=n;i++){
		gr[i][i] = 1;
		int cnt = 0;
		for(int j=1;j<=n;j++) cnt += gr[i][j]|gr[j][i];
		if(cnt == n) res++;
	}
	cout << res;
}