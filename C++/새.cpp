#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	int cnt = 1,res = 0;
	while(n){
		if(cnt > n) cnt = 1;
		n -= cnt++;
		res++;
	}
	cout << res;
}