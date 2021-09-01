#include <bits/stdc++.h>

using namespace std;


long long n;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	vector<int> a;
	cin >> n;
	while(n){
		a.push_back(n%2);
		n/=2;
	}
	for(auto i=a.rbegin();i<a.rend();i++) cout << *i;
}