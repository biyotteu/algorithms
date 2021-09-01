#include <bits/stdc++.h>

using namespace std;

int n;
long long res;
map<int,long long> mp;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	mp[1e9] = -1L;
	mp[-1e9] = -1L;
	while(n--){
		int x;
		cin >> x;
		auto upp = mp.upper_bound(x);
		auto low = upp;
		low--;
		long long dth = max(upp->second,low->second) + 1;
		mp[x] = dth;
		res += dth;
		cout << res << "\n";
	}
}