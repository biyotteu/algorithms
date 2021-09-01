#include <bits/stdc++.h>
#define ll long long

using namespace std;

int prime[2000005];
vector<ll> pp;
bool isprime(ll v){
	for(int i=0;i<pp.size() && (ll)pp[i]*pp[i] <= v;i++)
		if(v%pp[i] == 0) return false;
	return true;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	prime[0] = 1;
	for(int i=2;i<=2000000;i++){
		if(prime[i]) continue;
		pp.push_back((ll)i);
		for(int j = i+i;j<=2000000;j+=i) prime[j] = 1;
	}
	ll t,a,b;
	cin >> t;
	while(t--){
		cin >> a >> b;
		if(a+b>=4 && ((a+b)%2 == 0 || isprime(a+b-2))) cout << "YES\n";
		else cout << "NO\n";
	}
}