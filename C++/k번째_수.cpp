#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,k;
	cin >> n >> k;
	vector<int>	a(n);
	for(auto &i:a) cin >> i;
	sort(a.begin(),a.end());
	cout << a[k-1];
}