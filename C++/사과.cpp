#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,res=0;
	cin >> n;
	while(n--){
		int x,y;
		cin >> x >> y;
		res += y%x;
	}
	cout << res;
}