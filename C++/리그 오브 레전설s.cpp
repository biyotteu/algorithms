#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m;
	cin >> n >> m;
	vector<long long> a(n+1);
	a[0] = 1;
	for(int i=1;i<=n;i++){
		if(i>=m) a[i] += a[i-m];
		a[i] += a[i-1];
		a[i]%=MOD;
	}
	cout << a[n];
}