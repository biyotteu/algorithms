#include <bits/stdc++.h>

using namespace std;

int prime[1000005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	prime[1] = 1;
	for(int i=2;i<=1000000;i++){
		if(!prime[i])
			for(int j=i+i;j<=1000000;j+=i) prime[j] = 1;
	}
	int n;
	while((cin >> n) && n !=0){
		for(int i=2;i<=n;i++){
			if(!prime[i] && !prime[n-i]){
				cout <<n << " = "<< i << " + " << n-i << "\n";
				break;
			}
		}
	}
}