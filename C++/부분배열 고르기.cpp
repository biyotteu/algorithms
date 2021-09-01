#include <bits/stdc++.h>

using namespace std;

vector<long long> a;
int n;
long long f(int x, int y){
	if(x == y) return (a[y] - a[x-1])*(a[y] - a[x-1]));
	return v;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	cin >> n;
	a.push_back(0);
	for(int i=0;i<n;i++){
		int x;
		cin >> x;
		a.push_back(x);
	}
	f(1,n);
	cout << res;
}