#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int h,n;
	cin >> h >> n;
	while(n--){
		int x,y;
		cin >> x >> y;
		if(x == 1) h-=y;
		else if(x == 2) h+=y;
		else{
			cout << h+y;
			return 0;
		}
	}
}