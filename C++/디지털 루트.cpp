#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	while(1){
		int a;
		cin >> a;
		if(!a) break;
		while(a/10 != 0){
			int c = 0;
			while(a){
				c += a%10;
				a/=10;
			}
			a = c;
		}
		cout << a << "\n";
	}
}