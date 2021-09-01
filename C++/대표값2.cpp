#include <bits/stdc++.h>

using namespace std;

int main(){
	vector<int> a(5);
	for(int i=0;i<5;i++) cin >> a[i];
	cout << accumulate(a.begin(),a.end(),0)/5 << "\n";
	sort(a.begin(),a.end());
	cout << a[2];
}