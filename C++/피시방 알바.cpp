#include <bits/stdc++.h>

using namespace std;

int main(){
	//ios::sync_with_stdio(false),cin.tie(0);
	int n,cnt=0;
	cin >> n;
	vector<int> a(101,0);
	while(n--){
		int x;
		cin >> x;
		if(a[x]) cnt++;
		else a[x]++;
	}
	cout << cnt;
}