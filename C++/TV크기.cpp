#include <bits/stdc++.h>

using namespace std;

int main(){
	double a,b,c,k;
	cin >> a >> b >> c;
	k = a/sqrt(b*b+c*c);
	b = b*k;
	c = c*k;
	cout << (int)b << ' '<< (int)c;
}