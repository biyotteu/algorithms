#include <bits/stdc++.h>

using namespace std;

int main(){
	int a,b,c,d;
	cin >> a >> b >> c >> d;
	int res  = min(a,b);
	res = min(res,c-a);
	res = min(res,d-b);
	cout << res;
}