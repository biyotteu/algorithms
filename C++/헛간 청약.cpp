#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,w,h,l;
	cin >> n >> w >> h >> l;
	cout << min((w/l)*(h/l),n);
}