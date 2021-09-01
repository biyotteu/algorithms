#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n,m,cnt=0;
		cin >> n >> m;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<n;j++){
				if((j*j+i*i+m)%(i*j) == 0) cnt++;
			}
		}
		cout << cnt << "\n";
	}
}