#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,res = INT_MAX;
	cin >> n;
	vector<int> sum(n+1,0);
	for(int i=1;i<=n;i++){
		cin >> sum[i];
		sum[i] += sum[i-1];
	}
	for(int i=1;i<=n;i++){
		res = min(res,(int)abs(sum[n] - sum[i-1]*2));
	}
	cout << res;
}