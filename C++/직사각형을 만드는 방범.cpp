#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	int n,res = 0;
	cin >> n;
	for(int i=1;i<=n;i++)
		for(int j=i;i*j<=n;j++) res++;
	cout << res;
}