#include <bits/stdc++.h>

using namespace std;

int main(){
	string a,b;
	cin >> a >> b;
	long long res = 0;
	for(auto i:a)
		for(auto j:b) res += (i-'0')*(j-'0');
	cout << res;
}