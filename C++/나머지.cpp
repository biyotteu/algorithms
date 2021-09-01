#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<int> a;
	for(int i=0;i<10;i++){
		int x;
		cin >> x;
		a.push_back(x%42);
	}
	sort(a.begin(),a.end());
	a.erase(unique(a.begin(),a.end()),a.end());
	cout << a.size();
}