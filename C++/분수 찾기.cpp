#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;
	cin >> n;
	int x = 1,y = 1,ix[2] = {1,-1},iy[2] = {-1,1},c = 0;
	n--;
	while(n--){
		int nx = x + ix[c];
		int ny = y + iy[c];
		if(nx < 1 || ny < 1){
			if(nx < 1) y++;
			else x++;
			c ^= 1;
		} 
		else{
			x = nx;
			y = ny;
		}
	}
	cout << y << '/' << x;
}