#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

int gcd(int a,int b){
	if(a < b) swap(a,b);
	while(b){
		int c = a%b;
		a = b;
		b = c;
	}
	return a;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;
	cin >> n;
	vector<int> ring(n);
	for(auto &i:ring) cin >> i;
	for(int i=1;i<n;i++){
		int k,x = ring[0],y = ring[i];
		while((k = gcd(x,y)) != 1){
			x /= k;
			y /= k;
		}
		cout << x << '/' << y << '\n';
	}
}