#include <bits/stdc++.h>

using namespace std;

int gcd(int a,int b){
	if(a < b) swap(a,b);
	if(b == 0) return a;
	return gcd(b,a%b);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		long long int sum = 0;
		cin >> n;
		vector<int> num(n);
		for(int i=0;i<n;i++) cin >> num[i];
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++) sum += gcd(num[i],num[j]);
		}
		cout << sum << "\n";
	}
}