#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n,d;
		cin >> n >> d;
		vector<int> a(n);
		for(auto &i:a) cin >> i;
		sort(a.begin(),a.end());
		if(*max_element(a.begin(),a.end()) <= d || a[0]+a[1] <= d) cout << "YES\n";
		else cout << "NO\n";
	}
}