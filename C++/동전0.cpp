#include <bits/stdc++.h>

using namespace std;

int n,k,c[10],res;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for(int i=0;i<n;i++) cin >> c[i];
	for(int i=n-1;i>=0;i--){
		res += k/c[i];
		k %= c[i];
	}
	cout << res;
}