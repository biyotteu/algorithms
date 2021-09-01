#include <bits/stdc++.h>

using namespace std;

int gcd(int a,int b){
	if(a < b) swap(a,b);
	return b ? gcd(b,a%b):a;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n),aa;
	for(int i=0;i<n;i++) cin >> a[i];
	sort(a.begin(),a.end());
	for(int i=0;i<n-1;i++) aa.push_back(a[i+1]-a[i]);
	int k = aa[0];
	for(int i=1;i<n-1;i++) k = gcd(k,aa[i]);
	int res = 0;
	for(auto i:aa) res += (i-1)/k;
	cout << res;
}