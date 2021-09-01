#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> num;
	while(n--){
		int x;
		cin >> x;
		num.push_back(x);
	}
	sort(num.begin(),num.end());
	for(auto i:num) cout << i << ' ';
}
