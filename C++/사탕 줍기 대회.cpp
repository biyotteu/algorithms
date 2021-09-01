#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(1){
		int n,m;
		vector<int> x,y;
		cin >> n >> m;
		if(n == 0 && m == 0) return 0;
		x.resize(n+2);
		y.resize(m+2);
		for(int i=2;i<=n+1;i++){
			for(int j=2;j<=m+1;j++){
				cin >> y[j];
				y[j] = max(y[j-1],y[j-2] + y[j]);
			}
			x[i] = max(y[m+1]+x[i-2],x[i-1]);
		}
		cout << x[n+1] << "\n";
	}
}