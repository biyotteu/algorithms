#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	while(1){
		int x,y;
		cin >> x >> y;
		if(x+y == 0) break;
		cout << (x>y ? "Yes\n" : "No\n"); 
	}
}