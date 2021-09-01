#include <bits/stdc++.h>

using namespace std;

int n,a[105],res = INT_MAX;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i=0;i<n;i++) cin >> a[i];
	for(int i=0;i<n;i++){
		int x;
		cin >> x;
		if(!x) continue;
		a[i]/=x;
		res = min(res,a[i]);
	}
	cout << res;
}