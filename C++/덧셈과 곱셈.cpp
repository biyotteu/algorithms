#include <bits/stdc++.h>

using namespace std;

long long int res = 1;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int a,b;
	cin >> a>> b;
	for(int i=a;i<=b;i++){
		res*=i*(i+1)/2;
		res%=14579;
	}
	cout << res;
}