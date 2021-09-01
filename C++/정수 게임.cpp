#include <bits/stdc++.h>

using namespace std;

int n,k,res;
vector<int> num;
int gcd(int a,int b){
	if(a < b) swap(a,b);
	if(b == 0) return a;
	return gcd(b,a%b);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for(int i=0;i<k;i++){
		int x;
		cin >> x;
		num.push_back(x);
	}
	for(int i=0;i<k;i++){
		int sum = 0;
		for(int j=0;j<i;j++)
			sum += (n/gcd(num[i],num[j]));
		cout << sum << "\n";
		res += (n/num[i] - sum);
	}
	cout << res;
}