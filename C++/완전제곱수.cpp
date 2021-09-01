#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int a,b,sum = 0, start = 0;
	cin >> a >> b;
	for(int i=sqrt(a);i<=sqrt(b);i++){
		if(i*i < a) continue;
		if(!start) start = i*i;
		sum += i*i;
	}
	if(!sum) cout << -1;
	else cout << sum << '\n' << start;
}