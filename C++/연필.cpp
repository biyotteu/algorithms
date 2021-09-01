#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,a,b,c,d;
	cin >> n >> a >> b >> c >> d;
	int aa = ((n/a)+!(n%a==0))*b;
	int cc = ((n/c)+!(n%c==0))*d;
	cout << min(aa,cc);
}