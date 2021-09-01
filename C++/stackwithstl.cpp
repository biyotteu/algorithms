#include <bits/stdc++.h>

using namespace std;

int main(){
	function<(int)> f = [](int n){
		cout << n << "\n";
		f(n-1);
	};
	f(5);
}