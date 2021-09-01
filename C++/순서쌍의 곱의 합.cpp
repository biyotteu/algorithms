#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	long long int n,res = 0;
	vector<long long int> num,sum;
	cin >> n;
	sum.resize(n+1);
	for(int i=1;i<=n;i++){
		long long int x;
		cin >> x;
		num.push_back(x);
		sum[i]+=(sum[i-1]+x);
	}
	for(int i=1;i<=n;i++){
		res += (sum[n]-sum[i])*num[i-1];
	}
	cout << res;

}