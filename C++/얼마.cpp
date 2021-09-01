#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n,m;
		cin >> n >> m;
		while(m--){
			int x,y;
			cin >> x >> y;
			n += x*y;
		}
		cout << n << "\n";
	}
}