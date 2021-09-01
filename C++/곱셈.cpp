#include <bits/stdc++.h>

using namespace std;

long long a,b,c;
long long f(long long v){
	if(v == 1) return a;
	else{
		long long cur = f(v/2);
		if(v%2) return ((cur*cur)%c*a)%c;
		else return (cur*cur)%c;
	}
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	cin >> a >> b >> c;
	a %= c;
	cout << f(b);	
}