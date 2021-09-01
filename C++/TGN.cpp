#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t,a,b,c;
	cin >> t;
	while(t--){
		cin >> a >> b >> c;
		b -= c;
		if(b > a) cout << "advertise\n";
		else if(b < a) cout << "do not advertise\n";
		else cout << "does not matter\n";
	}
}