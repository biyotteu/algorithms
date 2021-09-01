#include <bits/stdc++.h>

using namespace std;

int main(){
	vector<int> a,b;
	for(int i=0;i<3;i++){
		int x;
		cin >> x;
		a.push_back(x);
	}
	for(int i=0;i<2;i++){
		int x;
		cin >> x;
		b.push_back(x);
	}
	cout << *min_element(a.begin(),a.end()) + *min_element(b.begin(),b.end()) - 50;
}