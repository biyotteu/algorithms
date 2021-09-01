#include <bits/stdc++.h>

using namespace std;

int x;
map<int,int> a;
int main(){
	cin >> x;
	while(1){
		if(x == 1) break;
		if(a[x]){
			cout << "UNHAPPY";
			return 0;
		}
		a[x] = 1;
		int k = 0;
		while(x){
			int b = x%10;
			k += b*b;
			x/=10;
		}
		x = k;
	}
	cout << "HAPPY";
}