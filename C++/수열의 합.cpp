#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,l;
	cin >> n >> l;
	for(int i=l;i<=100;i++){
		int a = i*(i-1)/2;
		if((n-a)%i == 0 && (n-a)/i>=0){
			int k = n/i-(i-1)/2;
			for(int j=k;j<k+i;j++){
				cout<<j<<' ';
			}
			return 0;
		}
	}
	cout << -1;
}