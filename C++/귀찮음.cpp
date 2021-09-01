#include <bits/stdc++.h>

using namespace std;

unsigned long long int res;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long int n,sum = 0;
	vector<long long int> num;
	cin >> n;
	for(int i=0;i<n;i++){
		long long int x;
		cin >> x;
		num.push_back(x);
		sum += x;
	}
	sort(num.rbegin(),num.rend());
	for(auto i:num){
		sum -= i;
		res += sum*i;
	}
	cout << res;
}