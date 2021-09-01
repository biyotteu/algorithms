#include <bits/stdc++.h>

using namespace std;

int b[15][15];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	for(int i=0;i<15;i++){
		for(int j=1;j<15;j++){
			if(!i) b[i][j] = j;
			else{
				for(int k=1;k<=j;k++) b[i][j] += b[i-1][k];
			}
		}
	}
	int t;
	cin >> t;
	while(t--){
		int n,k;
		cin >> n >> k;
		cout << b[n][k] <<'\n';
	}
}