#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin >> t;
	for(int T=1;T<=t;T++){
		int k;
		cin >> k;
		vector<int> x(8),y(8);
		for(int i=0;i<8;i++) cin >> x[i] >> y[i];
		sort(x.begin(),x.end());
		sort(y.begin(),y.end());
		int l=-100000000, r= 100000000;
		while(l<r){
			int mid = (l+r)/2;
			
		}

		cout << "Case #" << T << "\n";
	}
}