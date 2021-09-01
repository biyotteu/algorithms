#include <bits/stdc++.h>

using namespace std;

int prime[1005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	prime[1] = 1;
	for(int i=2;i<=1000;i++){
		if(prime[i]) continue;
		for(int j=i+i;j<=1000;j+=i) prime[j] = 1;
	}
	int n,res=0;
	cin >> n;
	while(n--){
		int x;
		cin >> x;
		if(!prime[x]) res++;
	}		
	cout << res;
}