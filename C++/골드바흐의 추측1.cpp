#include <bits/stdc++.h>

using namespace std;

int prime[10005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	prime[0] = prime[1] = 1;
	for(int i=2;i<=10000;i++){
		if(prime[i]) continue;
		for(int j=i+i;j<=10000;j+=i) prime[j] = 1;
	}
	int t;
	cin >> t;
	while(t--){
		int x,a,b,d = 10005;
		cin >> x;
		for(int i=2;2*i<=x;i++){
			if(!prime[i] && !prime[x-i]){
				if(x-2*i < d){
					d = x-2*i;
					a = i;
					b = x-i;
				}
			}
		}
		cout << min(a,b) << ' ' << max(a,b) << "\n";
	}
}