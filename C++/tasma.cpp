#include <bits/stdc++.h>

using namespace std;

long long f(long long v){
	if(v<0) return -v;
	return v;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	long long n,res;
	cin >> n;
	vector<long long> sum(n+1,0);
	for(int i=1;i<=n;i++){
		cin >> sum[i];
		sum[i] += sum[i-1];
	}
	res = f(sum[n] - sum[1]*2);
	for(int i=3;i<=n;i++){
		res = min(res,f(sum[n] - sum[i-1]*2));
	}
	cout << res;
}