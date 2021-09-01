#include <bits/stdc++.h>

using namespace std;

int gcd(int a,int b){
	if(a < b) swap(a,b);
	if(a%b == 0) return b;
	return gcd(b,a%b); 
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,v;
	cin >> n >> v;
	for(int i=1;i<n;i++){
		int x;
		cin >> x;
		v = gcd(v,x);
	}
	for(int i=1;i<=v;i++){
		if(v%i == 0) cout << i << "\n";
	}
}