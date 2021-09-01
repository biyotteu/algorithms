#include <bits/stdc++.h>

using namespace std;

int main(){
	vector<int> num(3);
	for(int i=0;i<3;i++) cin >> num[i];
	sort(num.begin(),num.end());
	for(auto i:num) cout << i << ' ';
}