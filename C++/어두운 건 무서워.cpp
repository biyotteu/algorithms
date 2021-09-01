#include <bits/stdc++.h>

using namespace std;

int n,m,q;
long long img[1005][1005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin >> img[i][j];
			img[i][j] += img[i-1][j];
			img[i][j] += img[i][j-1];
			img[i][j] -= img[i-1][j-1];
		}
	}
	for(int i=0;i<q;i++){
		long long r1,c1,r2,c2;
		cin >> r1 >> c1 >> r2 >> c2;
		long long sum = img[r2][c2] - img[r2][c1-1] - img[r1-1][c2] + img[r1-1][c1-1];
		sum /= (r2-r1+1)*(c2-c1+1);
		cout << sum << "\n";
	}	
}