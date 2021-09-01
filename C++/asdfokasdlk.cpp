#include <bits/stdc++.h>

using namespace std;

int main(){
	int res=0,n;
	cin >> n;
	for(int i=1;i<=n;i++)
		res += (i/10 + 1);
	cout << res;
}