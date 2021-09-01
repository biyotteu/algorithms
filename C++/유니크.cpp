#include <bits/stdc++.h>

using namespace std;

int n,pl[205][3],res[205];
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	cin >> n;
	for(int i=0;i<n;i++) cin >> pl[i][0] >> pl[i][1] >> pl[i][2];
	for(int i=0;i<3;i++){
		for(int j=0;j<n;j++){
			int cmp = 1;
			for(int k=0;k<n;k++){
				if(j == k) continue;
				if(pl[j][i] == pl[k][i]){
					cmp = 0;
					break;
				}
			} 
			if(cmp) res[j] += pl[j][i];
		}
	}
	for(int i=0;i<n;i++) cout << res[i] << "\n";
}