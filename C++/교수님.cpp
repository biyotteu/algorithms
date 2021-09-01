#include <bits/stdc++.h>

using namespace std;

int bm[105][105];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,k;
	cin >> n >> k;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			int x;
			cin >> x;
			for(int p=i*k;p<(i+1)*k;p++){
				for(int q=j*k;q<(j+1)*k;q++){
					bm[p][q] = x;
				}
			}
		}
	}
	for(int i=0;i<n*k;i++){
		for(int j=0;j<n*k;j++){
			cout << bm[i][j] << ' ';
		}
		cout << "\n";
	}
}