#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin >> n;
	vector<int> num(n);
	for(int i=0;i<n;i++) cin >> num[i];
	cin >> m;
	cout << lower_bound(num.begin(),num.end(),m) - num.begin();
}