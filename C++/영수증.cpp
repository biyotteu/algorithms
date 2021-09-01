#include <bits/stdc++.h>

using namespace std;

int main(){
	int res;
	cin >> res
;	for(int i=0;i<9;i++){
		int x;
		cin >> x;
		res -= x;
	}
	cout << res;
}