#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int a,b,c,k;
		cin >> a >> b >> c;
		

		if(c%a){
			cout << c%a;
			k = c/a + 1;
		} 
		else{
			cout << a;
			k = c/a;
		} 

		if(k<10) cout << '0';
		cout << k << "\n";

	}
}