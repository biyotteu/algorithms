#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<int> a;
	auto i = lower_bound(a.begin(),a.end(),0);
	cout << (int)(i-a.begin());
}