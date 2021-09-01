#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	pair<int,int> a,b,c;
	cin >> a.first >> a.second;
	cin >> b.first >> b.second;
	cin >> c.first >> c.second;
	long long int res = a.first*b.second + b.first*c.second + c.first*a.second - a.second*b.first - b.second*c.first - a.first*c.second;
	if(res < 0) cout << -1;
	if(res > 0) cout << 1;
	if(res == 0) cout << 0;
}