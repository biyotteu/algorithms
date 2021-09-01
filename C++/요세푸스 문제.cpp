#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,k,res = 0;
	cin >> n >>k;
	for(int i=1;i<=n;i++)	res = (res+k)%i;
	cout << res+1;
}	