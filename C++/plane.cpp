#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	vector<int> a(4);
	for(auto &i:a) cin >> i;
	cout << a[0]*a[1] + a[2]*a[3]; 
}