#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	while(1){
		int x,y;
		cin >> x >> y;
		if(y == 0) return 0;
		cout << x/y << ' ' << x%y << " / " << y << "\n";
	}
}