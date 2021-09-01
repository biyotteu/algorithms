#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,f;
	cin >> n >> f;
	n/=100;
	n*=100;
	for(int i=n;i<n+1000;i++)
		if(i%f == 0){
			if(i%100 < 10) cout << 0 << i%10;
			else cout << i%100;
			return 0;
		}
}