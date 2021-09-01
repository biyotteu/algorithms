#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	int t,n;
	cin >> t;
	while(t--){
		cin >> n;
		vector<int> a(n);
		for(auto &i:a) cin >> i;
		cout << accumulate(a.begin(),a.end(),0) << "\n";
	}
}