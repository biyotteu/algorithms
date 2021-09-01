#include <bits/stdc++.h>

using namespace std;

vector<int> num;
int n;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i=0;i<n;i++){
		int x;
		cin >> x;
		num.push_back(x);
	}
	cout << *max_element(num.begin(),num.end()) - *min_element(num.begin(),num.end());
}