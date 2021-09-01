#include <bits/stdc++.h>

using namespace std;

int main(){
	double a,p,q;
	cin >> a;
	p =2*a*a*a*a*a-17*a*a*a+32*a*a-25*a+6.0;
	q = a*a-2*a+2;
	cout << 2*a*a*a*a*a-17*a*a*a+32*a*a-25*a+6.0 << endl;
	cout << a*a-2*a+2 << endl;
	cout << p/q;
}