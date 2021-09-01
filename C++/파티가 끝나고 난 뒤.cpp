#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m,t=5;
	cin >> n >> m;
	while(t--){
		int x ;
		cin >> x;
		cout << x - n*m << ' ';
	}
}