#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int sum;
	cin >> sum;
	while(1){
		int x;
		char y;
		cin >> y;
		if(y == '='){
			cout << sum;
			return 0;
		}
		cin >> x;
		if(y == '+') sum += x;
		else if(y == '-') sum -= x;
		else if(y == '*') sum *= x;
		else sum /= x;
	}
}