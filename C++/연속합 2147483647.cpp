#include <bits/stdc++.h>
#define INF 1000000005
using namespace std;

int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	int n,cmp = 1;
	long long sum = 0,res = -INF, cur = -INF;
	cin >> n;
	while(n--){
		long long x;
		cin >> x;
		cur = max(cur,x);
		if(x>0) sum += x,cmp = 0;
		else
			if(sum + x > 0) sum += x;
			else sum = 0;
		res = max(res,sum);
	}
	if(cmp) cout << cur;
	else cout << res;
}