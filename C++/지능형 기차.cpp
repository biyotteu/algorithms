#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int res = 0, cur = 0;
	for(int i=0;i<4;i++){
		int x,y;
		cin >> x >> y;
		cur = cur - x + y;
		res = max(cur,res);
	}
	cout << res;
}