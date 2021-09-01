#include <bits/stdc++.h>

using namespace std;

int a[20][20];
int main(){
	a[0][0] = 1;
	for(int i=1;i<20;i++){
		for(int j=0;j<=i;j++) {
			if(j == 0) a[i][j] = 1;
			else a[i][j] = a[i-1][j-1] + a[i-1][j];
		}
	}
	int n,m;
	cin >> n >> m;
	cout << a[n][m];
}