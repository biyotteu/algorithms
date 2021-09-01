#include <bits/stdc++.h>

using namespace std;

int main(){
	int d,p,q;
	cin >> d >> p >> q;
	
	if(p < q) swap(p,q);
	int res = d/p*p+p;
	int k = res;
	for(int i=1;i<=k/p;i++){
		int cur = k - i*p;
		if(!((d-cur)%q)){
			cout << d;
			return 0;
		}
		cur += (d-cur)/q*q + q;
		if(cur == res) break;
		res = min(res,cur);
	}
	cout << res;
}