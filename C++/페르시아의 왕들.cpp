#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	while(1){
		int a,b,c,d;
		cin >> a >> b >> c >> d;
		if(a == b && b == c && c == d && d == 0) return 0;
		cout << c-b << ' ' << d-a << "\n";
	}
}