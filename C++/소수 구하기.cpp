#include <bits/stdc++.h>
#define MM 1000005

using namespace std;

int prime[MM];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	prime[1] = 1;
	for(int i=2;i<=MM;i++){
		if(prime[i]) continue;
		for(int j=i+i;j<=MM;j+=i) prime[j] = 1;
	}
	int a,b;
	cin >> a >> b;
	for(int i=a;i<=b;i++) if(!prime[i]) cout << i << '\n';
}