#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int a,b,c,d,e,f;
	cin >> a >> b >> c >> d >> e >> f;
	cout << (c*e-f*b)/(a*e-d*b) << ' ' << (c*d-a*f)/(b*d-a*e);
}