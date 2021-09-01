#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	for(int i=0;i<3;i++){
		long double sum = 0;
		int n;
		cin >> n;
		while(n--){
			long double x;
			cin >> x;
			sum += x;
		}
		if(sum == 0) cout << 0 << "\n";
		else if(sum > 0) cout << "+\n";
		else cout << "-\n";
	}
}