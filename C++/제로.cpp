#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;
	cin >> n;
	vector<int> a;
	while(n--){
		int x;
		cin >> x;
		if(x) a.push_back(x);
		else a.pop_back();
	}
	cout << accumulate(a.begin(),a.end(),0);
}