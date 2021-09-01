#include <bits/stdc++.h>

using namespace std;

int n,k=64,res;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n;
	while(n){
		if(n%2) res++;
		n/=2;
	}
	cout << max(res,1);
}