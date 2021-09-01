#include <bits/stdc++.h>

using namespace std;

int main(){
	vector<int> a(3);
	for(int i=0;i<3;i++) cin >> a[i];
	sort(a.begin(),a.end());
	string s;
	cin >> s;
	for(auto i:s){
		cout << a[i-'A'] <<' ';
	}
}