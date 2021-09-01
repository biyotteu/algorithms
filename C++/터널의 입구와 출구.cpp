#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m,res;
	cin >> n >> m;
	res = m;
	while(n--){
		int a,b;
		cin >> a >> b;
		m += (a-b);
		if(m < 0){
			cout << 0;
			return 0;
		}
		res = max(res,m);
	}
	cout << res;
}