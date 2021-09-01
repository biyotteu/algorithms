#include <bits/stdc++.h>

using namespace std;

map<long long int,long long int> dp;
long long int n,p,q;
long long int f(long long int v){
	if(v == 0) return 1;
	if(dp[v] != 0) return dp[v];
	return dp[v] = f(v/p) + f(v/q);
}
int main(){
	cin >> n >> p >> q;
	cout << f(n);
}