#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m;
	cin >> n >> m;
	vector<int> num(n);
	for(auto &i:num) cin >> i;
	sort(num.begin(),num.end());
	while(m--){
		int x;
		cin >> x;
		auto idx = lower_bound(num.begin(),num.end(),x);
		if(idx == num.end() || *idx != x){
			cout << -1 << "\n";
			continue;
		}
		cout << idx - num.begin() << "\n";
	}
	
}