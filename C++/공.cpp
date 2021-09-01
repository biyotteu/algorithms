#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,start = 1;
	cin >> n;
	while(n--){	
		int x,y;
		cin >> x >> y;
		if(x == start) start = y;
		else if(y == start) start = x;
	}
	cout << start;
}