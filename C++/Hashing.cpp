#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,mod = 1234567891,r = 31;
	long long res = 0;
	string str;
	cin >> n >> str;
	for(int i=0;i<str.size();i++){
		long long cur = str[i] - 'a' + 1;
		for(int j=0;j<i;j++)
			cur = (cur*r)%mod;
		res += cur;
		res %= mod;
	}
	cout << res;
}