#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin >> t;
	for(int T=1;T<=t;T++){
		long long r;
		cin >> r;
		long long cnt = 0;
		for(long long x=1;x<r;x++){
			long long k = (long long)sqrt(r*r-x*x);
			if(k*k + x*x == r*r) cnt += k-1;
			else cnt += k;
		}
		cout << "Case #" << T << "\n";
		cout << (cnt+r-1)*4+1 << "\n";
	}
}