#include <bits/stdc++.h>

using namespace std;

int prime[10005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m,sum = 0,ret = 0;
	cin >> m >> n;
	prime[0] = prime[1] = 1;
	for(int i=2;i<=n;i++){
		if(prime[i]) continue;
		for(int j=i+i;j<=n;j+=i) prime[j] = 1;
	}
	for(int i=m;i<=n;i++){
		if(!prime[i]){
			if(!ret) ret = i;
			sum += i;
		}
	}
	if(sum == 0) cout << -1;
	else cout << sum << "\n" << ret;
}