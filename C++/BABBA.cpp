#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	int a = 1,b = 0;
	while(n--){
		int x = b,y = a+b;
		a = x,b = y;
	}
	cout << a << ' '<< b;
}