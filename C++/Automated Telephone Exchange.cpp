#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	int n,cnt = 0;
	cin >> n;
	for(int i=1;i<=99;i++) if(n-i<=99) cnt++;
	cout << cnt;
}