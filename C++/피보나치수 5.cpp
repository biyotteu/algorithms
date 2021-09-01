#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,fibo[21];
	cin >> n;
	fibo[0] = 0;
	fibo[1] = 1;
	for(int i=2;i<=n;i++) fibo[i] = fibo[i-1] + fibo[i-2];
	cout << fibo[n];
}